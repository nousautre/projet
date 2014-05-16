// PROJET
// Marc-Étienne Leblanc
// Gabriel Poulin


#include <stdio.h>

// cette procédure ( qui ne renvoie rien) lis le nombre de point total attendu
void nombrePointTotal(int * nombreDePointTotal){
 scanf("%d", &*nombreDePointTotal);
}


// La fonction main ( retourne 0 lorsque bien complété)
// lis le nombre de point total au clavier
int main(){
    int nombreDePointTotal=0;
    nombrePointTotal(&nombreDePointTotal);
printf( "BIENVENUE %i\n", nombreDePointTotal); //
return 0;
}