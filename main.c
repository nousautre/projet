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

void coordoneePointXYActuel(char * ligneLuCoordonee){
 scanf("%127s", &*ligneLuCoordonee);
}

//void coordoneePointXYActuel(int nombreDePointTotal, int * tableauCoordoneePointXY){



// La fonction main ( retourne 0 lorsque bien complété)
// lis le nombre de point total au clavier
int main(){
    int nombreDePointTotal=0;
    char ligneLuCoordonee[128];
    printf( "BIENVENUE \n"); // SERA RETIRER
    
    nombrePointTotal(&nombreDePointTotal);
    printf( "Total de point: %i\n", nombreDePointTotal); // SERA RETIRER
    coordoneePointXYActuel(&ligneLuCoordonee);
    printf( "La ligne lu: %s\n", ligneLuCoordonee); // SERA RETIRER


return 0;
}