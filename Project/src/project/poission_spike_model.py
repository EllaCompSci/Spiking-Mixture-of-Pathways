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

from time import perf_counter
from ml_genn.utils.data import (calc_latest_spike_time, calc_max_spikes,
                                log_latency_encode_data)

from ml_genn.compilers.event_prop_compiler import default_params
from poission_spikes import poission_spike_generator

from cogtasks import list_tasks

def data_encoding():
    tasks = list(list_tasks("modcog")) 
    spikes, Y, X, M, LENGHT = poission_spike_generator(tasks) 
    X = [preprocess_spikes(t, ids, 115) for t, ids in spikes] 
    print(len(X))
    return X, Y, M, LENGHT

def model(X, Y):
    INPUT_NUM = 115
    HIDDEN_NUM = 256
<<<<<<< HEAD
    OUT_NUM = int(Y.max())+1  # 17 if classes run 0..16, as in your plot
    print(OUT_NUM)
    BATCH_SIZE = 64
=======
    OUT_NUM = int(Y.max())   # 17 if classes run 0..16, as in your plot
    BATCH_SIZE = 1
>>>>>>> 04296bb (custom loss function during fixation and response period)
    SPARSITY = 1.0
    TRAIN = True
    NUM_EPOCHS = 100
    
    network = Network(default_params=default_params)
    with network:
        inp = Population(SpikeInput(max_spikes=BATCH_SIZE * calc_max_spikes(X)), INPUT_NUM)
        hid = Population(LeakyIntegrateFire(v_thresh=0.2, v_reset=0.0, tau_mem=20.0,
                                        tau_refrac=1.0), HIDDEN_NUM)
        out = Population(LeakyIntegrate(tau_mem=20.0, readout="max_var"), OUT_NUM)

        Connection(inp, hid, Dense(Normal(sd=1.0, mean=0.5)), synapse=Exponential(5.0))
        Connection(hid, hid, Dense(Normal(sd=1.0, mean=0.5)), synapse=Exponential(5.0))   # recurrent
        Connection(hid, out, Dense(Normal(sd=1.0, mean=0.5)), synapse=Exponential(5.0)) 


    STEPS_PER = 20
<<<<<<< HEAD
    NUM_STEPS = Y.shape[1] * STEPS_PER                       # 34 * 20 = 680
    Y_t = np.repeat(np.eye(OUT_NUM, dtype=np.float32)[Y],    
                STEPS_PER, axis=1)                       

    Y_trail = Y.max(axis=1).astype(np.int32)                      
    if TRAIN:
        compiler = EventPropCompiler(
            example_timesteps=NUM_STEPS,
            losses="sparse_categorical_crossentropy",
            optimiser="adam",
            batch_size=BATCH_SIZE,
            kernel_profiling=True,
            backend="cuda")
        
        compiled_net = compiler.compile(network)
        
        print(Y_t.shape)
=======
    OUT_NUM = 16

    resp_start = (Y > 0).argmax(axis=1) * STEPS_PER        # (N,) in sim timesteps
    trial_end  = LENGTH.astype(int) * STEPS_PER            # (N,) in sim timesteps

    # class 0 (fixation) -> all zeros; class c in 1..16 -> one-hot on unit c-1
    onehot = np.zeros((*Y.shape, OUT_NUM), np.float32)     # (N, 34, 16)
    r = Y > 0
    onehot[r, Y[r] - 1] = 1.0

    Y_t = np.repeat(onehot, STEPS_PER, axis=1)             # (N, 680, 16)

    # padding: everything at or after the real end is ignored
    t = np.arange(Y_t.shape[1])[None, :]
    Y_t[t >= trial_end[:, None]] = -1.0    

    print(Y_t.shape)
    

    if TRAIN:
        compiler = EventPropCompiler(
            example_timesteps=680,
            losses=FixationMSEResponseCE(),
            optimiser="adam",
            batch_size=BATCH_SIZE,
            kernel_profiling=True, 
            per_timestep_loss=True,
            )
        
        compiled_net = compiler.compile(network)
        
        serialiser = Numpy("checkpoints")
>>>>>>> 04296bb (custom loss function during fixation and response period)

        with compiled_net:
            start_time = perf_counter()
            callbacks = ["batch_progress_bar"]
            metrics, _  = compiled_net.train(
                {inp: X},
                {out: Y_trail},
                num_epochs=NUM_EPOCHS,
                shuffle=True,
                callbacks=callbacks,
            )

            end_time = perf_counter()

            compiled_net.save_connectivity((NUM_EPOCHS - 1,), serialiser="numpy")  # check name in docs

            print(f"Accuracy = {100 * metrics[out].result}%")
           

        network.load((NUM_EPOCHS - 1,), serialiser)          # trained weights into the network

        inf = InferenceCompiler(evaluate_timesteps=680, batch_size=BATCH_SIZE)
        inf_net = inf.compile(network)

        with inf_net:
            _, cb = inf_net.evaluate({inp: X}, {out: Y_t},
                             callbacks=[VarRecorder(out, "v", key="out_v")])

        v = np.array(cb["out_v"])                            # expect (N, 680, 16)
        print(v.shape)
        print("L_fix %.3f  L_resp %.3f  resp acc %.3f" % combined_loss(v, Y_t))

def combined_loss(v, Y_t):
    rs = Y_t.sum(-1)
    fix, resp = np.abs(rs) < 0.5, rs >= 0.5
    L_fix = (v[fix] ** 2).sum(-1).mean()
    m = v.max(-1, keepdims=True)
    logp = v - m - np.log(np.exp(v - m).sum(-1, keepdims=True))
    L_resp = -(logp * (Y_t > 0)).sum(-1)[resp].mean()
    acc = (v.argmax(-1) == Y_t.argmax(-1))[resp].mean()
    return L_fix, L_resp, acc



            



if __name__ == "__main__":
    spikes, Y, M, LENGTH = data_encoding()
    model(spikes, Y)


