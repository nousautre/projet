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

//void coordoneePointXYActuel(int nombreDePointTotal, int * tableauCoordoneePointXY){



// La fonction main ( retourne 0 lorsque bien complété)
// lis le nombre de point total au clavier
// lis la première coordonée entre
int main(){
    int nombreDePointTotal=0;
    double pointXActuel=0;
    double pointYActuel=0;
    printf( "BIENVENUE \n"); // SERA RETIRER
    nombrePointTotal(&nombreDePointTotal);
    printf( "Total de point: %i\n", nombreDePointTotal); // SERA RETIRER
    coordoneePointXYActuel(&pointXActuel,&pointYActuel);
    printf( "Coordone X: %lf\n", pointXActuel); // SERA RETIRER
    printf( "Coordone Y: %lf\n", pointYActuel); // SERA RETIRER

return 0;
}