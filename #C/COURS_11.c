#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
  char* firstname;
  char* lastname;
  unsigned int age;
  char* job;
};

void contact_print( struct contact contact ) {
  printf("%s ", contact.firstname);
  printf("%s a ", contact.lastname);
  printf("%u ans et travail en tant que ", contact.age);
  printf("%s\n", contact.job);
}

struct contact contact_create( char* firstname,  char* lastname, unsigned int age, char* job ) {
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

void contact_destroy( struct contact contact ) {
  free(contact.firstname);
  free(contact.lastname);
  free(contact.job);
}

int main() {

  struct contact Bob = contact_create("Bob", "Bobby", 32, "Milliardaire");

  contact_print( Bob );

  contact_destroy( Bob );

  return 0;
}