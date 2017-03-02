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
  Grille=new Metabolite**[height];
  for(int i=0; i<height; i++){
    Grille[i]=new Metabolite*[width];
  }
}

//==============================
//    DESTRUCTOR
//==============================
Map::~Map(){}

//==============================
//    PUBLIC METHODS
//==============================
Metabolite*** Map::GetGrille(){

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
  vector<Bacterie*> tableDeBacteries;

  /*for (vector<int>::iterator it=tableDeNombres.begin(); it!=tableDeNombres.end(); ++it){
    cout << ' ' << *it;
  }*/

  int compteur=0;
  while(compteur<width*height){
    for(int i=0; i<width; i++){
      for(int j=0; j<height; j++){
        if(tableDeNombres[compteur]==0){
    
          Lignee_A* a= new Lignee_A(i,j);
	        Grille[i][j]= new Metabolite(A_init, a); 
          compteur++;
        }

        else{
          
          Lignee_B* b= new Lignee_B(i,j);
          Grille[i][j]= new Metabolite(A_init, b);
          compteur++;
        }
        
	    }
    }
  }
}

void Map::bougeMetabo(){

}

void Map::DescribeBacteries(){

  for(int i=0; i<width;i++){
    for(int j=0; j<height; j++){
      cout<<(Grille[i][j]->Getptr())->Gettype()<<" ";

    }
    
  }
  cout<<""<<endl;
}

void Map::DescribeABC(){

  for(int i=0; i<width;i++){
    for(int j=0; j<height; j++){
      cout<<"("<<Grille[i][j]->GetA()<<", "<<Grille[i][j]->GetB()<<", "<<Grille[i][j]->GetC()<<") ";

    }
    
  }
  cout<<""<<endl;
}
  
void Map::renouvelle(){
  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      Grille[i][j]->SetA(A_init);
      Grille[i][j]->SetC(0.0);
      Grille[i][j]->SetA(0.0);
    }
  }
}
