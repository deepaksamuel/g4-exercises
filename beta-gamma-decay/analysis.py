#%%
import numpy as np 
import matplotlib.pyplot as plt
import pandas as pd
from scipy.optimize import curve_fit


headers = ['eid','pid','detector','is_primary','x','y','z','del_x','del_y','del_z','vx','vy','vz','delt','globTime',"propTime",'localTime','ni_edep','tot_edep',
           'tot_E','tot_KE','momx','momy','momz','px','py','pz']

df = pd.read_csv("build/output_nt_simple_t0.csv",skiprows=30,header=0,names=headers)

plt.hist(df['pid'],bins=100,log=True)
# print(df['pid'].unique())


#%%
