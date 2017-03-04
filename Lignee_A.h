#ifndef LIGNEE_A
#define LIGNEE_A
//==============================
//    INCLUDES 
//==============================

/**
 * @class Bacteries
 * @brief Creates a Bacteria of type A
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

  virtual void Describe();// Decrit la bacterie
  virtual int Death(); //revoit 1 (la bacterie vit) ou 0 (la bacterie meurt) avec une proba p_death
  /*virtual void Deplacement();*/
  virtual Bacterie* Division();// divise les concentrations de la bacterie par deux et renvoit une bacterie identique
  virtual int Mute(); //renvoit 1 (la bacterie ne mute pas) ou 0 (la bacterie mute) avec une proba p_mutation 
  static int nombre_A();   //Renvoie le nombre d'objets créés
  virtual float Mange(float a, float h); //execute euler sur la bacterie, prend en argument le pas de temps h 
  //et la concentration en A de la case
  virtual float euler(float a, float& aint, float& bint, float h, float p1, float p2); // prend en argument la concentration de la case ,
  //modifie sur place les concentrations internes des bacteries et renvoit la nouvelle concentration de la case



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
  static int compteur_A;//variable qui compte les instances de la classe Lignee_A
  

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
