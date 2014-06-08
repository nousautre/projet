// PROJET
// Marc-etienne Leblanc
// Gabriel Poulin

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// pour LONG_MAX
#include <limits.h> 

// la structure de donnee contien ptX signifie point X de coordone de l'abscisse
//ptY signifie point Y de coordonné de l'ordonne
typedef struct {
    double ptX;
    double ptY;
} coordonee;

void sortieErreur() {
    fprintf(stderr, "L'argument donne n'est pas valide, veuillez entrez un seul chiffre entre 1 et 100.");
    exit(-1);
}

void sortieErreurOrdre() {
    fprintf(stderr, "Veuillez entrez des coordonnees valides en ordre.");
    exit(-1);
}

void validationCoordonePointXY(double * pointXActuel, double * pointYActuel) {
    if ((*pointXActuel < LONG_MIN) || (*pointYActuel < LONG_MIN) ||
            (*pointXActuel > LONG_MAX) || (*pointYActuel > LONG_MAX)) {
        fprintf(stderr, "Veuillez entrez des coordonnees valides.");
        exit(-1);
    }
}

void validationArgumentV(int pointAConserverArgument1) {
    if ((pointAConserverArgument1 < 1) || (pointAConserverArgument1 > 100)) {
        sortieErreur();
    }
}

void validationArgumentC(int argc) {
    if (argc != 2) {
        sortieErreur();
    }
}
// Le nombre de coordonnee minimal que le programme accepte est de 2
void validationNombrePointTotal(const int nombreDePointTotal) {
    if (nombreDePointTotal < 2) {
        fprintf(stderr, "Veuillez entrez un seul chiffre a partir de 2 et plus");
        exit(-1);
    }
}

// Cette fonction renvoie le nombre total de point X,Y que l'utilisateur entre.
// Elle lis un nombre et appel la validation de ce nombre

int nombrePointTotal() {
    int NOMBREDEPOINTTOTAL;
    scanf("%i", &NOMBREDEPOINTTOTAL);
    validationNombrePointTotal(NOMBREDEPOINTTOTAL);
    return NOMBREDEPOINTTOTAL;
}

// Cette procedure lis la coordonee actuellement entrer.

void coordoneePointXYActuel(double * pointXActuel, double * pointYActuel) {
    scanf("%lf", &*pointXActuel);
    scanf("%lf", &*pointYActuel);
    //validationCoordonePointXY(pointXActuel, pointYActuel); pas besoin de verifier
}

// cette procedure construit le tableau des coordonnee a l'aide de la fonction de lecture de point coordonePointXYActuel 
// principale fonctionnalite est de construire le tableau de coordonee des donnee recu au clavier

void construitTableauCoordoneePointXY(const int NOMBREDEPOINTTOTAL, coordonee tableauCoordoneePointXY[]) {
    double pointXActuel = 0;
    double pointXPrecedent = LONG_MIN;
    double pointYActuel = 0;
    int i = 0;
    for (i; i < NOMBREDEPOINTTOTAL; ++i) {
        coordoneePointXYActuel(&pointXActuel, &pointYActuel);
        if (pointXPrecedent > pointXActuel) {
            sortieErreurOrdre();
        }
        pointXPrecedent = pointXActuel;
        tableauCoordoneePointXY[i].ptX = pointXActuel;
        tableauCoordoneePointXY[i].ptY = pointYActuel;
    }
}

//cette procedure affiche le tableau creer a la base

void afficheTableauCoordoneePointXY(const int NOMBREDEPOINTTOTAL, coordonee tableauCoordoneePointXY[]) {
    int i = 0;
    for (i; i < NOMBREDEPOINTTOTAL; ++i) {
        printf("%8f ", tableauCoordoneePointXY[i].ptX);
        printf("%8f\n", tableauCoordoneePointXY[i].ptY);
    }
}

// cette fonction calcule la pente entre deux points
// y du pointA - y du pointB / x du pointA - x du pointB 

double calculDelaPente(coordonee pointA, coordonee pointB) {
    return (pointA.ptY - pointB.ptY) / (pointA.ptX - pointB.ptX);
}

