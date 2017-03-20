#ifndef Case_H
#define Case_H

//==============================
//    INCLUDES 
//==============================

/**
 * @class Bacteries
 * @brief Creates a Character
 */
#include "Bacterie.h"
#include "Lignee_A.h"
#include "Lignee_B.h"

class Case
{
public:
//==============================
//    CONSTRUCTORS
//==============================
  Case(int a, int b, float A_init, Bacterie* cible);

//==============================
//    DESTRUCTOR
//==============================
  virtual ~Case();

//==============================
//    GETTERS
//==============================

  float GetA()const;
  float GetB()const;
  float GetC()const;
  Bacterie* Getptr()const;
  int Getx()const;
  int Gety()const;

//==============================
//    SETTERS
//==============================

  void SetA(float a);
  void SetB(float b);
  void SetC(float c);
  void Setptr(Bacterie* cible);
  
//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================
  void Describe();
  void makeDie(); /*teste si la bacterie meurt, si oui récupère les Cases, détruit la bacterie et rend 
  le pointeur null.*/
  void makeMute(); /*teste si la bacterie mute, si oui créé une bacterie de type opposé, détruit la bactérie 
  et fait pointer ptr vers la nouvelle bactérie.*/

  void makeEat(float h);/* Applique la méthode absorb sur la bactérie pointée par l'attribut ptr, modifie
  la concentration de la case en fonction du type de bactérie */
  void add(float a, float b, float c);
protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
  float A; //concentration en A de la case
  float B; //concentration en B de la case
  float C; //concentration en C de la case
  Bacterie* ptr; //pointeur sur la bactérie qui est sur la case
  int x; //coordonnée de la case 
  int y;

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
#endif // Case_H 
