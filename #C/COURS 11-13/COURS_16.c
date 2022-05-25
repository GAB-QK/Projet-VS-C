#include "stdio.h"
#include "string.h"
#include "stdlib.h"


void add_debut(char **ref){
    char *str = *ref;
    char *temp;
    temp = malloc(strlen(str)+ sizeof(char)*7);
    strcpy(temp, "debut ");
    strcat(temp, str);
    *ref = temp;
    free(str);
}

int main(){
    char *str = malloc(sizeof(char)*7);
    strcpy(str, "et fin");
    add_debut(&str);
    printf("%s", str); 
    return 0;
}