#include <iostream>
#include "Map.h"
#include "Bacterie.h"
#include "Lignee_A.h"
#include "Lignee_B.h"
#include "Case.h"
#include <fstream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

// méthodes permettant de tracer le diagramme de phase : etat final en fonction des valeurs de A_init et T


//on utilise la méthode de dichotomie pour trouver, à une valeur de T donnée, le point de transition de phase

float searchExtinction(float T, float a, float b, float e, float D=0.1){

  float borne1=a; //bornes entre lesquelles on recherche la limite d'exctinction (à bien choisir!!)
  float borne2=b;
  float mid; // milieu ds bornes

  while(abs(borne1-borne2)>e){ // condition définissant la précision de la recherche

    

    Map* a=new Map(borne1, T, D); //on créé des Maps aux bornes (A_init correspond aux bornes)
    Map* b=new Map(borne2, T, D);

    char state_A=a->run(); 
    delete(a);

    char state_B=b->run();
    delete(b);

    cout<<"D= "<<D<<" et T= "<<T<<" => "<<"Bornes "<<borne1<<" :"<<state_A<<" "<<borne2<<" :"<<state_B<<endl;


    if((state_A=='E' && state_B=='C') || (state_A=='E' && state_B=='A')){ //teste si la limite se trouve toujours entre les bornes

      mid=(borne1+borne2)/2;

      Map* m=new Map(mid, T, D); //création d'un environnement au "milieu"
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

    else if (state_A=='C' || state_A=='A'){

     
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
float searchExclusion(float T, float a, float b, float e, float D=0.1){

  float borne1=a;
  float borne2=b;
  float mid;

  while(abs(borne1-borne2)>e){

    

    Map* a=new Map(borne1, T, D);
    Map* b=new Map(borne2, T, D);

    char state_A=a->run();
    delete(a);

    char state_B=b->run();
    delete(b);

    cout<<"D= "<<D<<" et T= "<<T<<" => "<<"Bornes "<<borne1<<" :"<<state_A<<" "<<borne2<<" :"<<state_B<<endl;


    if((state_A=='C' && state_B=='A') || (state_A=='E' && state_B=='A')){

      mid=(borne1+borne2)/2;
      Map* m=new Map(mid, T, D);
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
  
  ofstream fichier("data.dat", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
 
    if(fichier){

      //bornes optimisées pour la recherche des limites avec P-mutation=0
      float e(0.001);
      float a1(0); //bornes initiales pour la recherche de la limite d'extinction
      float b1(0.005);

      float a2(0); //bornes initiales pour la recherche de la limite d'exclusion
      float b2(0.01);

      fichier << "#A_init"<<" "<<"Textinction"<<" "<<"Texclusion"<<endl;
      fichier <<1<<" "<<searchExtinction(1, a1, b1, e)<<" "<<searchExclusion(1, a2, b2, e)<<endl;
 

      for(int i=5; i<30; i+=5){//on fait varier la valeur de T
      

        fichier <<i<<" "<<searchExtinction(i, a1, b1, e)<<" "<<searchExclusion(i, a2, b2, e)<<endl;
 
      }

      b2=50;

      for(int i=30; i<=330; i+=100){

        fichier <<i<<" "<<searchExtinction(i, a1, b1, e)<<" "<<searchExclusion(i, a2, b2, e)<<endl;

      }

      b1=1;
      for(int i=430; i<=630; i+=100){

        fichier <<i<<" "<<searchExtinction(i, a1, b1, e)<<" "<<searchExclusion(i, a2, b2, e)<<endl;

      }



      b1=50;
      e=0.1;

      for(int i=730; i<=1530; i+=100){

        fichier <<i<<" "<<searchExtinction(i, a1, b1, e)<<" "<<searchExclusion(i, a2, b2, e)<<endl;

      }


      fichier.close();
    }
    
    else
      cerr << "Impossible d'ouvrir le fichier !" << endl;
 
}



//Trace le diagramme
void plotCurve(){

    FILE * f;
    // Ouverture du shell et lancement de gnuplot
    f = popen("gnuplot", "w");
    // exécution de la commande gnuplot
    fprintf(f, " set title \"Diagramme de phase\"\n ");
    fprintf(f, "set xlabel \"Concentration initiale en glucose\" \n ");
    fprintf(f, "set ylabel \"Intervalle de renouvellement du milieu\" \n ");
    fprintf(f, "set key outside \n");

    fprintf(f, " plot \"data.dat\" using 2:1 with filledcurve x2 lt rgb \"cyan\" title 'exclusion', \"data.dat\" using 3:1 with filledcurve x1 lt rgb \"magenta\" title 'extinction' \n ");
    
    fflush(f);
    // terminer l'envoi de commandes et fermer gnuplot
    sleep(50);
    pclose(f);

}        




//écrit dans un fichier les valeurs de transitions de phases obtenues
void getCurve3D(){
  
  ofstream fichier("data.dat", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
 
    if(fichier){

      //bornes optimisées pour la recherche des limites avec P-mutation=0
      float e(0.001);
      float a1(0); //bornes initiales pour la recherche de la limite d'extinction
      float b1(0.002);

      float a2(0); //bornes initiales pour la recherche de la limite d'exclusion
      float b2(0.002);

      fichier <<"D "<< "#A_init"<<" "<<"Textinction"<<" "<<"Texclusion"<<endl;


      for(int d=0; d<0.1; d+=0.01){
        for(int i=1; i<50; i+=5){//on fait varier la valeur de T
      

          fichier <<d<<" "<<i<<" "<<searchExtinction(i, a1, b1, e, d)<<" "<<searchExclusion(i, a2, b2, e, d)<<endl;
 
        }

        b2=50;

        for(int i=50; i<1500; i+=100){

          fichier <<d<<" "<<i<<" "<<searchExtinction(i, a1, b1, e, d)<<" "<<searchExclusion(i, a2, b2, e, d)<<endl;

        }

        fichier.close();
      }
    }

    else
      cerr << "Impossible d'ouvrir le fichier !" << endl;
 
}



int main(){

srand(time(NULL)); //initiale un générateur de nombre pseudo-aléatoire 


cout<<""<<endl;
cout<<" Running... "<<endl;
cout<<""<<endl;

getCurve();
plotCurve();


  return 0;
}

