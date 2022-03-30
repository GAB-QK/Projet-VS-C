#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct GYM
{
    char *name;
    char *lastname;
    char *souscription;
    unsigned int id;
    unsigned int age;
    unsigned int weight;
    unsigned int size;
    struct GYM *suivant;
};

struct Liste
{
    struct GYM *premier;
};

struct Liste *initialisation()
{
    struct Liste *liste = malloc(sizeof(*liste));
    struct GYM *gym = malloc(sizeof(*gym));

    if (liste == NULL || gym == NULL)
    {
        exit(EXIT_FAILURE);
    }

    gym->name = "gabriel";
    gym->lastname = "Qaddaha";
    gym->souscription = "STAFF";
    gym->id = 1;
    gym->age = 22;
    gym->weight = 82;
    gym->size = 180;

    gym->suivant = NULL;
    liste->premier = gym;

    return liste;
}

void insertion(struct Liste *liste, char *name, char *lastname, char *souscription, unsigned int id, unsigned int age, unsigned int weight, unsigned int size)
{
    struct GYM *new = malloc(sizeof(*new));
    if (liste == NULL || new == NULL)
    {
        exit(EXIT_FAILURE);
    }

    new->name = name;
    new->lastname = lastname;
    new->souscription = souscription;
    new->id = id;
    new->age = age;
    new->weight = weight;
    new->size = size;

    struct GYM *temp;
    temp = liste->premier;

    while (temp->suivant != NULL)
    {
        temp = temp->suivant;
    }
    temp->suivant = new;
    new->suivant = NULL;
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
            temp = temp->suivant;
        }

        temp2 = temp->suivant->suivant; // element 3
                                        // temp = element 1
        free(temp->suivant);            // supp element 2
        temp->suivant = temp2;          // repointe element 1 ver l'element 3
    }
}

void affichage(struct Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    struct GYM *parcourt = liste->premier;

    while (parcourt != NULL)
    {
        printf("%s ", parcourt->name);
        printf("/");
        printf("%s ", parcourt->lastname);
        printf("/");
        printf("%s ", parcourt->souscription);
        printf("/");
        printf("%u -> ", parcourt->id);
        printf("/");
        printf("%u -> ", parcourt->age);
        printf("/");
        printf("%u -> ", parcourt->weight);
        printf("/");
        printf("%u -> ", parcourt->size);
        printf("\n");
        parcourt = parcourt->suivant;
    }
}

int main()
{
    struct Liste *maListe = initialisation();
    // gab
    insertion(maListe, "moïse", "Clipal", "membre", 02, 22, 75, 175);
    insertion(maListe, "sofiane", "Clipal", "membre", 03, 22, 75, 175);
    insertion(maListe, "charlottegrosboobs", "Clipal", "membre", 04, 22, 75, 175);

    supprimer(maListe, 1);
    supprimer(maListe, 2);
    
    affichage(maListe);

    return 0;
}