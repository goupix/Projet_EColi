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
  t=200;
  temps=0;
  h=1;
  Grille=new Metabolite**[height];
  for(int i=0; i<height; i++){
    Grille[i]=new Metabolite*[width];
  }
}

//==============================
//    DESTRUCTOR
//==============================
Map::~Map(){

  delete [] Grille;
}

//==============================
//    PUBLIC METHODS
//==============================
Metabolite*** Map::GetGrille(){

  return Grille;
}

void Map::placeBacteries(){
  
  vector<int> tableDeNombres;
  for(int i=0; i<(height*width)/2; i++){
    tableDeNombres.push_back(0);
  }
  for(int i=(height*width)/2; i<=height*width; i++){
    tableDeNombres.push_back(1);
  }
  random_shuffle(tableDeNombres.begin(), tableDeNombres.end());
  vector<Bacterie*> tableDeBacteries;

  /*for (vector<int>::iterator it=tableDeNombres.begin(); it!=tableDeNombres.end(); ++it){
    cout << ' ' << *it;
  }*/

  int compteur=0;
  while(compteur<width*height){
    for(int i=0; i<width; i++){
      for(int j=0; j<height; j++){
        if(tableDeNombres[compteur]==0){
    
          Lignee_A* a= new Lignee_A();
	        Grille[i][j]= new Metabolite(i, j, A_init, a); 
          compteur++;
        }

        else{
          
          Lignee_B* b= new Lignee_B();
          Grille[i][j]= new Metabolite(i, j, A_init, b);
          compteur++;
        }
        
	    }
    }
  }
}