// Construit le tableau de pente de chacun des points
// Le calcul s'effectue sur NOMBREDEPOINTTOTAL -1 car le dernier point n'a pas de suivant

void construitTableauDePente(const int NOMBREDEPOINTTOTAL, coordonee tableauCoordoneePointXY[], double tableauDePente[]) {
    int i = 0;
    for (i; i < NOMBREDEPOINTTOTAL - 1; ++i) {
        tableauDePente[i] = calculDelaPente(tableauCoordoneePointXY[i], tableauCoordoneePointXY[i + 1]);
    }
}

//cette procedure affiche le tableau de pente

void afficheTableauDePente(const int NOMBREDEPOINTTOTAL, double tableauDePente[]) {
    int i = 0;
    for (i; i < NOMBREDEPOINTTOTAL - 1; ++i) {
        printf("Tableau espace la pente vaut: %lf\n", tableauDePente[i]);
    }
    printf("\n*****************************************\n");
}

// cette procedure calcule et renvoie arc tangente d'un angle

double calculDeLArcTan(double pente) {
    return atan(pente);
}

// Construit le tableau de ArcTan de chacun des points
// Le calcul s'effectue sur NOMBREDEPOINTTOTAL -1 car le dernier point n'a pas de suivant

void construitTableauDeLArcTan(const int NOMBREDEPOINTTOTAL, double tableauDePente[], double tableauDeArcTan[]) {
    int i = 0;
    for (i; i < NOMBREDEPOINTTOTAL - 1; ++i) {
        tableauDeArcTan[i] = calculDeLArcTan(tableauDePente[i]);
    }
}

//cette procedure affiche le tableau de ArcTan

void afficheTableauDeLArcTan(const int NOMBREDEPOINTTOTAL, double tableauDeArcTan[]) {
    int i = 0;
    for (i; i < NOMBREDEPOINTTOTAL - 1; ++i) {
        printf("ARCTAN vaut: %lf\n ", tableauDeArcTan[i]);
    }
}

// OK CETTE FONCTION JE NE SUIS PAS SUR SI CA DOIT TOUJOURS ETRE UN RESULTAT x1 - x2
// ca adonnait drole dans cest exemple
// return ai+1 - ai

double calculDifferenceAngle(double angleAIplus1, double angleAI) {
    return (fabs(angleAIplus1 - angleAI));
}

void construitTableauDifferenceAngle(const int NOMBREDEPOINTTOTAL, double tableauDeArcTan[], double tableauDifferenceAngle[]) {
    int i = 0;
    for (i; i < NOMBREDEPOINTTOTAL - 2; ++i) {
        tableauDifferenceAngle[i] = calculDifferenceAngle(tableauDeArcTan[i + 1], tableauDeArcTan[i]);
    }
}

//cette procedure affiche le tableau de ArcTan

void afficheTableauDifferenceAngle(const int NOMBREDEPOINTTOTAL, double tableauDifferenceAngle[]) {
    int i = 0;
    for (i; i < NOMBREDEPOINTTOTAL - 2; ++i) {
        printf("TableauDiffAngle vaut: %lf \n", tableauDifferenceAngle[i]);
    }
}
// verifier pointAConserverArgument1 = 0  verifier pointAConserverArgument1 = 1 verifier pointAConserverArgument1 = 2

int calculNombreDePointConserver(int NOMBREDEPOINTTOTAL, int pointAConserverArgument1) {
    return ((((double) NOMBREDEPOINTTOTAL * (double) pointAConserverArgument1) / 100) + .5);
}

//remove tableauCoordoneePointXY[indiceDansLeTableauDuPlusPetit];
//remove differenceAngle[indiceDansLeTableauDuPlusPetit]
//calculer la difference angle entre le precedent et le suivant du remove
//le remettre dans le tableau 
// LE NOMBRE DE POINT TOTAL doit CHANGER !!!!

