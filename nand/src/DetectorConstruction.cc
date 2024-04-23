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
#include "G4Tubs.hh"

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
  G4Material* det_mat = nist->FindOrBuildMaterial("G4_Al");//Vaccum
  

  // define sizes:
  // World (cube)
  G4double world_sizeXYZ = 100*cm; // 2cm cube



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


  //G4Tubs (const G4String &pName, G4double pRMin, G4double pRMax, G4double pDz, G4double pSPhi, G4double pDPhi)
  double pRMin =0; 
  double pRMax =10*cm;
  double pDz   =5*cm;
  double pSPhi =0;
  double pDPhi =360*degree;
  


  G4String detName_prefix = "detector";

  // detector 0
  int detNum =0;
  G4String detName = detName_prefix + std::to_string(detNum);
  G4Tubs* solidDet0 =
    new G4Tubs(detName,                       //its name
       pRMin,pRMax,pDz,pSPhi,pDPhi);     //its size
  
  G4LogicalVolume* logicDet0 =
    new G4LogicalVolume(solidDet0,          //its solid
                        det_mat,           //its material
                        detName);            //its name


    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(0,0,-35*cm),       //at (0,0,0) // world usually placed at 0,0,0
                      logicDet0,            //its logical volume
                      detName,               //its name 
                      logicWorld,                     //its mother  volume is the world volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking                
  

  // detector 1  
  // detNum =1;
  // detName = detName_prefix + std::to_string(detNum);

  // G4Tubs* solidDet1 =
  //   new G4Tubs(detName,                       //its name
  //      pRMin,pRMax,pDz,pSPhi,pDPhi);     //its size
  
  // G4LogicalVolume* logicDet1 =
  //   new G4LogicalVolume(solidDet1,          //its solid
  //                       det_mat,           //its material
  //                       detName);            //its name


  //   new G4PVPlacement(0,                     //no rotation
  //                     G4ThreeVector(0,0,35*cm),       //at (0,0,0) // world usually placed at 0,0,0
  //                     logicDet1,            //its logical volume
  //                     detName,               //its name 
  //                     logicWorld,                     //its mother  volume is the world volume
  //                     false,                 //no boolean operation
  //                     0,                     //copy number
  //                     checkOverlaps);        //overlaps checking                
  


  // detector 2 - rotated by 90 deg
  // detNum=2; 
  // detName = detName_prefix + std::to_string(detNum);
  // G4Tubs* solidDet2 =
  //   new G4Tubs(detName+detNum,                       //its name
  //      pRMin,pRMax,pDz,pSPhi,pDPhi);     //its size
  
  // G4LogicalVolume* logicDet2 =
  //   new G4LogicalVolume(solidDet2,          //its solid
  //                       det_mat,           //its material
  //                       detName+detNum);            //its name


  //   G4RotationMatrix* rotation = new G4RotationMatrix();
  //   rotation->rotateX(0*deg);
  //   rotation->rotateY(90*deg);
  //   rotation->rotateZ(0*deg);

  //   new G4PVPlacement(rotation,                     //no rotation
  //                     G4ThreeVector(35*cm,0,0),       //at (0,0,0) // world usually placed at 0,0,0
  //                     logicDet2,            //its logical volume
  //                     detName+detNum,               //its name 
  //                     logicWorld,                     //its mother  volume is the world volume
  //                     false,                 //no boolean operation
  //                     0,                     //copy number
  //                     checkOverlaps);        //overlaps checking    












  // Set Shape2 as scoring volume
  //
  fScoringVolume = logicDet0;

  //
  //always return the physical World
  //
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}
