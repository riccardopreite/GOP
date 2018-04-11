CC = g++

FLAG_CC = -I $(HEAD_DIR) -o

SRC_DIR = source/

HEAD_DIR = 	header/

OBJECT_DIR = object/
all: GOP

GOP:  GOP.o Giocatori.o Persona.o deck.o Dado.o Tabellone.o Coda.o Nodo.o Type.o
	g++ $(OBJECT_DIR)GOP.o $(OBJECT_DIR)Giocatori.o $(OBJECT_DIR)Persona.o $(OBJECT_DIR)Type.o $(OBJECT_DIR)deck.o $(OBJECT_DIR)Dado.o $(OBJECT_DIR)Tabellone.o $(OBJECT_DIR)Coda.o $(OBJECT_DIR)Nodo.o $(FLAG_CC) GOP

Type.o: $(HEAD_DIR)Type.h $(SRC_DIR)Type.cpp
	g++ $(SRC_DIR)Type.cpp -c $(FLAG_CC) $(OBJECT_DIR)Type.o

Persona.o: $(HEAD_DIR)Persona.h $(SRC_DIR)Persona.cpp
	g++ $(SRC_DIR)Persona.cpp -c $(FLAG_CC) $(OBJECT_DIR)Persona.o

Dado.o: $(HEAD_DIR)Dado.h $(SRC_DIR)Dado.cpp
	g++ $(SRC_DIR)Dado.cpp -c $(FLAG_CC) $(OBJECT_DIR)Dado.o

Giocatori.o: $(HEAD_DIR)Giocatori.h $(SRC_DIR)Giocatori.cpp
	g++ $(SRC_DIR)Giocatori.cpp -c $(FLAG_CC) $(OBJECT_DIR)Giocatori.o

deck.o: $(HEAD_DIR)deck.h $(SRC_DIR)deck.cpp
	g++ $(SRC_DIR)deck.cpp -c $(FLAG_CC) $(OBJECT_DIR)deck.o

Tabellone.o: $(HEAD_DIR)Tabellone.h $(SRC_DIR)Tabellone.cpp
	g++ $(SRC_DIR)Tabellone.cpp -c $(FLAG_CC) $(OBJECT_DIR)Tabellone.o

Coda.o: $(HEAD_DIR)Coda.h $(SRC_DIR)Coda.cpp
	g++ $(SRC_DIR)Coda.cpp -c $(FLAG_CC) $(OBJECT_DIR)Coda.o

Nodo.o: $(HEAD_DIR)Nodo.h $(SRC_DIR)Nodo.cpp
	g++ $(SRC_DIR)Nodo.cpp -c $(FLAG_CC) $(OBJECT_DIR)Nodo.o

GOP.o: $(SRC_DIR)GOP.cpp
		g++ $(SRC_DIR)GOP.cpp -c $(FLAG_CC) $(OBJECT_DIR)GOP.o
clean:
	rm -rf GOP
