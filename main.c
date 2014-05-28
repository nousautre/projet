// PROJET
// Marc-Étienne Leblanc
// Gabriel Poulin

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct {
                double ptX;
                double ptY;
 }coordonee;


// cette procédure ( qui ne renvoie rien) lis le nombre de point total attendu
void nombrePointTotal(int * NOMBREDEPOINTTOTAL){
 scanf("%d", &*NOMBREDEPOINTTOTAL);
}

// cette procédure ( qui ne renvoie rien) lis la coordonée actuelle
// verifier si lutilisateur entre plein despace consécutive

void coordoneePointXYActuel(double * pointXActuel, double * pointYActuel){
 scanf("%lf", &*pointXActuel);
 scanf("%lf", &*pointYActuel);
 printf( "Coordone X: %lf\n", *pointXActuel); // SERA RETIRER
 printf( "Coordone Y: %lf\n", *pointYActuel); // SERA RETIRER
}

// cette procédure construit le tableau des coordonnée a l'aide de la fonction de lecture de point coordonePointXYActuel 
// principale fonctionnalité est de construire le tableau de base des donnée recu au clavier
void construitTableauCoordoneePointXY(const int NOMBREDEPOINTTOTAL, coordonee tableauCoordoneePointXY[]){
    double pointXActuel=0;
    double pointYActuel=0;
    int i=0;
    for (i;i<NOMBREDEPOINTTOTAL;++i){
       coordoneePointXYActuel(&pointXActuel,&pointYActuel);
       tableauCoordoneePointXY[i].ptX = pointXActuel; // pour l'instant ce n'est pas un tableau de structure alors je ne garde que le x
       tableauCoordoneePointXY[i].ptY = pointYActuel;
    }   
}

//cette procedure affiche le tableau creer à la base
void afficheTableauCoordoneePointXY(const int NOMBREDEPOINTTOTAL, coordonee tableauCoordoneePointXY[]){
    int i = 0;
    for (i;i<NOMBREDEPOINTTOTAL;++i){
         printf( "Tableau espace  le X vaut: %lf \n",tableauCoordoneePointXY[i].ptX);  
         printf( "Tableau espace  le Y vaut: %lf \n",tableauCoordoneePointXY[i].ptY);
    }   
}

// cette fonction calcule la pente entre deux points
// y du pointA - y du pointB / x du pointA - x du pointB 
// tout ca dans l'absolu
double calculDelaPente(coordonee pointA, coordonee pointB){
        return (pointA.ptY-pointB.ptY)/(pointA.ptX-pointB.ptX);
}

// Construit le tableau de pente de chacun des points
// Le calcul s'effectue sur NOMBREDEPOINTTOTAL -1 car le dernier point n'a pas de suivant
void construitTableauDePente(const int NOMBREDEPOINTTOTAL, coordonee tableauCoordoneePointXY[], double tableauDePente[]){
int i = 0;
    for (i;i<NOMBREDEPOINTTOTAL-1;++i){
         tableauDePente[i] = calculDelaPente(tableauCoordoneePointXY[i],tableauCoordoneePointXY[i+1]);
    }
}

//cette procedure affiche le tableau de pente
void afficheTableauDePente(const int NOMBREDEPOINTTOTAL,double tableauDePente[]){
    int i = 0;
    for (i;i<NOMBREDEPOINTTOTAL-1;++i){
         printf( "\nTableau espace la pente vaut: %lf \n",tableauDePente[i]);  
    }   
}

// cette procédure calcule et renvoie artan d'un angle
double calculDeLArcTan(double pente){
   return  atan(pente);
}

// Construit le tableau de ArcTan de chacun des points
// Le calcul s'effectue sur NOMBREDEPOINTTOTAL -1 car le dernier point n'a pas de suivant
void construitTableauDeLArcTan(const int NOMBREDEPOINTTOTAL, double tableauDePente[], double tableauDeArcTan[]){
int i = 0;
    for (i;i<NOMBREDEPOINTTOTAL-1;++i){
         tableauDeArcTan[i] = calculDeLArcTan(tableauDePente[i]);
    }
}

//cette procedure affiche le tableau de ArcTan
void afficheTableauDeLArcTan(const int NOMBREDEPOINTTOTAL,double tableauDeArcTan[]){
    int i = 0;
    for (i;i<NOMBREDEPOINTTOTAL-1;++i){
         printf( "\nARCTAN vaut: %lf \n",tableauDeArcTan[i]);  
    }   
}

// OK CETTE FONCTION JE NE SUIS PAS SUR SI CA DOIT TOUJOURS ETRE UN RESULTAT x1 - x2
// ca adonnait drole dans cest exemple
// return ai+1 - ai
double calculDifferenceAngle(double angleAIplus1, double angleAI){
   return angleAIplus1 - angleAI;
}

