import numpy as np
import pandas as pd

l=list(range(0,21))
p=np.arange(36).reshape((6,6))
upper,lower=np.vsplit(p,[5])
print(upper,lower)