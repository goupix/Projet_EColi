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
  virtual float GetA_int()=0;
  virtual float GetB_int()=0;
  virtual float GetC_int()=0;
  virtual float& Getw()=0;
  
//==============================
//    SETTERS
//==============================

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================
virtual void Describe()=0; //Décris la bactérie
virtual int Death(); //revoit 1 (la bacterie vit) ou 0 (la bacterie meurt) avec une proba p_death
virtual int Mute(); //renvoit 1 (la bacterie ne mute pas) ou 0 (la bacterie mute) avec une proba p_mutation 
virtual Bacterie* Division()=0; //methode qui gere la division des bacteries (x2) (divise les concentrations de la bacterie par deux et renvoit une bacterie identique)
virtual float absorb(float c, float h)=0; //execute absorb sur la bacterie, prend en argument le pas de temps h 
  //et la concentration de la case 

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
float p_death; //probabilité de mort (=0.02)
float p_mutation; //probabilité de mutation (0)
float W_min; //seuil minimum de fitness (=0.001)

//Concentration intracellulaire des métabolites
float A_int;
float B_int;
float C_int;

char type; //type de bacterie (A ou B)

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
