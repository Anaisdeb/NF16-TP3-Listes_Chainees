#include <stdio.h>
#include <stdlib.h>
#include "tp3.h"

/* ========== CREER SEMAINE ========== */
t_semaine_elt *creerSemaine(int num_semaine, int nb_vaccins) {
    // Allouer de la mémoire pour la nouvelle semaine
    t_semaine_elt *nouvelleSemaine = malloc(sizeof(t_semaine_elt));
    // Si l'espace mémoire est insuffisant, un message d'erreur apparaît.
    if (nouvelleSemaine == NULL) {exit(EXIT_FAILURE);}

    else {
    nouvelleSemaine->nombre_vaccins = nb_vaccins;
    nouvelleSemaine->numero_semaine = num_semaine;
    nouvelleSemaine->suivant = NULL;
    }

    return nouvelleSemaine;
}



/* ========== CREER VILLE ========== */
t_ville_elt *creerVille(char *ville){
    t_ville_elt *nouvelleVille = malloc(sizeof(t_ville_elt));
    if (nouvelleVille == NULL) {exit(EXIT_FAILURE);}

    nouvelleVille->nom_ville = ville;
    nouvelleVille->suivant = NULL;

    return nouvelleVille;
}



/* ========== CREER VACCIN ========== */
t_vaccin_elt *creerVaccin(char *marque){
    t_vaccin_elt *nouveauVaccin = malloc(sizeof(t_vaccin_elt));
    if (nouveauVaccin == NULL) {exit(EXIT_FAILURE);}

    nouveauVaccin->marque = marque;

    return nouveauVaccin;
}

/* ========== AJOUT SEMAINE DANS LISTE SEMAINES ========== */
t_semaine_elt *ajouterSemaine (t_semaine_elt *liste, t_semaine_elt *semaine){

    if ((semaine->numero_semaine<1 && semaine->numero_semaine>53) && (semaine->nombre_vaccins <0)) {
        printf("Le nombre de semaines doit être compris entre 1 et 53 !");
        printf("Le nombre de vaccins doit être strictement positif !");
        {exit(EXIT_FAILURE);}
    }
    // si liste vide ou élément à ajouter en tête de liste
    if (liste == NULL || semaine->numero_semaine <= liste->numero_semaine){
        semaine->suivant = liste;
        liste = semaine; //nouvelle tête de liste
    }
    else { //sinon chercher la place précédente et insérer après
        t_semaine_elt* parent = liste;
        t_semaine_elt* header = liste;
        // Il faut trouver l'élément précédent l'élément à insérer
        // Donc la liste est parcourue tant que l'élément courant n'est pas NULL et que la valeur de l'élément à insérer est supérieure à la valeur de l'élément courant
        while (header!=NULL && semaine->numero_semaine > header->numero_semaine){
        // Il faut deux pointeurs : un pour l'élément courant et un pour l'élément précédent
            parent = header;
            header = header->suivant;
        }
        parent->suivant = semaine;
        semaine->suivant = header;
    }
    return liste;
}


