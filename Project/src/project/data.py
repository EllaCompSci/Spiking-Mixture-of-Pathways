import sys
from types import NoneType
import numpy as np
import pyqtgraph as pg
from PyQt6 import QtWidgets, QtCore
from cogtasks import make_dataset

import numpy as np
from cogtasks import list_tasks, make_task

def build_trials(collection, tasks, n_per_task, seed=0, **kwargs):
    n_tasks = len(tasks)
    obs, gts, rule = [], [], []

    for k, name in enumerate(tasks):
        env = make_task(collection, name, seed=seed + k, **kwargs)
        for _ in range(n_per_task):
            env.new_trial()
            obs.append(env.ob.copy())      # (T_i, 33)
            gts.append(env.gt.copy())      # (T_i,)
            rule.append(k)

    lengths = np.array([len(g) for g in gts])
    T, D, N = lengths.max(), obs[0].shape[1], len(obs)

    X = np.zeros((N, T, D + n_tasks), np.float32)   # inputs + one-hot rule
    Y = np.zeros((N, T), np.int64)                  # labels (0 = fixation)
    M = np.zeros((N, T), bool)                      # True on real timesteps

    for i, (o, g, k) in enumerate(zip(obs, gts, rule)):
        L = len(g)
        X[i, :L, :D] = o
        X[i, :L, D + k] = 1.0                       # rule unit k on
        Y[i, :L] = g
        M[i, :L] = True
    return X, Y, M, lengths




COLLECTION = "modcog"
N_PER_TASK = 100

tasks = list(list_tasks(COLLECTION))# build_trials as in your original code
X, Y, M, lengths = build_trials(COLLECTION, tasks, n_per_task=N_PER_TASK)


def show_task():
    tasks = list(list_tasks(COLLECTION))
    X, Y, M, lengths = build_trials(COLLECTION, tasks, n_per_task=N_PER_TASK)
    N, T, C = X.shape
    n_tasks = len(tasks)
    print(X.shape, "| max/min length:", lengths.max(), lengths.min())

    app = QtWidgets.QApplication(sys.argv)
    root = QtWidgets.QWidget()
    root.setWindowTitle("Mod-Cog trials")
    root.resize(1100, 750)
    vbox = QtWidgets.QVBoxLayout(root)

    glw = pg.GraphicsLayoutWidget()
    vbox.addWidget(glw, 1)

    # Input heatmap: time on x, channel on y
    p_in = glw.addPlot(row=0, col=0)
    p_in.setLabel("left", "Channel (0=fix, 1-32=ring, 33+=rule)")
    img = pg.ImageItem()
    img.setColorMap(pg.colormap.get("viridis"))
    p_in.addItem(img)
    pad_in = pg.LinearRegionItem(brush=(128, 128, 128, 120), movable=False)
    p_in.addItem(pad_in)

    # Target class
    p_lab = glw.addPlot(row=1, col=0)
    p_lab.setLabel("left", "Target class")
    p_lab.setLabel("bottom", "Timestep")
    p_lab.setXLink(p_in)
    curve = p_lab.plot(pen=None, symbol="s", symbolSize=5, symbolBrush="c")
    pad_lab = pg.LinearRegionItem(brush=(128, 128, 128, 120), movable=False)
    p_lab.addItem(pad_lab)

    def make_row(label, maximum):
        row = QtWidgets.QHBoxLayout()
        lab = QtWidgets.QLabel(label)
        lab.setFixedWidth(60)
        sl = QtWidgets.QSlider(QtCore.Qt.Orientation.Horizontal)
        sl.setRange(0, maximum)
        sp = QtWidgets.QSpinBox()
        sp.setRange(0, maximum)
        sl.valueChanged.connect(sp.setValue)
        sp.valueChanged.connect(sl.setValue)
        row.addWidget(lab); row.addWidget(sl, 1); row.addWidget(sp)
        vbox.addLayout(row)
        return sl

    s_task = make_row("Task", n_tasks - 1)
    s_trial = make_row("Trial", N_PER_TASK - 1)
    s_all = make_row("Global", N - 1)

    updating = False

    def draw(i):
        L = lengths[i]
        img.setImage(X[i])                      # (T, C): time on x
        curve.setData(np.arange(T), Y[i])
        pad_in.setRegion((L, T)); pad_lab.setRegion((L, T))
        k = i // N_PER_TASK
        p_in.setTitle(f"{tasks[k]}  |  task {k}  |  trial {i % N_PER_TASK}  |  T={L}")
        p_in.autoRange()

    def from_task_trial():
        nonlocal updating
        if updating: return
        updating = True
        i = s_task.value() * N_PER_TASK + s_trial.value()
        s_all.setValue(i)
        updating = False
        draw(i)

    def from_global():
        nonlocal updating
        if updating: return
        updating = True
        i = s_all.value()
        s_task.setValue(i // N_PER_TASK)
        s_trial.setValue(i % N_PER_TASK)
        updating = False
        draw(i)

    s_task.valueChanged.connect(from_task_trial)
    s_trial.valueChanged.connect(from_task_trial)
    s_all.valueChanged.connect(from_global)

    draw(0)
    root.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    show_task()

