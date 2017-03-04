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
int Lignee_B::compteur_B = 0; //On initialise notre compteur à 0


//==============================
//    CONSTRUCTORS
//==============================

Lignee_B::Lignee_B(){

  compteur_B++;

  type='B';

  Rbb=0.1;
  Rbc=0.1;

}
Lignee_B::Lignee_B(float a, float b, float c){

  compteur_B++;
  
  type='B';

  A_int=a;
  B_int=b;
  C_int=c;

  Rbb=0.1;
  Rbc=0.1;

}


Lignee_B::Lignee_B(const Lignee_B& b){

  compteur_B++;

  type=b.type;

  A_int=b.A_int;
  B_int=b.B_int;
  C_int=b.C_int;

  Rbb=b.Rbb;
  Rbc=b.Rbc;
}


//==============================
//    DESTRUCTOR
//==============================

Lignee_B::~Lignee_B(){
  compteur_B--;
}
//==============================
//    PUBLIC METHODS
//==============================

Bacterie* Lignee_B::Division(){
	A_int = A_int/2.0;
	B_int = B_int/2.0;
	C_int = C_int/2.0;

	Lignee_B* newcell = new Lignee_B(A_int,B_int,C_int);
	return newcell;
}

void Lignee_B::Describe(){
	cout<< "Cette bactérie de type " <<type<<" présente une concentration interne en A: "<<A_int<<", en B: "<<B_int<<" et en C: "<<C_int<<endl<<" ainsi qu'une fitness de "<<w<<endl;

}

int Lignee_B::Death(){
  float nombre = (rand()%(1000))/1000.0;

  /*srand(time(NULL));
  float nombre = (float)rand() / (float)RAND_MAX;*/
    if(nombre<p_death){
      return 0;
      
        
    }
    
    else{
      return 1;
    }
    }
/*void Lignee_B::Deplacement(){Bacterie::Deplacement();}*/
char Lignee_B::Gettype(){Bacterie::Gettype();}
int Lignee_B::Mute(){Bacterie::Mute();}
float Lignee_B::GetA_int(){return A_int;}
float Lignee_B::GetB_int(){return B_int;}
float Lignee_B::GetC_int(){return C_int;}
float& Lignee_B::Getw(){return w;}

int Lignee_B::nombre_B()
{
    return compteur_B;   //On renvoie simplement la valeur du compteur
}

float Lignee_B::euler(float a, float& aint, float& bint, float h, float p1, float p2){Bacterie::euler(a, aint, bint, h, p1, p2);}

float Lignee_B::Mange(float a, float h){
  return euler(a, B_int, C_int, h, Rbb, Rbc);
  
}