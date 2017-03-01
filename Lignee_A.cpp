//==============================
//    INCLUDES
//==============================
#include "Lignee_A.h"
#include <iostream>
using std::cout;
using std::endl;


//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================



//==============================
//    CONSTRUCTORS
//==============================

Lignee_A::Lignee_A(int x, int y){
  
  coord[0]=x;
  coord[1]=y;

  Raa=0.1;
  Rab=0.1;

}
Lignee_A::Lignee_A(int x, int y, float a, float b, float c){
  
  coord[0]=x;
  coord[1]=y;

  A_int=a;
  B_int=b;
  C_int=c;

  Raa=0.1;
  Rab=0.1;

}


//==============================
//    DESTRUCTOR
//==============================

Lignee_A::~Lignee_A(){}
//==============================
//    PUBLIC METHODS
//==============================

void Lignee_A::Describe(){
	cout<< "Cette bactérie de type "<<type<<" est placée en ("<<coord[0]<<", "<<coord[1]<<" )"<<endl;
	cout<< "Elle présente une concentration interne en A: "<<A_int<<", en B: "<<B_int<<" et en C: "<<C_int<<endl<<" ainsi qu'une fitness de "<<w<<endl;

}

void Lignee_A::Death(){}
void Lignee_A::Deplacement(){Bacterie::Deplacement();}