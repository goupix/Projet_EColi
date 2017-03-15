//==============================
//    INCLUDES
//==============================
#include "Bacterie.h"
#include "Case.h"
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
srand(time(NULL)); //initiale un générateur de nombre pseudo-aléatoire 

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

char Bacterie::Gettype(){
  return type;
}



int Bacterie::Death(){
  
  float nombre =  (rand()%(1000))/1000.0;  //tire un nombre pseudo-aléatoire entier positif entre 0 et 1
  
    if(nombre<p_death){

      return 0;
      
    }
    
    else{

      return 1;

    }
  
}



int Bacterie::Mute(){


  float nombre =  (rand()%(1000))/1000.0;

  if (nombre<p_mutation){

    return 0;
  }

  else{

    return 1;
  }

}









      
