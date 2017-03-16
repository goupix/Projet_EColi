#include <iostream>
#include "Map.h"
#include "Bacterie.h"
#include "Lignee_A.h"
#include "Lignee_B.h"
#include "Case.h"
#include <fstream>

using namespace std;

// méthodes permettant de tracer le diagramme de phase : etat final en fonction des valeurs de A_init et T


//on utilise la méthode de dichotomie pour trouver, à une valeur de T donnée, le point de transition de phase

float searchExtinction(float T, float a, float b){

  float borne1=a; //bornes entre lesquelles on recherche la limite d'exctinction (à bien choisir!!)
  float borne2=b;
  float mid; // milieu ds bornes

  while(abs(borne1-borne2)>0.001){ // condition définissant la précision de la recherche

    

    Map* a=new Map(borne1, T); //on créé des Maps aux bornes (A_init correspond aux bornes)
    Map* b=new Map(borne2, T);

    char state_A=a->run(); 
    delete(a);

    char state_B=b->run();
    delete(b);

    cout<<"Bornes "<<borne1<<" :"<<state_A<<" "<<borne2<<" :"<<state_B<<endl;


    if((state_A=='E' && state_B=='C') || (state_A=='E' && state_B=='A')){ //teste si la limite se trouve toujours entre les bornes

      mid=(borne1+borne2)/2;

      Map* m=new Map(mid,T); //création d'un environnement au "milieu"
      char state_M=m->run();

      //on modifie les bornes en fonction de l'état final de la Map "milieu"
      if(state_M=='C' || state_M=='A'){

        borne2=mid;

      }

      else{

        borne1=mid;

      }


    delete(m);
    }

    // prise en compte de la nature stochastique du modèle: si la limite se déplace, on garde la borne la plus proche d'elle
    else if (state_B=='E'){ 

      
      mid=borne2;
      break;
    
    }

    else if (state_A=='C' || state_A='A'){

     
      mid=borne1;
      break;
    }

    else {
      cout<<"Error"<<endl;
      break;
    }

  }

  return mid;
  
}




// même méthode que ci-dessus, adaptée pour la recherche de la limite d'exclusion
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


    if((state_A=='C' && state_B=='A') || (state_A=='E' && state_B=='A')){

      mid=(borne1+borne2)/2;
      Map* m=new Map(mid,T);
      char state_M=m->run();


      if(state_M=='C' || state_M=='E'){

        borne1=mid;

      }

      else{

        borne2=mid;

      }

      
    delete(m);

    }


    else if (state_A=='A'){

    
      mid=borne1;
      break;
    
    }

    else if (state_B=='C' || state_B=='E'){

    
      mid=borne2;
      break;
    }


    else {
      cout<<"Error"<<endl;
      break;
    }

  }

  return mid;
  
}






//écrit dans un fichier les valeurs de transitions de phases obtenues
void getCurve(){
  
  ofstream fichier("data.txt", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
 
    if(fichier){

      float a1(0); //bornes initiales pour la recherche de la limite d'extinction
      float b1(0.01);

      float a2(0); //bornes initiales pour la recherche de la limite d'exclusion
      float b2(50);

      fichier << "A_init"<<" "<<"Textinction"<<" "<<"Texclusion"<<endl;

      for(int i=1; i<1500; i+=100){//on fait varier la valeur de T
      

        fichier <<i<<" "<<searchExtinction(i, a1, b1)<<" "<<searchExclusion(i, a2, b2)<<endl;
 
      }

      fichier.close();
    }
    
    else
      cerr << "Impossible d'ouvrir le fichier !" << endl;
 
}

//Pour tracer les courbes obtenus, on utilisera gnuplot avec les options suivante:         








int main(){

srand(time(NULL)); //initiale un générateur de nombre pseudo-aléatoire 



  cout<<""<<endl;
  cout<<" Running... "<<endl;
  cout<<""<<endl;


  getCurve();


  return 0;
}