void moulinetteDuRetraitDuTableauCoordoneXY(int NOMBREDEPOINTTOTAL, int indiceDuPlusPetitDansDiff, coordonee tableauCoordoneePointXY[]) {
    int i = indiceDuPlusPetitDansDiff;
    int j = i + 1;
    for (i; i < NOMBREDEPOINTTOTAL; ++i) {
        tableauCoordoneePointXY[i].ptX = tableauCoordoneePointXY[j].ptX; // pour l'instant ce n'est pas un tableau de structure alors je ne garde que le x
        tableauCoordoneePointXY[i].ptY = tableauCoordoneePointXY[j].ptY;
        ++j;
    }
}

void retraitDuTableauCoordoneXY(int NOMBREDEPOINTTOTAL, int indiceDuPlusPetitDansDiff, coordonee tableauCoordoneePointXY[]) {
    int i = 0;
    int j = 0;
    for (j; j < NOMBREDEPOINTTOTAL; ++j) {
        if (i == indiceDuPlusPetitDansDiff + 1) {
            j = j + 1;
        }
        tableauCoordoneePointXY[i].ptX = tableauCoordoneePointXY[j].ptX; // pour l'instant ce n'est pas un tableau de structure alors je ne garde que le x
        tableauCoordoneePointXY[i].ptY = tableauCoordoneePointXY[j].ptY;
        ++i;
    }
}

// La fonction main ( retourne 0 lorsque bien complete)
// Appel les routines de validations des arguments passe
// creer les tableaux qui retiennent l'information

int main(int argc, char ** argv) {
    validationArgumentC(argc);
    int pointAConserverArgument = atoi(argv[1]);
    validationArgumentV(pointAConserverArgument);

    int nombreDePointTotal = nombrePointTotal();
    int pointConserver = (calculNombreDePointConserver(nombreDePointTotal, pointAConserverArgument));
    pointConserver < 2?pointConserver:2;
    
    //creation des tableaux 
    coordonee * tableauCoordoneePointXY = malloc(sizeof (coordonee) * nombreDePointTotal);
    double * tableauDePente = malloc(sizeof (double) *(nombreDePointTotal - 1));
    double * tableauDeArcTan = malloc(sizeof (double) *(nombreDePointTotal - 1));
    double * tableauDifferenceAngle = malloc(sizeof (double) *(nombreDePointTotal - 1));
    
    construitTableauCoordoneePointXY(nombreDePointTotal, tableauCoordoneePointXY); 
    construitTableauDePente(nombreDePointTotal, tableauCoordoneePointXY, tableauDePente); 
    construitTableauDeLArcTan(nombreDePointTotal, tableauDePente, tableauDeArcTan); 
    construitTableauDifferenceAngle(nombreDePointTotal, tableauDeArcTan, tableauDifferenceAngle); 
    
    if (pointConserver != pointAConserverArgument) {
        int nombreDePointASupprimer = nombreDePointTotal - pointConserver;
        int i = 1;
        for (i; i <= nombreDePointASupprimer; ++i) {
            double lePlusPetitDansDiff = LONG_MAX;
            int indiceDuPlusPetitDansDiff = INT_MAX;
            int j = 0;
            // -2 car indice d'un tableau debute a 0 et le calcul entre deux points renvoie n-1 point a la fin. 
            for (j; j < nombreDePointTotal - 2; ++j) {
                if (tableauDifferenceAngle[j] < lePlusPetitDansDiff) {
                    lePlusPetitDansDiff = tableauDifferenceAngle[j];
                    indiceDuPlusPetitDansDiff = j;
                }
            }
            retraitDuTableauCoordoneXY(nombreDePointTotal, indiceDuPlusPetitDansDiff, tableauCoordoneePointXY);
            nombreDePointTotal--; 
            construitTableauDePente(nombreDePointTotal, tableauCoordoneePointXY, tableauDePente);
            construitTableauDeLArcTan(nombreDePointTotal, tableauDePente, tableauDeArcTan); 
            construitTableauDifferenceAngle(nombreDePointTotal, tableauDeArcTan, tableauDifferenceAngle); 
        }
    }
    printf("\n%i\n", pointConserver);
    afficheTableauCoordoneePointXY(nombreDePointTotal, tableauCoordoneePointXY);
    free(tableauCoordoneePointXY);
    free(tableauDePente);
    free(tableauDeArcTan);
    free(tableauDifferenceAngle);
    return 0;
}

