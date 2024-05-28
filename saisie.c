#include "initialiser.h"

int Comparaison_reponses(int nb_joueur, int* tab){
    int stock_min = tab[0], res = 0 ;
    int stock_max = tab[0];
  
    for(int i=0;i<nb_joueur; i++){  //Trouver le joueur avec le minimum de déplacements annoncé
        if(stock_min > tab[i]){
          stock_min = tab[i];
          res = i;
    
        }    
    }
    
    for(int i=0; i<nb_joueur; i++){ //Trouver le joueur avec le maximum de déplacements annoncé
        if(stock_max < tab[i]){
            stock_max = tab[i];
        }
    } 
    
    if(stock_max == stock_min && stock_max == 0){  //Si tous les joueurs ont annoncés 0
        return -1;
    }
    if(stock_min != 0){ //Si aucun joueur a annoncé 0
        return res;
    }
    else{  //Trouver un joueur avec des déplacements annoncés différent de 0
        int diff_zero;
        for(int i = nb_joueur-1; i>=0;i--){
            if(tab[i] != 0){
                diff_zero = i;
                break;
            }
        }
        int stock_min1 = tab[diff_zero], res1 = diff_zero; //Cherche le joueur avec le moins de déplacement sans compter ceux à 0
        for(int i=diff_zero;i>=0; i--){
            if(tab[i] != 0){
                if(stock_min1 >= tab[i]){
                    stock_min1 = tab[i];
                    res1 = i;
                }    
            }
        }
        
        return res1;
    }
}

int Recuperation_reponses(int nb_joueur, int* stock_index){
    int* reponses = NULL; 
    reponses = (int*)malloc(nb_joueur*sizeof(int));
    char c;

    printf("Si vous pensez la partie irréalisable, rentrez la valeur 0. Si vous choisissez tous de mettre 0, une nouvelle grille aléatoire sera alors créee.\n");
    for(int i=1; i<=nb_joueur; i++){
        do{
            printf("Joueur %d, en combien de coups penses-tu pouvoir atteindre la cible ? (maximum 20) \n", i);
            if (scanf("%d%c", &reponses[i-1], &c) != 2 || c != '\n') {
                printf("Erreur : Vous n'avez pas entré un entier valide.\n");
                exit(EXIT_FAILURE);
            }
            }while(reponses[i-1]<0 || reponses[i-1]>20);
      }

    *stock_index = Comparaison_reponses(nb_joueur, reponses);
    if((*stock_index)==-1){
        return 0;
    }
    printf("Très bien, Joueur %d,\nMontre nous comment tu atteinds la cible en seulement %d coups !\n", (*stock_index)+1, reponses[(*stock_index)]);
    
    return reponses[(*stock_index)];
    free(reponses);
    
}