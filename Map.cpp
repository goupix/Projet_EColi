//==============================
//    INCLUDES
//==============================
#include "Map.h"
#include <iostream>
#include <string>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector



using namespace std;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
 
#define CLEAR "\033[2J"  // clear screen escape code 



//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================

Map::Map(){

  A_init=10;
  D=0.1;
  T=10000;
  t=10;
  temps=0;
  h=1;

  grille=new Case**[height];

  for(int i=0; i<height; i++){
    grille[i]=new Case*[width];
  }
}


Map::Map(float a, int nb){

  A_init=a;
  D=0.1;
  T=10000;
  t=nb;
  temps=0;
  h=1;

  grille=new Case**[height];

  for(int i=0; i<height; i++){
    grille[i]=new Case*[width];
  }

}




//==============================
//    DESTRUCTOR
//==============================
Map::~Map(){


  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){

      delete(grille[i][j]);

    }
  }

  for(int i=0; i<width; i++){
    delete [] grille[i];
  }

  delete[] grille;

  

}

//==============================
//    PUBLIC METHODS
//==============================




void Map::set(){

  /*Creation d'un vecteur contenant moitié de 0 (correspondant à la lignée A) et moitié de 1 (lignée B) */
  
  vector<int> tableDeNombres;
  for(int i=0; i<(height*width)/2; i++){
    tableDeNombres.push_back(0);
  }
  for(int i=(height*width)/2; i<=height*width; i++){
    tableDeNombres.push_back(1);
  }
  random_shuffle(tableDeNombres.begin(), tableDeNombres.end()); /*Les nombres sont mélangés aléatoirement*/


  /*for (vector<int>::iterator it=tableDeNombres.begin(); it!=tableDeNombres.end(); ++it){
    cout << ' ' << *it;
  }*/

  /* Pour chaque case de l'attribut grille, on crée un métabolite avec une concentration A_init. Chaque métabolite pointe 
  vers une bactérie. Le type des bactéries est choisi suivant le vecteur créé precédement (0=type A, 1=type B)*/
  int compteur=0;
  while(compteur<width*height){
    for(int i=0; i<width; i++){
      for(int j=0; j<height; j++){
        if(tableDeNombres[compteur]==0){
    
          Lignee_A* a= new Lignee_A();
	        grille[i][j]= new Case(i, j, A_init, a); 
          compteur++;
        }

        else{
          
          Lignee_B* b= new Lignee_B();
          grille[i][j]= new Case(i, j, A_init, b);
          compteur++;
        }
        
	    }
    }
  }


}





void Map::diffusion(){



  
  Case grille_init[height][width];

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){

      grille_init[i][j]=Case (*grille[i][j]);

    }
  }




  for(int x=0; x<width; x++){
    for(int y=0; y<height; y++){


      /* Pour la case dont les coordonnées sont données en argument, on cherche les Cases du voisinage de Moore et on 
      les stockent dans un vecteur*/
      int valx=0;
      int valy=0;
      for(int i=-1; i<2;i++){
        for(int j=-1; j<2; j++){

          valx=(x+i)%width;
          valy=(y+j)%height;
        
          if((x+i)%width==-1){
            valx=31;
          }

          if((y+j)%height==-1){
            valy=31;

          }
          
          grille[x][y]->add(D*grille_init[valx][valy].GetA(), D*grille_init[valx][valy].GetB(), D*grille_init[valx][valy].GetC());
         

          
        }
      }
     
      grille[x][y]->add(-9*D*(grille_init[x][y].GetA()), -9*D*(grille_init[x][y].GetB()),-9*D*(grille_init[x][y].GetC()));
    
      
    }

  }


  
}




void Map::DescribeBacteries(){

  for(int i=0; i<width;i++){
    for(int j=0; j<height; j++){
      if(grille[i][j]->Getptr()==nullptr){

        cout<<BOLDBLACK<<'O'<<" "<<RESET;
      }
      else if ((grille[i][j]->Getptr())->Gettype()=='A'){
        cout<<BOLDCYAN<<'O'<<" "<<RESET;
      }

      else {
        cout<<BOLDMAGENTA<<'O'<<" "<<RESET;
      }

    }
    cout<<""<<endl;
  }
  cout<<""<<endl;
}




void Map::DescribeABC(){

  for(int i=0; i<width;i++){
    for(int j=0; j<height; j++){
      cout<<"("<<grille[i][j]->GetA()<<", "<<grille[i][j]->GetB()<<", "<<grille[i][j]->GetC()<<") ";

    }
  cout<<""<<endl;  
  }
  cout<<""<<endl;
}



void Map::DescribeInt(){

  for(int i=0; i<width;i++){
    for(int j=0; j<height; j++){

      if(grille[i][j]->Getptr()!=nullptr){
        cout<<"("<<(grille[i][j]->Getptr())->GetA_int()<<", "<<(grille[i][j]->Getptr())->GetB_int()<<", "<<(grille[i][j]->Getptr())->GetC_int()<<") ";
      }

      else{
        cout<<'0';
      }
    }
    cout<<""<<endl;
    
  }
  cout<<""<<endl;
}


  
void Map::renew(){

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      grille[i][j]->SetA(A_init);
      grille[i][j]->SetB(0.0);
      grille[i][j]->SetC(0.0);
    }
  }
}



