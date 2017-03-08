#include <iostream>
#include "Map.h"
#include "Bacterie.h"
#include "Lignee_A.h"
#include "Lignee_B.h"
#include "Case.h"

using namespace std;

int main(){


/* Test de la classe Map

  cout<<""<<endl;
  cout<<"########## Constructeur par défaut de la classe Map ##########"<<endl;
  cout<<""<<endl;
  Map environnement=Map();


  cout<<""<<endl;
  cout<<"########## Methode set ##########"<<endl;
  cout<<""<<endl;

  environnement.set();
  environnement.DescribeBacteries();

  cout<<""<<endl;
  cout<<"########## compteur##########"<<endl;
  cout<<""<<endl;

  cout<<"Il y a "<<Lignee_A::nombre_A()<<" bactéries de type A, et "<<Lignee_B::nombre_B()<<" bactéries de type B"<<endl;



Test de la classe Case

  cout<<""<<endl;
  cout<<"########## Constructeur par défaut de la classe Case ##########"<<endl;
  cout<<""<<endl;
  Bacterie* t1=new Bacterie;
  Case m1=Case(0, 0, 2.0, t1);
  m1.Describe();
  delete(t1);

Test de la classe Bacterie

  cout<<""<<endl;
  cout<<"########## Constructeur par défaut de la classe Bactérie ##########"<<endl;
  cout<<""<<endl;
  Bacterie t=Bacterie();
  t.Describe();


Test de la classe Lignee_B

  Constructeur 1

  cout<<""<<endl;
  cout<<"########## Bactéries de la lignée B, avec trois constructeurs ##########"<<endl;
  cout<<""<<endl;
  Lignee_B b1=Lignee_B();
  b1.Describe();

  Constructeur 2

  Lignee_B b2= Lignee_B(2.5,2.0,1.1);
  b2.Describe();

  Constructeur par copie

  Lignee_B b3(b2);
  b3.Describe();


Test de la classe Lignee_A

  Constructeur 1

  cout<<""<<endl;
  cout<<"######### Bactéries de la lignée A, avec trois constructeurs ##########"<<endl;
  cout<<""<<endl;
  Lignee_A a1=Lignee_A();
  a1.Describe();

  Constructeur 2

  Lignee_A a2=Lignee_A(5.3,0.1,0.6);
  a2.Describe();

  Constructeur par copie

  Lignee_A a3(a2);
  a3.Describe();

Test de la methode Division

  cout<<""<<endl;
  cout<<"######### Methode division ##########"<<endl;
  cout<<""<<endl;
  Bacterie* a4=a3.Division();
  a3.Describe();
  a4->Describe();
  
  

Test du destructeur de Map
  cout<<""<<endl;
  cout<<"######### Desctructeur ##########"<<endl;
  cout<<""<<endl;
  Map* e1=new Map();
  delete(e1);*/


/*Test du programme en entier*/

  cout<<""<<endl;
  cout<<"########## Methode update et run ##########"<<endl;
  cout<<""<<endl;
  Map* e= new Map();
  e->run();
  delete(e);
  cout<<"Il y a "<<Lignee_A::nombre_A()<<" bactéries de type A, et "<<Lignee_B::nombre_B()<<" bactéries de type B"<<endl;

  
  return 0;
}

