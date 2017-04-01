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


p_death=0.02; 
p_mutation=0.00; 
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
  
    if(nombre<p_death){ //et ce nombre est comparé à la probabilité de mort que nous avons déclaré

      return 0; 
      
    }
    
    else{

      return 1;

    }
  
}



int Bacterie::Mute(){


  float nombre =  (rand()%(1000))/1000.0; //idem

  if (nombre<p_mutation){ //et on compare ce nombre à la probabilité de mutation que nous avons déclaré

    return 0;
  }

  else{

    return 1;
  }

}









      
