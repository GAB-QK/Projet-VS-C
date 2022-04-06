#include <stdio.h>

int fonction (int nombre){
    
    int factoriel = 1;
    
    for(int i = 1; i < nombre; i++){
        factoriel = i * factoriel;
    }
return factoriel;
}

int main(){
    int nombre = 10;
    
    printf("la factorielle de 10 est de ");
    printf("%d\n",fonction(nombre));
}