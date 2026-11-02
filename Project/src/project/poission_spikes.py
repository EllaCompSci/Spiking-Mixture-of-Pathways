from data import build_trials
from cogtasks import list_tasks
import numpy as np 

tasks = list(list_tasks("modcog"))
X, Y, M, lengths = build_trials("modcog", tasks, n_per_task=100)


