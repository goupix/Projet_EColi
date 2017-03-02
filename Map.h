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
void DescribeBacteries();
void DescribeABC();
void bougeMetabo(); // bouge les metabolites
/*void update(); // les bacteries se nourrissent, metabolisent, mutent, se divisent, meurent eventuellement*/
void renouvelle(); //reinitialise le milieu de culture
/*int* count();// compte le nombre de bacteries des lignees S et L
*/

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
int T; //temps de simulation
int t; //temps de renouvellement
int temps; //temps reel de la simulation
int h; //pas de temps
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

