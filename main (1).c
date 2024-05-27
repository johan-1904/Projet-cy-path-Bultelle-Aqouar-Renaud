#include "initialiser.h"

int main(){
    srand(time(NULL));
    int difficulte, resultat, numero_joueur;
    int nb_joueur;
    char c;
    do{
        printf("Entrez le nombre de joueurs (entre 2 et 4) : ");
        if (scanf("%d%c", &nb_joueur, &c) != 2 || c != '\n') {
            printf("Erreur : Vous n'avez pas entré un entier valide.\n");
            exit(EXIT_FAILURE);
        }
      }while(nb_joueur<2||nb_joueur>4);
   
    Joueur* tab_joueurs = Initialiser_joueurs(nb_joueur);
    
    do{
        printf("Maintenant, choisissez une difficulté : 1 pour facile, 2 pour moyen et 3 pour difficile.\n");
        if (scanf("%d%c", &difficulte, &c) != 2 || c != '\n') {
            printf("Erreur : Vous n'avez pas entré un entier valide.\n");
            exit(EXIT_FAILURE); 
        }
      }while(difficulte<1||difficulte>3);
    int i=0;
    while(i<3){
        system("clear");
        
        int taille = (rand()%6+15)*2+1;
    
        int** tab=initialiserCarre(taille);
        Initialiser_points(tab,taille);
        Initialiser_robots(tab,taille);
        afficherTab(tab,taille,i+1);
        int robot=robot_selectionne();
        int cible=cible_selectionne();
        niv_difficulte(difficulte);
        int nombres_coups = Recuperation_reponses(nb_joueur, &numero_joueur);
        if(nombres_coups==0){
            libererCarre(tab, taille);
        }
        else{
            Deroulement_partie(tab, taille, robot, nombres_coups, cible, tab_joueurs, numero_joueur, nb_joueur, i+1);
            i++;
            if(i<2){
                printf("\n\n\nPréparez vous ! La manche suivante va démarrer !\n");
                sleep(3);
            }
            libererCarre(tab, taille);
        }
        sleep(1);
    }
    Scores_finaux(tab_joueurs, nb_joueur);
    return 0;
}