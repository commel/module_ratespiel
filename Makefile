CFLAGS=-std=c99 -pedantic -Wall -g

spiel:	spiel.o spiel_rand.o

spiel_rand.o:	spiel_rand.h

clean:
	$(RM) *.o spiel
