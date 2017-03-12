#include <iostream>
#include "Map.h"
#include "Bacterie.h"
#include "Lignee_A.h"
#include "Lignee_B.h"
#include "Case.h"
#include <fstream>

using namespace std;


//on utilise la méthode de dichotomie pour trouver, à une valeur de T donnée, le point de transition de phase

float searchExtinction(float T, float a, float b){

  float borne1=a;
  float borne2=b;
  float mid;

  while(abs(borne1-borne2)>0.1){

    

    Map* a=new Map(borne1, T);
    Map* b=new Map(borne2, T);

    char state_A=a->run();
    delete(a);

    char state_B=b->run();
    delete(b);

    cout<<"Bornes "<<borne1<<" :"<<state_A<<" "<<borne2<<" :"<<state_B<<endl;


    if(state_A=='E' && state_B=='C'){

      mid=(borne1+borne2)/2;
      Map* m=new Map(mid,T);
      char state_M=m->run();


      if(state_M==state_A){

        borne1=mid;

      }

      else if(state_M==state_B){

        borne2=mid;

      }

      else{

        cout<<"jonction"<<endl;
      }

    delete(m);
    }

    else{

      cout<<"Erreur, changez les bornes svp."<<endl;
      mid=(borne1+borne2)/2;
      break;
    
    }

  }

  return mid;
  
}





float searchExclusion(float T, float a, float b){

  float borne1=a;
  float borne2=b;
  float mid;

  while(abs(borne1-borne2)>0.1){

    

    Map* a=new Map(borne1, T);
    Map* b=new Map(borne2, T);

    char state_A=a->run();
    delete(a);

    char state_B=b->run();
    delete(b);

    cout<<"Bornes "<<borne1<<" :"<<state_A<<" "<<borne2<<" :"<<state_B<<endl;


    if(state_A=='C' && state_B=='A'){

      mid=(borne1+borne2)/2;
      Map* m=new Map(mid,T);
      char state_M=m->run();


      if(state_M==state_A){

        borne1=mid;

      }

      else if(state_M==state_B){

        borne2=mid;

      }

      else{

        cout<<"jonction"<<endl;
      }

    delete(m);
    }

    else{

      cout<<"Erreur, changez les bornes svp."<<endl;
      mid=(borne1+borne2)/2;
      break;
    
    }

  }

  return mid;
  
}






//écrit dans un fichier les valeurs de transitions de phases obtenues
void getCurve(){
  
  ofstream fichier("data.txt", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
 
    if(fichier){

      float a1(0);
      float b1(1);
      float a2(5);
      float b2(50);

      for(int i=1; i<1500; i++){
      
        fichier << "A_init"<<" "<<"Textinction"<<" "<<"Texclusion";
        fichier <<i<<" "<<searchExtinction(i, a1, b1)<<" "<<searchExclusion(i, a2, b2);
 
        fichier.close();
      }
    }
    
    else
      cerr << "Impossible d'ouvrir le fichier !" << endl;
 
}

//Pour tracer les courbes obtenus, on utilisera gnuplot avec les options suivante:         








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
  cout<<"####################### Running... #######################"<<endl;
  cout<<""<<endl;

 /*Map* e= new Map(0,2);
  e->run();
  delete(e);*/

  
  cout<<searchExtinction(1, 0, 2)<<endl;
  /*cout<<searchExclusion(1, 5, 50);*/
  return 0;
}

