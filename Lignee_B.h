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

virtual void Death();
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
char type='B';

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
