#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct GYM
{
    char name[12];
    char lastname[12];
    char souscription[12];
    unsigned int id;
    unsigned int age;
    unsigned int weight;
    unsigned int size;
    struct GYM *suivant;
    struct GYM *precedent;
};

struct Liste
{
    struct GYM *premier;
};

struct Liste *initialisation(char *name, char *lastname,
               char *souscription, unsigned int id, unsigned int age,
               unsigned int weight, unsigned int size)
{
    struct Liste *liste = malloc(sizeof(*liste));
    struct GYM *gym = malloc(sizeof(*gym));

    if (liste == NULL || gym == NULL)
    {
        exit(EXIT_FAILURE);
    }

    strcpy( gym->name, name );
    strcpy( gym->lastname, lastname );
    strcpy( gym->souscription, souscription );
    gym->id = id;
    gym->age = age;
    gym->weight = weight;
    gym->size = size;

    gym->suivant = NULL;
    gym->precedent = NULL;
    liste->premier = gym;

    return liste;
}

void insertion(struct Liste *liste, char *name, char *lastname,
               char *souscription, unsigned int id, unsigned int age, unsigned int weight, unsigned int size)
{
    struct GYM *new = malloc(sizeof(*new));
    if (liste == NULL || new == NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy( new->name, name );
    strcpy( new->lastname, lastname );
    strcpy( new->souscription, souscription );
    new->id = id;
    new->age = age;
    new->weight = weight;
    new->size = size;

    struct GYM *temp;
    temp = liste->premier;

    while (temp->suivant != NULL)
    {
        temp = temp->suivant; // en sortie derniere element avant NULL
    }

    temp->suivant = new;   // remplace l'ancien NULL par le nouveau
    new->precedent = temp; // fait pointer nouvelle element a l'element precedent
    new->suivant = NULL;   // fais pointer le new vers NULL car devient derniere element de la liste
}

void supprimer(struct Liste *liste, unsigned int id)
{

    struct GYM *temp = liste->premier;
    struct GYM *temp2;

    if (id == liste->premier->id)
    {
        liste->premier = temp->suivant;
        free(temp);
    }
    else
    {
        while (temp->suivant->id != id)
        {
            temp = temp->suivant; // en sortie element juste avant l'element qui doit etre supp
        }

        temp2 = temp->suivant->suivant; // element 3
                                        // temp = element 1
        free(temp->suivant);            // supp element 2
        temp->suivant = temp2;          // repointe element 1 ver l'element 3
        temp2->precedent = temp;        // repointe le precedent de l'element 3 sure le 1
    }
}

void affichage(struct GYM *parcourt)
{
    printf("prenom : %s ", parcourt->name);
    printf("/");
    printf("nom : %s ", parcourt->lastname);
    printf("/");
    printf("abonnement :  %s ", parcourt->souscription);
    printf("/");
    printf("ID : %u ", parcourt->id);
    printf("/");
    printf("Age :  %u  ", parcourt->age);
    printf("/");
    printf("Poid : %u  ", parcourt->weight);
    printf("/");
    printf("Taille : %u ", parcourt->size);
    printf("\n");
}

void affichage_gestionnaire(struct Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    struct GYM *parcourt = liste->premier;
    printf("Liste de Membres : \n");
    while (parcourt != NULL)
    {
        affichage(parcourt);
        parcourt = parcourt->suivant;
    }
}

void recherche_par_int(struct Liste *liste, unsigned int recherche)
{
    struct GYM *temp = liste->premier;
    unsigned int verification = 0;

    while (temp != NULL)
    {
        if (recherche == temp->id || recherche == temp->size || recherche == temp->weight || recherche == temp->age)
        {
            verification++;
            if (verification == 1)
            {
                printf("\n recherche : %u \n", recherche);
            }
            affichage(temp);
            temp = temp->suivant;
        }
        else
        {
            temp = temp->suivant;
        }
    }
    if (verification == 0)
    {
        printf("\n recherche : %u \n", recherche);
        printf("\n pas de correspondance a la recherche");
    }
}

void recherche_par_char(struct Liste *liste, char *recherche)
{
    struct GYM *temp = liste->premier;
    unsigned int verification = 0;
    int i = 0;

    while (temp != NULL)
    {

        if (strcmp(recherche, temp->name) || strcmp(recherche, temp->lastname) || strcmp(recherche, temp->souscription) == 0)
        {
            verification++;
            if (verification == 1)
            {
                printf("\n recherche : %s \n", recherche);
            }
            affichage(temp);
            temp = temp->suivant;
        }
        else
        {
            temp = temp->suivant;
        }
    }
    if (verification == 0)
    {
        printf("\n recherche : %s \n", recherche);
        printf("pas de correspondance a la recherche");
    }

}

int main()
{
    struct Liste *maListe = initialisation("Gabriel", "Qaddaha", "STAFF", 01, 22, 82, 180);

    insertion(maListe, "mo??se", "Clipal", "membre", 02, 22, 75, 175);
    insertion(maListe, "sofiane", "Clipal", "membre", 03, 2, 75, 174);
    insertion(maListe, "JP", "Clipal", "membre", 03, 22, 75, 17);


    affichage_gestionnaire(maListe);

    recherche_par_int(maListe, 03);
    recherche_par_char(maListe, "sofiane");

    return 0;
}