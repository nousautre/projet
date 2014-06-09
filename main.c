/**
 * INF3135 TP1
 * 
 * LEBM21097907, Leblanc, Marc-Etienne
 * POUG15087908, Poulin, Gabriel
 * 
 * Logiciel qui reduit le nombre de points decrivant une courbe.
 * Ce logiciel recois une liste de points (coordonnees cartesiennes) 
 * et enleve les points qui cause une perte d'information minimum.
 * 
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//#include <limits.h> 

/*
 * La structure de donnee contient ptX signifie point X de coordone de l'abscisse
 * Le ptY signifie point Y de coordonne de l'ordonne
 */

typedef struct {
    double ptX;
    double ptY;
} Coordonees;

/*
 * Les procedure dont le nom debute par sortie sont toutes appeler lors d'erreur
 */

/* Erreur argument errone*/
void sortieErreurArgument() {
    fprintf(stderr, "ERREUR: le pourcentage doit etre entre 1 et 100!\n");
    exit(-1);
}

/* Erreur dans l'ordre que les points X sont entre*/
void sortieErreurOrdre() {
    fprintf(stderr, "ERREUR: Les valeurs en x doivent etre donnees en ordre croissant!\n");
    exit(-1);
}

/* Erreur lors de la creation de tableau dynamique*/
void sortieErreurTableau() {
    fprintf(stderr, "ERREUR:La creation des tableaux a echouer.");
    exit(-1);
}

/* Erreur lors de la saisie du nombre de point entrer par l'utilisateur*/
void sortieErreurNombreDePoint() {
    fprintf(stderr, "ERREUR: Le nombre de points doit etre au minimum de 2!\n");
    exit(-1);
}

/*
 *  Les procedure qui debute par validation verifie que les donnes saisie ou generer
 *  sont valide ou acceptable pour le systeme
 */

/* La validation de l'argument lors du lancement par lutilisateur 
 * Elle recoit l'entree utilisateur du % associer au nombre de point conserver
 */
void validationArgumentV(const int pointAConserverArgument1) {
    if ((pointAConserverArgument1 < 1) || (pointAConserverArgument1 > 100)) {
        sortieErreurArgument();
    }
}

/* 
 * Recoit argC en argument.
 * La validation de l'argument lors du lancement par lutilisateur 
 * un seul argument est accepter le premier etant le programme lui-meme
 */
void validationArgumentC(const int argc) {
    if (argc != 2) {
        sortieErreurArgument();
    }
}

/*
 * La validation de l'argument nombre de coordonnee minimal ici nomme (nombreDePointTotal)
 * que le programme accepte est de 2.
 */
void validationNombrePointTotal(const int nombreDePointTotal) {
    if (nombreDePointTotal < 2) {
        sortieErreurNombreDePoint();
    }
}

/* 
 * Cette fonction renvoie le nombre total de point X,Y que l'utilisateur entre.
 * Elle lis un nombre et appel la validation de ce nombre
 */

int nombrePointTotal() {
    int nombreDePointTotal;
    scanf("%i", &nombreDePointTotal);
    validationNombrePointTotal(nombreDePointTotal);
    return nombreDePointTotal;
}

/* 
 * Cette procedure lis la coordonee actuellement entrer.
 */

void coordoneePointXYActuel(double * pointXActuel, double * pointYActuel) {
    scanf("%lf", &*pointXActuel);
    scanf("%lf", &*pointYActuel);
}

/* 
 * Cette procedure construit le tableau des coordonnee a l'aide
 *  de la fonction de lecture de point coordonePointXYActuel. 
 * principale fonctionnalite est de construire le tableau 
 * de coordonee des donnee recu au clavier jusqua un maximale de nombreDePointTotal
 */

void construitTableauCoordoneePointXY(const int nombreDePointTotal, Coordonees tableauCoordoneePointXY[]) {
    double pointXActuel = 0;
    double pointXPrecedent = 0;
    double pointYActuel = 0;
    int i = 0;
    for (i; i < nombreDePointTotal; ++i) {
        coordoneePointXYActuel(&pointXActuel, &pointYActuel);
        if ((pointXPrecedent > pointXActuel) && (i != 0)) {
            sortieErreurOrdre();
        }
        pointXPrecedent = pointXActuel;
        tableauCoordoneePointXY[i].ptX = pointXActuel;
        tableauCoordoneePointXY[i].ptY = pointYActuel;
    }
}

