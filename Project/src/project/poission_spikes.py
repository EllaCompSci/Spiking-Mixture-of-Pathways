from data import build_trials
from cogtasks import list_tasks
import numpy as np 
from ml_genn.utils.data import preprocess_spikes


def modcog_to_spikes(x, task_dt_ms=20, sim_dt_ms=1.0, max_rate_hz=300.0,
                     lo=0.0, hi=1.0, rng=None):
    rng = rng or np.random.default_rng()
    steps_per = int(round(task_dt_ms / sim_dt_ms))

    # data -> rate, with FIXED lo/hi from the training set, not per trial
    x01 = np.clip((x - lo) / (hi - lo), 0.0, 1.0)
    rates = x01 * max_rate_hz                      # (T, B, D)

    # hold each task step's rate for steps_per sim steps
    rates = np.repeat(rates, steps_per, axis=0)    # (T*steps_per, B, D)

    p = 1.0 - np.exp(-rates * sim_dt_ms / 1000.0) 
    return rng.random(p.shape) < p

def raster_to_events(spikes, lengths, steps_per, dt_ms=1.0): 
    events = []
    for b, L in enumerate(lengths):
        seg = spikes[:L * steps_per, b, :]        # drop the padding
        t_idx, n_idx = np.nonzero(seg)
        events.append((t_idx * dt_ms, n_idx))
    return events
 
import numpy as np
import matplotlib.pyplot as plt

def plot_trial(events, X, lengths, b, steps_per=20, task_dt_ms=20):
    t, ids = events[b]
    L = lengths[b]

    fig, ax = plt.subplots(2, 1, figsize=(11, 7), sharex=True)

    # input (X is (B, T, D)), x axis in ms
    ax[0].imshow(X[b, :L, :].T, aspect="auto", origin="lower",
                 extent=[0, L * task_dt_ms, 0, X.shape[2]], cmap="viridis")
    ax[0].set_ylabel("channel")
    ax[0].set_title(f"trial {b}: input")

    # spike raster
    ax[1].scatter(t, ids, s=6, marker="|", color="k")
    ax[1].set_xlim(0, L * task_dt_ms)
    ax[1].set_ylim(-0.5, X.shape[2] - 0.5)
    ax[1].set_ylabel("channel")
    ax[1].set_xlabel("time (ms)")
    ax[1].set_title(f"spikes ({len(t)} total)")

    plt.tight_layout()
    plt.show()


def poission_spike_generator(tasks):
    X, Y, M, lengths = build_trials("modcog", tasks, n_per_task=100)
    X_t = X.transpose(1, 0, 2)               # (B, T, D) -> (T, B, D) = (34, 8200, 115)
    spikes = modcog_to_spikes(X_t)           # (34*20, 8200, 115) = (680, 8200, 115)
    print(spikes.shape)                      # expect (680, 8200, 115)
    events = raster_to_events(spikes, lengths, steps_per=20)
    return events, Y, X, M, lengths

if __name__ == "__main__":
    tasks = list(list_tasks("modcog"))
    events, Y, X, M, lengths = poission_spike_generator(tasks)
    plot_trial(events, X, lengths, 2)



