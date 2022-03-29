#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact{

  char *firstname;
  char *lastname;
  unsigned int age;
  char *job;
  struct contact *suivant;
};

struct Liste{
  struct contact *premier;
};

struct Liste *initialisation()
{
    struct Liste *liste = malloc(sizeof(*liste));
    struct contact *contact = malloc(sizeof(*contact));

    if (liste == NULL || contact == NULL)
    {
        exit(EXIT_FAILURE);
    }

    contact->firstname = "gab";
    contact->lastname = "le plus beau";
    contact->age = 22;
    contact->job = "riche";

    contact->suivant = NULL;
    liste->premier = contact; // premier > suivant > NULL 

    return liste;
}

void insertion(struct Liste *liste, char* N_firstname,  char* N_lastname, unsigned int N_age, char* N_job)
{
    /* Création du nouvel élément */
    struct contact *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->firstname = N_firstname;
    nouveau->lastname = N_lastname;
    nouveau->age = N_age;
    nouveau->job = N_job;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void afficherListe(struct Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    struct contact *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%s ", actuel->firstname);
        printf("/");
        printf("%s ", actuel->lastname);
        printf("/");
        printf("%d ", actuel->age);
        printf("/");
        printf("%s -> ", actuel->job);
        printf("\n");
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

int main()
{
    struct Liste *maListe = initialisation();

    insertion(maListe, "thomas", "G",19,"etudiant");
    insertion(maListe, "aurelien", "IOH",12,"etudiant");
    insertion(maListe, "alex", "erf",56,"etudiant");

    afficherListe(maListe);

    return 0;
}