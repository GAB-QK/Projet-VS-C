#include <stdio.h>
#include <string.h>

void swap(int tableau[], int a, int b)
{
    int temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
}

void quickSort(int tableau[], int debut, int fin)
{
    int taille = fin + 1;
    int i = debut;
    int j = taille - 1 ;
    int pivot = tableau[0];


    if (taille >= 2){

        while (i < j){

            if (tableau[i + 1] >= pivot)
            {
                swap(tableau, i + 1, j); //Envoyer les indexes, pas  la valeur
                j--;
            }
            else
            {
                swap(tableau, i + 1, i);
                i++;
            }
        }
        

        quickSort(tableau, 0, i - 1);
        quickSort(tableau, i + 1, taille - 1);
    } 
}

int main(void)
{
    int tab[5] = {5, 3, 4, 1, 2};

    quickSort(tab, 0, 4); // problème il faut connaitre la longueur de la table ( prend du temps a faire perte de temps )

    for (int i = 0; i < 5; i++) // affichage de la liste final
    {
        printf("%d ", tab[i]);
    }

    return 0;
}