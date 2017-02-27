#ifndef MAP_H 
#define MAP_H 

//==============================
//    INCLUDES
//==============================

/**
 * @class Character
 * @brief Creates a Character
 */
#include "Bacterie.h"
#include "Lignee_A.h"
#include "Lignee_B.h"
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
void bougeMetabo(); // bouge les metabolites
void update(); // les bacteries se nourrissent, metabolisent, mutent, se divisent, meurent eventuellement
void renouvelle(); //reinitialise le milieu de culture
int* count();// compte le nombre de bacteries des lignees S et L


protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
int width; //longueur grille
int height;//hauteur grille
float A_init; //concentration initiale en glucose
float D; //coef de diffusion
int T; //temps de simulation
int t; //temps de renouvellement
int temps; //temps reel de la simulation
int h; //pas de temps
Bacterie* Metaboliste[3][width][height]; //grille des concentrations en metabolites
std::vector<Bacterie*> listeBacteries(width*height);


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

