#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define RESET "\033[0m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"


//Création d'un fonction pour changer la couleur d'un print
#define couleur(param) printf("\033[%sm",param)

typedef struct{
    int x;
    int y;
    int numero;
}Point;

typedef struct{
    int x;
    int y;
    int couleur;
}Robot;

typedef struct{
    int numero;
    int points;
}Joueur;

int** initialiserCarre(int taille);
void Initialiser_points(int** tab, int taille);
int Verif_position(int** tab, int taille, Point point);
void Creer_coin(int** tab, int taille, Point point);
void Initialiser_robots(int** tab, int taille);
Joueur* Initialiser_joueurs(int nb_joueur);
int Comparaison_reponses(int nb_joueur, int* tab);

int Comparaison_reponses(int nb_joueur, int* tab);
int Recuperation_reponses(int nb_joueur, int* stock_index);

int robot_selectionne();
int cible_selectionne();
void niv_difficulte(int difficulte);
void libererCarre(int** tab, int taille);

void afficherTab(int** tab, int taille);
int deplacement(int** tab, int robot, int taille, int numero, int* stockage);
void Deroulement_partie(int** tab, int taille, int robot, int nombres_coups, int numero, Joueur* tab_j, int numero_joueur, int nombre_joueur);

int main();