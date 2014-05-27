// PROJET
// Marc-Étienne Leblanc
// Gabriel Poulin


#include <stdio.h>


typedef struct {
                double x;
                double y;
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
       tableauCoordoneePointXY[i].x = pointXActuel; // pour l'instant ce n'est pas un tableau de structure alors je ne garde que le x
       tableauCoordoneePointXY[i].y = pointYActuel;
    }   
}

//cette procedure affiche le tableau creer à la base
void afficheTableauCoordoneePointXY(const int NOMBREDEPOINTTOTAL, coordonee tableauCoordoneePointXY[]){
    int i = 0;
    for (i;i<NOMBREDEPOINTTOTAL;++i){
         printf( "Tableau espace  le X vaut: %lf \n",tableauCoordoneePointXY[i].x);  
         printf( "Tableau espace  le Y vaut: %lf \n",tableauCoordoneePointXY[i].y);
    }   
}

// cette fonction calcule la pente entre deux points
// y du pointA - y du pointB / x du pointA - x du pointB 
// tout ca dans l'absolu
double calculDelaPente(coordonee pointA, coordonee pointB){
        return (pointA.y-pointB.y)/(pointA.x-pointB.x);
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
         printf( "Tableau espace la pente vaut: %lf \n",tableauDePente[i]);  
    }   

}

// La fonction main ( retourne 0 lorsque bien complété)
// lis le nombre de point total au clavier
// lis la première coordonée entre
int main(int argc, char ** argv){
    const unsigned int NOMBREDEPOINTTOTAL; // a verifier aupres de l'enseignant si cest valide de declarer et dassigner apres la valeur de la constante....
    printf( "BIENVENUE \n"); // SERA RETIRER
    nombrePointTotal(&NOMBREDEPOINTTOTAL);
    
    coordonee tableauCoordoneePointXY[NOMBREDEPOINTTOTAL]; // combien de point total par defaut en assignant une valeur non dynamique?? création de tableau non dynamique
    double tableauDePente[NOMBREDEPOINTTOTAL-1];
    
    printf( "\nTotal de point: %i\n", NOMBREDEPOINTTOTAL); // SERA RETIRER
    
    construitTableauCoordoneePointXY(NOMBREDEPOINTTOTAL,tableauCoordoneePointXY);// un tableau cest toujours passe en référence je crois
    afficheTableauCoordoneePointXY(NOMBREDEPOINTTOTAL,tableauCoordoneePointXY);

    construitTableauDePente(NOMBREDEPOINTTOTAL,tableauCoordoneePointXY,tableauDePente);// un tableau cest toujours passe en référence je crois
    afficheTableauDePente(NOMBREDEPOINTTOTAL,tableauDePente);
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
 
 */