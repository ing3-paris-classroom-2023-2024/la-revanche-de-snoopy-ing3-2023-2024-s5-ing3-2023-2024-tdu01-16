#include "header.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

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
struct TypeBloc blocPousser = {'9','#'};
struct TypeBloc blocOiseau = {'B',0xB8};

typedef struct Balle {
    int x;
    int y;
    int directionX;
    int directionY;
}t_balle;

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
void saisirDirection(char* direction, char* NextBlock, int* snoopyX, int* snoopyY, int* NextPositionX, int* NextPositionY, char tableau[12][22], clock_t* start_time, int* secondes,int *fin,t_balle*balle,int*vie
                    ,int*spawnSnoopyX,int*spawnSnoopyY) {

    char pause;
    Color(14, 0);
    gotoligcol(*snoopyX, *snoopyY);
    printf("0");

    while (1) {

        // Vérifier si une seconde s'est écoulée
       if ((clock() - *start_time) >= CLOCKS_PER_SEC) {
        (*secondes)--;
        gotoligcol(3, 25);
        printf("%d secondes restantes", *secondes);
        gotoligcol(*snoopyX, *snoopyY);
        // deplacement de la balle
            // Effacer la position actuelle de la balle
    gotoligcol(balle->x, balle->y);
    if (tableau[balle->x][balle->y]== blocInvincible.identifiant){
            Color(7, 0);

    }
   else if (tableau[balle->x][balle->y]== blocSnoopy.caractereAffiche){
            Color(14, 0);

    }
    else{Color(2, 0);}
    printf("%c",tableau[balle->x][balle->y]);
    Color(14, 0);

    // Mettre à jour la position de la balle
    balle->x += balle->directionX;
    balle->y += balle->directionY;

    // Vérifier les collisions avec les murs (rebonds)
    if (balle->x == 1 || balle->x == 10) {
        balle->directionX = -balle->directionX;  // Inverser la direction en cas de collision avec un mur vertical
    }

   else if (balle->y == 1 || balle->y == 20) {
        balle->directionY = -balle->directionY;  // Inverser la direction en cas de collision avec un mur horizontal
    }
    if(balle->x == (*snoopyX) && balle->y == (*snoopyY)) {

            *vie = *vie - 1;
    gotoligcol(*snoopyX, *snoopyY);
    printf("%c",blocVide.caractereAffiche);
    gotoligcol(*spawnSnoopyX,*spawnSnoopyY);
    printf("%c",blocSnoopy.caractereAffiche);
    tableau[*snoopyX][*snoopyY] = blocVide.caractereAffiche;
    tableau[*spawnSnoopyX][*spawnSnoopyY]= blocSnoopy.caractereAffiche;
    gotoligcol(2,25);
    printf("vies %d/3",*vie);
    gotoligcol(*snoopyX, *snoopyY);
    printf("%c",blocVide.caractereAffiche);
    *snoopyX = *spawnSnoopyX;
    *snoopyY = *spawnSnoopyY;


            }
    if (*secondes==0){

       *vie = *vie - 1;
       gotoligcol(2,25);
        printf("vies %d/3",*vie);
    }
    if(*vie==0){
        *fin = 1;
    }
    if(*secondes<=0){
        //*secondes=0;
        gotoligcol(3, 25);
        printf("0 secondes restantes");
    }

    // Afficher la balle à la nouvelle position
    gotoligcol(balle->x, balle->y);
    printf("o");
        // Réinitialiser le chrono
        *start_time = clock();
    if(*secondes<=0){
        *secondes=0;
    }


    }



    // Vérifier si une touche est en attente
      else if (_kbhit()) {

            (*direction) = _getch();
            fflush(stdin);

            switch (*direction) {
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
                    (*NextPositionY) = (*snoopyY) - 1;
                    (*NextBlock) = tableau[*NextPositionX][*NextPositionY];
                    break;
                case 'd':
                    (*NextPositionX) = (*snoopyX);
                    (*NextPositionY) = (*snoopyY) + 1;
                    (*NextBlock) = tableau[*NextPositionX][*NextPositionY];
                    break;
                case 'c':
                    (*direction) = 'c';
                    break;
                case 'p':
                        gotoligcol(4, 25);
                        Color(4,0);
                        printf("PAUSE");
                    pause   = _getch();
                    fflush(stdin);
                    while(pause!='p'){

                        pause   = _getch();
                        fflush(stdin);

                    }
                    gotoligcol(4, 25);
                    Color(14,0);
                    printf("      ");


                    break;
                default:

                    break;
            }

            // Si la saisie est valide, sortir de la boucle
            if (*direction == 'z' || *direction == 's' || *direction == 'q' || *direction == 'd' || *direction == 'c') {
                break;
            }
        }

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

void caseBlockpiege(char* NextBlock, int* snoopyX, int* snoopyY, int* NextPositionX, int* NextPositionY, char tableau[12][22],int* vie,const int* spawnSnoopyX,const int *spawnSnoopyY, int*fin){

if ((*NextBlock) == blocPiege.caractereAffiche){
    *vie = *vie - 1;
    gotoligcol(*snoopyX, *snoopyY);
    printf("%c",blocVide.caractereAffiche);
    gotoligcol(*spawnSnoopyX,*spawnSnoopyY);
    printf("%c",blocSnoopy.caractereAffiche);
    tableau[*snoopyX][*snoopyY] = blocVide.caractereAffiche;
    tableau[*spawnSnoopyX][*spawnSnoopyY]= blocSnoopy.caractereAffiche;
    gotoligcol(2,25);
    printf("vies %d/3",*vie);
    gotoligcol(*snoopyX, *snoopyY);
    printf("%c",blocVide.caractereAffiche);
    *snoopyX = *spawnSnoopyX;
    *snoopyY = *spawnSnoopyY;
    if(*vie==0){
        *fin = 1;
    }
    }
}

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
void remplacerSymboles(char tableau[12][22], struct TypeBloc typesBlocs[], int taille, int *snoopyX, int *snoopyY, int *spawnSnoopyX,int*spawnSnoopyY) {
    for (int ligne = 0; ligne < 12; ++ligne) {
        for (int colonne = 0; colonne < 22; ++colonne) {
            char symbole = tableau[ligne][colonne];
            if (symbole == '7'){
                    *snoopyX = ligne;
                    *snoopyY = colonne;
                    *spawnSnoopyX = *snoopyX;
                    *spawnSnoopyY = *snoopyY;

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

void menuDemarrer(char*niveau) {

    char motDePasseNiv1[] = "motdepasse";
    char motDePasseNiv2[] = "1234";
    char motDePasseNiv3[] = "ABCDEFG";

    char motDePasseUtilisateur[50];
    int continuer = 0;





    gotoligcol(5, 0);
        Color(14, 0);
        printf("LA REVANCHE DE SNOOPY");
        sleep(2);
        Color(15, 0);
        printf("\033[2J\033[H");
    while (continuer ==0) {

        gotoligcol(5, 0);
        printf("1 - Regles du jeu");
        gotoligcol(7, 0);
        printf("2 - Jouer");
        gotoligcol(9, 0);
        printf("3 - Charger un niveau");
        gotoligcol(11, 0);
        printf("4 - score");
        gotoligcol(11, 0);
        printf("5 - quitter");

        char saisie = getch();
        switch(saisie){
        case '1':
            printf("\033[2J\033[H");
            gotoligcol(0, 0);
            printf("Initialement, le joueur possede 3 vies.\n");
            printf("Chaque niveau doit etre resolu en moins de 120 secondes.\n");
            printf("Si le temps est ecoule, le joueur perd une vie et recommence le niveau.\n");
            printf("Le but est de recuperer les 4 oiseaux du niveau sans se faire toucher par la balle et/ou les ennemis (si presents).\n\n\n");
            printf(" Z\nQSD POUR SE DEPLACER\n");
            printf("  vous pouvez mettre pause a tout moment en appuyant sur p\n\n\n");

            printf("Appuyez sur 'b' pour revenir au menu.\n");

            while (1) {
                saisie = getch();
                if (saisie == 'b') {
                    break;  // Sortir de la boucle règles
                }
            }

            printf("\033[2J\033[H");
        break;


        case '2':
           continuer = 1; // Logique pour démarrer le jeu
            break;  // Sortir de la boucle principale du menu

        case '3':
            printf("\033[2J\033[H");
            gotoligcol(0, 0);
            printf("charger un niveau");
            gotoligcol(5, 0);
            printf("entrer le mot de passe : ");

            fgets(motDePasseUtilisateur, sizeof(motDePasseUtilisateur), stdin);

            // Supprimer le caractère de nouvelle ligne ajouté par fgets
            size_t longueur = strlen(motDePasseUtilisateur);
            if (longueur > 0 && motDePasseUtilisateur[longueur - 1] == '\n') {
            motDePasseUtilisateur[longueur - 1] = '\0';

            if (strcmp(motDePasseUtilisateur, motDePasseNiv1) == 0) {
            printf("Mot de passe correct. OK!\n");
            strcpy(niveau, "niveau1.txt");
            printf("\033[2J\033[H");
            gotoligcol(5, 0);
            printf("niveau 1");
            sleep(2);
            printf("\033[2J\033[H");
            }

            else if (strcmp(motDePasseUtilisateur, motDePasseNiv2) == 0) {

            strcpy(niveau, "niveau2.txt");
            printf("\033[2J\033[H");
            gotoligcol(5, 0);
            printf("niveau 2");
            sleep(2);
            printf("\033[2J\033[H");


            }
             else if (strcmp(motDePasseUtilisateur, motDePasseNiv3) == 0) {

            strcpy(niveau, "niveau3.txt");
            printf("\033[2J\033[H");
            gotoligcol(5, 0);
            printf("niveau 3");
            sleep(2);
            printf("\033[2J\033[H");


            }
            else{
                printf("\033[2J\033[H");
                gotoligcol(5, 0);
                printf("mot de passe incorrecte!");
                sleep(2);
                printf("\033[2J\033[H");
            }

    }

break;

        case '4':

            break;

        case '5':
            printf("\033[2J\033[H");
             gotoligcol(5, 0);
            printf("Au revoir !\n");
            sleep(2);
                exit(0);


            break;
        default:
            break;





        }

    printf("\033[2J\033[H");
}

}
int calcul_score(int score,int secondes){
    int calc = 0;
    calc = score + secondes*100;

    return calc;
}

