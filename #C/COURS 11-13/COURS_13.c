
/*
Écrire une fonction qui lit un entier et détermine s'il est premier ou non.
Un nombre premier est divisible par 1 et lui-même.

Écrire une fonction qui retourne la table de multiplication d'un entier passé en paramètre.

Écrire un programme  qui vérifie qu'une chaîne est un palindrome

Écrire un programme qui définit unestructure 'point' qui contient les deux coordonnées d'un plan
Écrire une fonction :
- pour afficher le point
- pour calculer la somme de 2 points
- pour retourner la milieu entre deux points

Écrire un programme qui définit une structure 'etudiant' représenté par son nom, prénom et un tableau de notes.
Une note est une structure avec une valeure et un coéfficient.
Écrire une fonction :
- pour ajouter une note
- pour calculer la moyenne d'un étudiant */

/* void compte(char phrase[], char recherche)
{
    int nombre = 0;
    int i = 0;

    while (phrase[i] != '\0')
    {
        if (phrase[i] == recherche)
        {
            nombre++;
        }
        i++;
    }
    printf("%d", nombre);
}

void multiplication(int nombre)
{

    for (int i = 0; i < 11; i++)
    {
        int resultat = nombre * i;
        printf("%d x %d = %d\n", i, nombre, resultat);
    }
}

void palindrome(char phrase[])
{
    int j;
    int resultat;
    for (int i = 0, j = strlen(phrase) - 1; i < strlen(phrase) / 2; i++, j--)
    {
        if (phrase[i] != phrase[j])
        {
            printf("ce n'est pas un palindrome");
            resultat = 0;
            break;
        }
    }
    if (resultat != 0)
    {
        printf("c'est un palindrome");
    }
}
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct POINT
{
    char nom;
    unsigned int x;
    unsigned int y;
};

struct LINK
{
    struct POINT point;
    struct LINK *suivant;
    struct LINK *precedent;
};

struct Liste
{
    struct LINK *premier;
};

struct POINT create_point(char nom, unsigned int x, unsigned int y)
{

    struct POINT point = {.nom = nom, .x = x, .y = y};
    return point;
}

struct Liste *initialisation(char nom, unsigned int x, unsigned int y)
{
    struct Liste *liste = malloc(sizeof(struct Liste));
    struct LINK *link = malloc(sizeof(struct LINK));

    if (liste == NULL || link == NULL)
    {
        exit(EXIT_FAILURE);
    }

    link->point = create_point(nom, x, y);

    link->suivant = NULL;
    link->precedent = NULL;
    liste->premier = link;

    return liste;
}

void insertion(struct Liste *liste, char nom, unsigned int x, unsigned int y)
{
    struct LINK *new = malloc(sizeof(struct LINK));
    if (liste == NULL || new == NULL)
    {
        exit(EXIT_FAILURE);
    }
    new->point.x = x;
    new->point.y = y;
    new->point.nom = nom;

    struct LINK *temp;
    temp = liste->premier;

    while (temp->suivant != NULL)
    {
        temp = temp->suivant; // en sortie derniere element avant NULL
    }

    temp->suivant = new;   // remplace l'ancien NULL par le nouveau
    new->precedent = temp; // fait pointer nouvelle element a l'element precedent
    new->suivant = NULL;   // fais pointer le new vers NULL car devient derniere element de la liste
}

void affichage(struct LINK *parcourt)
{
    printf("point %c :", parcourt->point.nom);
    printf("\n");
    printf("x : %u ", parcourt->point.x);
    printf("/");
    printf("y : %u ", parcourt->point.y);
    printf("\n");
}

void affichage_gestionnaire(struct Liste *liste)
{

    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    struct LINK *parcourt = liste->premier;
    printf("Liste de Points : \n");
    while (parcourt != NULL)
    {
        affichage(parcourt);
        parcourt = parcourt->suivant;
    }
}

void calcul(struct Liste *liste, char recherche1, char recherche2)
{
    struct LINK *temp = liste->premier;
    unsigned int verification = 0;
    int resultat_X;
    int resultat_Y;
    int X1, X2,Y1 ,Y2;

    while (temp != NULL)
    {
        if (recherche1 == temp->point.nom)
        {
            /* printf("trouvé ! \n ");
            affichage(temp); */
            X1 = temp->point.x;
            Y1 = temp->point.y;
            break;
        }
        else
        {
            temp = temp->suivant;
        }
    }
    while (temp != NULL)
    {
        if (recherche2 == temp->point.nom)
        {
            /* printf("trouvé ! \n ");
            affichage(temp); */
            X2 = temp->point.x;
            Y2 = temp->point.y;
            break;
        }
        else
        {
            temp = temp->suivant;
        }
    }
    resultat_X = X1 + X2;
    resultat_Y = Y1 + Y2;
    printf(" resultat X : %d resultat Y : %d", resultat_X , resultat_Y);
    

}

int main()
{
    struct Liste *maListe = initialisation('A', 1, 1);
    insertion(maListe, 'B',1, 1);
    affichage_gestionnaire(maListe);
    calcul(maListe, 'A', 'B');
    return 0;
}
