#ifndef METABOLITE_H
#define METABOLITE_H

//==============================
//    INCLUDES 
//==============================

/**
 * @class Bacteries
 * @brief Creates a Character
 */
#include "Bacterie.h"

class Metabolite
{
public:
//==============================
//    CONSTRUCTORS
//==============================
  Metabolite(int a, int b, float A_init, Bacterie* cible);

//==============================
//    DESTRUCTOR
//==============================
  virtual ~Metabolite();

//==============================
//    GETTERS
//==============================
  float GetA();
  float GetB();
  float GetC();
  Bacterie* Getptr();
  int Getx();
  int Gety();
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
#endif // METABOLITE_H 
