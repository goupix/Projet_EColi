//==============================
//    INCLUDES
//==============================
#include "Bacterie.h"
#include "Metabolite.h"
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
coord[0]=0; 
coord[1]=0;

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
void Bacterie::Describe(){
	cout<< "Cette bactérie est placée en ("<<coord[0]<<", "<<coord[1]<<" )"<<endl;
	cout<< "Elle présente une concentration interne en A: "<<A_int<<", en B: "<<B_int<<" et en C: "<<C_int<<endl;
}

char Bacterie::Gettype(){
  return type;
}

void Bacterie::Deplacement(){
    int alea=rand()%4+1;
  //std::random_shuffle(depl.begin(), depl.end());
  switch (alea)
  {
      case 1:
        if (coord[0] == 31) {
          coord[0] = 0;
        }
        else {
          coord[0] ++;
        }
          break;

      case 2:
        if (coord[0] == 0) {
          coord[0] = 31;
        }
        else {
          coord[0] --;
        }

        break;

      case 3:
        if (coord[1] == 31) {
          coord[1] = 0;
        }
        else {
          coord[1] ++;
        }
      break;

      case 4:
        if (coord[1] == 0) {
          coord[1] = 31;
        }
        else {
          coord[1] --;
        }
      break;
      
      default :
        break;
  }
}



int Bacterie::Death(){
  srand(time(NULL));
  float nombre = (float)rand() / (float)RAND_MAX;
    if(nombre<p_death){
      return 0;
      cout<<"RIP"<<endl;
        
    }
    
    else{
      return 1;
    }
    
}
      
