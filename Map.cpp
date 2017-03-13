//==============================
//    INCLUDES
//==============================
#include "Map.h"
#include <iostream>
#include <string>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector

using namespace std;

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

  Grille=new Case**[height];

  for(int i=0; i<height; i++){
    Grille[i]=new Case*[width];
  }
}


Map::Map(float a, int nb){

  A_init=a;
  D=0.1;
  T=10000;
  t=nb;
  temps=0;
  h=1;

  Grille=new Case**[height];

  for(int i=0; i<height; i++){
    Grille[i]=new Case*[width];
  }
}




//==============================
//    DESTRUCTOR
//==============================
Map::~Map(){


  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){

      delete(Grille[i][j]);

    }
  }

  for(int i=0; i<width; i++){
    delete [] Grille[i];
  }

  delete[] Grille;

  

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

  /* Pour chaque case de l'attribut Grille, on crée un métabolite avec une concentration A_init. Chaque métabolite pointe 
  vers une bactérie. Le type des bactéries est choisi suivant le vecteur créé precédement (0=type A, 1=type B)*/
  int compteur=0;
  while(compteur<width*height){
    for(int i=0; i<width; i++){
      for(int j=0; j<height; j++){
        if(tableDeNombres[compteur]==0){
    
          Lignee_A* a= new Lignee_A();
	        Grille[i][j]= new Case(i, j, A_init, a); 
          compteur++;
        }

        else{
          
          Lignee_B* b= new Lignee_B();
          Grille[i][j]= new Case(i, j, A_init, b);
          compteur++;
        }
        
	    }
    }
  }
}





void Map::diffusion(Case*& m){


  float newA;// variables de stockage des nouvelles valeurs des concentrations en métabolites
  float newB;
  float newC;


  newA=m->GetA();//initialisation des variables
  newB=m->GetB();
  newC=m->GetC();

  int x=m->Getx();
  int y=m->Gety();

  vector<Case*> voisins;


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
      

          
      voisins.push_back(Grille[valx][valy]);
      
    }
  }


  

  /*execution de l'algorithme de diffusion*/
  for(int i=0; i<9; i++){
      newA+=D*(voisins[i]->GetA());
      newB+=D*(voisins[i]->GetB());
      newC+=D*(voisins[i]->GetC());
      
    }



  newA+=(-9*D*(Grille[x][y]->GetA()));
  newB+=(-9*D*(Grille[x][y]->GetB()));
  newC+=(-9*D*(Grille[x][y]->GetC()));

  m->SetA(newA);
  m->SetB(newB);
  m->SetC(newC);
  
}




void Map::DescribeBacteries(){

  for(int i=0; i<width;i++){
    for(int j=0; j<height; j++){
      if(Grille[i][j]->Getptr()==nullptr){
        cout<<'O'<<" ";
      }
      else{
        cout<<(Grille[i][j]->Getptr())->Gettype()<<" ";
      }

    }
    cout<<""<<endl;
  }
  cout<<""<<endl;
}




void Map::DescribeABC(){

  for(int i=0; i<width;i++){
    for(int j=0; j<height; j++){
      cout<<"("<<Grille[i][j]->GetA()<<", "<<Grille[i][j]->GetB()<<", "<<Grille[i][j]->GetC()<<") ";

    }
  cout<<""<<endl;  
  }
  cout<<""<<endl;
}



void Map::DescribeInt(){

  for(int i=0; i<width;i++){
    for(int j=0; j<height; j++){
      cout<<"("<<(Grille[i][j]->Getptr())->GetA_int()<<", "<<(Grille[i][j]->Getptr())->GetB_int()<<", "<<(Grille[i][j]->Getptr())->GetC_int()<<") ";

    }
    cout<<""<<endl;
    
  }
  cout<<""<<endl;
}


  
void Map::renew(){

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      Grille[i][j]->SetA(A_init);
      Grille[i][j]->SetB(0.0);
      Grille[i][j]->SetC(0.0);
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
      

          
      voisins.push_back(Grille[valx][valy]);
      
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

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){

        diffusion(Grille[i][j]);   //les métabolites diffusent dans la grille

      
    }

  }

  

  //Les bacteries meurent!

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){

      if (Grille[i][j]->Getptr()!=nullptr){

        Grille[i][j]->makeDie(); //le contenu d'une bactérie qui meurt est déversé dans sa case correspondante

      }
    }
  }
  

  //Les bacteries entrent en compétition!
  
  vector<Case*> gaps;  //on créé un vecteur de pointeurs sur les gaps

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){

      if(Grille[i][j]->Getptr()==nullptr){

        gaps.push_back(Grille[i][j]);

      }
    }
  }
  
  
  random_shuffle(gaps.begin(), gaps.end()); //on mélange la liste des gaps aléatoirement


  for(unsigned int i=0; i<gaps.size(); i++){
  
    Bacterie* gagnant=competition(gaps[i]->Getx(),gaps[i]->Gety()); //retourne la bactérie de la case avoisinante qui a gagné
    
    if(gagnant!=nullptr){

      Bacterie* newborn=gagnant->Division(); //cette bactérie gagnante va à son tour se diviser 

      Grille[gaps[i]->Getx()][gaps[i]->Gety()]->Setptr(newborn);

    }
  }

  
  

  //Les bactéries mutent!

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      if(Grille[i][j]->Getptr()!=nullptr){

        Grille[i][j]->makeMute(); 
      } 
    }
  }


  

  //Les bactéries se nourrissent!!
  
  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      if(Grille[i][j]->Getptr()!=nullptr){

      Grille[i][j]->makeEat(h); 

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

  cout<<"Il y a "<<Lignee_A::nombre_A()<<" bactéries de type A, et "<<Lignee_B::nombre_B()<<" bactéries de type B"<<endl;
  char s=state(Lignee_A::nombre_A(), Lignee_B::nombre_B());

  return s;

}
