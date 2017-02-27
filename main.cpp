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
  Metabolite m=Metabolite();
  grille1.placeBacteries();
  return 0;
}

