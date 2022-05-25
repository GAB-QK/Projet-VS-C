#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void comparateurdelamort(char *chaine_1, char *chaine_2)
{
    int lenght1 = 0;
    int lenght2 = 0;
    for (int i = 0; chaine_1[i] != '\0'; i++)
    {
        lenght1 ++;
    }
    for (int i = 0; chaine_2[i] != '\0'; i++)
    {
        lenght2 ++;
    }
    if (lenght1 == lenght2)
    {
        printf("0");
    }else if (lenght1 > lenght2){
        printf("1");
    }else if(lenght1 < lenght2){
        printf("-1");
    }
    
}

int main()
{
    char blabla_1[] = "je suis  la chaine 1";
    char blabla_2[] = "je suis la chaine 2";

    comparateurdelamort(blabla_1, blabla_2);

    return 0;
}