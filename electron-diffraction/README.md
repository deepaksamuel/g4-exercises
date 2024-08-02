## Nuclear radius from electron diffraction
Electrons of energy 183 MeV shot along the z direction from (0,0,-1*mm) hits  gold target of size 0.5 cm x 0.5 cm x 0.1 mm. A sphere of inner radius 0.24999 cm and outer radius 0.25000 cm surrounds it, working as a detector.

The default world material is Vaccum.

The nucleus presents itself as a disc to the incoming electrons which get diffracted. These diffracted electrons form light-like interference pattern on the detectors.
From the first minima in the scattering angle distribution, one can estimate the nuclear radius.

This activity requires huge CPU power in order for the first minima to be visible (see file `gold_183MeV_109particles_cut_180MeV`).

For the above setup it required 10^9 particles and the simulation ran for 1 hour on a CPU with 100 threads. The files were in the order of 40 GB, even plotting the histograms took about 15 minutes. In the plot in file `gold_183MeV_109particles_cut_180MeV` one can clearly see the minimum at 40 degrees as in  https://www.sr-niel.org/index.php/sr-niel-long-write-up/electron-cross-section.

Only elastic scattering was selected was enforcing a cut of E>180 MeV.


For this example to work, the nuclear form factors have to be set appropiately. It was set to `Flat` (see, exampleB1.cc).

### Activities

a. Change the target to G4_In and check if you see a minimum at 60 deg. Repeat for Carbon and Oxygen and verify the plots in Kenneth Krane

b. For each of the target check what would be an optimal energy by choosing a very low energy and a very high energy and observing the scattering angles.
