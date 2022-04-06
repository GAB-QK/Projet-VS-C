#include <stdio.h>

int main() {

    int a = 2;
    int entier = 1;
    float virgule = 1.2;
    char caractere = 'c';
    
    char array [] = {'m','a',' ','c','h','a','i','n','e'};
    char String [] = "ma chaine de caractère\n";

    if (a > 10 && a < 30) {                 // && reviens au "ET" 
        printf("superieur à 10");
    }
    else{
        printf("inferieur à 10");
    }

    printf("hello world \n");

    if (a >2 || a == 2){                     // revient à "OU"
        printf("condition ou remplie ");
    }                    
    if (a != 7){
        printf("la condition de négation est remplie");
    }

    while(1) {
        printf("boucle infinie");
    }

    while(a < 10){
        printf("boucle");
        a++;
    }

    do{
        printf("boucle");
        a++;

    }while(a < 20);

    for( int i = 0; i<30 ; i++ ){
        printf("boucle for");
    }
    return 0;
}

int switch_test(){

    int option;
    printf("Mon Menu :\n1. option\n2. option2\n3. option 3\n4. option 4\n");
    
    switch(option) {
        case 1: printf("reponse 1\n"); break;
        case 2: printf("reponse 2\n"); break;
        case 3: printf("reponse 3\n"); break;
        case 4: printf("reponse 4\n"); break;
        default: printf("erreur\n");
        
    }
}