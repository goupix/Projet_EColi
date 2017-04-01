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

Case::Case(const Case& c){
  x=c.x;
  y=c.y;
  A=c.A;
  B=c.B;
  C=c.C;
  ptr=nullptr;

}


//==============================
//    DESTRUCTOR
//==============================
Case::~Case(){

  delete(ptr);
  
}

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

  }
  

}

void Case::makeMute(){
  

  if(ptr->Mute()==0){
    if(ptr->Gettype()=='L'){

      Lignee_S* newcell=new Lignee_S(ptr->GetA_int(), ptr->GetB_int(), ptr->GetC_int());

      delete(ptr);
      ptr=newcell;

    }

    else{

      Lignee_L* newcell=new Lignee_L(ptr->GetA_int(), ptr->GetB_int(), ptr->GetC_int());
      delete(ptr);
      ptr=newcell;
    }


  }

}


void Case::makeEat(float h){

  if(ptr->Gettype()=='L'){

    A=ptr->absorb(A,h);
  }

  else{

    B=ptr->absorb(B,h);

  }

}

void Case::add(float a, float b, float c){

  A+=a;
  B+=b;
  C+=c;
 
}

