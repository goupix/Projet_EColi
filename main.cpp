#include <iostream>
#include "Map.h"
#include "Bacterie.h"
#include "Lignee_A.h"
#include "Lignee_B.h"
#include "Metabolite.h"

using namespace std;

int main(){

  Map grille1=Map();
  Bacterie b=Bacterie();
  grille1.placeBacteries();
  cout<<"Case 1, A: "<< grille1.GetGrille()[0][0].GetA() <<endl;
  return 0;
}

