#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"
#include "sous-programmes.c"
#include <time.h>
#include <pthread.h>






int main() {

    // Déclaration et initialisation du tableau 12x22
    char tableau[12][22];
    int snoopyX;
    int snoopyY;
    int NextPositionX;
    int NextPositionY;
    char NextBlock;
    char direction;
    int objectif = 0;
    int secondes = 20;


    // Déclaration et initialisation du tableau de types de blocs
    struct TypeBloc typesBlocs[] = {blocVide, blocCassable, blocPoussableHaut,blocPoussableBas,
     blocPoussableGauche, blocPoussableDroite,  blocPiege, blocInvincible, blocDA,blocOiseau,blocSnoopy};
    int tailleTypesBlocs = sizeof(typesBlocs) / sizeof(typesBlocs[0]);
    menuDemarrer();


    affichageContour(tableau);
    chargerNiveau("niveau1.txt", tableau);
    remplacerSymboles(tableau, typesBlocs, tailleTypesBlocs,&snoopyX,&snoopyY);
    affichertableau(tableau);



    while(objectif<4){







        saisirDirection(&direction,&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY, tableau);
        caseVide(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau);
        caseBlockCassable(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);
        caseblocPoussableHaut(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);
        caseblocPoussableBas(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);
        caseblocPoussableGauche(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);
        caseblocPoussableDroite(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);
        caseBlocOiseau(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction, &objectif);


    }


    printf("\033[2J\033[H");
    gotoligcol(5,5);
    printf("niveau termine");
    sleep(4);


}
