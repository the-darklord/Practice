import numpy as np
import pandas as pd

data = pd.DataFrame({'group': ['a', 'a', 'a', 'b','b', 'b', 'c', 'c','c'],'ounces': [4, 3, 12, 6, 7.5, 8, 3, 5, 6]})
data=data.pivot_table(values='ounces',index='group',aggfunc="count")
print(data)