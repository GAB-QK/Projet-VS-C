#include <stdio.h>

void swap(int tableau[], int a, int b)
{
    int temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
}

void quickSort(int tableau[], int debut, int fin)
{

    int gauche = debut-1;
    printf("Gauche: ");
    printf("%d\n", gauche);
    printf("Tableau Gauche: ");
    printf("%d\n", tableau[gauche]);

    int droite = fin+1;
    printf("Droite: ");
    printf("%d\n", droite);
    printf("Tableau droite ");
    printf("%d\n", tableau[droite]);

    const int pivot = tableau[debut];
    printf("Pivot: ");
    printf("%d—", pivot);


    printf("liste :  ");
    int i;
    for(i = 0; i < 5; i++)
    {
	printf("%d ", tableau[i]);
    }
    printf("\n");
    printf("\n");

    /* Si le tableau est de longueur nulle, il n'y a rien à faire. */
    if(debut >= fin)
        return;

    /* Sinon, on parcourt le tableau, une fois de droite à gauche, et une
       autre de gauche à droite, à la recherche d'éléments mal placés,
       que l'on permute. Si les deux parcours se croisent, on arrête. */
    while(1)
    {
        do gauche++; while(tableau[gauche] < pivot);
        do droite--; while(tableau[droite] > pivot);
        

        if(gauche < droite)
            swap(tableau, gauche, droite);
            
        else break;
    }

    /* Maintenant, tous les éléments inférieurs au pivot sont avant ceux
       supérieurs au pivot. On a donc deux groupes de cases à trier. On utilise
       pour cela... la méthode quickSort elle-même ! */
    quickSort(tableau, debut, droite);
    quickSort(tableau, droite+1, fin);
}

int main(void)
{
    int tab[5] = {5, 3, 4, 1, 2};
    int i;

    quickSort(tab, 0, 4);       // problème il faut connaitre la longueur de la table ( prend du temps a faire perte de temps )
    
    for(i = 0; i < 5; i++)      // affichage de la liste final 
    {
	printf("%d ", tab[i]);
    }
    
    return 0;
}


