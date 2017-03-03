#ifndef BACTERIE_H
#define BACTERIE_H 


//==============================
//    INCLUDES 
//==============================
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
/**
 * @class Bacterie
 * @brief 
 */

class Bacterie
{
public:
//==============================
//    CONSTRUCTORS
//==============================
  Bacterie();
//==============================
//    DESTRUCTOR
//==============================
  virtual ~Bacterie();

//==============================
//    GETTERS
//==============================
  virtual char Gettype();
  virtual float GetA_int();
  virtual float GetB_int();
  virtual float GetC_int();
  virtual float& Getw();
  virtual void euler(float& a, float& aint, float& bint, float h, float p1, float p2);
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

virtual int Mute();

virtual Bacterie* Division(); //methode qui gere la division des bacteries (x2)
/*virtual void Deplacement(); //methode qui gere le deplacement des bacteries sur la map*/

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
int coord[2]; //tableau de coordonnees [x,y]
float p_death; //probabilité de mort (=0.02)
float p_mutation; //probabilité de mutation (0)
float W_min; //seuil minimum de fitness (=0.001)

//Concentration intracellulaire des métabolites
float A_int;
float B_int;
float C_int;

char type;
//std::vector<int> depl;
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

#endif // BACTERIE_H
