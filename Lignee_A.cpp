//==============================
//    INCLUDES
//==============================
#include "Lignee_A.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;


//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================
int Lignee_A::compteur_A = 0; //On initialise notre compteur à 0


//==============================
//    CONSTRUCTORS
//==============================

Lignee_A::Lignee_A(){
  
  compteur_A++;

  type='A';

  Raa=0.1;
  Rab=0.1;

}

Lignee_A::Lignee_A( float a, float b, float c){

  compteur_A++;
  
  type='A';

  A_int=a;
  B_int=b;
  C_int=c;

  Raa=0.1;
  Rab=0.1;

}

Lignee_A::Lignee_A(const Lignee_A& a){

  compteur_A++;

  type=a.type;

  A_int=a.A_int;
  B_int=a.B_int;
  C_int=a.C_int;

  Raa=a.Raa;
  Rab=a.Rab;
}




//==============================
//    DESTRUCTOR
//==============================

Lignee_A::~Lignee_A(){
  compteur_A--;
}
//==============================
//    PUBLIC METHODS
//==============================

void Lignee_A::Describe(){
	cout<< "Cette bactérie de type "<<type<<" présente une concentration interne en A: "<<A_int<<", en B: "<<B_int<<" et en C: "<<C_int<<endl<<" ainsi qu'une fitness de "<<w<<endl;
}

Bacterie* Lignee_A::Division(){
	A_int = A_int/2.0;
	B_int = B_int/2.0;
	C_int = C_int/2.0;
  
	Lignee_A* newcell = new Lignee_A(A_int,B_int,C_int);
	return newcell;
}



int Lignee_A::Death(){
  float nombre =  (rand()%(1000))/1000.0;
  /*srand(time(NULL));
  float nombre = (float)rand() / (float)RAND_MAX;*/
  
    if(nombre<p_death){
      return 0;
      
        
    }
    
    else{
      return 1;
    }
    
}
/*void Lignee_A::Deplacement(){Bacterie::Deplacement();}*/
char Lignee_A::Gettype(){Bacterie::Gettype();}
int Lignee_A::Mute(){Bacterie::Mute();}
float Lignee_A::GetA_int(){return A_int;}
float Lignee_A::GetB_int(){return B_int;}
float Lignee_A::GetC_int(){return C_int;}
float& Lignee_A::Getw(){return w;}

int Lignee_A::nombre_A()
{
    return compteur_A;   //On renvoie simplement la valeur du compteur
}


void Lignee_A::euler(float& a, float& aint, float& bint, float h, float p1, float p2){Bacterie::euler(a, aint, bint, h, p1, p2);}
