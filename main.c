#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"
#include "sous-programmes.c"






int main() {
    // Déclaration et initialisation du tableau 12x22
    char tableau[12][22];
    int snoopyX;
    int snoopyY;

    // Déclaration et initialisation du tableau de types de blocs
    struct TypeBloc typesBlocs[] = {blocVide, blocCassable, blocPoussableAuto, blocPiege, blocInvincible, blocDA};
    int tailleTypesBlocs = sizeof(typesBlocs) / sizeof(typesBlocs[0]);

    // Appel de la fonction en passant un pointeur vers le tableau
    affichageContour(tableau);
    chargerNiveau("niveau1.txt", tableau);
    remplacerSymboles(tableau, typesBlocs, tailleTypesBlocs,&snoopyX,&snoopyY);
    affichertableau(tableau);

    while(1) {
        deplacement(tableau, &snoopyX, &snoopyY);
    }

    return 0;
}
