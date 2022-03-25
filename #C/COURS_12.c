#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
  char* firstname;
  char* lastname;
  unsigned int age;
  char* job;
  unsigned int id ;
};

void contact_print( struct contact contact ) {
  printf("%s ", contact.firstname);
  printf("%s a ", contact.lastname);
  printf("%u ans et travail en tant que ", contact.age);
  printf("%s", contact.job);
  printf("%u\n",contact.id);
}

struct contact contact_create( char* firstname,  char* lastname, unsigned int age, char* job, unsigned int id) {
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

int main(){
    printf("combien dentrée dans la liste ?");
    scanf("%u",counter );

    for (int counter = 0; i < count; i++)
    {

    }
    

    contact_print( Bob );

    return 0;
}