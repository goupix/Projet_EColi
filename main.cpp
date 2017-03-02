#include <iostream>
#include "Map.h"
#include "Bacterie.h"
#include "Lignee_A.h"
#include "Lignee_B.h"
#include "Metabolite.h"

using namespace std;

int main(){
/* Test de la classe Map*/
  cout<<""<<endl;
  cout<<"########## Constructeur par défaut de la classe Map ##########"<<endl;
  cout<<""<<endl;
  Map environnement=Map();

  cout<<""<<endl;
  cout<<"########## Methode placeBacteries ##########"<<endl;
  cout<<""<<endl;
  environnement.placeBacteries();
  cout<<"Case 1 contient un concentration en A de: "<< environnement.GetGrille()[0][0]->GetA() <<endl;
  cout<<"Case 1 contient une bactérie"<<endl;
  (environnement.GetGrille()[0][0]->Getptr())->Describe();

  cout<<""<<endl;
  cout<<"########## Methodes Describe ##########"<<endl;
  cout<<""<<endl;
  environnement.DescribeBacteries();
  cout<<""<<endl;
  environnement.DescribeABC();

  cout<<""<<endl;
  cout<<"########## Methode bougeMetabo ##########"<<endl;
  cout<<""<<endl;
  (environnement.GetGrille()[5][6])->SetA(2);
  environnement.bougeMetabo(5,6);
  (environnement.GetGrille()[5][6])->SetA(10);

  (environnement.GetGrille()[5][31])->SetA(2);
  environnement.bougeMetabo(5,31);
  (environnement.GetGrille()[5][31])->SetA(10);

  (environnement.GetGrille()[31][7])->SetA(2);
  environnement.bougeMetabo(31,7);
  (environnement.GetGrille()[31][7])->SetA(10);

  (environnement.GetGrille()[0][31])->SetA(2);
  environnement.bougeMetabo(0,31);
  (environnement.GetGrille()[0][31])->SetA(10);

  (environnement.GetGrille()[31][31])->SetA(2);
  environnement.bougeMetabo(31,31);
  (environnement.GetGrille()[31][31])->SetA(10);
  
  cout<<""<<endl;
  cout<<"########## Methode update ##########"<<endl;
  cout<<""<<endl;
  environnement.update();
  environnement.DescribeBacteries();
  


/*Test de la classe Metabolite*/
  cout<<""<<endl;
  cout<<"########## Constructeur par défaut de la classe Metabolite ##########"<<endl;
  cout<<""<<endl;
  Bacterie* t1=new Bacterie;
  Metabolite m1=Metabolite(2.0, t1);
  m1.Describe();
  delete(t1);

/*Test de la classe Bacterie*/
  cout<<""<<endl;
  cout<<"########## Constructeur par défaut de la classe Bactérie ##########"<<endl;
  cout<<""<<endl;
  Bacterie t=Bacterie();
  t.Describe();
/*Test de la méthode Déplacement
  cout<<""<<endl;
  cout<<"########## Méthode déplacement de la classe Bactérie ##########"<<endl;
  cout<<""<<endl;
  t.Deplacement();
  t.Describe();
  t.Deplacement();
  t.Describe();*/

/*Test de la classe Lignee_B*/
  /*Constructeur 1*/
  cout<<""<<endl;
  cout<<"########## Bactéries de la lignée B, avec trois constructeurs ##########"<<endl;
  cout<<""<<endl;
  Lignee_B b1=Lignee_B(1,3);
  b1.Describe();
  /*Constructeur 2*/
  Lignee_B b2= Lignee_B(1,3,2.5,2.0,1.1);
  b2.Describe();
  /*Constructeur par copie*/
  Lignee_B b3(b2);
  b3.Describe();


/*Test de la classe Lignee_A*/
  /*Constructeur 1*/
  cout<<""<<endl;
  cout<<"######### Bactéries de la lignée A, avec trois constructeurs ##########"<<endl;
  cout<<""<<endl;
  Lignee_A a1=Lignee_A(15,20);
  a1.Describe();
  /*Constructeur 2*/
  Lignee_A a2=Lignee_A(15,20,5.3,0.1,0.6);
  a2.Describe();
  /*Constructeur par copie*/
  Lignee_A a3(a2);
  a3.Describe();

/*Test de la methode Division*/
  cout<<""<<endl;
  cout<<"######### Methode division ##########"<<endl;
  cout<<""<<endl;
  Bacterie* a4=a3.Division();
  a3.Describe();
  a4->Describe();
  
  


  return 0;
}

