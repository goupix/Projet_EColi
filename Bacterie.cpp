//==============================
//    INCLUDES
//==============================
#include "Bacterie.h"
#include "Metabolite.h"
#include <iostream>
using std::cout;
using std::endl;


//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================



//==============================
//    CONSTRUCTORS
//==============================
Bacterie::Bacterie(){
coord[0]=0; 
coord[1]=0;

p_death=0.02; 
p_mutation=0; 
W_min=0.001; 


A_int=0;
B_int=0; 
C_int=0;
}

//==============================
//    DESTRUCTOR
//==============================

Bacterie::~Bacterie(){}
//==============================
//    PUBLIC METHODS
//==============================
void Bacterie::Describe(){
	cout<< "Cette bactérie est placée en ("<<coord[0]<<", "<<coord[1]<<" )"<<endl;
	cout<< "Elle présente une concentration interne en A: "<<A_int<<", en B: "<<B_int<<" et en C: "<<C_int<<endl;
}

void Bacterie::Death(){
  for(int i=0; i<32; i++){
    for(int j=0; j<32; j++){
      srand(time(NULL));
      float nombre = (float)rand() / (float)RAND_MAX;
      if(nombre<p_death){
        float A=A_int;
        float B=B_int; //tester plutot avec Grille(x,y) qui correspond aux concentrations en métabolites dans la grille 
        float C=C_int;
        cout<<"RIP"<<endl;
        cout<<A+B+C<<endl; 
        }
      }
     }
    }
        
