from ml_genn.synapses import Exponential
import numpy as np
import matplotlib.pyplot as plt

from ml_genn import Population, Connection, SequentialNetwork, Network
from ml_genn.callbacks import Checkpoint
from ml_genn.compilers import EPropCompiler, EventPropCompiler, InferenceCompiler, compiled_network
from ml_genn.connectivity import Dense,FixedProbability
from ml_genn.initializers import Normal
from ml_genn.neurons import IntegrateFireInput, LeakyIntegrate, LeakyIntegrateFire, SpikeInput
from ml_genn.serialisers import Numpy
from ml_genn.utils.data import preprocess_spikes
from ml_genn.callbacks import VarRecorder, SpikeRecorder
from ml_genn.losses import FixationMSEResponseCE
from ml_genn.metrics import Metric

from time import perf_counter
from ml_genn.utils.data import (calc_latest_spike_time, calc_max_spikes,
                                log_latency_encode_data)

from ml_genn.compilers.event_prop_compiler import default_params
from poission_spikes import poission_spike_generator

from cogtasks import list_tasks

class NoMetric(Metric):
    def update(self, y_true, y_pred, communicator):
        pass
    def reset(self):
        pass
    @property
    def result(self):
        return None

def data_encoding():
    tasks = list(list_tasks("modcog")) 
    spikes, Y, X, M, LENGHT = poission_spike_generator(tasks) 
    X = [preprocess_spikes(t, ids, 115) for t, ids in spikes] 
    print(len(X))
    return X, Y, M, LENGHT

