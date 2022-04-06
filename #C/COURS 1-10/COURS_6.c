#include <stdio.h>

// strlen -> retourne la longueur d'une chaine
// strcmp -> 0 si elles sont égales 1 sinon
// strchr -> retourne l'indice de la première occurence de la lettre, -& sinon

#include <stdio.h>

unsigned int strlen( char string[] ) {
  unsigned int size;

  for(size = 0; 1; size++) {
    char character = string[size];
    if(character == '\0') {
      break;
    }
  }

  return size;
}

int strchr( char string[], char character ) {
  unsigned int index;

  for(index = 0; 1; index++) {
    char _character = string[index];
    
    if( _character == character ) {
      return index;
    }

    if(_character == '\0') {
      break;
    }
  }

  return -1;
}

int strcmp( char string_a[], char string_b[] ) {

  int size_a = strlen( string_a ),
      size_b = strlen( string_b );

  if( size_a < size_b ) return -1;
  if( size_a > size_b ) return 1;

  for( unsigned int i = 0; i < size_a; i++ ) {
    if( string_a[i] != string_b[i] ) {
      return -1;
    }
  }
  
  return 0;
}

int main() {
  char string_a[] = "hello";
  char string_b[] = "hell";
  int response = strcmp(string_a, string_b);

  if( response == 0 ) {
    printf("equal\n");
  }
  else {
    printf("%d\n", response);
  }


  return 0;
}