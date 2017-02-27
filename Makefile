all: main

main: main.o Lignee_A.o Lignee_B.o Bacterie.o Map.o Metabolite.o
	g++ -g main.o Lignee_A.o Lignee_B.o Bacterie.o Map.o Metabolite.o -Wall -Wextra -o main -std=c++11
	
main.o: main.cpp Lignee_A.h Lignee_B.h Bacterie.h Map.h Metabolite.h
	g++ -g -c main.cpp -Wall -Wextra -o main.o -std=c++11
	
Bacterie.o : Bacterie.cpp Bacterie.h
	g++ -g -c Bacterie.cpp -Wall -Wextra -o Bacterie.o -std=c++11

Map.o : Map.cpp Map.h
	g++ -g -c Map.cpp -Wall -Wextra -o Map.o -std=c++11

Lignee_A.o : Lignee_A.cpp Lignee_A.h
	g++ -g -c Lignee_A.cpp -Wall -Wextra -o Lignee_A.o -std=c++11

Lignee_B.o : Lignee_B.cpp Lignee_B.h
	g++ -g -c Lignee_B.cpp -Wall -Wextra -o Lignee_B.o -std=c++11

Metabolite.o : Metabolite.cpp Metabolite.h
	g++ -g -c Metabolite.cpp -Wall -Wextra -o Metabolite.o -std=c++11