def model(X, Y):
    INPUT_NUM = 115
    HIDDEN_NUM = 128
    OUT_NUM = int(Y.max())   # 17 if classes run 0..16, as in your plot
    BATCH_SIZE = 64
    N_LAYERS = 3
    SPARSITY = 1.0
    TRAIN = True
    NUM_EPOCHS = 2000
    
    network = Network(default_params=default_params)
    with network:
        inp = Population(SpikeInput(max_spikes=BATCH_SIZE * calc_max_spikes(X)), INPUT_NUM, record_spikes=True)
        hid_1 = Population(LeakyIntegrateFire(v_thresh=0.7, v_reset=0.0, tau_mem=20.0,
                                        tau_refrac=1.0), HIDDEN_NUM, record_spikes=True)
        hid_2 = Population(LeakyIntegrateFire(v_thresh=0.7, v_reset =0.0, tau_mem=20.0,
                                        tau_refrac=1.0), HIDDEN_NUM, record_spikes=True)
        hid_3 = Population(LeakyIntegrateFire(v_thresh=0.7, v_reset =0.0, tau_mem=20.0,
                                                tau_refrac=1.0), HIDDEN_NUM, record_spikes=True)
        out = Population(LeakyIntegrate(tau_mem=20.0, readout="var"), OUT_NUM, record_spikes=True)

        Connection(inp, hid_1, Dense(Normal(sd=1.0 / np.sqrt(INPUT_NUM), mean=0.6)), synapse=Exponential(5.0))
        Connection(hid_1, hid_1, Dense(Normal(sd=1.0 / np.sqrt(HIDDEN_NUM))), synapse=Exponential(5.0))
        Connection(hid_1, hid_2, Dense(Normal(sd=1.0 / np.sqrt(HIDDEN_NUM), mean=0.4)), synapse=Exponential(5.0))  
        Connection(hid_2, hid_2, Dense(Normal(sd=1.0 / np.sqrt(HIDDEN_NUM))), synapse=Exponential(5.0))
        Connection(hid_2, hid_3, Dense(Normal(sd=1.0 / np.sqrt(HIDDEN_NUM), mean=0.1)), synapse=Exponential(5.0))   
        Connection(hid_3, hid_3, Dense(Normal(sd=1.0 / np.sqrt(HIDDEN_NUM))), synapse=Exponential(5.0))  # recurrent
        Connection(hid_3, out, Dense(Normal(sd=0.1 / np.sqrt(HIDDEN_NUM))), synapse=Exponential(5.0)) 


    STEPS_PER = 20
    OUT_NUM = 16


    # class 0 (fixation) -> all zeros; class c in 1..16 -> one-hot on unit c-1
    onehot = np.zeros((*Y.shape, OUT_NUM), np.float32)     # (N, 34, 16)
    r = Y > 0
    onehot[r, Y[r] - 1] = 1.0
    Y_t = np.repeat(onehot, STEPS_PER, axis=1)             # (N, 680, 16)
    # padding: everything at or after the real end is ignored
    t = np.arange(Y_t.shape[1])[None, :]
    Y_t[t >= (LENGTH.astype(int) * STEPS_PER)[:, None]] = -1.0    

    rs = Y_t.sum(-1)
    resp = rs >= 0.5
    w = Y_t.shape[1] / np.maximum(resp.sum(1), 1)
    Y_t = Y_t * np.where(resp, w[:, None], 1.0)[:, :, None]

    print(Y_t.shape)
    

    if TRAIN:
        compiler = EventPropCompiler(
            example_timesteps=680,
            losses=FixationMSEResponseCE(),
            optimiser="adam",
            batch_size=BATCH_SIZE,
            kernel_profiling=True, 
            per_timestep_loss=True,
            backend="cuda",
            reg_nu_upper = 10,
            reg_lambda_upper = {hid_1: 4e-9, hid_2: 4e-9, hid_3: 4e-9},
            reg_lambda_lower = {hid_1: 4e-9, hid_2: 4e-9, hid_3: 4e-9},
            )
        
        compiled_net = compiler.compile(network, record_spikes=True)
        
        serialiser = Numpy("checkpoints")

        with compiled_net:
            start_time = perf_counter()
            callbacks = ["batch_progress_bar"]
            metrics, _  = compiled_net.train(
                {inp: X[:512]},
                {out: Y_t[:512]},
                num_epochs=NUM_EPOCHS,
                metrics=NoMetric(),
                shuffle=True,
                callbacks=["batch_progress_bar", Checkpoint(serialiser)],
            )

            end_time = perf_counter()

            compiled_net.save_connectivity((NUM_EPOCHS - 1,), serialiser="numpy")  # check name in docs

        
           

        network.load((NUM_EPOCHS - 1,), serialiser)          # trained weights into the network

        inf = InferenceCompiler(evaluate_timesteps=680, batch_size=BATCH_SIZE)
        inf_net = inf.compile(network)

        hidden = [hid_1, hid_2, hid_3]
        N_EVAL = 512

        with inf_net:
            _, cb = inf_net.evaluate({inp: X[:N_EVAL]}, {out: Y_t[:N_EVAL]},metrics=NoMetric(),
                             callbacks=[VarRecorder(out, "v", key="out_v")] + [SpikeRecorder(h, key=f"h{i}") for i, h in enumerate(hidden)])

        layer_report(cb, len(hidden), HIDDEN_NUM, 680/1000)

        v = np.array(cb["out_v"])                            # expect (N, 680, 16)
        print(v.shape)
        print("L_fix %.3f  L_resp %.3f  resp acc %.3f" % combined_loss(v[:512], Y_t[:512]))

        fix = np.abs(Y_t[:512].sum(-1)) <0.5
        resp = Y_t[:512].sum(-1) >= 0.5
        print("max v            :", np.abs(v).max())
        print("mean v fixation  :", np.abs(v[fix].mean()))
        print("mean v response  :", np.abs(v[resp]).mean())
        print("spread response  :", v[resp].std(-1).mean())

def combined_loss(v, Y_t):
    rs = Y_t.sum(-1)
    fix, resp = np.abs(rs) < 0.5, rs >= 0.5
    L_fix = (v[fix] ** 2).sum(-1).mean()
    m = v.max(-1, keepdims=True)
    logp = v - m - np.log(np.exp(v - m).sum(-1, keepdims=True))
    L_resp = -(logp * (Y_t > 0)).sum(-1)[resp].mean()
    acc = (v.argmax(-1) == Y_t.argmax(-1))[resp].mean()
    return L_fix, L_resp, acc

def layer_report(cb, n_layers, n_neurons, t_sec):
    for i in range(n_layers):
        data = cb[f"h{i}"]
        if isinstance(data, tuple) and len(data) == 2:
            ids = data[1]
        else:
            ids = [d[1] for d in data]
        n_trails = len(ids)
        all_ids = np.concatenate ([np.asarray(x, dtype=int) for x in ids]) if n_trails else np.array([], int)  
        per_neuron = np.bincount(all_ids, minlength=n_neurons) / max(n_trails, 1)
        rate = per_neuron / t_sec
        print(f"layer {i+1}: mean {rate.mean():6.1f} Hz | max {rate.max():6.1f} Hz | Silent {np.sum(per_neuron == 0)}/{n_neurons}" )


            



if __name__ == "__main__":
    spikes, Y, M, LENGTH = data_encoding()
    model(spikes, Y)


