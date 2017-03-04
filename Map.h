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
#include "Metabolite.h"
#include "Lignee_B.h"
#include "Lignee_A.h"
#include <vector>

class Map
{
public:
//==============================
//    CONSTRUCTORS
//==============================
Map();

//==============================
//    DESTRUCTOR
//==============================
virtual ~Map();

//==============================
//    GETTERS
//==============================
Metabolite*** GetGrille();

//==============================
//    SETTERS
//==============================

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================
void placeBacteries(); // cree et positionne les bacteries 
void DescribeBacteries();//renvoit un tableau avec le type (A ou B), de bactéries pour chaque case
void DescribeABC();//renvoit un tableau avec les concentrations (A,B,C) pour chaque case
void DescribeInt();////renvoit un tableau avec les concentrations (A_int,B_int,C_int) internes des bacteries pour chaque case
void bougeMetabo(Metabolite*& m); // bouge les metabolites
void update(); // les bacteries se nourrissent, metabolisent, mutent, se divisent, meurent eventuellement, les metabolites diffusent
void renouvelle(); //reinitialise le milieu de culture
Bacterie* competition(int x, int y); //renvoit le gagnant d'un gap sous forme de pointeur
void run();// exectute l'algorithme jusqu'a un temps T donné



protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
static constexpr int width=32; //longueur grille
static constexpr int height=32;//hauteur grille
float A_init; //concentration initiale en glucose
float D; //coef de diffusion
float T; //temps total de simulation
int t; //pas de renouvellement
float temps; //temps reel de la simulation
float h; //pas de temps
Metabolite*** Grille; //grille des concentrations en metabolites



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

