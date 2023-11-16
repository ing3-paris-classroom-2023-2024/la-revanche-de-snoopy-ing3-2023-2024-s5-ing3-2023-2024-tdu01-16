#include "header.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
struct TypeBloc {
    char identifiant;
    char caractereAffiche;
};

// Exemples de types de blocs
struct TypeBloc blocVide = {'0', ' '};
struct TypeBloc blocCassable = {'1',0xB1};
struct TypeBloc blocPoussableHaut = {'2', '^'};
struct TypeBloc blocPoussableBas = {'3', 'v'};
struct TypeBloc blocPoussableGauche = {'4', '<'};
struct TypeBloc blocPoussableDroite = {'5', '>'};
struct TypeBloc blocPiege = {'6','6'};
struct TypeBloc blocSnoopy = {'7','0'};
struct TypeBloc blocInvincible = {'8',0xFE};
struct TypeBloc blocDA = {'9','9'};
struct TypeBloc blocPousser = {'A','A'};
struct TypeBloc blocOiseau = {'B',0xB8};

struct Balle {
    int x;
    int y;
    int directionX;
    int directionY;
};

void Color(int couleurDuTexte,int couleurDeFond)
{
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void gotoligcol( int lig, int col )
{
// ressources
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void affichageContour(char tableau[12][22]){

Color(2,0);


    // Initialisation des coins et des lignes horizontales
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 22; ++j) {
            // Coin supérieur gauche
            if (i == 0 && j == 0) {
                tableau[i][j] = 0xC9;
            }
                // Coin supérieur droit
            else if (i == 0 && j == 21) {
                tableau[i][j] = 0xBB;

                // Coin inférieur gauche
            } else if (i == 11 && j == 0) {
                tableau[i][j] = 0xC8;

                // Coin inférieur droit
            } else if (i == 11 && j == 21) {
                tableau[i][j] = 0xBC;
                // Ligne horizontale
            } else if (i == 0 || i == 11) {
                tableau[i][j] = 0xCD;

                // Ligne verticale
            } else if (j == 0 || j == 21) {
                tableau[i][j] = 0xBA;

                // Caractère par défaut (espace)
            } else {
                tableau[i][j] = ' ';
            }
        }
    }

}

void deplacement(char tableau[12][22], int *snoopyX, int *snoopyY) {
  Color(14,0);
  gotoligcol(*snoopyX,*snoopyY);
  printf("0");


    char saisie = getch();
    fflush(stdin);


    switch (saisie) {
        case 'z':
            if(tableau[*snoopyX - 1][*snoopyY]==' '){
            gotoligcol(*snoopyX,*snoopyY);
            printf(" ");
            gotoligcol(*snoopyX -1,*snoopyY);
            printf("0");
            tableau[*snoopyX - 1][*snoopyY] = 0x01;
            tableau[*snoopyX][*snoopyY] = ' ';



            (*snoopyX)--;
            }
            break;
        case 's':
            if(tableau[*snoopyX + 1][*snoopyY]==' '){
            gotoligcol(*snoopyX,*snoopyY);
            printf(" ");
            gotoligcol(*snoopyX +1,*snoopyY);
            printf("0");
            tableau[*snoopyX + 1][*snoopyY] = 0x01;
            tableau[*snoopyX][*snoopyY] = ' ';

            (*snoopyX)++;
            }
            break;

        case 'q':
            if(tableau[*snoopyX][*snoopyY - 1]==' '){
            gotoligcol(*snoopyX,*snoopyY);
            printf(" ");
            gotoligcol(*snoopyX,*snoopyY-1);
            printf("0");
            tableau[*snoopyX][*snoopyY - 1] = 0x01;
            tableau[*snoopyX][*snoopyY] = ' ';

            (*snoopyY)--;
            }
            break;
        case 'd':
            if(tableau[*snoopyX][*snoopyY + 1]== ' '){
            gotoligcol(*snoopyX,*snoopyY);
            printf(" ");
            gotoligcol(*snoopyX,*snoopyY+1);
            printf("0");
            tableau[*snoopyX][*snoopyY + 1] = 0x01;
            tableau[*snoopyX][*snoopyY] = ' ';

            (*snoopyY)++;
            }
            break;
        default:
            break;
    }

}
void saisirDirection(char*direction,char*NextBlock,int*snoopyX,int*snoopyY,int*NextPositionX,int*NextPositionY,char tableau[12][22]){

Color(14,0);
  gotoligcol(*snoopyX,*snoopyY);
  printf("0");

    (*direction) = getch();
    fflush(stdin);

    switch (*direction){
    case 'z':
        (*NextPositionX) = (*snoopyX) - 1;
        (*NextPositionY) = (*snoopyY);
        (*NextBlock) = tableau[*NextPositionX][*NextPositionY];



            break;
        case 's':
            (*NextPositionX) = (*snoopyX) + 1;
        (*NextPositionY) = (*snoopyY);
        (*NextBlock) = tableau[*NextPositionX][*NextPositionY];


            break;

        case 'q':
            (*NextPositionX) = (*snoopyX);
        (*NextPositionY) = (*snoopyY)-1;
        (*NextBlock) = tableau[*NextPositionX][*NextPositionY];


            break;
        case 'd':
            (*NextPositionX) = (*snoopyX);
        (*NextPositionY) = (*snoopyY)+1;
        (*NextBlock) = tableau[*NextPositionX][*NextPositionY];


            break;
        case 'c':
        (*direction)= 'c';
        default:

            break;
    }


}

