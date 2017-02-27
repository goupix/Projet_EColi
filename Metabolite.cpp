//==============================
//    INCLUDES
//==============================
#include "Metabolite.h"
#include <iostream>


//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================



//==============================
//    CONSTRUCTORS
//==============================
Metabolite::Metabolite(float A_init, Bacterie* cible){
  A=A_init;
  B=0;
  C=0;
  ptr=cible;

}



//==============================
//    DESTRUCTOR
//==============================
Metabolite::~Metabolite(){}

//==============================
//    PUBLIC METHODS
//==============================
float Metabolite::GetA(){
  return A;
}

float Metabolite::GetB(){
  return B;
}

float Metabolite::GetC(){
  return C;
}

Bacterie* Metabolite::Getptr(){
  return ptr;
}

void Metabolite::SetA(float a){
  A=a;
}

void Metabolite::SetB(float b){
  B=b;
}

void Metabolite::SetC(float c){
  C=c;
}

void Metabolite::Setptr(Bacterie* cible){
  ptr=cible;
}




