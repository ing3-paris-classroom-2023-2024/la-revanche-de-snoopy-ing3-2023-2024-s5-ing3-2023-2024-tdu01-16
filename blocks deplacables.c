#include <stdio.h>

void caseBlocPoussable(char* NextBlock, int* snoopyX, int* snoopyY, int* NextPositionX, int* NextPositionY, char tableau[12][22], char* direction){

if ((*NextBlock) == blocPousser.caractereAffiche) {

    switch (*direction){
    case 'z':
        if(tableau[(*NextPositionX)-1][*NextPositionY] == ' '){
           gotoligcol(*snoopyX, *snoopyY);
        printf(" ");
        gotoligcol(*NextPositionX, *NextPositionY);
        printf("0");
        tableau[*NextPositionX][*NextPositionY] = blocSnoopy.caractereAffiche;
        tableau[*snoopyX][*snoopyY] = blocVide.caractereAffiche;
        *snoopyX = *NextPositionX;
        *snoopyY = *NextPositionY;
        gotoligcol((*NextPositionX)-1,*NextPositionY);
        Color(7,0);
        printf("%c", blocPousser.caractereAffiche);
        Color(14,0);
        tableau[(*NextPositionX)-1][*NextPositionY] = blocPousser.caractereAffiche;


        }
        break;

    case 's':
        if(tableau[(*NextPositionX)+1][*NextPositionY] == ' '){
           gotoligcol(*snoopyX, *snoopyY);
        printf(" ");
        gotoligcol(*NextPositionX, *NextPositionY);
        printf("0");
        tableau[*NextPositionX][*NextPositionY] = blocSnoopy.caractereAffiche;
        tableau[*snoopyX][*snoopyY] = blocVide.caractereAffiche;
        *snoopyX = *NextPositionX;
        *snoopyY = *NextPositionY;
        gotoligcol((*NextPositionX)+1,*NextPositionY);
        Color(7,0);
        printf("%c", blocPousser.caractereAffiche);
        Color(14,0);
        tableau[(*NextPositionX)+1][*NextPositionY] = blocPousser.caractereAffiche;


        }
        break;

    case 'q':
        if(tableau[(*NextPositionX)][(*NextPositionY)-1] == ' '){
           gotoligcol(*snoopyX, *snoopyY);
        printf(" ");
        gotoligcol(*NextPositionX, *NextPositionY);
        printf("0");
        tableau[*NextPositionX][*NextPositionY] = blocSnoopy.caractereAffiche;
        tableau[*snoopyX][*snoopyY] = blocVide.caractereAffiche;
        *snoopyX = *NextPositionX;
        *snoopyY = *NextPositionY;
        gotoligcol((*NextPositionX),(*NextPositionY)-1);
        Color(7,0);
        printf("%c", blocPousser.caractereAffiche);
        Color(14,0);
        tableau[(*NextPositionX)][(*NextPositionY)-1] = blocPousser.caractereAffiche;
        }
        break;

    case 'd':
        if(tableau[(*NextPositionX)][(*NextPositionY)+1] == ' '){
           gotoligcol(*snoopyX, *snoopyY);
        printf(" ");
        gotoligcol(*NextPositionX, *NextPositionY);
        printf("0");
        tableau[*NextPositionX][*NextPositionY] = blocSnoopy.caractereAffiche;
        tableau[*snoopyX][*snoopyY] = blocVide.caractereAffiche;
        *snoopyX = *NextPositionX;
        *snoopyY = *NextPositionY;
        gotoligcol((*NextPositionX),(*NextPositionY)+1);
        Color(7,0);
        printf("%c", blocPousser.caractereAffiche);
        Color(14,0);
        tableau[(*NextPositionX)][(*NextPositionY)+1] = blocPousser.caractereAffiche;


        }
        break;

    default :
        break;



        }


        }



    }

    void caseblocPoussableHaut(char* NextBlock, int* snoopyX, int* snoopyY, int* NextPositionX, int* NextPositionY, char tableau[12][22], char* direction) {

    if ((*NextBlock) == blocPoussableHaut.caractereAffiche) {
        if(tableau[(*NextPositionX)-1][*NextPositionY] == ' '){
           gotoligcol(*snoopyX, *snoopyY);
        printf(" ");
        gotoligcol(*NextPositionX, *NextPositionY);
        printf("0");
        tableau[*NextPositionX][*NextPositionY] = blocSnoopy.caractereAffiche;
        tableau[*snoopyX][*snoopyY] = blocVide.caractereAffiche;
        *snoopyX = *NextPositionX;
        *snoopyY = *NextPositionY;
        gotoligcol((*NextPositionX)-1,*NextPositionY);
        Color(7,0);
        printf("%c", blocInvincible.caractereAffiche);
        Color(14,0);
        tableau[(*NextPositionX)-1][*NextPositionY] = blocInvincible.caractereAffiche;


        }
    }
}
void caseblocPoussableBas(char* NextBlock, int* snoopyX, int* snoopyY, int* NextPositionX, int* NextPositionY, char tableau[12][22], char* direction) {

    if ((*NextBlock) == blocPoussableBas.caractereAffiche) {
        if(tableau[(*NextPositionX)+1][*NextPositionY] == ' '){
           gotoligcol(*snoopyX, *snoopyY);
        printf(" ");
        gotoligcol(*NextPositionX, *NextPositionY);
        printf("0");
        tableau[*NextPositionX][*NextPositionY] = blocSnoopy.caractereAffiche;
        tableau[*snoopyX][*snoopyY] = blocVide.caractereAffiche;
        *snoopyX = *NextPositionX;
        *snoopyY = *NextPositionY;
        gotoligcol((*NextPositionX)+1,*NextPositionY);
        Color(7,0);
        printf("%c", blocInvincible.caractereAffiche);
        Color(14,0);
        tableau[(*NextPositionX)+1][*NextPositionY] = blocInvincible.caractereAffiche;


        }
    }
}

