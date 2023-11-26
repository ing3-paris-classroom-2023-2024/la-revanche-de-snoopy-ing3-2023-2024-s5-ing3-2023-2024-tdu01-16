#include <stdio.h>

void caseBlockCassable(char* NextBlock, int* snoopyX, int* snoopyY, int* NextPositionX, int* NextPositionY, char tableau[12][22], char* direction) {
    if ((*NextBlock) == blocCassable.caractereAffiche && (*direction) == 'c') {
        gotoligcol(*NextPositionX, *NextPositionY);
        printf(" ");
        tableau[*NextPositionX][*NextPositionY] = ' ';
    }
}
