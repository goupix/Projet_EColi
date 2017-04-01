//==============================
//    INCLUDES
//==============================
#include "Lignee_S.h"
#include <iostream>
using std::cout;
using std::endl;


//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================
int Lignee_S::compteur_S = 0; //On initialise notre compteur à 0


//==============================
//    CONSTRUCTORS
//==============================

Lignee_S::Lignee_S(){

  compteur_S++;

type='S';

  Rbb=0.1;
  Rbc=0.1;

}
Lignee_S::Lignee_S(float a, float b, float c){

  compteur_S++;
  
  type='S';

  A_int=a;
  B_int=b;
  C_int=c;

  Rbb=0.1;
  Rbc=0.1;

}





//==============================
//    DESTRUCTOR
//==============================

Lignee_S::~Lignee_S(){
  compteur_S--;
}
//==============================
//    PUBLIC METHODS
//==============================

Bacterie* Lignee_S::Division(){

	A_int = A_int/2.0; //les individus fils héritent de la moitié des concentrations internes du parent
	B_int = B_int/2.0;
	C_int = C_int/2.0;

	Lignee_S* newcell = new Lignee_S(A_int, B_int, C_int); //nouvelle bactérie de type B qui récupère les nouveaux attributs 
	return newcell;

}

void Lignee_S::Describe(){
	cout<< "Cette bactérie de type " <<type<<" présente une concentration interne en A: "<<A_int<<", en B: "<<B_int<<" et en C: "<<C_int<<endl<<" ainsi qu'une fitness de "<<w<<endl;

}

int Lignee_S::Death(){ return Bacterie::Death();}

char Lignee_S::Gettype(){return Bacterie::Gettype();}

int Lignee_S::Mute(){return Bacterie::Mute();}

float Lignee_S::GetA_int(){return A_int;}

float Lignee_S::GetB_int(){return B_int;}

float Lignee_S::GetC_int(){return C_int;}

float& Lignee_S::Getw(){return w;}

int Lignee_S::nombre_S()
{
    return compteur_S;   //On renvoie simplement la valeur du compteur
}

float Lignee_S::absorb(float c, float h){ //système qui régit le réseau métabolique des individus de type Gb

  float newb=c;
  float newbint=B_int;
  float newcint=C_int;

  newb+=h*(-Rbb*c);
  newbint+=h*(Rbb*c-Rbc*B_int);
  newcint+=h*(Rbc*B_int);

  B_int=newbint;
  C_int=newcint;
  
  return newb;

}

