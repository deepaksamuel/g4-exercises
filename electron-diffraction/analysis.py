#%%
import numpy as np 
import matplotlib.pyplot as plt
import pandas as pd
from scipy.optimize import curve_fit
#column double pid
#column double posx
#column double posy
#column double posz
#column double tot_E
#column double tot_KE

headers = ['pid','x','y','z','tot_E','tot_KE']

df = pd.read_csv("build/output_nt_simple_t0.csv",skiprows=30,header=0,names=headers)

# df = df[df['pid']==1000020000] # select alpha particles

# plt.hist(df['z'],log=True) 

# print(df['pid'].unique()[0]) # get pids

# plot angular distribution

r= np.sqrt(df['x']**2 + df['y']**2 + df['z']**2)  # Magnitude of the vector
df['theta'] = np.arccos(np.sqrt(df['x']**2 + df['z']**2) / r)

df = df[df['theta']>0.1]
plt.hist(np.degrees(df['theta']),bins=120,log=True)



# fitting cosec^4(theta/2) !!! needs updating

# def func(theta, a):
#     return a * np.power(np.sin(theta /2), -4)

# df = df[df['pid']==1000020000] # select alpha particles

# r= np.sqrt(df['x']**2 + df['y']**2 + df['z']**2)  # Magnitude of the vector
# zenith_rad = np.arccos(np.sqrt(df['x']**2 + df['z']**2) / r)

# counts, bins, patches = plt.hist(zenith_rad , bins=25, density=True)
# # plt.show()
# bin_centers = (bins[:-1] + bins[1:]) / 2

# # Fit the function to the histogram
# popt, pcov = curve_fit(func, bin_centers, counts, p0=1)

# a = popt[0]

# plt.plot(bin_centers, func(bin_centers, a), label='Fitted curve')
#%%
