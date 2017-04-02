#include <iostream>
#include "Map.h"
#include "Bacterie.h"
#include "Lignee_L.h"
#include "Lignee_S.h"
#include "Case.h"
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <string>

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

    char state_L=a->run(); 
    delete(a);

    char state_S=b->run();
    delete(b);

    cout<<"D= "<<D<<" et T= "<<T<<" => "<<"Bornes "<<borne1<<" :"<<state_L<<" "<<borne2<<" :"<<state_S<<endl;


    if((state_L=='E' && state_S=='C') || (state_L=='E' && state_S=='A')){ //teste si la limite se trouve toujours entre les bornes

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
    else if (state_S=='E'){ 

      
      mid=borne2;
      break;
    
    }

    else if (state_L=='C' || state_L=='A'){

     
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

    char state_L=a->run();
    delete(a);

    char state_S=b->run();
    delete(b);

    cout<<"D= "<<D<<" et T= "<<T<<" => "<<"Bornes "<<borne1<<" :"<<state_L<<" "<<borne2<<" :"<<state_S<<endl;


    if((state_L=='C' && state_S=='A') || (state_L=='E' && state_S=='A')){

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


    else if (state_L=='L'){

    
      mid=borne1;
      break;
    
    }

    else if (state_S=='C' || state_S=='E'){

    
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
void getCurve_no_mutation(){
  
  ofstream fichier("diagramme_no_mutation.dat", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
 
    if(fichier){

      //bornes optimisées pour la recherche des limites avec P-mutation=0, afin d'optimiser le programme tout en augmentant la précision au niveau des "virages" des courbes
      float e(0.001);
      float a1(0); //bornes initiales pour la recherche de la limite d'extinction
      float b1(0.003);

      float a2(0); //bornes initiales pour la recherche de la limite d'exclusion
      float b2(0.003);

      fichier << "#A_init"<<" "<<"Textinction"<<" "<<"Texclusion"<<endl;
      fichier <<1<<" "<<searchExtinction(1, a1, b1, e)<<" "<<searchExclusion(1, a2, b2, e)<<endl;
 

      for(int i=5; i<=30; i+=5){//on fait varier la valeur de T
      

        fichier <<i<<" "<<searchExtinction(i, a1, b1, e)<<" "<<searchExclusion(i, a2, b2, e)<<endl;
 
      }

      b2=50;
   
      fichier <<60<<" "<<searchExtinction(60, a1, b1, e)<<" "<<searchExclusion(60, a2, b2, e)<<endl;
 
      for(int i=130; i<=330; i+=100){

        fichier <<i<<" "<<searchExtinction(i, a1, b1, e)<<" "<<searchExclusion(i, a2, b2, e)<<endl;

      }



      b1=50;
      e=0.1;
      

      for(int i=430; i<=1530; i+=100){

        fichier <<i<<" "<<searchExtinction(i, a1, b1, e)<<" "<<searchExclusion(i, a2, b2, e)<<endl;

      }


      fichier.close();
    }
    
    else
      cerr << "Impossible d'ouvrir le fichier !" << endl;
 
}







//écrit dans un fichier les valeurs de transitions de phases obtenues
void getCurve_with_mutation(){
  
  ofstream fichier("diagramme_mutation.dat", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
 
    if(fichier){

      //bornes optimisées pour la recherche des limites avec P-mutation=0.001
      float e(0.001);
      float a1(0); //bornes initiales pour la recherche de la limite d'extinction
      float b1(0.003);

      float a2(0); //bornes initiales pour la recherche de la limite d'exclusion
      float b2(50);

      fichier << "#A_init"<<" "<<"Textinction"<<" "<<"Texclusion"<<endl;
      fichier <<1<<" "<<searchExtinction(1, a1, b1, e)<<" "<<searchExclusion(1, a2, b2, e)<<endl;
      
   
      for(int i=100; i<=300; i+=100){//on fait varier la valeur de T
      

        fichier <<i<<" "<<searchExtinction(i, a1, b1, e)<<" "<<searchExclusion(i, a2, b2, e)<<endl;
 
      }
      
      b1=50;
      e=0.1;
       
      fichier <<350<<" "<<searchExtinction(350, a1, b1, e)<<" "<<searchExclusion(350, a2, b2, e)<<endl;
     
      for(int i=400; i<=1500; i+=100){

        fichier <<i<<" "<<searchExtinction(i, a1, b1, e)<<" "<<searchExclusion(i, a2, b2, e)<<endl;

      }

      

      fichier.close();
    }
    
    else
      cerr << "Impossible d'ouvrir le fichier !" << endl;
 
}







//écrit dans un fichier les valeurs de transitions de phases obtenues
void getCurve3D(){
  
  ofstream fichier("graphique3D.dat", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
 
    if(fichier){

      //bornes optimisées pour la recherche des limites avec P-mutation=0
      float e(0.01);
      float a1(0); //bornes initiales pour la recherche de la limite d'extinction
      float b1(50);

      float a2(0); //bornes initiales pour la recherche de la limite d'exclusion
      float b2(50);

      fichier <<"#D "<< "A_init"<<" "<<"Textinction"<<" "<<"Texclusion"<<endl;
      

      for(float d=0; d<=0.1; d+=0.01){
        
        fichier <<d<<" "<<1<<" "<<searchExtinction(1, a1, b1, e, d)<<" "<<searchExclusion(1, a2, b2, e, d)<<endl;

        for(int i=100; i<=1500; i+=100){//on fait varier la valeur de T

          fichier <<d<<" "<<i<<" "<<searchExtinction(i, a1, b1, e, d)<<" "<<searchExclusion(i, a2, b2, e, d)<<endl;
 
        }
      }

      fichier.close();
    }

    else
      cerr << "Impossible d'ouvrir le fichier !" << endl;
 
}





//Trace le diagramme
void plotGraphs(){

    FILE * f;
    // Ouverture du shell et lancement de gnuplot
    f = popen("gnuplot", "w");
    // exécution de la commande gnuplot
     fprintf(f, "set multiplot \n");
    fprintf(f, "set size 0.55,0.5 \n");
    fprintf(f, "set origin 0,0.5 \n");
    fprintf(f, " set title \"Diagramme de phase, avec p_mutation=0\"\n ");
    fprintf(f, "set xlabel \"Concentration initiale en glucose\" \n ");
    fprintf(f, "set ylabel \"Intervalle de renouvellement du milieu\" \n ");
    fprintf(f, "set xrange [0:50] \n");
    fprintf(f, "set yrange [0:1500] \n");
    fprintf(f, "set key rmargin \n");
    fprintf(f, " plot \"diagramme_no_mutation.dat\" using 2:1 with filledcurve x2 lt rgb \"cyan\" title 'extinction', \"diagramme_no_mutation.dat\" using 3:1 with filledcurve x1 lt rgb \"magenta\" title 'exclusion' \n ");
    
    fprintf(f, "set size 0.55,0.5 \n");
    fprintf(f, "set origin 0,0 \n");


    fprintf(f, " set title \"Diagramme de phase, avec p_mutation=0.001\"\n ");
    fprintf(f, " plot \"diagramme_mutation.dat\" using 2:1 with filledcurve x2 lt rgb \"cyan\" title 'extinction', \"diagramme_mutation.dat\" using 3:1 with filledcurve x1 lt rgb \"magenta\" title 'exclusion' \n ");
    
    fprintf(f, "set size 0.7,0.7 \n");
    fprintf(f, "set origin 0.5,0.2 \n");

    fprintf(f, " set title \"Diagramme de phase 3D\"\n ");
    fprintf(f,"set ticslevel 0\n");
    fprintf(f, "set view 60,160 \n");
    fprintf(f, "set xlabel \"Concentration initiale en glucose\"\n ");
    fprintf(f, "set ylabel \"D\"\n ");
    fprintf(f, "set zlabel \"Intervalle de renouvellement du milieu\" rotate parallel\n ");
    fprintf(f, "set xrange [0:50] \n");
    fprintf(f, "set yrange [0:0.1] \n");
    fprintf(f, "set zrange [0:1500] \n");
    fprintf(f, "set hidden3d \n");
    
    

    fprintf(f,"splot \"graphique3D.dat\" u 3:1:2 with lines title 'extinction', \"graphique3D.dat\" u 4:1:2 with lines title 'exclusion'\n ");

    fflush(f);
    // terminer l'envoi de commandes et fermer gnuplot
    sleep(5000);
    pclose(f);

}  





int main(){

  srand(time(NULL)); //initialise un générateur de nombre pseudo-aléatoire 


  cout<<""<<endl;
  cout<<" Running... "<<endl;
  cout<<""<<endl;

  plotGraphs();


  return 0;
}

