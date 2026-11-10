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

from time import perf_counter
from ml_genn.utils.data import (calc_latest_spike_time, calc_max_spikes,
                                log_latency_encode_data)

from ml_genn.compilers.eprop_compiler import default_params
from poission_spikes import poission_spike_generator

from cogtasks import list_tasks

def data_encoding():
    tasks = list(list_tasks("modcog")) 
    spikes, Y, M, LENGHT = poission_spike_generator(tasks) 
    X = [preprocess_spikes(t, ids, 115) for t, ids in spikes]
    return X, Y, M, LENGHT

def model(X, Y):
    print(Y.shape)
    INPUT_NUM = 115
    HIDDEN_NUM = 256
    OUT_NUM = Y.shape[-1]
    BATCH_SIZE = 1
    SPARSITY = 1.0
    TRAIN = True
    NUM_EPOCHS = 3
    
    network = Network()
    with network:
        inp = Population(SpikeInput(max_spikes=BATCH_SIZE * calc_max_spikes(X)), INPUT_NUM)
        hid = Population(LeakyIntegrateFire(v_thresh=1.0, v_reset=0.0, tau_mem=20.0,
                                        tau_refrac=1.0), HIDDEN_NUM)
        out = Population(LeakyIntegrate(tau_mem=20.0, readout="avg_var"), OUT_NUM)

        Connection(inp, hid, Dense(Normal(sd=1.0 / np.sqrt(INPUT_NUM))), synapse=Exponential(5.0))
        Connection(hid, hid, Dense(Normal(sd=1.0 / np.sqrt(HIDDEN_NUM))), synapse=Exponential(5.0))   # recurrent
        Connection(hid, out, Dense(Normal(sd=1.0 / np.sqrt(OUT_NUM))), synapse=Exponential(5.0)) 


    STEPS_PER = 20                                   # 20 ms task step / 1 ms sim step
    NUM_STEPS = int(LENGTH.max()) * STEPS_PER        # 34 * 20 = 680

    if TRAIN:
        compiler = EventPropCompiler(
            example_timesteps=NUM_STEPS,
            losses="sparse_categorical_crossentropy",
            optimiser="adam",
            batch_size=BATCH_SIZE,
            kernel_profiling=True,
        )
        compiled_net = compiler.compile(network)
        Y = np.argmax(Y, axis=-1).astype(np.int32)  # shape: (N,)        # (8200, 680, 34)


        with compiled_net:
            start_time = perf_counter()
            callbacks = ["batch_progress_bar"]
            metrics, _  = compiled_net.train(
                {inp: X},
                {out: Y},
                num_epochs=NUM_EPOCHS,
                shuffle=True,
                callbacks=callbacks)

            end_time = perf_counter()
            



if __name__ == "__main__":
    spikes, Y, M, LENGTH = data_encoding()
    model(spikes, Y)


