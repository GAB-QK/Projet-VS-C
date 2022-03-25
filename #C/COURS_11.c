#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
  char* firstname;
  char* lastname;
  unsigned int age;
  char* job;
  unsigned int* id ;
};

void contact_print( struct contact contact ) {
  printf("%s ", contact.firstname);
  printf("%s a ", contact.lastname);
  printf("%u ans et travail en tant que ", contact.age);
  printf("%s\n", contact.job);
}


struct contact contact_create( char* firstname,  char* lastname, unsigned int age, char* job) {
  struct contact contact;

  contact.firstname = malloc( strlen(firstname) * sizeof(char) );
  strcpy( contact.firstname, firstname );
  contact.lastname = malloc(  strlen(lastname) * sizeof(char) );
  strcpy( contact.lastname, lastname );
  contact.job = malloc( strlen(job) * sizeof(char) );
  strcpy( contact.job, job );
  contact.age = age;

  return contact;
}

struct element{
    struct contact contact;
    struct element *prev;
    struct element *next;
};

void init_first_element(struct element *first_element, char *prenom, char *nom, unsigned int age, char *job){
    first_element->contact = contact_create(prenom,nom,age,job);
    first_element->prev = malloc(sizeof(char));
    first_element->prev = NULL;
    first_element->next = malloc(sizeof(char));
    first_element->prev = NULL;
}


int main() {

    struct element *first_element = malloc(sizeof(struct element));
    struct contact Bob = contact_create("Bob", "Bobby", 32, "Milliardaire");
    contact_print( Bob );
    return 0;
}