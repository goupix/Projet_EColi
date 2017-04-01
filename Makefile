all: main

main: main.o Lignee_L.o Lignee_S.o Bacterie.o Map.o Case.o
	g++ -g main.o Lignee_L.o Lignee_S.o Bacterie.o Map.o Case.o -Wall -Wextra -o main -std=c++11
	
main.o: main.cpp Lignee_L.h Lignee_S.h Bacterie.h Map.h Case.h
	g++ -g -c main.cpp -Wall -Wextra -o main.o -std=c++11
	
Bacterie.o : Bacterie.cpp Bacterie.h
	g++ -g -c Bacterie.cpp -Wall -Wextra -o Bacterie.o -std=c++11

Map.o : Map.cpp Map.h
	g++ -g -c Map.cpp -Wall -Wextra -o Map.o -std=c++11

Lignee_A.o : Lignee_L.cpp Lignee_L.h
	g++ -g -c Lignee_L.cpp -Wall -Wextra -o Lignee_L.o -std=c++11

Lignee_B.o : Lignee_S.cpp Lignee_S.h
	g++ -g -c Lignee_S.cpp -Wall -Wextra -o Lignee_S.o -std=c++11

Case.o : Case.cpp Case.h
	g++ -g -c Case.cpp -Wall -Wextra -o Case.o -std=c++11