void caseVide(char* NextBlock, int* snoopyX, int* snoopyY, int* NextPositionX, int* NextPositionY, char tableau[12][22]) {
    if ((*NextBlock) ==  blocVide.caractereAffiche) {
        gotoligcol(*snoopyX, *snoopyY);
        printf(" ");
        gotoligcol(*NextPositionX, *NextPositionY);
        printf("0");
        tableau[*NextPositionX][*NextPositionY] = 0x01;
        tableau[*snoopyX][*snoopyY] = ' ';
        *snoopyX = *NextPositionX;
        *snoopyY = *NextPositionY;
    }
}
void caseBlockCassable(char* NextBlock, int* snoopyX, int* snoopyY, int* NextPositionX, int* NextPositionY, char tableau[12][22], char* direction) {
    if ((*NextBlock) == blocCassable.caractereAffiche && (*direction) == 'c') {
        gotoligcol(*NextPositionX, *NextPositionY);
        printf(" ");
        tableau[*NextPositionX][*NextPositionY] = ' ';
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

void caseBlocOiseau(char* NextBlock, int* snoopyX, int* snoopyY, int* NextPositionX, int* NextPositionY, char tableau[12][22], char* direction, int*objectif){
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
}






void chargerNiveau(char fichierNom[50], char tableau[12][22]) {
    FILE *fichier = fopen(fichierNom, "r");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    for (int i = 1; i < 11; ++i) {
        for (int j = 1; j < 21; ++j) {
        fscanf(fichier, " %c", &tableau[i][j]);

        }

    }


    fclose(fichier);

}
void affichertableau(char tableau[12][22]){
    for (int k = 0; k < 12; ++k) {
    for (int l = 0; l < 22; ++l) {
            if(tableau[k][l]==blocInvincible.caractereAffiche){
                Color(7,0);
                printf("%c", tableau[k][l]);
                Color(2,0);
            }
            else{
                    Color(2,0);
                printf("%c", tableau[k][l]);
            }
    }
        printf("\n");
    }


}
void remplacerSymboles(char tableau[12][22], struct TypeBloc typesBlocs[], int taille, int *snoopyX, int *snoopyY) {
    for (int ligne = 0; ligne < 12; ++ligne) {
        for (int colonne = 0; colonne < 22; ++colonne) {
            char symbole = tableau[ligne][colonne];
            if (symbole == '7'){
                    *snoopyX = ligne;
                    *snoopyY = colonne;

            }

            for (char k = 0; k < taille; ++k) {
                if (symbole == typesBlocs[k].identifiant) {
                    tableau[ligne][colonne] = typesBlocs[k].caractereAffiche;
                    break;
                }
            }
        }
    }
}

void menuDemarrer(void) {
    gotoligcol(5, 0);
        Color(14, 0);
        printf("LA REVANCHE DE SNOOPY");
        sleep(4);
        Color(15, 0);
        printf("\033[2J\033[H");
    while (1) {

        gotoligcol(5, 0);
        printf("1 - Regles du jeu");
        gotoligcol(7, 0);
        printf("2 - Jouer");

        char saisie = getch();

        if (saisie == '1') {
            printf("\033[2J\033[H");
            gotoligcol(0, 0);
            printf("Initialement, le joueur possede 3 vies.\n");
            printf("Chaque niveau doit etre resolu en moins de 120 secondes.\n");
            printf("Si le temps est écoule, le joueur perd une vie et recommence le niveau.\n");
            printf("Le but est de recuperer les 4 oiseaux du niveau sans se faire toucher par la balle et/ou les ennemis (si presents).\n\n\n");
            printf("Appuyez sur 'b' pour revenir au menu.\n");

            while (1) {
                saisie = getch();
                if (saisie == 'b') {
                    break;  // Sortir de la boucle règles
                }
            }

            printf("\033[2J\033[H");
        } else if (saisie == '2') {
            // Logique pour démarrer le jeu
            break;  // Sortir de la boucle principale du menu
        }
    }
    printf("\033[2J\033[H");
}


