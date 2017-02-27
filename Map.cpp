//==============================
//    INCLUDES
//==============================
#include "Map.h"
#include <iostream>
#include <string>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector

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

  vector<int> tableDeNombres;
  for(int i=0; i<(height*width)/2; i++){
    tableDeNombres.push_back(0);
  }
  for(int i=(height*width)/2; i<=height*width; i++){
    tableDeNombres.push_back(1);
  }
  random_shuffle(tableDeNombres.begin(), tableDeNombres.end());

  /*for (vector<int>::iterator it=tableDeNombres.begin(); it!=tableDeNombres.end(); ++it){
    cout << ' ' << *it;
  }

  for(int k=0; k<width*height; k++){
    for(int i=0; i<width; i++){
      for(int j=0; j<height; j++){
        if(tableDeNombres[k]==0){

	        Grille[i][j]=*new Metabolite(A_init, Bacterie* new Lignee_A(i,j)); 
          
        }

        else{
  
          Grille[i][j]=*new Metabolite(A_init, Bacterie* new Lignee_B(i,j));
        }
        
	    }
    }
  }*/
}
