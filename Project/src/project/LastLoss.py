import numpy as np
from ml_genn.metrics import MeanSquareError

class LastStepMSE(MeanSquareError):
    def update(self, y_true, y_pred, communicator):
        y_true = np.asarray(y_true)[:, -1, :]
        super().update(y_true, y_pred, communicator)