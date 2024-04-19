#%%
import numpy as np 
import matplotlib.pyplot as plt
import pandas as pd
import math

headers = ['eid','pid','detector','is_primary','x','y','z','del_x','del_y','del_z','vx','vy','vz','delt','globTime',"propTime",'localTime','ni_edep','tot_edep',
           'tot_E','tot_KE','momx','momy','momz','px','py','pz']
# len(headers)

df = pd.read_csv("build/output_nt_simple_t0.csv",skiprows=30,header=0,names=headers)

df = df[df['pid']==1000020000] # select alpha particles
# plt.hist(df['tot_KE'])
r= np.sqrt(df['x']**2 + df['y']**2 + df['z']**2)  # Magnitude of the vector

zenith_rad = np.arccos(np.sqrt(df['x']**2 + df['z']**2) / r)    
# plt.hist(np.degrees(zenith_rad),bins=100,log=True)

plt.hist(df['z'],log=True)

# print(df['pid'].unique()[0])
