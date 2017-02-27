//==============================
//    INCLUDES
//==============================
#include "Map.h"
#include "Metabolite.h"
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
  width=32;
  height=32;
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

