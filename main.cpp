#include <iostream>
#include "Map.h"
#include "Bacterie.h"
#include "Lignee_A.h"
#include "Lignee_B.h"
#include "Metabolite.h"

using namespace std;

int main(){
/* Test de la classe Map*/

  Map environnement=Map();
  /*environnement.placeBacteries();
  cout<<"Case 1, A: "<< environnement.GetGrille()[0][0]->GetA() <<endl;*/


/*Test de la classe Metabolite*/
  cout<<""<<endl;
  cout<<"########## Constructeur par défaut de la classe Metabolite ##########"<<endl;
  cout<<""<<endl;
  Bacterie* t1=new Bacterie;
  Metabolite m1=Metabolite(2.0, t1);
  m1.Describe();

/*Test de la classe Bacterie*/
  cout<<""<<endl;
  cout<<"########## Constructeur par défaut de la classe Bactérie ##########"<<endl;
  cout<<""<<endl;
  Bacterie t=Bacterie();
  t.Describe();

/*Test de la classe Lignee_B*/
  /*Constructeur 1*/
  cout<<""<<endl;
  cout<<"########## Bactéries de la lignée B, avec deux constructeurs ##########"<<endl;
  cout<<""<<endl;
  Lignee_B b1=Lignee_B(1,3);
  b1.Describe();
  /*Constructeur 2*/
  Lignee_B b2= Lignee_B(1,3,2.5,2.0,1.1);
  b2.Describe();

/*Test de la classe Lignee_A*/
  /*Constructeur 1*/
  cout<<""<<endl;
  cout<<"######### Bactéries de la lignée A, avec deux constructeurs ##########"<<endl;
  cout<<""<<endl;
  Lignee_A a1=Lignee_A(15,20);
  a1.Describe();
  /*Constructeur 2*/
  Lignee_A a2= Lignee_A(15,20,5.3,0.1,0.6);
  a2.Describe();
  
  Bacterie f=Bacterie();
  f.Death();



  return 0;
}

