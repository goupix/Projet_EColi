#ifndef LIGNEE_L
#define LIGNEE_L
//==============================
//    INCLUDES 
//==============================

/**
 * @class Bacteries
 * @brief Creates a Bacteria of type A
 */
#include "Bacterie.h"

class Lignee_L: public Bacterie{

public:
//==============================
//    CONSTRUCTORS
//==============================
  Lignee_L();
  Lignee_L(float a, float b, float c);

//==============================
//    DESTRUCTOR
//==============================
  virtual ~Lignee_L();

//==============================
//    GETTERS
//==============================
  virtual float GetA_int();
  virtual float GetB_int();
  virtual float GetC_int();
  virtual char Gettype();
  virtual float& Getw();
  
//==============================
//    SETTERS
//==============================

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================

  virtual void Describe();
  virtual int Death(); 
  virtual Bacterie* Division();
  virtual int Mute(); 
  static int nombre_L();  
  virtual float absorb(float c, float h); 



protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
  float Raa;// taux d'absorption
  float Rab;//taux de conversion
  float& w=B_int;//fitness
  static int compteur_L;//variable qui compte les instances de la classe Lignee_L
  

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

#endif // LIGNEE_L
