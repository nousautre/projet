// PROJET
// Marc-Étienne Leblanc
// Gabriel Poulin


#include <stdio.h>

// cette procédure ( qui ne renvoie rien) lis le nombre de point total attendu
void nombrePointTotal(int * nombreDePointTotal){
 scanf("%d", &*nombreDePointTotal);
}

// cette procédure ( qui ne renvoie rien) lis la coordonée actuelle
// verifier si lutilisateur entre plein despace consécutive

void coordoneePointXYActuel(double * pointXActuel, double * pointYActuel){
 scanf("%lf", &*pointXActuel);
 scanf("%lf", &*pointYActuel);
}

void construitTableauCoordoneePointXY(int nombreDePointTotal, int * tableauCoordoneePointXY){
    double pointXActuel=0;
    double pointYActuel=0;
    coordoneePointXYActuel(&pointXActuel,&pointYActuel);
    printf( "Coordone X: %lf\n", pointXActuel); // SERA RETIRER
    printf( "Coordone Y: %lf\n", pointYActuel); // SERA RETIRER
}


// La fonction main ( retourne 0 lorsque bien complété)
// lis le nombre de point total au clavier
// lis la première coordonée entre
int main(){
    const unsigned int NOMBREDEPOINTTOTAL;
    
    printf( "BIENVENUE \n"); // SERA RETIRER
    nombrePointTotal(&NOMBREDEPOINTTOTAL);
    printf( "Total de point: %i\n", NOMBREDEPOINTTOTAL); // SERA RETIRER
    

return 0;
}