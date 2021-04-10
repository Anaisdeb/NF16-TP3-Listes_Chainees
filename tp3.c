#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

    if (testSemaine(semaine->numero_semaine, semaine->nombre_vaccins) == 0){
        {exit(EXIT_FAILURE);}
    }
    else {
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
}

/* ========== AJOUT VILLE DANS LISTE VILLES ========== */
t_ville_elt *ajouterVille (t_ville_elt *liste, t_ville_elt *ville, t_semaine_elt *l_semaine) {

    /// A FAIRE : insérer puis trier
    return liste;
}


/* ========== SUPPRIMER SEMAINE DANS LISTE SEMAINES ========== */
t_semaine_elt *supprimerSemaine (t_semaine_elt *liste, int semaine){

    if (testSemaine(semaine, 0) == 0){
        {exit(EXIT_FAILURE);}
    }
    else {
        t_semaine_elt *header = liste;
        if (liste == NULL){
            printf("La liste de semaines est vide");
            return liste;
        }
        if (liste->numero_semaine==semaine){ // si on supprime le premier élément de la liste
                header = liste;
                liste = liste->suivant;
                free(header);
            }
            else {
                t_semaine_elt *parent = liste;
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


/* ========== SUPPRIMER VILLE DANS LISTE VILLES ========== */
t_ville_elt *supprimerVille (t_ville_elt *liste, char* ville){
    /// A FAIRE
}


/* ========== AJOUT NB VACCIN DANS LISTE SEMAINES ========== */
t_semaine_elt *ajouterVaccinS(t_semaine_elt *liste, int semaine, int nb_vaccins){

    if (testSemaine(semaine, nb_vaccins) == 0){
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
    if (testSemaine(semaine, nb_vaccins) == 0){
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
            if (header->nombre_vaccins < nb_vaccins)
                printf("Impossible. Veuillez saisir un nombre de vaccins inferieur ou egal au nombre disponible : %d", header->nombre_vaccins);
            header->nombre_vaccins -= nb_vaccins;
            if (header->nombre_vaccins == 0)
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

    while (liste->suivant!=NULL && liste->nom_ville!=ville){
        liste=liste->suivant;
    }

    if (liste == NULL){
        liste = ajouterVille(creerVille(ville), liste, creerSemaine(semaine, nb_vaccins));
        return liste;
    }
    else {
        ajouterVaccinS(liste->semaines_planifiees, semaine, nb_vaccins);
    }
    return trierVilles(liste);
}


// TRIER LISTE DE COMMUNES EN FONCTION DU NOMBRE TOTAL DE VACCINS
// CALCULER NB TOTAL VACCIN
t_ville_elt* trierVilles (t_ville_elt *liste){
    t_ville_elt *headerV = liste;
    int max=0;
    while (headerV!=NULL){
        t_semaine_elt *headerS = headerV->semaines_planifiees;
        while (headerS!=NULL){
            headerV->nombre_vaccins_total += headerS->nombre_vaccins;
            headerS=headerS->suivant;
        }
        if (headerV->nombre_vaccins_total<max){
            // Décalage de la ville vers la gauche

            ///A FAIRE

        }
        else {
            max = headerV->nombre_vaccins_total;
        }
        headerV=headerV->suivant;
    }

    return liste;
}


/* ========== RETRAIT NB VACCIN DE LISTE VILLES ========== */
t_ville_elt *deduireVaccinV(t_ville_elt *liste, char* ville, int semaine, int nb_vaccins){
    t_ville_elt *header = liste;
    if (liste == NULL){
        printf("La liste de villes est vide");
        return liste;
    }
    while (header->nom_ville!=ville && header->suivant!=NULL){
        header=header->suivant;
    }

    if (header->nom_ville == ville){
        if(header->nombre_vaccins_total < nb_vaccins){
            printf("Impossible. Veuillez saisir un nombre de vaccins inferieur ou egal au nombre total disponible : %d", header->nombre_vaccins_total);
            deduireVaccinS(liste->semaines_planifiees, semaine, nb_vaccins);
        }
        // Cas où la ville n'a plus de vaccins
        if (header->nombre_vaccins_total == 0)
            liste = supprimerVille(liste, ville);
    }
    else {
        printf("La ville n'existe pas.");
        return liste;
    }
    return trierVilles(liste);
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

bool testSemaine (int semaine, int nb_vaccins){
    if ((semaine<1 && semaine>53) && (nb_vaccins <0)) {
        printf("Le nombre de semaines doit être compris entre 1 et 53 !");
        printf("Le nombre de vaccins doit être strictement positif !");
        return 1;
    }
    else
        return 0;
}

