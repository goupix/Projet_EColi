#ifndef MAP_H 
#define MAP_H 

//==============================
//    INCLUDES
//==============================

/**
 * @class Map
 * @brief Creates a Map of cells
 */
#include "Bacterie.h"
#include "Case.h"
#include "Lignee_S.h"
#include "Lignee_L.h"
#include <vector>

class Map
{
public:
//==============================
//    CONSTRUCTORS
//==============================

Map(float A_int=50, int t=10000, float d=0.1);

//==============================
//    DESTRUCTOR
//==============================
virtual ~Map();

//==============================
//    GETTERS
//==============================


//==============================
//    SETTERS
//==============================

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================

void DescribeBacteries();//renvoit un tableau avec le type (L ou S) de bactéries pour chaque case
void DescribeABC();//renvoit un tableau avec les concentrations (A,B,C) pour chaque case
void DescribeInt();////renvoit un tableau avec les concentrations (A_int,B_int,C_int) internes des bacteries pour chaque case
char run();// exectute l'algorithme jusqu'a un temps T donné



protected:
//==============================
//    PROTECTED METHODS
//==============================

void set(); // cree et positionne les bacteries 
void update(); // les bacteries se nourrissent, metabolisent, mutent, se divisent, meurent eventuellement, les métabolites diffusent
void diffusion(); // bouge les métabolites suivant un modèle de diffusion
void renew(); //reinitialise le milieu de culture
Bacterie* competition(int x, int y); //renvoie le gagnant d'un gap sous forme de pointeur
char state(int nbL, int nbS);

//==============================
//    ATTRIBUTES
//==============================
static constexpr int width=32; //longueur grille
static constexpr int height=32;//hauteur grille
float A_init; //concentration initiale en glucose
float D; //coefficient de diffusion
float T; //temps total de simulation
int t; //pas de renouvellement
float temps; //temps reel de la simulation
float h; //pas de temps
Case*** grille; //grille des concentrations en métabolites



//==============================
//    GETTER DEFINITION
//==============================

//==============================
//    SETTER DEFINITION
//==============================

//==============================
//    OPERATOR DEFINITION
//==============================
};
#endif // MAP_H

