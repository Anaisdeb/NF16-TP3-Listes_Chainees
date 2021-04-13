#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

    nouvelleVille->nom_ville = strdup(ville); // strdup est important pour copier le nom et non attribuer le pointeur !
    nouvelleVille->suivant = NULL;
    nouvelleVille->semaines_planifiees = NULL;
    nouvelleVille->nombre_vaccins_total = 0;

    return nouvelleVille;
}



/* ========== CREER VACCIN ========== */
t_vaccin_elt *creerVaccin(char *marque){
    t_vaccin_elt *nouveauVaccin = malloc(sizeof(t_vaccin_elt));
    if (nouveauVaccin == NULL) {exit(EXIT_FAILURE);}

    nouveauVaccin->marque = strdup(marque); // strdup !!
    nouveauVaccin->villes_dispo = NULL;

    return nouveauVaccin;
}



/* ========== AJOUT SEMAINE DANS LISTE SEMAINES ========== */
t_semaine_elt *ajouterSemaine (t_semaine_elt *liste, t_semaine_elt *semaine){

    ///ERREUR
    /*if (testSemaine(semaine->numero_semaine, semaine->nombre_vaccins) == 0){
        {exit(EXIT_FAILURE);}
    }
    else {*/
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
    //}
}

/* ========== AJOUT VILLE DANS LISTE VILLES ========== */
t_ville_elt *ajouterVille (t_ville_elt *liste, t_ville_elt *ville, t_semaine_elt *l_semaine) {

    // Ajouter en tête de liste. Si liste vide on crée une nouvelle liste.
    ville -> suivant = liste;
    ville -> semaines_planifiees = l_semaine;
    liste = ville; // nouvelle tête de liste
    printf("\nLa ville %s est ajoutee.\n", liste->nom_ville);
    /// ERREUR ICI
    //return trierVilles(liste);
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
    return liste;
}


/* ========== AJOUT NB VACCIN DANS LISTE SEMAINES ========== */
t_semaine_elt *ajouterVaccinS(t_semaine_elt *liste, int semaine, int nb_vaccins){

    /*if (testSemaine(semaine, nb_vaccins) == 0){
        {exit(EXIT_FAILURE);}
    }
    else {*/
        t_semaine_elt *header = liste;
        // Si la liste chaînée actuelle est vide, alors l'en-tête de la liste chaînée est remplacée par le nouvel élément semaine.
        if (header == NULL){
            return creerSemaine(semaine, nb_vaccins);
        }
        // On s'arrête quand on a trouvé ou quand le numéro de la semaine à chercher devient inférieur à numero_semaine car c'est ordonné donc impossible de trouver dans les prochaines itérations.
        while (header->numero_semaine!=semaine  && header->numero_semaine < semaine && header->suivant!=NULL) { // header->suivant et non header !
               header=header->suivant;
        }
        if (header->numero_semaine == semaine)
            header->nombre_vaccins += nb_vaccins;
        else {
          liste=ajouterSemaine(liste, creerSemaine(semaine, nb_vaccins));
        }
    //}
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

    if (liste == NULL){
        liste = ajouterVille(liste, creerVille(ville), creerSemaine(semaine, nb_vaccins));
        return liste;
    }
    t_ville_elt *header = liste;
    while (header!=NULL && strcmp(header->nom_ville,ville)!=0 ){ // strcmp permet de comparer deux chaînes de caractères
        header=header->suivant;
    }
    if (header == NULL){ // On crée la ville
        liste = ajouterVille(liste, creerVille(ville), creerSemaine(semaine, nb_vaccins));
        return liste;
    }
    else {
        header->semaines_planifiees = ajouterVaccinS(header->semaines_planifiees, semaine, nb_vaccins); // Ne pas oublier de récupérer l'élément renvoyé
    }
    return liste;
    /// ERREUR ICI
    //return trierVilles(liste);
}


