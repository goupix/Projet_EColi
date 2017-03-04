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
float Metabolite::GetA()const{
  return A;
}

float Metabolite::GetB()const {
  return B;
}

float Metabolite::GetC()const {
  return C;
}

Bacterie* Metabolite::Getptr() const{
  return ptr;
}

int Metabolite::Getx()const{
  return x;
}

int Metabolite::Gety()const {
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

void Metabolite::MakeDie(){

  if(ptr->Death()==0){
    
    A+=ptr->GetA_int();
    B+=ptr->GetB_int();
    C+=ptr->GetC_int();

    delete(ptr);
    ptr=nullptr;

    cout<<"RIP"<<" ";
  }
  

}

void Metabolite::MakeMute(){
  

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


void Metabolite::MakeEat(float h){

  if(ptr->Gettype()=='A'){

    A=ptr->Mange(A,h);
  }

  else{

    B=ptr->Mange(B,h);

  }

}


