//==============================
//    INCLUDES
//==============================
#include "Map.h"
#include <iostream>
#include <string>
using namespace std;

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
Map::Map(){
  A_init=10;
  D=0.1;
  T=10000;
  t=200;
  temps=0;
  h=1;
}

//==============================
//    DESTRUCTOR
//==============================
Map::~Map(){}

//==============================
//    PUBLIC METHODS
//==============================
Metabolite** Map::GetGrille(){
  return Grille;
}

void Map::placeBacteries(){
  for(int i=0; i<width; i++){
    for(int j=0; i<height; i++){
	  Grille[i][j]=*new Metabolite(A_init, new Bacterie());  
	  }
  }
}
