#include "header.h"
#include <stdio.h>
#include <conio.h>

struct TypeBloc {
    char identifiant;
    char caractereAffiche;
};

// Exemples de types de blocs
struct TypeBloc blocVide = {'0', ' '};
struct TypeBloc blocCassable = {'1', '1'};
struct TypeBloc blocPoussableAuto = {'2', '2'};
struct TypeBloc blocPiege = {'3','3'};
struct TypeBloc blocInvincible = {'4','4'};
struct TypeBloc blocDA = {'5','5'};
struct TypeBloc blocPousser = {'6','6'};
struct TypeBloc blocSnoopy = {'7','0'};
struct TypeBloc blocOiseau = {'9','9'};

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
            printf("%c", tableau[k][l]);
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

            for (int k = 0; k < taille; ++k) {
                if (symbole == typesBlocs[k].identifiant) {
                    tableau[ligne][colonne] = typesBlocs[k].caractereAffiche;
                    break;
                }
            }
        }
    }
}

