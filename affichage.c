#include "initialiser.h"

void afficherTab(int** tab, int taille, int manche){
   printf("Manche Numéro %d/3\n",manche);
   for(int i=0;i<taille;i++){
        for(int j=0;j<taille;j++){
            if(tab[i][j]<10){
                printf("  %d ",tab[i][j]);
            }
            else if(tab[i][j]<20){
                printf(" %d ",tab[i][j]);
            }
            switch(tab[i][j]){
                case 20:
                  printf("    "); 
                  break;
                case 22:
                    printf(" "); 
                    break;
                case 23:
                    printf("+");
                    break;
                case 24:
                    printf("\033[34m----\033[0m");
                    break;
                case 25:
                    printf("\033[34m|\033[0m");
                    break;
                case 26:
                    printf("\033[34m+\033[0m");
                    break;
                case 27: 
                    printf(BG_RED " 🤖  " RESET);
                    break;
                case 28: 
                    printf(BG_GREEN " 🤖  " RESET);
                    break;
                case 29: 
                    printf(BG_YELLOW " 🤖  " RESET);
                
                    break;
                case 30: 
                    printf(BG_MAGENTA " 🤖  " RESET);
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    } 
}

int deplacement(int** tab, int robot, int taille, int numero, int* stockage, int manche){
    int x, y;
    char direction;
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (tab[i][j] == robot) {
                x = i;
                y = j;
                break;
            }
        }
    }
    afficherTab(tab, taille, manche);
    printf("\nPour vous déplacer, utilisez :\nZ pour aller en haut.\nS pour aller en bas.\nQ pour aller à gauche.\nEt enfin, D pour aller à droite.\n");
    scanf(" %c", &direction);
    if (direction != 'z' && direction != 's' && direction != 'd' && direction != 'q') {
            printf("Erreur : Vous n'avez pas entré un entier valide.\n");
            exit(EXIT_FAILURE);
        }
    switch (direction) {
        case 'z': //haut
            while (x > 1 && tab[x-1][y] == 20 && tab[x-2][y]<27) {
                if(tab[x-2][y]<19 && tab[x-2][y]>0){
                    x=x-2;
                    system("clear"); 
                    *stockage = tab[x][y];
                    tab[x][y] = robot;
                    tab[x+2][y] = 20;
                    if(*stockage == numero){
                        return 1;
                    }
                    break;
                }
                else if(*stockage != 20){
                    x=x-2;
                    system("clear"); 
                    tab[x][y] = robot;
                    tab[x+2][y] = *stockage;
                    *stockage = 20;
                }
                else{ 
                    x=x-2;
                    system("clear"); 
                    tab[x][y] = robot;
                    tab[x+2][y] = 20;
                }
                afficherTab(tab, taille, manche);
                    usleep(500000/2);
            }
            break;
        case 's': //bas
            while (x < taille-1 && tab[x+1][y] == 20 && tab[x+2][y]<27) {
                if(tab[x+2][y]<19 && tab[x+2][y]>0){
                    *stockage = tab[x+2][y];
                    x=x+2;
                    system("clear"); 
                    tab[x][y] = robot;
                    tab[x-2][y] = 20;
                    if(*stockage == numero){
                        return 1;
                    }
                    break;
                }
                else if(*stockage != 20){
                    x=x+2;
                    system("clear"); 
                    tab[x][y] = robot;
                    tab[x-2][y] = *stockage;
                    *stockage = 20;
                }
                else{ 
                    x=x+2;
                    system("clear"); 
                    tab[x][y] = robot;
                    tab[x-2][y] = 20;
                }
                afficherTab(tab, taille, manche);
                usleep(500000/2);
            }
            break;
        case 'q': //gauche
            while (y > 1 && tab[x][y-1] == 22 && tab[x][y-2]<27){
                if(tab[x][y-2]<19 && tab[x][y-2]>0){
                    *stockage = tab[x][y-2];
                    y=y-2;
                    system("clear"); 
                    tab[x][y] = robot;
                    tab[x][y+2] = 20;
                    if(*stockage == numero){
                        return 1;
                    }
                    break;
                }
                else if(*stockage != 20){
                    y=y-2;
                    system("clear"); 
                    tab[x][y] = robot;
                    tab[x][y+2] = *stockage;
                    *stockage = 20;
                }
                else{ 
                    y=y-2;
                    system("clear"); 
                    tab[x][y] = robot;
                    tab[x][y+2] = 20;
                }
                afficherTab(tab, taille, manche);
                usleep(500000/2);
            }
            break;
        case 'd': //droite
            while (y < taille-1 && tab[x][y+1] == 22 && tab[x][y+2]<27) {
                if(tab[x][y+2]<19 && tab[x][y+2]>0){
                    *stockage = tab[x][y+2];
                    y=y+2;
                    system("clear"); 
                    tab[x][y] = robot;
                    tab[x][y-2] = 20;
                    if(*stockage == numero){
                        return 1;
                    }
                    break;
                }
                else if(*stockage != 20){
                    y=y+2;
                    system("clear"); 
                    tab[x][y] = robot;
                    tab[x][y-2] = *stockage;
                    *stockage = 20;
                }
                else{ 
                    y=y+2;
                    system("clear"); 
                    tab[x][y] = robot;
                    tab[x][y-2] = 20;
                }
                afficherTab(tab, taille, manche);
                usleep(500000/2);
            }
            break;
    }
}

void Deroulement_partie(int** tab, int taille, int robot, int nombres_coups, int numero, Joueur* tab_j, int numero_joueur, int nombre_joueur, int manche){
    int stockage = 20, resultat;
    for (int i=0;i<nombres_coups;i++){
        printf("\nCoup %d/%d\n", i+1, nombres_coups);
        resultat = deplacement(tab, robot, taille, numero, &stockage, manche);
        system("clear");
        if(resultat == 1){
            if(nombres_coups == i+1){
                printf("Bien joué, tu as réussi à atteindre le point %d avec le bon nombre de coups ! Tu gagnes donc 2 points !",numero);
                (tab_j[numero_joueur].points) +=2;
            }
            if(nombres_coups > i+1){
                printf("Dommage tu as été meilleur que prévu ! Tu perds un point :-( ");
                (tab_j[numero_joueur].points) -=1;
                break;
            }
        }
    }
    if(resultat != 1){
        printf("\nNombre de coups maximum atteind, tu as perdu ! Tous les autres joueurs gagnent un point !\n");
        (tab_j[numero_joueur].points) -= 1;        
        for(int j=0; j<nombre_joueur; j++){
            (tab_j[j].points) += 1;
        }
    }
    printf("\nRécapitulatif des scores : \n");
    for(int j=0; j<nombre_joueur; j++){
            sleep(1);
            printf("Point du Joueur %d = %d points\n", j+1, tab_j[j].points);
    }
    sleep(1);
}