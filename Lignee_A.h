#ifndef LIGNEE_A
#define LIGNEE_A
//==============================
//    INCLUDES 
//==============================

/**
 * @class Bacteries
 * @brief Creates a Character
 */
#include "Bacterie.h"

class Lignee_A: public Bacterie{

public:
//==============================
//    CONSTRUCTORS
//==============================
  Lignee_A();
  Lignee_A(float a, float b, float c);
  Lignee_A(const Lignee_A& a);
//==============================
//    DESTRUCTOR
//==============================
  virtual ~Lignee_A();

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
  /*virtual void Deplacement();*/
  virtual Bacterie* Division();
  virtual int Mute();



protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
  float Raa;
  float Rab;
  float& w=B_int;
  

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

#endif // LIGNEE_A
