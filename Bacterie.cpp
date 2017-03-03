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
srand(time(0));


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
}

char Bacterie::Gettype(){
  return type;
}

float Bacterie::GetA_int(){}
float Bacterie::GetB_int(){}
float Bacterie::GetC_int(){}

float& Bacterie::Getw(){}

/*void Bacterie::Deplacement(){
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
}*/



int Bacterie::Death(){
  
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

Bacterie* Bacterie::Division(){ ///méthode division

}

void Bacterie::euler(float& a, float& aint, float& bint, float h, float p1, float p2){
  float newa=a;
  float newbint=bint;
  float newaint=aint;

  newa+=h*(-p1*a);
  newaint+=h*(p1*a-p2*aint);
  newbint+=h*(p2*aint);

  a=newa;
  bint=newbint;
  aint=newaint;

}



      