Bacterie* Map::competition(int x, int y){
  vector<Case*> voisins;


  /* Pour la case dont les coordonnées sont données en argument, on cherche les Cases du voisinage de Moore et on 
  les stocke dans un vecteur*/
  int valx=0;
  int valy=0;
  for(int i=-1; i<2;i++){
    for(int j=-1; j<2; j++){

      valx=(x+i)%width;
      valy=(y+j)%height;
        
      if((x+i)%width==-1){
        valx=width-1;
      }

      if((y+j)%height==-1){
        valy=height-1;

      }
      

          
      voisins.push_back(grille[valx][valy]);
      
    }
  }


  /*On efface les nullptr des voisins*/
  
  int nb=0;
  for (unsigned int i=0; i<voisins.size(); i++){
    if(voisins[i]->Getptr()==nullptr){
      nb++;
    }
  }

  for (int i=0; i<nb; i++){
    int i_null=0;
    for (unsigned int i=0; i<voisins.size(); i++){
      if(voisins[i]->Getptr()==nullptr){
        i_null=i;
      }
    }
    voisins.erase(voisins.begin()+i_null);
  }



  /*On efface les elements avec une fitness inférieure à W_min*/
  
  int n=0;
  for (unsigned int i=0; i<voisins.size(); i++){
    if((voisins[i]->Getptr())->Getw()<0.001){
      n++;
    }
  }

  for (int i=0; i<n; i++){
    int i_fit=0;
    for (unsigned int i=0; i<voisins.size(); i++){
      if((voisins[i]->Getptr())->Getw()<0.001){
        i_fit=i;
      }
    }
    voisins.erase(voisins.begin()+i_fit);
  }


  if(voisins.size()>0){

    int indice=0; //indice correspondant à la case gagnante parmi les Cases voisines, dans le vecteur voisins
    float wmax=(voisins[0]->Getptr())->Getw();

    for (unsigned int i=0; i<voisins.size(); i++){
    
      if((voisins[i]->Getptr())->Getw()>wmax){// on compare les fitness
        indice=i;
        wmax=(voisins[i]->Getptr())->Getw();
      }
    
    }
     return voisins[indice]->Getptr();
    }

    else{
  
      Bacterie* vide=nullptr;
      return vide;
  }
}






//Méthode qui va actualiser l'expérience 

void Map::update(){

  
  //Diffusion des métabolites.
  diffusion();   //les métabolites diffusent dans la grille
  
  
  //Les bacteries meurent!

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){

      if (grille[i][j]->Getptr()!=nullptr){

        grille[i][j]->makeDie(); //le contenu d'une bactérie qui meurt est déversé dans sa case correspondante

      }
    }
  }
  

  //Les bacteries entrent en compétition!
  
  vector<Case*> gaps;  //on créé un vecteur de pointeurs sur les gaps

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){

      if(grille[i][j]->Getptr()==nullptr){

        gaps.push_back(grille[i][j]);

      }
    }
  }
  
  
  random_shuffle(gaps.begin(), gaps.end()); //on mélange la liste des gaps aléatoirement


  for(unsigned int i=0; i<gaps.size(); i++){
  
    Bacterie* gagnant=competition(gaps[i]->Getx(),gaps[i]->Gety()); //retourne la bactérie de la case avoisinante qui a gagné
    
    if(gagnant!=nullptr){

      Bacterie* newborn=gagnant->Division(); //cette bactérie gagnante va à son tour se diviser 

      grille[gaps[i]->Getx()][gaps[i]->Gety()]->Setptr(newborn);

    }
  }

  
  

  //Les bactéries mutent!

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      if(grille[i][j]->Getptr()!=nullptr){

        grille[i][j]->makeMute(); 
      } 
    }
  }


  

  //Les bactéries se nourrissent!!
  
  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      if(grille[i][j]->Getptr()!=nullptr){

      grille[i][j]->makeEat(h); 

      }
    }
  }




}


char Map::state(int nbA, int nbB){

  if(nbA!=0 && nbB==0){
    
    cout<<"Exclusion"<<endl;
    return 'A';
    
  }

  else if(nbA==0 && nbB==0){

    cout<<"Extinction"<<endl;
    return 'E';
    
  }

  else if(nbA!=0 && nbB!=0){

    cout<<"Cohabitation"<<endl;
    return 'C';


  }

  else{ 

    
    cout<<"Exclusion de la lignée A"<<endl;
    return 'X';

  }

}



char Map::run(){
  int tours=0;
  set();

  while(temps<T){
    while(tours<t){

      update();

      temps+=0.1;
      tours++;
    }
    renew();
    tours=0;
  }
  cout<<" "<<endl;
  DescribeBacteries();
  
  cout<<"Il y a "<<BOLDCYAN<<Lignee_A::nombre_A()<<RESET<<" bactéries de type A, et "<<BOLDMAGENTA<<Lignee_B::nombre_B()<<RESET<<" bactéries de type B"<<endl;
  char s=state(Lignee_A::nombre_A(), Lignee_B::nombre_B());

  return s;

}