void construitTableauDifferenceAngle(const int NOMBREDEPOINTTOTAL,double tableauDeArcTan[], double tableauDifferenceAngle[]){
int i = 0;
    for (i;i<NOMBREDEPOINTTOTAL-2;++i){
         tableauDifferenceAngle[i] = calculDifferenceAngle(tableauDeArcTan[i+1],tableauDeArcTan[i]);
    }
}

//cette procedure affiche le tableau de ArcTan
void afficheTableauDifferenceAngle(const int NOMBREDEPOINTTOTAL,double tableauDifferenceAngle[]){
    int i = 0;
    for (i;i<NOMBREDEPOINTTOTAL-2;++i){
         printf( "\nTableauDiffAngle vaut: %lf \n",tableauDifferenceAngle[i]);  
    }   
}
// verifier pointAConserverArgument1 = 0  verifier pointAConserverArgument1 = 1 verifier pointAConserverArgument1 = 2

int calculPourcentagePointConserver(int NOMBREDEPOINTTOTAL, int pointAConserverArgument1){
    return ((NOMBREDEPOINTTOTAL * pointAConserverArgument1)/100);    
}

void sortieErreur(){
  fprintf( stderr, "L'argument donne n'est pas valide, veuillez entrez un seul chiffre entre 1 et 100." );
  exit(-1);
}

void validationArgumentV(int pointAConserverArgument1){
     if ((pointAConserverArgument1 < 0)||(pointAConserverArgument1>100)){
         sortieErreur();
    }
}
void validationArgumentC(int argc){
     if (argc != 2){
        sortieErreur();
    }
}

// La fonction main ( retourne 0 lorsque bien complété)
// lis le nombre de point total au clavier
// lis la première coordonée entre
int main(int argc, char ** argv){
    validationArgumentC(argc);
    int pointAConserverArgument = atoi(argv[1]);
    validationArgumentV(pointAConserverArgument);
    printf( "\nCONSERVER => : %i \n", pointAConserverArgument); //sera Retirer 
       
    int NOMBREDEPOINTTOTAL; // a verifier aupres de l'enseignant si cest valide de declarer et dassigner apres la valeur de la constante....
    printf( "BIENVENUE \n"); // SERA RETIRER
    nombrePointTotal(&NOMBREDEPOINTTOTAL);
    int pointConserver = calculPourcentagePointConserver(NOMBREDEPOINTTOTAL, pointAConserverArgument);
    printf( "pointConserver:%i  \n",pointConserver);
    
    
    coordonee tableauCoordoneePointXY[NOMBREDEPOINTTOTAL]; // combien de point total par defaut en assignant une valeur non dynamique?? création de tableau non dynamique
    double tableauDePente[NOMBREDEPOINTTOTAL-1];
    double tableauDeArcTan[NOMBREDEPOINTTOTAL-1];
    double tableauDifferenceAngle[NOMBREDEPOINTTOTAL-1];
    
    printf( "\nTotal de point: %i\n", NOMBREDEPOINTTOTAL); // SERA RETIRER
    
    construitTableauCoordoneePointXY(NOMBREDEPOINTTOTAL,tableauCoordoneePointXY);// un tableau cest toujours passe en référence je crois
    afficheTableauCoordoneePointXY(NOMBREDEPOINTTOTAL,tableauCoordoneePointXY);

    construitTableauDePente(NOMBREDEPOINTTOTAL,tableauCoordoneePointXY,tableauDePente);// un tableau cest toujours passe en référence je crois
    afficheTableauDePente(NOMBREDEPOINTTOTAL,tableauDePente);
    
    construitTableauDeLArcTan(NOMBREDEPOINTTOTAL,tableauDePente,tableauDeArcTan);// un tableau cest toujours passe en référence je crois
    afficheTableauDeLArcTan(NOMBREDEPOINTTOTAL,tableauDeArcTan);
    
    construitTableauDifferenceAngle(NOMBREDEPOINTTOTAL, tableauDeArcTan, tableauDifferenceAngle);// un tableau cest toujours passe en référence je crois
    afficheTableauDifferenceAngle(NOMBREDEPOINTTOTAL,tableauDifferenceAngle);
    
    
return 0;
}

/*
 -4.5 2.0   -4 3.0              =>  2
 -4 3.0     -3.5 4.0            =>  2
-3.5 4.0    -3 2.0              => -4
-3 2.0      -2.5 1              => -2
-2.5 1      -2 -40.4            => -82.800000
-2 -40.4    -1 12               =>  52.40
-1 12        3 -4.0423434       => -4.010586
3 -4.0423434 6 2.098            =>  2.046781
6 2.098      15 1.49            => -0.067556
15 1.49
 
 * 
 * 
 * 
5
-2 -0.5
-1 2.2
0 1.6 
1 1.8
2 1.0
 * 
 */