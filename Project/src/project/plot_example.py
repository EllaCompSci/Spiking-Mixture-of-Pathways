import pygenn
import sys
import numpy as np
import pyqtgraph as pg
from PyQt6 import QtWidgets

app = QtWidgets.QApplication(sys.argv)

win = pg.plot(title="Spike raster")
win.setLabel("bottom", "Time (ms)")
win.setLabel("left", "Neuron")

# fake spikes: replace with your own arrays
rng = np.random.default_rng(0)
times, ids = np.nonzero(rng.random((500, 32)) < 0.02)

win.plot(times, ids, pen=None, symbol="s", symbolSize=3, symbolBrush="w")

sys.exit(app.exec())
