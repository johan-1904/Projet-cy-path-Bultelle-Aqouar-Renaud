#include "initialiser.h"

int Scores_finaux(Joueur* tab_joueur, int  nombre_joueur){
    int score_max = (tab_joueur[0].points);
    for(int i=0; i<nombre_joueur; i++){
        if(score_max < (tab_joueur[i].points)){
            score_max = (tab_joueur[i].points);
        }
    }
    int compteur = 0;
    for(int i=0; i<nombre_joueur; i++){
        if(score_max == (tab_joueur[i].points)){
            compteur ++;
        }
    }
    if(compteur == 1){
        printf("\n\n\nLe vainqueur est donc ");
    }
    if(compteur > 1){
        printf("\n\n\nLes vainqueurs sont donc ");
    }
    for(int i=0; i<nombre_joueur; i++){
        if(score_max == (tab_joueur[i].points)){
            printf("Joueur %d ", (tab_joueur[i].numero));
        }
    }
    printf("!\n\n\n\n\n\n\n");
}