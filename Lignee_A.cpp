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
  
  type='A';

  coord[0]=x;
  coord[1]=y;

  Raa=0.1;
  Rab=0.1;

}

Lignee_A::Lignee_A(int x, int y, float a, float b, float c){
  
  type='A';

  coord[0]=x;
  coord[1]=y;

  A_int=a;
  B_int=b;
  C_int=c;

  Raa=0.1;
  Rab=0.1;

}

Lignee_A::Lignee_A(const Lignee_A& a){
  type=a.type;

  coord[0]=a.coord[0];
  coord[1]=a.coord[1];

  A_int=a.A_int;
  B_int=a.B_int;
  C_int=a.C_int;

  Raa=a.Raa;
  Rab=a.Rab;
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

Bacterie* Lignee_A::Division(){
	A_int = A_int/2;
	B_int = B_int/2;
	C_int = C_int/2;
	Lignee_A* newcell = new Lignee_A(coord[0],coord[1],A_int,B_int,C_int);
	return newcell;
}



int Lignee_A::Death(){Bacterie::Death();}
/*void Lignee_A::Deplacement(){Bacterie::Deplacement();}*/
char Lignee_A::Gettype(){Bacterie::Gettype();}