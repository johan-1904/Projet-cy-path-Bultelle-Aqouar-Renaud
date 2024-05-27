#include "initialiser.h"

int robot_selectionne(){
  int robot = rand() % 4 + 27;
  if (robot==27){
    printf ("Soyez attentif vous jouez avec le robot rouge\n");
  }
  if (robot==28){
    printf ("Soyez attentif vous jouez avec le robot vert\n");
  }
  if (robot==29){
    printf ("Soyez attentif vous jouez avec le robot jaune\n");
  }
  if (robot==30){
    printf ("Soyez attentif vous jouez avec le robot magenta\n");
  }
    
  return robot;
}

int cible_selectionne(){
  int cible =rand()%18 + 1;
  printf ("Quant à la cible, c'est le numéro %d qui nous intéresse\n",cible);
  return cible;
}

void niv_difficulte(int difficulte){
  if (difficulte==3){
      printf("La difficulté sera donc difficile, tu as 10 secondes devant toi\n");
      for(int i=15;i>0;i--){ 
        printf("%d\n",i);
        sleep(1);
      }
      system("clear");
  }
    if (difficulte==2){
      printf("La difficulté sera donc moyenne, tu as 20 secondes devant toi\n");
      for(int i=30;i>0;i--){ 
        printf("%d\n",i);
        sleep(1);
      }
      system("clear");
    }
    if (difficulte==1){
      printf("La difficulté sera donc facile, tu as 30 secondes devant toi\n");
      for(int i=45;i>0;i--){ 
        printf("%d\n",i);
        sleep(1);
      }
      system("clear");
    }  
}

void libererCarre(int** tab, int taille) {
    for (int i = 0; i < taille; i++) {
        free(tab[i]);
    }
    free(tab);
}