void Map::bougeMetabo(int x, int y){
  float newA;
  float newB;
  float newC;

  newA=Grille[x][y]->GetA();
  newB=Grille[x][y]->GetB();
  newC=Grille[x][y]->GetC();

  vector<Metabolite*> voisins;


  
  if(x!=0 && x!=31 && y!=0 && y!=31){

    for(int i=-1; i<2;i++){
      for(int j=-1; j<2; j++){
        voisins.push_back(Grille[x+i][y+j]);
      
      }
    }
  }
  

  else if(x==0 && y!=0 && y!=31){
    for(int i=0; i<2;i++){
      for(int j=-1; j<2; j++){
        voisins.push_back(Grille[x+i][y+j]);
      
      }
    }
    voisins.push_back(Grille[31][y-1]);
    voisins.push_back(Grille[31][y]);
    voisins.push_back(Grille[31][y+1]);

  }

  else if(x==31 && y!=0 && y!=31){
    for(int i=-1; i<1;i++){
      for(int j=-1; j<2; j++){
        voisins.push_back(Grille[x+i][y+j]);
      
      }
    }
    voisins.push_back(Grille[0][y-1]);
    voisins.push_back(Grille[0][y]);
    voisins.push_back(Grille[0][y+1]);
    
  }

  else if(y==0 && x!=0 && x!=31){
    for(int i=-1; i<2;i++){
      for(int j=0; j<2; j++){
        voisins.push_back(Grille[x+i][y+j]);
      
      }
    }
    voisins.push_back(Grille[x-1][31]);
    voisins.push_back(Grille[x][31]);
    voisins.push_back(Grille[x+1][31]);
  }

  else if(y==31 && x!=0 && x!=31){
    for(int i=-1; i<2;i++){
      for(int j=-1; j<1; j++){
        voisins.push_back(Grille[x+i][y+j]);
      }
    }
    voisins.push_back(Grille[x-1][0]);
    voisins.push_back(Grille[x][0]);
    voisins.push_back(Grille[x+1][0]);  
  }

  else if(y==0 && x==0){

    voisins.push_back(Grille[x][y]);
    voisins.push_back(Grille[x+1][y]);
    voisins.push_back(Grille[x][y+1]); 
    voisins.push_back(Grille[x+1][y+1]);

    voisins.push_back(Grille[x][31]);
    voisins.push_back(Grille[x+1][31]); 
    voisins.push_back(Grille[31][y]);
    voisins.push_back(Grille[31][y+1]);

    voisins.push_back(Grille[31][31]); 
  }

  else if(y==31 && x==31){

    voisins.push_back(Grille[x][y]);
    voisins.push_back(Grille[x][y-1]);
    voisins.push_back(Grille[x-1][y-1]); 
    voisins.push_back(Grille[x-1][y]);

    voisins.push_back(Grille[x][0]);
    voisins.push_back(Grille[x-1][0]); 
    voisins.push_back(Grille[0][y-1]);
    voisins.push_back(Grille[0][y]);

    voisins.push_back(Grille[0][0]);  

  }

  else if(y==31 && x==0){

    voisins.push_back(Grille[x][y]);
    voisins.push_back(Grille[x][y-1]);
    voisins.push_back(Grille[x+1][y-1]); 
    voisins.push_back(Grille[x+1][y]);

    voisins.push_back(Grille[x][0]);
    voisins.push_back(Grille[x+1][0]); 
    voisins.push_back(Grille[31][y-1]);
    voisins.push_back(Grille[31][y]);

    voisins.push_back(Grille[31][0]); 

  }

  else if(y==0 && x==31){

    voisins.push_back(Grille[x][y]);
    voisins.push_back(Grille[x][y+1]);
    voisins.push_back(Grille[x-1][y+1]); 
    voisins.push_back(Grille[x-1][y]);

    voisins.push_back(Grille[x][31]);
    voisins.push_back(Grille[x-1][31]); 
    voisins.push_back(Grille[0][y+1]);
    voisins.push_back(Grille[0][y]);

    voisins.push_back(Grille[0][31]); 

  }


  for(int i=0; i<9; i++){
      newA+=D*(voisins[i]->GetA());
      newB+=D*(voisins[i]->GetB());
      newC+=D*(voisins[i]->GetC());
      
    }



  newA+=(-9*D*(Grille[x][y]->GetA()));
  newB+=(-9*D*(Grille[x][y]->GetB()));
  newC+=(-9*D*(Grille[x][y]->GetB()));
  
  cout<<" Les nouvelles concentrations de la case ( "<<x<<", "<<y<<" ) sont ("<<newA<<", "<<newB<<", "<<newC<<" )"<<endl;
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
    
  }
  cout<<""<<endl;
}

void Map::DescribeABC(){

  for(int i=0; i<width;i++){
    for(int j=0; j<height; j++){
      cout<<"("<<Grille[i][j]->GetA()<<", "<<Grille[i][j]->GetB()<<", "<<Grille[i][j]->GetC()<<") ";

    }
    
  }
  cout<<""<<endl;
}

void Map::DescribeInt(){

  for(int i=0; i<width;i++){
    for(int j=0; j<height; j++){
      cout<<"("<<(Grille[i][j]->Getptr())->GetA_int()<<", "<<(Grille[i][j]->Getptr())->GetB_int()<<", "<<(Grille[i][j]->Getptr())->GetC_int()<<") ";

    }
    
  }
  cout<<""<<endl;
}


  
void Map::renouvelle(){
  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      Grille[i][j]->SetA(A_init);
      Grille[i][j]->SetC(0.0);
      Grille[i][j]->SetA(0.0);
    }
  }
}

