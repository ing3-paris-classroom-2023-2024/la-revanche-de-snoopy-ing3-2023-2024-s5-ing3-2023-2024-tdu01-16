#include <stdio.h>

void caseBlocOiseau(char* NextBlock, int* snoopyX, int* snoopyY, int* NextPositionX, int* NextPositionY, char tableau[12][22], char* direction, int*objectif, int*fin){
    if(*NextBlock == blocOiseau.caractereAffiche){
        gotoligcol(*snoopyX, *snoopyY);
        printf("%c",blocVide.caractereAffiche);
        gotoligcol(*NextPositionX, *NextPositionY);
        printf("%c",blocSnoopy.caractereAffiche);
        tableau[*NextPositionX][*NextPositionY] = blocSnoopy.caractereAffiche;
        tableau[*snoopyX][*snoopyY] = blocVide.caractereAffiche;
        *snoopyX = *NextPositionX;
        *snoopyY = *NextPositionY;
        *objectif= *objectif+1;
        Color(5,0);
        gotoligcol(1,25);
        printf("Objectif %d/4",*objectif);
        Color(14,0);


    }
        Color(5,0);
        gotoligcol(1,25);
        printf("Objectif %d/4",*objectif);
        Color(14,0);
        if(*objectif==4){
            *fin =1;
        }
}
