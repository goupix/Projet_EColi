//==============================
//    INCLUDES
//==============================
#include "Bacterie.h"
#include "Metabolite.h"
#include <iostream>
using std::cout;
using std::endl;

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================



//==============================
//    CONSTRUCTORS
//==============================
Bacterie::Bacterie(){
/*depl.push_back(1);
depl.push_back(2);
depl.push_back(3);
depl.push_back(4);*/
srand(time(NULL));
coord[0]=0; 
coord[1]=0;

p_death=0.02; 
p_mutation=0; 
W_min=0.001; 


A_int=0;
B_int=0; 
C_int=0;
}

//==============================
//    DESTRUCTOR
//==============================

Bacterie::~Bacterie(){}
//==============================
//    PUBLIC METHODS
//==============================
void Bacterie::Describe(){
	cout<< "Cette bactérie est placée en ("<<coord[0]<<", "<<coord[1]<<" )"<<endl;
	cout<< "Elle présente une concentration interne en A: "<<A_int<<", en B: "<<B_int<<" et en C: "<<C_int<<endl;
}

void Bacterie::Death(){
  for(int i=0; i<32; i++){
    for(int j=0; j<32; j++){
      srand(time(NULL));
      float nombre = (float)rand() / (float)RAND_MAX;
      if(nombre<p_death){
        float A=A_int;
        float B=B_int; //tester plutot avec Grille(x,y) qui correspond aux concentrations en métabolites dans la grille 
        float C=C_int;
        cout<<"RIP"<<endl;
        cout<<A+B+C<<endl; 
        }
      }
     }
    }

void Bacterie::Deplacement(){
    int alea=rand()%4+1;
	//std::random_shuffle(depl.begin(), depl.end());
	switch ()
	{
    	case 1:
    		if (coord[0] == 31) {
    			coord[0] = 0;
    		}
    		else {
    			coord[0] ++;
    		}
        	break;

    	case 2:
    		if (coord[0] == 0) {
    			coord[0] = 31;
    		}
    		else {
    			coord[0] --;
    		}

    		break;

    	case 3:
    		if (coord[1] == 31) {
    			coord[1] = 0;
    		}
    		else {
    			coord[1] ++;
    		}
			break;

    	case 4:
    		if (coord[1] == 0) {
    			coord[1] = 31;
    		}
    		else {
    			coord[1] --;
    		}
			break;
    	
    	default :
    		break;
	}
}
