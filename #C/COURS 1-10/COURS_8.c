#include <stdio.h>
#include <string.h>

int reverse(char str1[]){

   int longeur = strlen(str1);
   int temp; 

   for (int i = 0; i < longeur/2; i++)
   {
     temp = str1[i];;
     str1[i] = str1[longeur - 1 -i ];
     str1[longeur - i -1]= temp;
   }

   printf("%s", str1);
   return 0;
}

int main(){
    char string_1[] = "jesuisunechevre";
    reverse(string_1);
    return 0;
}