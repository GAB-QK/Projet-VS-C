#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct LINK
{
    int nombre;
    struct LINK *suivant;
    struct LINK *precedent;
};

struct Liste
{
    struct LINK *premier;
};

/* struct LINK create(int nombre)
{
    struct LINK new = {.nombre = nombre};
    return new;
} */

struct Liste *initialisation(int nombre)
{
    struct Liste *liste = malloc(sizeof(struct Liste));
    struct LINK *link = malloc(sizeof(struct LINK));

    if (liste == NULL || link == NULL)
    {
        exit(EXIT_FAILURE);
    }

    link->nombre = nombre;

    link->suivant = NULL;
    link->precedent = NULL;
    liste->premier = link;

    return liste;
}

void insertion(struct Liste *liste, char nombre)
{
    struct LINK *new = malloc(sizeof(struct LINK));
    if (liste == NULL || new == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    new->nombre = nombre;

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
        printf("point %d :", parcourt->nombre);
        parcourt = parcourt->suivant;
    }
}


int main()
{
    struct Liste *maListe = initialisation(1);
    insertion(maListe, 2);
    insertion(maListe, 3);
    insertion(maListe, 4);
    affichage_gestionnaire(maListe);
    return 0;
}