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

float Bacterie::euler(float a, float& aint, float& bint, float h, float p1, float p2){
  float newa=a;
  float newbint=bint;
  float newaint=aint;

  newa+=h*(-p1*a);
  newaint+=h*(p1*a-p2*aint);
  newbint+=h*(p2*aint);

  bint=newbint;
  aint=newaint;
  
  return newa;

}
float Bacterie::Mange(float a, float h){
  
}




      
