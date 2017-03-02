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
  
  type='B';

  coord[0]=x;
  coord[1]=y;

  Rbb=0.1;
  Rbc=0.1;

}
Lignee_B::Lignee_B(int x, int y, float a, float b, float c){
  
  type='B';

  coord[0]=x;
  coord[1]=y;

  A_int=a;
  B_int=b;
  C_int=c;

  Rbb=0.1;
  Rbc=0.1;

}

Lignee_B::Lignee_B(const Lignee_B& a){
  type=a.type;

  coord[0]=a.coord[0];
  coord[1]=a.coord[1];

  A_int=a.A_int;
  B_int=a.B_int;
  C_int=a.C_int;

  Rbb=a.Rbb;
  Rbc=a.Rbc;
}


//==============================
//    DESTRUCTOR
//==============================

Lignee_B::~Lignee_B(){}
//==============================
//    PUBLIC METHODS
//==============================

Bacterie* Lignee_B::Division(){
	A_int = A_int/2;
	B_int = B_int/2;
	C_int = C_int/2;
	Lignee_B* newcell = new Lignee_B(coord[0],coord[1],A_int,B_int,C_int);
	return newcell;
}

void Lignee_B::Describe(){
	cout<< "Cette bactérie de type "<<type<<" est placée en ("<<coord[0]<<", "<<coord[1]<<" )"<<endl;
	cout<< "Elle présente une concentration interne en A: "<<A_int<<", en B: "<<B_int<<" et en C: "<<C_int<<endl<<" ainsi qu'une fitness de "<<w<<endl;

}

int Lignee_B::Death(){Bacterie::Death();}
/*void Lignee_B::Deplacement(){Bacterie::Deplacement();}*/
char Lignee_B::Gettype(){Bacterie::Gettype();}