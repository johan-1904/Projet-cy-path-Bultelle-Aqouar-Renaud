#include "initialiser.h"

int** initialiserCarre(int taille) {
    int **carre = (int **)malloc(taille * sizeof(int*));
    for (int i = 0; i < taille; i++) {
        carre[i] = (int *)malloc(taille * sizeof(int));
        for(int i=0; i<taille; i++){
            if(carre[i] == NULL){
                //Libérer toute mémoire déjà allouée en cas d'erreur
                for(int j=0;j<i;j++){
                    free(carre[i]);
                }
            }
        }
        for (int j = 0; j < taille; j++) {
            if(i==0 || i==taille-1){
              if(j==0 || j==taille-1){
                    carre[i][j] = 26;
                }
                else if(j%2==1){
                    carre[i][j] = 24;
                }
                else{
                    carre[i][j] = 26;
                }
            }
            else if(i%2==1){
                if(j==0 || j==taille-1){
                    carre[i][j] = 25;
                }
                else if(j%2==1){
                    carre[i][j] = 20;
                }
                else{
                    carre[i][j] = 22;
                }
            }
            else{
                if(j==0 || j==taille-1 ){
                    carre[i][j] = 25;
                }
                else if(j%2==1){
                    carre[i][j] = 20;
                }
                else{
                 carre[i][j] = 23;
                }
            }
        }
    }

    int stockage, stockage1 = -1;

    for(int i=1;i<taille;i=i+(taille-3)){  //Murs aléatoire sur les côtés (haut bas)
        stockage = rand()%(((taille-1)/2)-6)+3;
        stockage1 = rand()%(((taille-1)/2)-6)+3;
        while(stockage - stockage1 >= -3 && stockage - stockage1 <= 3){
            stockage1 = rand()%(((taille-1)/2)-6)+3;
        }
        carre[i][stockage*2] = 25;
        carre[i][stockage1*2] = 25;
    }

    for(int j=1;j<taille;j=j+(taille-3)){  // (gauche droite)
        stockage = rand()%(((taille-1)/2)-6)+3;
        stockage1 = rand()%(((taille-1)/2)-6)+3;
        while(stockage - stockage1 >= -3 && stockage - stockage1 <= 3){
            stockage1 = rand()%(((taille-1)/2)-6)+3;
        }
        carre[stockage*2][j] = 24;
        carre[stockage1*2][j] =24;
    }

    return carre;
}

void Initialiser_points(int** tab, int taille){
    Point* tab1 = NULL;
    tab1 = (Point*)malloc(18*sizeof(Point));
    for(int i=0;i<18;i++){

        tab1[i].numero = i+1;
        do{ 
            tab1[i].x = rand()%(taille-6)+3;
            while(tab1[i].x%2==0){
                tab1[i].x = rand()%(taille-6)+3;
            }

            tab1[i].y = rand()%(taille-6)+3;
             while(tab1[i].y%2==0){
                tab1[i].y = rand()%(taille-6)+3;
            }
        }while(Verif_position(tab,taille,tab1[i])!=0);
        tab[tab1[i].x][tab1[i].y] = i+1 ;
        Creer_coin(tab,taille,tab1[i]);
    }
}

int Verif_position(int** tab, int taille, Point point){
    int i = point.x-2, j = point.y-2;
    for(int k=0;k<6;k+=2){
        if(tab[i+k][j]<18 && tab[i+k][j]>0){ // On vérifie qu'il n'y a pas d'autres points dans la première ligne entourant notre point 
            return -1;
        }
    }
    j+=2;
    for(int k=0;k<6;k+=2){
        if(tab[i+k][j]<18 && tab[i+k][j]>0){ // Puis dans la deuxième 
            return -1;
        }
    }
    j+=2;
    for(int k=0;k<6;k+=2){
        if(tab[i+k][j]<18 && tab[i+k][j]>0){ // Et enfin dans la troisième
            return -1;
        }
    }
    return 0;
}

void Creer_coin(int** tab, int taille, Point point){
    int stockage_vert, stockage_hor, i = point.x, j = point.y;

    stockage_vert = rand()%2+1; // 1 = gauche et 2 = droite
    stockage_hor = rand()%2+1; // 1 = haut et 2 = bas
    if(stockage_vert == 1){
        tab[i][j-1] = 25;
    }
    else if(stockage_vert == 2){
        tab[i][j+1] = 25;
    }

    if(stockage_hor == 1){
        tab[i-1][j] = 24;
    }
    else if(stockage_hor == 2){
        tab[i+1][j] = 24;
    }
}

void Initialiser_robots(int** tab, int taille){
    Robot* tab1 = NULL;
    tab1 = (Robot*)malloc(4*sizeof(Robot));
    for(int i=27;i<31;i++){

        tab1[i].couleur = i;
        do{ 
            tab1[i].x = rand()%(taille-2)+1;
            while(tab1[i].x%2==0){
                tab1[i].x = rand()%(taille-2)+1;
            }

            tab1[i].y = rand()%(taille-2)+1;
            while(tab1[i].y%2==0){
                tab1[i].y = rand()%(taille-2)+1;
            }
        
        }while(tab[tab1[i].x][tab1[i].y]!=20);
        tab[tab1[i].x][tab1[i].y] = i ;
    }
}

Joueur* Initialiser_joueurs(int nb_joueur){
    Joueur* tab1 = NULL;
    tab1 = (Joueur*)malloc(nb_joueur*sizeof(Joueur));
    for(int i=0;i<nb_joueur;i++){
        tab1[i].numero = i+1;
        tab1[i].points = 0;
    }
    return tab1;
}