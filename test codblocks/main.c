#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"
#include "sous-programmes.c"
#include <time.h>






int main() {

    // Déclaration et initialisation du tableau 12x22

    char niveau[] = "niveau1.txt";
    char tableau[12][22];
    int snoopyX;
    int snoopyY;
    int fin = 0;

    int spawnSnoopyX;
    int spawnSnoopyY;
    int NextPositionX;
    int NextPositionY;
    char NextBlock;
    char direction;
    int objectif = 0;
    int secondes = 120;
    int compteur_s = 0;
    int vies_tot=0;

    int score = 0;
    clock_t start_time, current_time;
    double seconds = 0;

    int vie =3;



    // Déclaration et initialisation du tableau de types de blocs
    struct TypeBloc typesBlocs[] = {blocVide, blocCassable, blocPoussableHaut,blocPoussableBas,
     blocPoussableGauche, blocPoussableDroite,  blocPiege, blocInvincible,blocOiseau,blocSnoopy,blocPousser};
    t_balle balle = {1, 1, 1, 1};




    int tailleTypesBlocs = sizeof(typesBlocs) / sizeof(typesBlocs[0]);


    menuDemarrer(&niveau);



    affichageContour(tableau);
    chargerNiveau(niveau, tableau);
    remplacerSymboles(tableau, typesBlocs, tailleTypesBlocs,&snoopyX,&snoopyY,&spawnSnoopyX,&spawnSnoopyY);
    affichertableau(tableau);



   while(fin==0){





        saisirDirection(&direction,&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY, tableau,&start_time,&secondes,&fin,&balle,&vie
                        ,&spawnSnoopyX,&spawnSnoopyY);
        caseVide(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau);
        caseBlockCassable(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);
        caseblocPoussableHaut(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);
        caseblocPoussableBas(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);
        caseblocPoussableGauche(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);
        caseblocPoussableDroite(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);
        caseBlocOiseau(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction, &objectif, &fin);
        caseBlockpiege(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&vie,&spawnSnoopyX,&spawnSnoopyY,&fin);
        caseBlocPoussable(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);




    }
    score=calcul_score(score,secondes);
    fin = 0;
    vie = 3;
    secondes = 120;
    objectif = 0;

    printf("\033[2J\033[H");
    gotoligcol(5,5);
    printf("niveau termine");
    sleep(4);
    printf("\033[2J\033[H");
    strcpy(niveau, "niveau2.txt");





    affichageContour(tableau);
    chargerNiveau(niveau, tableau);
    remplacerSymboles(tableau, typesBlocs, tailleTypesBlocs,&snoopyX,&snoopyY,&spawnSnoopyX,&spawnSnoopyY);
    affichertableau(tableau);


while(fin==0){





        saisirDirection(&direction,&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY, tableau,&start_time,&secondes,&fin,&balle,&vie
                        ,&spawnSnoopyX,&spawnSnoopyY);
        caseVide(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau);
        caseBlockCassable(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);
        caseblocPoussableHaut(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);
        caseblocPoussableBas(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);
        caseblocPoussableGauche(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);
        caseblocPoussableDroite(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);
        caseBlocOiseau(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction, &objectif, &fin);
        caseBlockpiege(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&vie,&spawnSnoopyX,&spawnSnoopyY,&fin);
        caseBlocPoussable(&NextBlock,&snoopyX,&snoopyY,&NextPositionX,&NextPositionY,tableau,&direction);




    }
    fin = 0;
    score=calcul_score(score,secondes);
    printf("\033[2J\033[H");
    gotoligcol(5,5);
    printf("niveau termine");
    sleep(4);

gotoligcol(5,5);
    printf("score final : %d points",score);
}

