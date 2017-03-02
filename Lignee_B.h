#ifndef LIGNEE_B
#define LIGNEE_B
//==============================
//    INCLUDES 
//==============================

/**
 * @class Bacteries
 * @brief Creates a Character
 */
#include "Bacterie.h"

class Lignee_B: public Bacterie
{
public:
//==============================
//    CONSTRUCTORS
//==============================
  Lignee_B(int x, int y);
  Lignee_B(int x, int y, float a, float b, float c);
  Lignee_B(const Lignee_B& a);

//==============================
//    DESTRUCTOR
//==============================
  virtual ~Lignee_B();

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

  virtual void Describe();
  virtual Bacterie* Division();
  virtual int Death();
  /*virtual void Deplacement();*/
  virtual char Gettype();

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
float Rbb;
float Rbc;
float& w=C_int;


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

#endif // LIGNEE_B