void caseblocPoussableGauche(char* NextBlock, int* snoopyX, int* snoopyY, int* NextPositionX, int* NextPositionY, char tableau[12][22], char* direction) {

    if ((*NextBlock) == blocPoussableGauche.caractereAffiche) {
        if(tableau[(*NextPositionX)][(*NextPositionY)-1] == ' '){
           gotoligcol(*snoopyX, *snoopyY);
        printf(" ");
        gotoligcol(*NextPositionX, *NextPositionY);
        printf("0");
        tableau[*NextPositionX][*NextPositionY] = blocSnoopy.caractereAffiche;
        tableau[*snoopyX][*snoopyY] = blocVide.caractereAffiche;
        *snoopyX = *NextPositionX;
        *snoopyY = *NextPositionY;
        gotoligcol((*NextPositionX),(*NextPositionY)-1);
        Color(7,0);
        printf("%c", blocInvincible.caractereAffiche);
        Color(14,0);
        tableau[(*NextPositionX)][(*NextPositionY)-1] = blocInvincible.caractereAffiche;
        }
    }
}

void caseblocPoussableDroite(char* NextBlock, int* snoopyX, int* snoopyY, int* NextPositionX, int* NextPositionY, char tableau[12][22], char* direction) {

    if ((*NextBlock) == blocPoussableDroite.caractereAffiche) {
        if(tableau[(*NextPositionX)][(*NextPositionY)+1] == ' '){
           gotoligcol(*snoopyX, *snoopyY);
        printf(" ");
        gotoligcol(*NextPositionX, *NextPositionY);
        printf("0");
        tableau[*NextPositionX][*NextPositionY] = blocSnoopy.caractereAffiche;
        tableau[*snoopyX][*snoopyY] = blocVide.caractereAffiche;
        *snoopyX = *NextPositionX;
        *snoopyY = *NextPositionY;
        gotoligcol((*NextPositionX),(*NextPositionY)+1);
        Color(7,0);
        printf("%c", blocInvincible.caractereAffiche);
        Color(14,0);
        tableau[(*NextPositionX)][(*NextPositionY)+1] = blocInvincible.caractereAffiche;


        }
    }
}
