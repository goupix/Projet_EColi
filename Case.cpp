//==============================
//    INCLUDES
//==============================
#include "Case.h"
#include <iostream>
using namespace std;

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================



//==============================
//    CONSTRUCTORS
//==============================
Case::Case(int a, int b, float A_init, Bacterie* cible){
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
Case::~Case(){}

//==============================
//    PUBLIC METHODS
//==============================
float Case::GetA()const{
  return A;
}

float Case::GetB()const {
  return B;
}

float Case::GetC()const {
  return C;
}

Bacterie* Case::Getptr() const{
  return ptr;
}

int Case::Getx()const{
  return x;
}

int Case::Gety()const {
  return y;
}

void Case::SetA(float a){
  A=a;
}

void Case::SetB(float b){
  B=b;
}

void Case::SetC(float c){
  C=c;
}

void Case::Setptr(Bacterie* cible){
  ptr=cible;
}



void Case::Describe(){
  cout<<"Cette case contient les concentrations A,B et C suivante: "<<A<<", "<<B<<" et "<<C<<"."<<endl;
  cout<<"Elle contient une bacterie. "<<endl;
  ptr->Describe();
}

void Case::makeDie(){

  if(ptr->Death()==0){
    
    A+=ptr->GetA_int();
    B+=ptr->GetB_int();
    C+=ptr->GetC_int();

    delete(ptr);
    ptr=nullptr;

    cout<<"RIP"<<"";
  }
  

}

void Case::makeMute(){
  

  if(ptr->Mute()==0){
    if(ptr->Gettype()=='A'){

      Lignee_B* newcell=new Lignee_B(ptr->GetA_int(), ptr->GetB_int(), ptr->GetC_int());

      delete(ptr);
      ptr=newcell;

    }

    else{

      Lignee_A* newcell=new Lignee_A(ptr->GetA_int(), ptr->GetB_int(), ptr->GetC_int());
      delete(ptr);
      ptr=newcell;
    }

    cout<<"Mutante"<<" ";
  }

}


void Case::makeEat(float h){

  if(ptr->Gettype()=='A'){

    A=ptr->Mange(A,h);
  }

  else{

    B=ptr->Mange(B,h);

  }

}


