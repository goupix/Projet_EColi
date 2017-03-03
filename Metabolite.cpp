//==============================
//    INCLUDES
//==============================
#include "Metabolite.h"
#include <iostream>
using namespace std;

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================



//==============================
//    CONSTRUCTORS
//==============================
Metabolite::Metabolite(int a, int b, float A_init, Bacterie* cible){
  x=a;
  y=b;
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

int Metabolite::Getx(){
  return x;
}

int Metabolite::Gety(){
  return y;
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



void Metabolite::Describe(){
  cout<<"Cette case contient les concentrations A,B et C suivante: "<<A<<", "<<B<<" et "<<C<<"."<<endl;
  cout<<"Elle contient une bacterie. "<<endl;
  ptr->Describe();
}




