import numpy as np

data=[1,2,3,4,5,6,7,8,9,10]

print("Mean : ",np.mean(data))
print("Median : ",np.median(data))
print("Percentile 25 : ",np.percentile(data,25),"\npercentile 75 : ",np.percentile(data,75))
print("Variance : ",np.var(data))
print("Standard Deviation : ",np.std(data))