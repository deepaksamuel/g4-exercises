#%%
import numpy as np 
import matplotlib.pyplot as plt
import pandas as pd
import math

headers = ['eid','pid','detector','is_primary','x','y','z','del_x','del_y','del_z','vx','vy','vz','delt','globTime',"propTime",'localTime','ni_edep','tot_edep',
           'tot_E','tot_KE','momx','momy','momz','px','py','pz']
# len(headers)

df = pd.read_csv("/home/samuel/g4-exercises/alpha-scattering/build/output_nt_simple.csv",skiprows=30,header=0,names=headers)
# plt.hist(df['tot_KE'])
r= np.sqrt(df['x']**2 + df['y']**2 + df['z']**2)  # Magnitude of the vector

zenith_rad = np.arccos(np.sqrt(df['x']**2 + df['z']**2) / r)    
plt.hist(np.degrees(zenith_rad))
