//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file DetectorConstruction.cc
/// \brief Implementation of the B1::DetectorConstruction class

#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

namespace B1
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
  G4bool checkOverlaps = true;

 
  
  // define materials
  
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_Galactic");//Vaccum
  
  G4double density = 10000*g/cm3;
  G4double a = 32*g/mole;
  // G4Material* target_mat = new G4Material("oxygen",8.,a,density); // target material
  G4Material* target_mat = nist->FindOrBuildMaterial("G4_Au"); // Oxygen target
  

  G4Material* detector_mat = nist->FindOrBuildMaterial("G4_AIR"); // simple material
  

  // define sizes:
  // World (cube)
  G4double world_sizeXYZ = 0.5*cm; // 2cm cube
  // target (cube)
  G4double target_sizeXY = 0.49999*cm; // 1cm lateral size
  G4double target_sizeZ  = 0.1*mm; // 1 micron thickness
  //detector (sphere)
  G4double detecter_inner_radius = 0.24999*cm; 
  G4double detecter_outer_radius = 0.25000*cm; 


 // create world volume
  G4Box* solidWorld =
    new G4Box("World",                       //its name
       0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);     //its size

  G4LogicalVolume* logicWorld =
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name

  G4VPhysicalVolume* physWorld =
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0) // world usually placed at 0,0,0
                      logicWorld,            //its logical volume
                      "World",               //its name 
                      0,                     //its mother  volume - world mother volume is 0
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking


  // create target
  G4Box* solidTar =
    new G4Box("Target",                    //its name
        0.5*target_sizeXY, 0.5*target_sizeXY, 0.5*target_sizeZ); //its size

  G4LogicalVolume* logicTar =
    new G4LogicalVolume(solidTar,            //its solid
                        target_mat,             //its material
                        "Target");         //its name

  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(),         //at (0,0,0)
                    logicTar,                //its logical volume
                    "Target",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking


    // create detector
   //G4Sphere (const G4String &pName, G4double pRmin, G4double pRmax, G4double pSPhi, G4double pDPhi, G4double pSTheta, G4double pDTheta)
  
  G4Sphere* solidDet =
    new G4Sphere("Detector",                    //its name
        detecter_inner_radius, detecter_outer_radius, 0.*degree, 360*degree, 0*degree, 180*degree); 

  G4LogicalVolume* logicDet =
    new G4LogicalVolume(solidDet,            //its solid
                        detector_mat,             //its material
                        "Detector");         //its name

  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(),         //at (0,0,0)
                    logicDet,                //its logical volume
                    "Detector",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
  // Set Shape2 as scoring volume
  //
  fScoringVolume = logicDet;

  //
  //always return the physical World
  //
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}