Bacterie* Map::competition(int x, int y){
  vector<Metabolite*> voisins;

  if(x!=0 && x!=31 && y!=0 && y!=31){

    for(int i=-1; i<2;i++){
      for(int j=-1; j<2; j++){
        voisins.push_back(Grille[x+i][y+j]);
      
      }
    }
  }
  

  else if(x==0 && y!=0 && y!=31){
    for(int i=0; i<2;i++){
      for(int j=-1; j<2; j++){
        voisins.push_back(Grille[x+i][y+j]);
      
      }
    }
    voisins.push_back(Grille[31][y-1]);
    voisins.push_back(Grille[31][y]);
    voisins.push_back(Grille[31][y+1]);

  }

  else if(x==31 && y!=0 && y!=31){
    for(int i=-1; i<1;i++){
      for(int j=-1; j<2; j++){
        voisins.push_back(Grille[x+i][y+j]);
      
      }
    }
    voisins.push_back(Grille[0][y-1]);
    voisins.push_back(Grille[0][y]);
    voisins.push_back(Grille[0][y+1]);
    
  }

  else if(y==0 && x!=0 && x!=31){
    for(int i=-1; i<2;i++){
      for(int j=0; j<2; j++){
        voisins.push_back(Grille[x+i][y+j]);
      
      }
    }
    voisins.push_back(Grille[x-1][31]);
    voisins.push_back(Grille[x][31]);
    voisins.push_back(Grille[x+1][31]);
  }

  else if(y==31 && x!=0 && x!=31){
    for(int i=-1; i<2;i++){
      for(int j=-1; j<1; j++){
        voisins.push_back(Grille[x+i][y+j]);
      }
    }
    voisins.push_back(Grille[x-1][0]);
    voisins.push_back(Grille[x][0]);
    voisins.push_back(Grille[x+1][0]);  
  }

  else if(y==0 && x==0){

    voisins.push_back(Grille[x][y]);
    voisins.push_back(Grille[x+1][y]);
    voisins.push_back(Grille[x][y+1]); 
    voisins.push_back(Grille[x+1][y+1]);

    voisins.push_back(Grille[x][31]);
    voisins.push_back(Grille[x+1][31]); 
    voisins.push_back(Grille[31][y]);
    voisins.push_back(Grille[31][y+1]);

    voisins.push_back(Grille[31][31]); 
  }

  else if(y==31 && x==31){

    voisins.push_back(Grille[x][y]);
    voisins.push_back(Grille[x][y-1]);
    voisins.push_back(Grille[x-1][y-1]); 
    voisins.push_back(Grille[x-1][y]);

    voisins.push_back(Grille[x][0]);
    voisins.push_back(Grille[x-1][0]); 
    voisins.push_back(Grille[0][y-1]);
    voisins.push_back(Grille[0][y]);

    voisins.push_back(Grille[0][0]);  

  }

  else if(y==31 && x==0){

    voisins.push_back(Grille[x][y]);
    voisins.push_back(Grille[x][y-1]);
    voisins.push_back(Grille[x+1][y-1]); 
    voisins.push_back(Grille[x+1][y]);

    voisins.push_back(Grille[x][0]);
    voisins.push_back(Grille[x+1][0]); 
    voisins.push_back(Grille[31][y-1]);
    voisins.push_back(Grille[31][y]);

    voisins.push_back(Grille[31][0]); 

  }

  else if(y==0 && x==31){

    voisins.push_back(Grille[x][y]);
    voisins.push_back(Grille[x][y+1]);
    voisins.push_back(Grille[x-1][y+1]); 
    voisins.push_back(Grille[x-1][y]);

    voisins.push_back(Grille[x][31]);
    voisins.push_back(Grille[x-1][31]); 
    voisins.push_back(Grille[0][y+1]);
    voisins.push_back(Grille[0][y]);

    voisins.push_back(Grille[0][31]); 

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


  /*for (unsigned int i=0; i<voisins.size(); i++){
    cout<<voisins[i]->Getptr()<<endl;
  }*/


  int indice=0; //indice correspondant à la case gagnante dans voisins
  

  for (unsigned int i=0; i<voisins.size(); i++){
    
    if((voisins[i]->Getptr())->Getw()<(voisins[i+1]->Getptr())->Getw()){
      indice=i;
    }
    else{
      indice=i;

    }
  }
  
  cout<<""<<endl;
  cout<<"Nous avons une gagnante pour le gaps ("<<x<<", "<<y<<" )"<<endl;
  
  (voisins[indice]->Getptr())->Describe();
  return voisins[indice]->Getptr();
}



void Map::update(){

  cout<<"Diffusion des métabolites. (à venir)"<<endl;
  cout<<""<<endl;


  cout<<"Les bacteries meurent!"<<endl;
  cout<<""<<endl;

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      if((Grille[i][j]->Getptr())->Death()==0){

        Grille[i][j]->SetA(Grille[i][j]->GetA()+(Grille[i][j]->Getptr())->GetA_int());
        Grille[i][j]->SetB(Grille[i][j]->GetB()+(Grille[i][j]->Getptr())->GetB_int());
        Grille[i][j]->SetC(Grille[i][j]->GetC()+(Grille[i][j]->Getptr())->GetC_int());
        
        DescribeABC();

        delete(Grille[i][j]->Getptr());
        Grille[i][j]->Setptr(nullptr);

        cout<<"RIP"<<" ";
      }
    }
  }
  cout<<""<<endl;
  DescribeBacteries();

  cout<<""<<endl;
  cout<<"Les bacteries entrent en compétition!"<<endl;
  cout<<""<<endl;
  
  vector<Metabolite*> gaps;

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      if(Grille[i][j]->Getptr()==nullptr){
        gaps.push_back(Grille[i][j]);

      }
    }
  }

  

  random_shuffle(gaps.begin(), gaps.end());


  for(unsigned int i=0; i<gaps.size(); i++){

    Bacterie* gagnant=competition(gaps[i]->Getx(),gaps[i]->Gety());

    Bacterie* newborn=gagnant->Division();
    cout<<""<<endl;
    cout<<"Elle se divise pour donné un nouveau né bactérie!"<<endl;
    cout<<""<<endl;
    newborn->Describe();

    Grille[gaps[i]->Getx()][gaps[i]->Gety()]->Setptr(newborn);
  }
  
  
  cout<<""<<endl;
  DescribeBacteries();
  DescribeABC();


  cout<<"Les bactéries mutent!"<<endl;
  cout<<""<<endl;

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      if (Grille[i][j]->Getptr()!=nullptr){
        if((Grille[i][j]->Getptr())->Mute()==0){
          if((Grille[i][j]->Getptr())->Gettype()=='A'){
            Lignee_B* newcell=new Lignee_B((Grille[i][j]->Getptr())->GetA_int(),(Grille[i][j]->Getptr())->GetB_int(),(Grille[i][j]->Getptr())->GetC_int());
            delete(Grille[i][j]->Getptr());
            Grille[i][j]->Setptr(newcell);

          }
          else{
            Lignee_A* newcell=new Lignee_A((Grille[i][j]->Getptr())->GetA_int(),(Grille[i][j]->Getptr())->GetB_int(),(Grille[i][j]->Getptr())->GetC_int());
            delete(Grille[i][j]->Getptr());
            Grille[i][j]->Setptr(newcell);
          }

          cout<<"Mutante"<<" ";
        }
      }
    }
  }

  cout<<""<<endl;
  DescribeBacteries();

  cout<<""<<endl;
  cout<<"Les bactéries se nourrissent!!"<<endl;
  cout<<""<<endl;
  
  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      if((Grille[i][j]->Getptr())->Gettype()=='A'){
        Grille[i][j]->SetA((Grille[i][j]->Getptr())->Mange(Grille[i][j]->GetA(),h));
      }
      else{
        Grille[i][j]->SetB((Grille[i][j]->Getptr())->Mange(Grille[i][j]->GetB(),h));

      }

    }
  }

  cout<<""<<endl;
  DescribeABC();
  cout<<""<<endl;
  DescribeInt();




}


void Map::run(){

  while(temps<T){
    while(temps<t){
      update();
    }
    renouvelle();

  }


}