/* 
 * Cette procedure affiche le tableau de coordonees des points X et Y du tableau 
 * recu. Elle lis le tableau jusquau maximum de ce tableau soit
 *  nombreDePointTotal lautre argument recu
 */

void afficheTableauCoordoneePointXY(const int nombreDePointTotal, Coordonees tableauCoordoneePointXY[]) {
    int i = 0;
    for (i; i < nombreDePointTotal; ++i) {
        printf("%8f ", tableauCoordoneePointXY[i].ptX);
        printf("%8f\n", tableauCoordoneePointXY[i].ptY);
    }
}

/*
 * Cette fonction calcule et renvoie la pente entre deux points y 
 * du pointA - y du pointB / x du pointA - x du pointB 
 */

double calculDelaPente(const Coordonees pointA, const Coordonees pointB) {
    return (pointA.ptY - pointB.ptY) / (pointA.ptX - pointB.ptX);
}

/*
 * Construit le tableau de pente des points recu tableauCoordoneePointXY 
 * elle remplie le tableauDePente avec c'est pente calculer.
 * Le calcul s'effectue sur nombreDePointTotal -1 car le dernier 
 * point n'a pas de pente a calculer avec un suivant fictif.
 */

void construitTableauDePente(const int nombreDePointTotal, Coordonees tableauCoordoneePointXY[], double tableauDePente[]) {
    int i = 0;
    for (i; i < nombreDePointTotal - 1; ++i) {
        tableauDePente[i] = calculDelaPente(tableauCoordoneePointXY[i], tableauCoordoneePointXY[i + 1]);
    }
}

/*
 *  Cette procedure calcule et renvoie arc tangente d'un angle a partir d'un 
 * argument pente recu.
 */

double calculDeLArcTan(const double pente) {
    return atan(pente);
}

/*
 *  Construit le tableau de l'arctan des points recu tableauDePente 
 * elle remplie le tableauDeArcTan avec c'est arc Tangente calculer.
 * Le calcul s'effectue sur nombreDePointTotal -1 car le dernier 
 * point n'a pas de darctan a calculer avec un suivant fictif.
 */

void construitTableauDeLArcTan(const int nombreDePointTotal, double tableauDePente[], double tableauDeArcTan[]) {
    int i = 0;
    for (i; i < nombreDePointTotal - 1; ++i) {
        tableauDeArcTan[i] = calculDeLArcTan(tableauDePente[i]);
    }
}

/*
 * Cette fonction retourne l'absolue de la difference entre les angles elle 
 * recoit et calcul la difference entre deux angles et renvoie le resultat
 */
double calculDifferenceAngle(const double angleAIplus1, const double angleAI) {
    return (fabs(angleAIplus1 - angleAI));
}

/*
 *  Construit le tableau de la difference d'angle des points recu  du 
 * tableauDeArcTan. Elle remplie le tableauDifferenceAngle
 * Le calcul s'effectue sur nombreDePointTotal -2 car le dernier 
 * point n'a pas de darctan a calculer avec un suivant fictif et le premier n'a
 * pas de precedent pour ce meme calcul
 */
void construitTableauDifferenceAngle(const int nombreDePointTotal, double tableauDeArcTan[], double tableauDifferenceAngle[]) {
    int i = 0;
    for (i; i < nombreDePointTotal - 2; ++i) {
        tableauDifferenceAngle[i] = calculDifferenceAngle(tableauDeArcTan[i + 1], tableauDeArcTan[i]);
    }
}

/*
 * Cette fonction renvoie le nombre de point que l'utilisateur desire conserver
 * Ce calcul est fait a partir de l'argument recu en parametre lors du lancement
 * ainsi que le nombre de coordonee entree.
 * 
 */

int calculNombreDePointConserver(const int nombreDePointTotal, const int pointAConserverArgument1) {
    return ((((double) nombreDePointTotal * (double) pointAConserverArgument1) / 100) + .5);
}

