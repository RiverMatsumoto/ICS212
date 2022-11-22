project_debug: llist.o user_interface.o
	g++ -o project_debug llist.o user_interface.o

llist.o: llist.cpp llist.h
	g++ -ansi -pedantic-errors -Wall -c llist.cpp -D DEBUGMODE

user_interface.o: user_interface.cpp
	g++ -ansi -pedantic-errors -Wall -c user_interface.cpp -D DEBUGMODE

clean:
	rm project_debug llist.o user_interface.o
