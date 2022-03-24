#include <stdio.h>
#include<string.h>

void swap(int tableau[], int a, int b)
{
    int temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
}

int main() {
    char nombre[] = "123456789";
    int size = strlen(nombre);
    int end = size - 1;
    
    swap(nombre,0,4 );

    for (int i = 0; i < size-1; i++)
    {
        printf("%c", nombre[i]);
    }
    
    
}