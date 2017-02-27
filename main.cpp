#include <iostream>
#include "Map.h"
#include "Bacterie.h"
#include "Lignee_A.h"
#include "Lignee_B.h"
#include "Metabolite.h"

using namespace std;

int main(){
/* Test de la classe Map

  Map environnement=Map();
  environnement.placeBacteries();
  cout<<"Case 1, A: "<< environnement.GetGrille()[0][0].GetA() <<endl;*/

/*Test de la classe Bacterie*/

  Bacterie b=Bacterie();
  b.Describe();

/*Test de la classe Lignee_B*/

  Lignee_B t=Lignee_B(1,3);
  t.Describe();


  return 0;
}

