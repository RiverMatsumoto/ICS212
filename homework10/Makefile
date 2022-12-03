homework10: main.o Pokemon.o Pikachu.o Dragonite.o Charizard.o
	g++ -o homework10 Pikachu.o Pokemon.o main.o Dragonite.o Charizard.o

main.o: main.cpp
	g++ -ansi -pedantic-errors -Wall -c main.cpp

Pikachu.o: Pikachu.cpp Pikachu.h
	g++ -ansi -pedantic-errors -Wall -c Pikachu.cpp

Dragonite.o: Dragonite.cpp Dragonite.h
	g++ -ansi -pedantic-errors -Wall -c Dragonite.cpp

Charizard.o: Charizard.cpp Charizard.h
	g++ -ansi -pedantic-errors -Wall -c Charizard.cpp

Pokemon.o: Pokemon.cpp Pokemon.h
	g++ -ansi -pedantic-errors -Wall -c Pokemon.cpp

clean:
	rm *.o homework10
