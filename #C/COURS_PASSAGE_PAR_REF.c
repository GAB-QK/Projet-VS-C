#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concat( char **ref, char *source ) {
  char* dest = *ref;

  unsigned int length = strlen(source);

  dest = realloc(dest, strlen(dest) + length);
  strcat(dest, source);

  *ref = dest;
}

int main( int argc, char** argv) {

  unsigned int lenght = strlen(argv[1]);
  char *string = malloc(lenght * sizeof(char));
  strcpy(string, argv[1]);

  concat(&string, "fin");

  printf("%s \n", string);

  return 0;
}
