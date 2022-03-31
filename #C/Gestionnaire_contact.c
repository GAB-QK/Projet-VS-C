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
    struct GYM *precedent;
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
        if (recherche == temp->id || recherche == temp-> size || recherche == temp-> weight || recherche == temp-> age)
        {
            printf("\n");
            printf("trouvé !!! \n");
            affichage(temp);
            temp = temp->suivant;
            verification ++;

        }
        else
        {
            temp = temp->suivant;
        }
    }
    if (verification == 0)
    {
        printf("pas de correspondance a la recherche");
    }
    
}

int main()
{
    struct Liste *maListe = initialisation();
    // gab
    insertion(maListe, "moïse", "Clipal", "membre", 02, 22, 75, 175);
    insertion(maListe, "sofiane", "Clipal", "membre", 03, 2, 75, 174);
    insertion(maListe, "charlottegrosboobs", "Clipal", "membre", 03, 22, 75, 17);

    /* supprimer(maListe, 2);
    supprimer(maListe, 1); */

    affichage_gestionnaire(maListe);

    recherche_par_int(maListe, 2);
    

    return 0;
}