// TRIER LISTE DE COMMUNES EN FONCTION DU NOMBRE TOTAL DE VACCINS
t_ville_elt* trierVilles (t_ville_elt *liste){
    t_ville_elt *headerV = liste;
    // CALCULER NB TOTAL DE VACCINS
    while (headerV!=NULL){
        t_semaine_elt *headerS = headerV->semaines_planifiees;
        while (headerS!=NULL){
            headerV->nombre_vaccins_total += headerS->nombre_vaccins;
            headerS=headerS->suivant;
        }
    }
    // RANGER LES VILLES DANS L'ORDRE CROISSANT DU NB TOTAL DE VACCINS
   t_ville_elt *temp1 = malloc(sizeof(t_ville_elt));
   t_ville_elt *temp2 = malloc(sizeof(t_ville_elt));
   int min;
   char *ville;
   t_semaine_elt *semaine;
   t_ville_elt *suivant;

   for(headerV=liste ; headerV!=NULL ; headerV=headerV->suivant)
   {
     temp2=headerV; // On sauvegarde la ville courante
     min=headerV->nombre_vaccins_total; // On attribue à min le nb total de vaccins de la ville courante
     // On cherche le minimum parmi tous les éléments suivant de la liste
     for(temp1=headerV->suivant ; temp1!=NULL ; temp1=temp1->suivant)
     {
        if(min > temp1->nombre_vaccins_total) // Si un élément suivant est inférieur à la l'élément courant
        {
           temp2=temp1; // Le 3e temporaire est l'adresse de l'élement où se trouve le minimum
           min=temp2->nombre_vaccins_total;
           ville=temp2->nom_ville;
           semaine=temp2->semaines_planifiees;
           suivant = temp2->suivant;
        }
     }
     // Echange des 2 villes
     // Echange du nombre de vaccins total
     temp2->nombre_vaccins_total=headerV->nombre_vaccins_total;
     headerV->nombre_vaccins_total=min;
     // Echange du nom de la ville
     temp2->nom_ville = headerV->nom_ville;
     headerV->nom_ville = ville;
     // Echange des semaines
     temp2->semaines_planifiees=headerV->semaines_planifiees;
     headerV->semaines_planifiees=semaine;
     // Echange de l'élément suivant
     temp2->suivant=headerV->suivant;
     headerV->suivant=suivant;
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
    return liste;
    //return trierVilles(liste);
}

/* ========== AFFICHER STOCK D'UN VACCIN ========== */
void afficherStock(t_vaccin_elt *vaccin){
    t_ville_elt *headerV = vaccin->villes_dispo;
    printf("%s : \n", vaccin->marque);
    while (headerV!=NULL){
        printf(" --- %s [Total = %d] \n", headerV->nom_ville, headerV->nombre_vaccins_total);
        t_semaine_elt *headerS = headerV->semaines_planifiees;
        while (headerS!=NULL){
            printf("\t --- semaine %d : %d \n", headerS->numero_semaine, headerS->nombre_vaccins);
            headerS=headerS->suivant;
        }
        headerV=headerV->suivant;
    }
}


/* ========== AFFICHER STOCK PLANIFIE D'UN VACCIN POUR UNE SEMAINE ========== */
void afficherPlanification(t_vaccin_elt *vaccin, int semaine){
    t_ville_elt *headerV = vaccin->villes_dispo;
    printf("%s : \n", vaccin->marque);
    printf(" --- semaine %d \n", semaine);
    while (headerV!=NULL){
        t_semaine_elt *headerS = headerV->semaines_planifiees;
        while (headerS!=NULL){
            if(headerS->numero_semaine==semaine) {
                printf("\t --- %s : %d \n", headerV->nom_ville, headerS->nombre_vaccins);
            }
            headerS=headerS->suivant;
        }
        headerV=headerV->suivant;
    }
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



t_vaccin_elt *rechercheTableau(char *marqueV, t_vaccin_elt *GESTION_VACCINS[10], int instance){
    int i = 0;
    while (i < instance-1 && strcmp(marqueV,GESTION_VACCINS[i]->marque)!=0) { // * car on compare les valeurs pointées !
      i++;
    }
    if (strcmp(marqueV,GESTION_VACCINS[i]->marque)==0) {
      return GESTION_VACCINS[i];
    }
    else {
      printf("Vaccin non trouve. Veuillez le creer.");
      return NULL;
    }
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



void desallouerVaccin (t_vaccin_elt**ElementSup) {
    free ((*ElementSup)->marque);
    free ((*ElementSup)->villes_dispo);
    free (*ElementSup);
}



void desallouerVille (t_ville_elt**ElementSup) {
    free ((*ElementSup)->nom_ville);
    free ((*ElementSup)->semaines_planifiees);
    free (*ElementSup);
}



void desallouerSemaine (t_semaine_elt**ElementSup) {
    free (*ElementSup);
}



void desallouerListeVaccin (t_vaccin_elt**GESTION_VACCINS, int instance) {
    for (int i=0; i<instance; i++){
        desallouerListeVille(&GESTION_VACCINS[i]->villes_dispo);
        desallouerVaccin(&GESTION_VACCINS[i]);
    }
    free(GESTION_VACCINS);
    GESTION_VACCINS=NULL;
}



void desallouerListeVille (t_ville_elt**ElementPrem) {
    t_ville_elt *n;
    while(*ElementPrem!=NULL){
        desallouerListeSem(&(*ElementPrem)->semaines_planifiees);
        n=*ElementPrem;
        *ElementPrem=(*ElementPrem)->suivant;
        desallouerVille(&n);
    }
    *ElementPrem=NULL;
}



void desallouerListeSem (t_semaine_elt**ElementPrem) {
    t_semaine_elt *n;
    while(*ElementPrem!=NULL){
        n=*ElementPrem;
        *ElementPrem=(*ElementPrem)->suivant;
        desallouerSemaine(&n);
    }
    *ElementPrem=NULL;
}

