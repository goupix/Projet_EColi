//==============================
//    INCLUDES
//==============================
#include "Lignee_B.h"
#include <iostream>
using std::cout;
using std::endl;


//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================



//==============================
//    CONSTRUCTORS
//==============================

Lignee_B::Lignee_B(int x, int y){
  
  coord[0]=x;
  coord[1]=y;

  Rbb=0.1;
  Rbc=0.1;

}
Lignee_B::Lignee_B(int x, int y, float a, float b, float c){
  
  coord[0]=x;
  coord[1]=y;

  A_int=a;
  B_int=b;
  C_int=c;

  Rbb=0.1;
  Rbc=0.1;

}


//==============================
//    DESTRUCTOR
//==============================

Lignee_B::~Lignee_B(){}
//==============================
//    PUBLIC METHODS
//==============================

void Lignee_B::Describe(){
	cout<< "Cette bactérie de type "<<type<<" est placée en ("<<coord[0]<<", "<<coord[1]<<" )"<<endl;
	cout<< "Elle présente une concentration interne en A: "<<A_int<<", en B: "<<B_int<<" et en C: "<<C_int<<endl<<" ainsi qu'une fitness de "<<w<<endl;

}

void Lignee_B::Death(){}
void Lignee_B::Deplacement(){Bacterie::Deplacement();}