all: exec clean

main.o : main.c initialiser.h
	gcc -c main.c -o main.o

jeu.o : jeu.c initialiser.h
	gcc -c jeu.c -o jeu.o

affichage.o : affichage.c initialiser.h
	gcc -c affichage.c -o affichage.o

parametre.o : parametre.c initialiser.h
	gcc -c parametre.c -o parametre.o

saisie.o : saisie.c initialiser.h
	gcc -c saisie.c -o saisie.o

initialiser.o : initialiser.c initialiser.h
	gcc -c initialiser.c -o initialiser.o

exec : main.o jeu.o affichage.o parametre.o saisie.o initialiser.o
	gcc *.o -o exec


clean:
	rm -f *.o