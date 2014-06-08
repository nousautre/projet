// PROJET
// Marc-Étienne Leblanc
// Gabriel Poulin

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // pour LONG_MAX

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

// revoir LA SORTIE sa semble pas marcher

void validationCoordonePointXY(double * pointXActuel, double * pointYActuel) {
    if ((*pointXActuel < LONG_MIN) || (*pointYActuel < LONG_MIN) ||
            (*pointXActuel > LONG_MAX) || (*pointYActuel > LONG_MAX)) {
        fprintf(stderr, "Veuillez entrez des coordonnees valides");
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

void validationNombrePointTotal(const int NOMBREDEPOINTTOTAL) {
    if (NOMBREDEPOINTTOTAL < 2) {
        fprintf(stderr, "Veuillez entrez un seul chiffre à partir de 2 et plus");
        exit(-1);
    }
}

// Cette fonction renvoie le nombre total de point X,Y que l'utilisateur entrera
// Elle lis un nombre et appel validation pour s'assurer qu'un nombre valide est entre

int nombrePointTotal() {
    int NOMBREDEPOINTTOTAL;
    scanf("%i", &NOMBREDEPOINTTOTAL);
    validationNombrePointTotal(NOMBREDEPOINTTOTAL);
    return NOMBREDEPOINTTOTAL;
}

// Cette procédure (qui ne renvoie rien) lis la coordonée actuellement entrer.
// verifier si lutilisateur entre plein despace consécutive ou du garbarge
// VERIFIE SI %lf cest ce que ca prend pour le double

void coordoneePointXYActuel(double * pointXActuel, double * pointYActuel) {
    scanf("%lf", &*pointXActuel);
    scanf("%lf", &*pointYActuel);
    //validationCoordonePointXY(pointXActuel, pointYActuel); pas besoin de vérifier ca lair
}

// cette procédure construit le tableau des coordonnée a l'aide de la fonction de lecture de point coordonePointXYActuel 
// principale fonctionnalité est de construire le tableau de base des donnée recu au clavier

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
        tableauCoordoneePointXY[i].ptX = pointXActuel; // pour l'instant ce n'est pas un tableau de structure alors je ne garde que le x
        tableauCoordoneePointXY[i].ptY = pointYActuel;
    }
}

//cette procedure affiche le tableau creer à la base

void afficheTableauCoordoneePointXY(const int NOMBREDEPOINTTOTAL, coordonee tableauCoordoneePointXY[]) {
    int i = 0;
    for (i; i < NOMBREDEPOINTTOTAL; ++i) {
        printf("%8f ", tableauCoordoneePointXY[i].ptX);
        printf("%8f\n", tableauCoordoneePointXY[i].ptY);
    }
}

// cette fonction calcule la pente entre deux points
// y du pointA - y du pointB / x du pointA - x du pointB 
// tout ca dans l'absolu

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

// cette procédure calcule et renvoie artan d'un angle

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

// La fonction main ( retourne 0 lorsque bien complété)
// lis le nombre de point total au clavier
// lis la première coordonée entre

int main(int argc, char ** argv) {
    validationArgumentC(argc);
    int pointAConserverArgument = atoi(argv[1]);
    validationArgumentV(pointAConserverArgument);

    int NOMBREDEPOINTTOTAL = nombrePointTotal();
    int pointConserver = calculNombreDePointConserver(NOMBREDEPOINTTOTAL, pointAConserverArgument);
    if (pointConserver < 2) {
        pointConserver = 2;
    }
    coordonee * tableauCoordoneePointXY = malloc(sizeof (coordonee) * NOMBREDEPOINTTOTAL);
    double * tableauDePente = malloc(sizeof (double) *(NOMBREDEPOINTTOTAL - 1));
    double * tableauDeArcTan = malloc(sizeof (double) *(NOMBREDEPOINTTOTAL - 1));
    double * tableauDifferenceAngle = malloc(sizeof (double) *(NOMBREDEPOINTTOTAL - 1));
    construitTableauCoordoneePointXY(NOMBREDEPOINTTOTAL, tableauCoordoneePointXY); // un tableau cest toujours passe en référence je crois
    construitTableauDePente(NOMBREDEPOINTTOTAL, tableauCoordoneePointXY, tableauDePente); // un tableau cest toujours passe en référence je crois
    construitTableauDeLArcTan(NOMBREDEPOINTTOTAL, tableauDePente, tableauDeArcTan); // un tableau cest toujours passe en référence je crois
    construitTableauDifferenceAngle(NOMBREDEPOINTTOTAL, tableauDeArcTan, tableauDifferenceAngle); // un tableau cest toujours passe en référence je crois


    if (pointConserver != pointAConserverArgument) {
        int nombreDePointASupprimer = NOMBREDEPOINTTOTAL - pointConserver;
        int i = 1;
        for (i; i <= nombreDePointASupprimer; ++i) {
            double lePlusPetitDansDiff = LONG_MAX;
            int indiceDuPlusPetitDansDiff = INT_MAX;
            int j = 0;
            // -2 car indice d'un tableau debute a 0 et le calcul entre deux points renvoie n-1 point à la fin. 
            for (j; j < NOMBREDEPOINTTOTAL - 2; ++j) {
                if (tableauDifferenceAngle[j] < lePlusPetitDansDiff) {
                    lePlusPetitDansDiff = tableauDifferenceAngle[j];
                    indiceDuPlusPetitDansDiff = j;
                }
            }
            retraitDuTableauCoordoneXY(NOMBREDEPOINTTOTAL, indiceDuPlusPetitDansDiff, tableauCoordoneePointXY);
            NOMBREDEPOINTTOTAL--; //SUPRA IMPORTANT DE FAIRE CA 
            construitTableauDePente(NOMBREDEPOINTTOTAL, tableauCoordoneePointXY, tableauDePente); // un tableau cest toujours passe en référence je crois
            construitTableauDeLArcTan(NOMBREDEPOINTTOTAL, tableauDePente, tableauDeArcTan); // un tableau cest toujours passe en référence je crois
            construitTableauDifferenceAngle(NOMBREDEPOINTTOTAL, tableauDeArcTan, tableauDifferenceAngle); // un tableau cest toujours passe en référence je crois
        }
    }
    printf("\n%i\n", pointConserver);
    afficheTableauCoordoneePointXY(NOMBREDEPOINTTOTAL, tableauCoordoneePointXY);
    free(tableauCoordoneePointXY);
    free(tableauDePente);
    free(tableauDeArcTan);
    free(tableauDifferenceAngle);
    return 0;
}

