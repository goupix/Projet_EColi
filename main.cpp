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

  while(abs(borne1-borne2)>0.001){

    

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
        break;
      }

    delete(m);
    }

    else if (state_A=='E' && state_B=='E'){

      
      mid=borne2;
      break;
    
    }

    else if (state_A=='C' && state_B=='C'){

     
      mid=borne1;
      break;
    }

    else {
      cout<<"jonction"<<endl;
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

        cout<<"Jonction!!!!!"<<endl;
        break;
      }

    delete(m);

    }

    else if (state_A=='A' && state_B=='A'){

    
      mid=borne1;
      break;
    
    }

    else if (state_A=='C' && state_B=='C'){

    
      mid=borne2;
      break;
    }


    else {
      cout<<"Jonction!!!!"<<endl;
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
      float b1(0.01);
      float a2(0.2);
      float b2(50);

      fichier << "A_init"<<" "<<"Textinction"<<" "<<"Texclusion"<<endl;

      for(int i=1; i<1500; i+=100){
      

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




/*Test du programme en entier*/

  cout<<""<<endl;
  cout<<"####################### Running... #######################"<<endl;
  cout<<""<<endl;


  getCurve();


  return 0;
}

