#include <stdio.h>
#include <stdlib.h>
#include "TP3.h"

int main()
{
    //t_vaccin_elt *GESTION_VACCINS[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

    char choix = '0';
    while (choix != '7') {

        printf("=================================================================================\n");
        printf("||    Bienvenu au menu principal d'une application d'ordonnancement medicale   ||\n");
        printf("=================================================================================\n");
        printf("||  1. Initialiser la liste des marques de vaccin disponibles.                 ||\n");
        printf("||  2. Ajouter et planifier un stock.                                          ||\n");
        printf("||  3. Retirer un nombre de vaccins du stock.                                  ||\n");
        printf("||  4. Afficher le stock d'un vaccin.                                          ||\n");
        printf("||  5. Afficher la planification pour une semaine.                             ||\n");
        printf("||  6. Fusionner deux stocks.                                                  ||\n");
        printf("||  7. Quitter.                                                                ||\n");
        printf("=================================================================================\n\n");

        printf("\n   Votre choix ? ");
        choix = getchar();
        viderBuffer();

        switch (choix) {
            case '1' :
                // TODO : menu 1
            break;

            case '2' :
                // TODO : menu 2
            break;

            case '3' :
                // TODO : menu 3
            break;

            case '4' :
                // TODO : menu 4
            break;

            case '5' :
                // TODO : menu 5
            break;

            case '6' :
                // TODO : menu 6
            break;

            case '7' :
                printf("\n======== PROGRAMME TERMINE ========\n");
            break;

            default :
                printf("\n\nERREUR : votre choix n'est pas valide ! ");

            }
            printf("\n\n\n");

        }

        return 0;
    }
