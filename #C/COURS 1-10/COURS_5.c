/*  
   
1. Écrire un programme qui affiche le nombre de chiffres d'un nombre (positif ou négatif)                     
1504 => 4                               
-40 => 2                                
0 => 1                                  
                                               
2. Écrire un programme qui affiche toutes les lettres miniscules  
=> abcdefghijklmnopqrstuvwxyz                  
                                               
3. Écrire une fonction qui renvoi l'équivalent majuscule d'une lettre minuscule                         
                                               
a => A                                         
                                               
4. Écrire un programme qui affiche ligne par ligne un triangle de ce type  
=>                                             
     *                                         
    * *                                        
  * * * *                                      
* * * * * *                                    
  
*/      
#include <stdio.h>
/*
int main(){
    int nombre = 1504;
    int digit = 0;

    do {
        number /=10;
        digits++;
    }while (number != 0);
   printf("%d", digit);

   return 0;
}
*/
/*
int Exercice_2(){
    
    for ( int alphabet = 97; alphabet < 123; alphabet++ ){
        printf("%c\n",alphabet);
    }
    return 0;
}

int main(){
    Exercice_2();
    return 0;

}
*/
/*
int Exercixe_3(char lettre []){
    int i = 0;
    int shift = 32;
    while (lettre[i] != '\0'){
        lettre[i] = lettre[i] - shift;
        i++;
    }
    printf("%s\n",lettre);
    return 0;
}

int main(){
    char lettre[] = "bizhdbhd";
    Exercixe_3(lettre);
    return 0;
}
*/

void print_stars( unsigned int number ){
    for(unsigned int star = 0; star < number; star++){
        printf("* ");
    }
}

void print_spaces(unsigned int number){
    for(unsigned int i = 0; i < number; i++){
        printf(" ");
    }
}

void print_layer(unsigned int spaces, unsigned int stars){
    print_spaces( spaces );
    print_stars( stars );
    printf("\n");

}

int main() {
    unsigned int base = 6;
    print_layer(base - 1, 1);
    
    for (int removed = base ; removed >= 0; removed -= 2){
        if(removed != base){
            print_layer( removed, base - removed);
            }
    }
    return 0;
}
