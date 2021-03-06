

#include "TDGDetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

TDGDetectorConstruction::TDGDetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

TDGDetectorConstruction::~TDGDetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* TDGDetectorConstruction::Construct()
{  
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
  
  // Envelope parameters
  //
  G4double env_sizeXY = 20*cm, env_sizeZ = 30*cm;
  G4Material* env_mat = nist->FindOrBuildMaterial("G4_AIR");
   
  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = false;

  //     
  // World
  //
  G4double world_sizeXY = 1.2*env_sizeXY;
  G4double world_sizeZ  = 1.2*env_sizeZ;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
  
  G4Box* solidWorld =    
    new G4Box("World",                       //its name
       0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size
      
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name
                                   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking
                     
  //     
  // Envelope
  //  
  G4Box* solidEnv =    
    new G4Box("Envelope",                    //its name
        0.5*env_sizeXY, 0.5*env_sizeXY, 0.5*env_sizeZ); //its size
      
  G4LogicalVolume* logicEnv =                         
    new G4LogicalVolume(solidEnv,            //its solid
                        env_mat,             //its material
                        "Envelope");         //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(),         //at (0,0,0)
                    logicEnv,                //its logical volume
                    "Envelope",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  G4Material* mat_int = nist -> FindOrBuildMaterial("G4_POLYSTYRENE");
 
  // build a internal detector

  
  
  G4double innerRadius =17.9*mm;
  G4double outerRadius =19.4*mm;
  G4double hz =10.5*mm; 
  G4double startAngle =0.*deg;
  G4double spanningAngle =360.*deg;


  G4Tubs* solidpozo = new G4Tubs ("pozo", innerRadius, outerRadius, hz, startAngle, spanningAngle);

  G4LogicalVolume* logicalcilindro= new G4LogicalVolume (solidpozo,
							 mat_int,
							 "pozo");
  //cilindro1
  G4RotationMatrix* rotationMatrix = new G4RotationMatrix();
  rotationMatrix -> rotateX(90.*deg);
 G4VPhysicalVolume* pozo1 =  new G4PVPlacement(rotationMatrix,
					       G4ThreeVector(38.8*mm,0,38.8*mm),
					       logicalcilindro,
					       "pozo",
					       logicEnv,
					       false,
					       0,
					       checkOverlaps);
 
 //cilindro2
 G4VPhysicalVolume* pozo2 = new G4PVPlacement(rotationMatrix,
					      G4ThreeVector(0,0,38.8*mm),
					      logicalcilindro,
					      "pozo",
					      logicEnv,
					      false,
					      0,
					      checkOverlaps);
 //cilindro3
 G4VPhysicalVolume* pozo3 = new G4PVPlacement(rotationMatrix,
					      G4ThreeVector(-38.8*mm,0,38.8*mm),
					      logicalcilindro,
					      "pozo",
					      logicEnv,
					      false,
					      0,
					      checkOverlaps);
 //cilindro4
 G4VPhysicalVolume* pozo4 = new G4PVPlacement(rotationMatrix,
					      G4ThreeVector(38.8*mm,0,0),
					      logicalcilindro,
					      "pozo",
					      logicEnv,
					      false,
					      0,
					      checkOverlaps);
 //cilindro5
  G4VPhysicalVolume* pozo5 = new G4PVPlacement(rotationMatrix,
					      G4ThreeVector(),
					      logicalcilindro,
					      "pozo",
					      logicEnv,
					      false,
					      0,
					      checkOverlaps);
  //cilindro6
   G4VPhysicalVolume* pozo6 = new G4PVPlacement(rotationMatrix,
						G4ThreeVector(-38.8*mm,0,0),
						logicalcilindro,
						"pozo",
						logicEnv,
						false,
						0,
						checkOverlaps);
   //cilindro7
    G4VPhysicalVolume* pozo7 = new G4PVPlacement(rotationMatrix,
						 G4ThreeVector(38.8*mm,0,-38.8*mm),
						 logicalcilindro,
						 "pozo",
						 logicEnv,
						 false,
						 0,
						 checkOverlaps);
    //cilindro8
     G4VPhysicalVolume* pozo8 = new G4PVPlacement(rotationMatrix,
						  G4ThreeVector(0,0,-38.8*mm),
						  logicalcilindro,
						  "pozo",
						  logicEnv,
						  false,
						  0,
						  checkOverlaps);
     //cilindro9
      G4VPhysicalVolume* pozo9 = new G4PVPlacement(rotationMatrix,
						   G4ThreeVector(-38.8*mm,0,-38.8*mm),
						   logicalcilindro,
						   "pozo",
						   logicEnv,
						   false,
						   0,
						   checkOverlaps);
  
 
 					      
  //tapas
  G4double innerRadius1 =0.*mm;
  G4double outerRadius1 =19.4*mm;
  G4double hz1 =0.75*mm; 
  G4double startAngle1 =0.*deg;
  G4double spanningAngle1 =360.*deg;
 


 G4Tubs* tapa = new G4Tubs("tapa_inf", innerRadius1, outerRadius1, hz1, startAngle1, spanningAngle1);
 G4LogicalVolume* logicaltapa = new G4LogicalVolume (tapa,
						     mat_int,
						     "tapa_inf");

 
 
 //tapa1
 G4VPhysicalVolume* tapa_infe = new G4PVPlacement(rotationMatrix,
						  G4ThreeVector(38.8*mm,-11.25*mm,38.8*mm),
						  logicaltapa,
						  "tapa_inf",
						  logicEnv,
						  false,
						  0,
						  checkOverlaps);
 
 //tapa2
 G4VPhysicalVolume* tapa_infe2 = new G4PVPlacement(rotationMatrix,
						   G4ThreeVector(0,-11.25*mm,38.8*mm),
						   logicaltapa,
						   "tapa_inf",
						   logicEnv,
						   false,
						   0,
						   checkOverlaps);
 //tapa3
 G4VPhysicalVolume* tapa_infe3 = new G4PVPlacement(rotationMatrix,
						   G4ThreeVector(-38.8*mm,-11.25*mm,38.8*mm),
						   logicaltapa,
						   "tapa_inf",
						   logicEnv,
						   false,
						   0,
						   checkOverlaps);

 //tapa4
 G4VPhysicalVolume* tapa_infe4 = new G4PVPlacement(rotationMatrix,
						   G4ThreeVector(38.8*mm,-11.25*mm,0),
						  logicaltapa,
						  "tapa_inf",
						  logicEnv,
						  false,
						  0,
						  checkOverlaps);
 //tapa5
  G4VPhysicalVolume* tapa_infe5 = new G4PVPlacement(rotationMatrix,
						    G4ThreeVector(0,-11.25*mm,0),
						    logicaltapa,
						    "tapa_inf",
						    logicEnv,
						    false,
						    0,
						    checkOverlaps);
  //tapa6
   G4VPhysicalVolume* tapa_infe6 = new G4PVPlacement(rotationMatrix,
						     G4ThreeVector(-38.8*mm,-11.25*mm,0),
						     logicaltapa,
						     "tapa_inf",
						     logicEnv,
						     false,
						     0,
						     checkOverlaps);
   //tapa7
    G4VPhysicalVolume* tapa_infe7 = new G4PVPlacement(rotationMatrix,
						      G4ThreeVector(38.8*mm,-11.25*mm,-38.8*mm),
						      logicaltapa,
						      "tapa_inf",
						      logicEnv,
						      false,
						      0,
						      checkOverlaps);
    //tapa8
     G4VPhysicalVolume* tapa_infe8 = new G4PVPlacement(rotationMatrix,
						       G4ThreeVector(0,-11.25*mm,-38.8*mm),
						       logicaltapa,
						       "tapa_inf",
						       logicEnv,
						       false,
						       0,
						       checkOverlaps);
     //tapa9
      G4VPhysicalVolume* tapa_infe9 = new G4PVPlacement(rotationMatrix,
							G4ThreeVector(-38.8*mm,-11.25*mm,-38.8*mm),
							logicaltapa,
							"tapa_inf",
							logicEnv,
							false,
							0,
							checkOverlaps);

 
 
 fScoringVolume=logicalcilindro;
 fScoringVolume=logicaltapa;
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
