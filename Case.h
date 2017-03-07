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

  void makeEat(float h);
  
protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
  float A;
  float B;
  float C;
  Bacterie* ptr;
  int x;
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
