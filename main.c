#include <stdio.h>
#include <stdlib.h>
#include "TP3.h"

int main()
{
    t_vaccin_elt *GESTION_VACCINS[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    char marqueV[125];
    char ville[125];
    int instance=0;
    int semaine;
    int quantite;

    char choix = '0';
    while (choix != '7') {

        printf("=================================================================================\n");
        printf("||    Bienvenu au menu principal                                               ||\n");
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
                if (instance == 10){
                    printf("La liste de vaccin est complete. Veuillez en supprimer un pour en ajouter un nouveau.");
                }
                else {
                    printf("Veuillez entrer un nom de vaccin.\n");
                    scanf("%124s", marqueV);
                    t_vaccin_elt* nouveau_vaccin = creerVaccin(marqueV);
                    GESTION_VACCINS[instance] = nouveau_vaccin;
                    printf("Le vaccin %s est initialise ! \n",GESTION_VACCINS[instance]->marque);
                    instance += 1;
                    printf("Voici le(s) %d vaccin(s) initialise(s) : \n", instance);
                    for (int i=0; i<instance; i++) {
                        printf("[%s]\t",GESTION_VACCINS[i]->marque);
                    }
                }
            break;

            case '2' :
                printf("Veuillez entrer la marque du vaccin.\n");
                scanf("%s", marqueV);
                t_vaccin_elt* vaccin = rechercheTableau(marqueV, GESTION_VACCINS);
                if (vaccin==NULL)
                    break;
                else{
                    printf("Veuillez entrer la ville dans laquelle ajouter le stock.\n");
                    scanf("%124s", ville);
                    printf("Veuillez entrer le numero de la semaine dans laquelle ajouter le stock.\n");
                    scanf("%d", &semaine);
                    printf("Veuillez entrer le nombre de vaccins a ajouter au stock.\n");
                    scanf("%d", &quantite);
                    vaccin->villes_dispo=ajouterVaccinV(vaccin->villes_dispo, ville, semaine, quantite);
                    break;
                }

            case '3' :
                // TODO : menu 3
            break;

            case '4' :
                printf("Veuillez entrer la marque du vaccin.\n");
                scanf("%s", marqueV);
                printf("\n");
                vaccin = rechercheTableau(marqueV, GESTION_VACCINS);
                if (vaccin==NULL)
                    break;
                else {
                    afficherStock(vaccin);
                    break;
                }

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
            viderBuffer();

        }
        return 0;
    }
