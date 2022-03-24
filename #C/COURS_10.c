/* 1. Déclarer une chaîne avec malloc */
/* 2. Transformer toutes les lettres en minuscule */
/* 3. Remplacer les 'a' par des 'z' et les 'e' par des 'y' */
/* 4. Rajouter ".fin" à la fin */
/* 5. Rajouter "debut:" au début */
/* 6. Supprimer un mot sur deux */
/* 7. Supprimer tous les doublons de la chaine */
/* 8. Ordonner la chaine en fonction de la valeur ASCII */

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>

int lowercase(char *string){
    unsigned int size = strlen(string);
    for (int i = 0; i < size; i++){
        char character = string[i];
        if (character >= 'A' && character <= 'Z')
        {
            string[i] += 32;
        }
    }
    return 0;
}

int bulbizare(char *string){
    unsigned int size = strlen(string);
    for (int i = 0; i < size; i++){
        char character = string[i];
        if (character == 'a')
        {
            string[i] += 25;
        }
        if (character == 'e')
        {
            string[i] += 20;
        }
    }
    return 0;
}

int Fin(char **ref, int *global_lenght){
    *global_lenght += 4;
    char *string = *ref;

    string = (realloc(*ref, (*global_lenght)));

    if (string == NULL){
        return 1;
    }
    
    strcat(string, " fin");
    *ref = string;
    return 0;
}

int Debut(char **ref,int  *global_lenght){ 
    int size = *global_lenght;
    char *string = *ref;
    string = realloc(string, (size + 8 ));

    if (string == NULL){
        return 1;
    }
    
    char temp[size];
    strcpy(temp, string);
    
    strcpy(string, "Debut: ");
    strcat(string, temp);  
    (*global_lenght) += 8;
    *ref = string;

    return 0;
}

int Doublon(char **ref, int *global_lenght){
    int size = *global_lenght;
    char *string = *ref;
    int compte = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (string[i] == string[j]){
                compte++;
                for (int k = j; k < size; k++)
                {
                    string[k] = string[k+1];
                }
            }
        }
    }
    string = realloc(string, (size - compte));
    if (string == NULL){
        return 1;
    }
    *ref = string;
    return 0;
}

int main() {

    int global_lenght = (18);

    char *string = malloc(global_lenght * sizeof(char));

    strcpy( string, "je suIs unE chevrE" );

    lowercase(string);
    bulbizare(string);
    Debut(&string, &global_lenght);  

    Fin(&string, &global_lenght);
    Doublon(&string, &global_lenght);
    

    printf("%s \n", string);
    free(string);
    return 0;
}
