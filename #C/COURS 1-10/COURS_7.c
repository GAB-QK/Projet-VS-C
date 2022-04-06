/*
* void factorielle
* void pow
* void pythagore 
* void abs 
*/

#include <stdio.h>

void factorielle(int *ref){
    int nombre = *ref;
    int factorielle = 1;
    for (int i = 1; i <= nombre; i++){
        factorielle *= i;
    }
    *ref = factorielle;
}

void carre(int *ref,int puisance){
    int nombre = *ref;
    int copy = nombre;
    
    for ( int i = 0; i < puisance; i++)
    {
        nombre = nombre * copy;
    }
    
    *ref = nombre;
}

void abs ( int *ref){
    int nombre = *ref;
    if (nombre < 0)
    {
        *ref = *ref * -1;
    }
    
}

void pythagore(int C1, int C2, int *ref){
    int puissance_2 = 2;
    carre(&C1, puissance_2);
    carre(&C2, puissance_2);
    *ref = C1 + C2;
    printf("l'hypotenus au carre est de  %d ", *ref);
}


int main(){
    int nombre = 8;
    int puissance = 5;

    int cote_1 = 5;
    int cote_2 = 19;
    int hyp;

    //factorielle(&nombre);
    //carre(&nombre, puissance);
    pythagore(cote_1, cote_2, &hyp);
    //printf("%d", carre(&nombre,&puissance));
    return 0;
}






