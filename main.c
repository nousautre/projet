// PROJET
// Marc-Étienne Leblanc
// Gabriel Poulin


#include <stdio.h>

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
void construitTableauCoordoneePointXY(const int NOMBREDEPOINTTOTAL, int * tableauCoordoneePointXY){
    double pointXActuel=0;
    double pointYActuel=0;
    int i=0;
    for (i;i<NOMBREDEPOINTTOTAL;++i){
        coordoneePointXYActuel(&pointXActuel,&pointYActuel);
       tableauCoordoneePointXY[i] =  pointXActuel; // pour l'instant ce n'est pas un tableau de structure alors je ne garde que le x
    }   
}

//cette procedure affiche le tableau creer à la base
void afficheTableauCoordoneePointXY(const int NOMBREDEPOINTTOTAL, int * tableauCoordoneePointXY){
    int i = 0;
    for (i;i<NOMBREDEPOINTTOTAL;++i){
         printf( "Tableau espace %i : %d \n",i, tableauCoordoneePointXY[i]);  
    }   

}

// La fonction main ( retourne 0 lorsque bien complété)
// lis le nombre de point total au clavier
// lis la première coordonée entre
int main(){
    const unsigned int NOMBREDEPOINTTOTAL; // a verifier aupres de l'enseignant si cest valide de declarer et dassigner apres la valeur de la constante....
    printf( "BIENVENUE \n"); // SERA RETIRER
    nombrePointTotal(&NOMBREDEPOINTTOTAL);
    int tableauCoordoneePointXY[NOMBREDEPOINTTOTAL]; // combien de point total par defaut en assignant une valeur non dynamique?? création de tableau non dynamique
    printf( "Total de point: %i\n", NOMBREDEPOINTTOTAL); // SERA RETIRER
    construitTableauCoordoneePointXY(NOMBREDEPOINTTOTAL,&tableauCoordoneePointXY);
    afficheTableauCoordoneePointXY(NOMBREDEPOINTTOTAL,&tableauCoordoneePointXY);

return 0;
}