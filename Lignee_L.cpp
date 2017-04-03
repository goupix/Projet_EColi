//==============================
//    INCLUDES
//==============================
#include "Lignee_L.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;


//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================
int Lignee_L::compteur_L = 0;  //On initialise notre compteur à 0


//==============================
//    CONSTRUCTORS
//==============================

Lignee_L::Lignee_L(){
  
  compteur_L++;

  type='L';

  Raa=0.1;
  Rab=0.1;

}

Lignee_L::Lignee_L(float a, float b, float c){

  compteur_L++;
  
  type='L';

  A_int=a;
  B_int=b;
  C_int=c;

  Raa=0.1;
  Rab=0.1;

}





//==============================
//    DESTRUCTOR
//==============================

Lignee_L::~Lignee_L(){
  compteur_L--;
}
//==============================
//    PUBLIC METHODS
//==============================

void Lignee_L::Describe(){
	cout<< "Cette bactérie de type "<<type<<" présente une concentration interne en A: "<<A_int<<", en B: "<<B_int<<" et en C: "<<C_int<<" ainsi qu'une fitness de "<<w<<endl;
}

Bacterie* Lignee_L::Division(){

	A_int = A_int/2.0; //les individus fils héritent de la moitié des concentrations internes du parent
	B_int = B_int/2.0;
	C_int = C_int/2.0;
  
	Lignee_L* newcell = new Lignee_L(A_int,B_int,C_int); //nouvelle bactérie de type A qui récupère les nouvelles concentrations intra suite à la division 
	return newcell;
}



int Lignee_L::Death(){return Bacterie::Death();}

char Lignee_L::Gettype(){return Bacterie::Gettype();}

int Lignee_L::Mute(){return Bacterie::Mute();}

float Lignee_L::GetA_int(){return A_int;}

float Lignee_L::GetB_int(){return B_int;}

float Lignee_L::GetC_int(){return C_int;}

float& Lignee_L::Getw(){return w;}

int Lignee_L::nombre_L()
{
    return compteur_L;   // renvoie la valeur du compteur
}


float Lignee_L::absorb(float c, float h){ // système qui régit le réseau métabolique des individus de type Ga

  float newa=c;
  float newbint=B_int;
  float newaint=A_int;

  newa+=h*(-Raa*c);
  newaint+=h*(Raa*c-Rab*A_int);
  newbint+=h*(Rab*A_int);

  B_int=newbint;
  A_int=newaint;
  
  return newa;
}

