import numpy as np
import pandas as pd

ages = [20, 22, 25, 27, 21, 23, 37, 31, 61, 45, 41, 32]
bins=[18,25,35,60,100]
cats=pd.cut(ages,bins)
t=pd.value_counts(cats)
bin_names = ['Youth', 'YoungAdult', 'MiddleAge', 'Senior']
new_cats=pd.cut(ages,bins,labels=bin_names)
t_new=pd.value_counts(new_cats).cumsum()
print(t_new)