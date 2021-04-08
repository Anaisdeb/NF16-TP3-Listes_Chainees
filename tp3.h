#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED

/* ========== STRUCTURES ========== */
typedef unsigned int (Index_semaine);
typedef unsigned int (Index_vaccin);
typedef unsigned int (Index_vaccins_total);

typedef struct semaine_elt {
    Index_semaine numero_semaine;
    Index_vaccin nombre_vaccins;
    struct semaine_elt* suivant;
} t_semaine_elt;

typedef struct ville_elt {
    char* nom_ville;
    Index_vaccins_total nombre_vaccins_total;
    t_semaine_elt* semaines_planifiees;
    struct ville_elt* suivant;
} t_ville_elt;

typedef struct vaccin_elt {
    char* marque;
    t_ville_elt* villes_dispo;
} t_vaccin_elt;

/* ========== FONCTIONS ========== */
t_semaine_elt *creerSemaine(int num_semaine, int nb_vaccins);
t_ville_elt *creerVille(char *ville);
t_vaccin_elt *creerVaccin(char *marque);
t_semaine_elt *ajouterVaccinS(t_semaine_elt *liste, int semaine, int nb_vaccins);
t_semaine_elt *deduireVaccinS(t_semaine_elt *liste, int semaine, int nb_vaccins);
t_ville_elt *ajouterVaccinV(t_ville_elt *liste, char* ville, int semaine, int nb_vaccins);
t_ville_elt *deduireVaccinV(t_ville_elt *liste, char* ville, int semaine, int nb_vaccins);
void afficherStock(t_vaccin_elt *vaccin);
void afficherPlanification(t_vaccin_elt *vaccin, int semaine);
t_vaccin_elt *fusionnerStocks(t_vaccin_elt *vaccinA, t_vaccin_elt *vaccinB);

/* ------- UTILITAIRES ------------ */
void viderBuffer ();


#endif // TP3_H_INCLUDED