/*
 * Cette procedure retire du tableau de coordonees la coordonnees associer 
 * au plus petit angle calculer. Elle reecrer seulement a partir de ce nombre 
 * les points dans le tableau qui le suive ainsi il y a un gain de rapidite.
 *  
 */
void retraitDuTableauCoordoneesXY(const int nombreDePointTotal, const int indiceDuPlusPetitDansDifferenceAngle, Coordonees tableauCoordoneePointXY[]) {
    int i = indiceDuPlusPetitDansDifferenceAngle + 1;
    int j = i + 1;
    for (i; i < nombreDePointTotal; ++i) {
        tableauCoordoneePointXY[i].ptX = tableauCoordoneePointXY[j].ptX;
        tableauCoordoneePointXY[i].ptY = tableauCoordoneePointXY[j].ptY;
        ++j;
    }
}

/* 
 * MAIN 
 * La fonction main ( retourne 0 lorsque bien complete)
 * Appel les routines de validations des arguments passe
 * Creer les tableaux qui retiennent l'information
 */

int main(int argc, char ** argv) {
    validationArgumentC(argc);
    int pointAConserverArgument = atoi(argv[1]);
    validationArgumentV(pointAConserverArgument);

    int nombreDePointTotal = nombrePointTotal();
    int pointConserver = (calculNombreDePointConserver(nombreDePointTotal, pointAConserverArgument));
    pointConserver < 2 ? pointConserver : 2;

    /*creation des tableaux */

    Coordonees * tableauCoordoneePointXY = malloc(sizeof (Coordonees) * nombreDePointTotal);
    if (tableauCoordoneePointXY == 0) {
        sortieErreurTableau();
    }
    double * tableauDePente = malloc(sizeof (double) *(nombreDePointTotal - 1));
    if (tableauDePente == 0) {
        sortieErreurTableau();
    }
    double * tableauDeArcTan = malloc(sizeof (double) *(nombreDePointTotal - 1));
    if (tableauDeArcTan == 0) {
        sortieErreurTableau();
    }
    double * tableauDifferenceAngle = malloc(sizeof (double) *(nombreDePointTotal - 1));
    if (tableauDifferenceAngle == 0) {
        sortieErreurTableau();
    }

    construitTableauCoordoneePointXY(nombreDePointTotal, tableauCoordoneePointXY);
    construitTableauDePente(nombreDePointTotal, tableauCoordoneePointXY, tableauDePente);
    construitTableauDeLArcTan(nombreDePointTotal, tableauDePente, tableauDeArcTan);
    construitTableauDifferenceAngle(nombreDePointTotal, tableauDeArcTan, tableauDifferenceAngle);

    if (pointConserver != pointAConserverArgument) {
        int nombreDePointASupprimer = nombreDePointTotal - pointConserver;
        int i = 1;
        for (i; i <= nombreDePointASupprimer; ++i) {
            double lePlusPetitDansDifferenceAngle = tableauDifferenceAngle[0] + 1;
            int indiceDuPlusPetitDansDifferenceAngle = 0;
            int j = 0;
            /* -2 car indice d'un tableau debute a 0 et le calcul entre deux points renvoie n-1 point a la fin. */
            for (j; j < nombreDePointTotal - 2; ++j) {
                if (tableauDifferenceAngle[j] < lePlusPetitDansDifferenceAngle) {
                    lePlusPetitDansDifferenceAngle = tableauDifferenceAngle[j];
                    indiceDuPlusPetitDansDifferenceAngle = j;
                }
            }
            retraitDuTableauCoordoneesXY(nombreDePointTotal, indiceDuPlusPetitDansDifferenceAngle, tableauCoordoneePointXY);
            nombreDePointTotal--;
            construitTableauDePente(nombreDePointTotal, tableauCoordoneePointXY, tableauDePente);
            construitTableauDeLArcTan(nombreDePointTotal, tableauDePente, tableauDeArcTan);
            construitTableauDifferenceAngle(nombreDePointTotal, tableauDeArcTan, tableauDifferenceAngle);
        }
    }
    printf("\n%i\n", pointConserver);
    afficheTableauCoordoneePointXY(nombreDePointTotal, tableauCoordoneePointXY);
    return 0;
}