/* ========== SUPPRIMER SEMAINE DANS LISTE SEMAINES ========== */
t_semaine_elt *supprimerSemaine (t_semaine_elt *liste, int semaine){

    if ((semaine<1 && semaine>53) && (nb_vaccins <0)) {
        printf("Le nombre de semaines doit être compris entre 1 et 53 !");
        printf("Le nombre de vaccins doit être strictement positif !");
        {exit(EXIT_FAILURE);}
    }

    else {
        t_semaine_elt *header = liste;
        if (liste == NULL){
            printf("La liste est vide");
            return liste;
        }
        if (liste->numero_semaine==semaine{ // si premier
                header = liste;
                liste = liste->suivant;
                free(header);
            }
            else {
                while (header->numero_semaine!=semaine && header->numero_semaine < semaine && header!=NULL) {
                       parent = header;
                       header = header->suivant;
                }
                if (header->numero_semaine == semaine){
                    parent->suivant = header->suivant;
                    free(header);
                    header = NULL;
                }
                else {
                        printf("La semaine n'existe pas");
                        return liste;
                }
            }
    }
    return liste;
}



/* ========== AJOUT NB VACCIN DANS LISTE SEMAINES ========== */
t_semaine_elt *ajouterVaccinS(t_semaine_elt *liste, int semaine, int nb_vaccins){

    if ((semaine<1 && semaine>53) && (nb_vaccins <0)) {
        printf("Le nombre de semaines doit être compris entre 1 et 53 !");
        printf("Le nombre de vaccins doit être strictement positif !");
        {exit(EXIT_FAILURE);}
    }
    else {
        t_semaine_elt *header = liste;
        // Si la liste chaînée actuelle est vide, alors l'en-tête de la liste chaînée est remplacée par le nouvel élément semaine.
        if (header == NULL){
            return creerSemaine(semaine, nb_vaccins);
        }
        // On s'arrête quand on a trouvé ou quand le numéro de la semaine à chercher devient inférieur à numero_semaine car c'est ordonné donc impossible de trouver dans les prochaines itérations.
        while (header->numero_semaine!=semaine && header->numero_semaine < semaine && header!=NULL) {
               header=header->suivant;
        }
        if (header->numero_semaine == semaine)
            header->nombre_vaccins += nb_vaccins;
        else
          ajouterSemaine(liste, creerSemaine(semaine, nb_vaccins));
    }
    return liste;
}




/* ========== RETRAIT NB VACCIN DE LISTE SEMAINES ========== */
t_semaine_elt *deduireVaccinS(t_semaine_elt *liste, int semaine, int nb_vaccins){
    if ((semaine<1 && semaine>53) && (nb_vaccins <0)) {
        printf("Le nombre de semaines doit être compris entre 1 et 53 !");
        printf("Le nombre de vaccins doit être strictement positif !");
        {exit(EXIT_FAILURE);}
    }
    else {
        t_semaine_elt *header = liste;
        if (liste == NULL){
            printf("La liste est vide");
            return liste;
        }
        while (header->numero_semaine!=semaine && header->numero_semaine < semaine && header!=NULL) {
               header=header->suivant;
        }
        if (header->numero_semaine == semaine)
            header->nombre_vaccins -= nb_vaccins;
            if (header->nombre_vaccins =< 0)
                supprimerSemaine(liste, semaine);
        else {
                printf("La semaine n'existe pas");
                return liste;
        }
    }
    return liste;
}



/* ========== AJOUT NB VACCIN DANS LISTE VILLES ========== */
t_ville_elt *ajouterVaccinV(t_ville_elt *liste, char* ville, int semaine, int nb_vaccins){
    return NULL;
    // TODO : ECRIRE ICI LE CODE DE CETTE FONCTION
}



/* ========== RETRAIT NB VACCIN DE LISTE VILLES ========== */
t_ville_elt *deduireVaccinV(t_ville_elt *liste, char* ville, int semaine, int nb_vaccins){
    return NULL;
    // TODO : ECRIRE ICI LE CODE DE CETTE FONCTION
}



/* ========== AFFICHER STOCK D'UN VACCIN ========== */
void afficherStock(t_vaccin_elt *vaccin){
    // TODO : ECRIRE ICI LE CODE DE CETTE FONCTION
}



/* ========== AFFICHER STOCK PLANIFIE D'UN VACCIN POUR UNE SEMAINE ========== */
void afficherPlanification(t_vaccin_elt *vaccin, int semaine){
    // TODO : ECRIRE ICI LE CODE DE CETTE FONCTION
}



/* ========== FUSION DEUX VACCINS ========== */
t_vaccin_elt *fusionnerStocks(t_vaccin_elt *vaccinA, t_vaccin_elt *vaccinB){
    return NULL;
    // TODO : ECRIRE ICI LE CODE DE CETTE FONCTION
}


/* ----------------------------------
 *   UTILITAIRES
 ---------------------------------- */
void viderBuffer (){
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
