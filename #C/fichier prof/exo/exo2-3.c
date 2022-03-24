#include <stdio.h>


char toUppercase( char lowercase ) {
  return lowercase - 32;
}

int main() {

  for(char letter = 97; letter <= 122; letter++) {
    printf("%c", toUppercase(letter));
  }

  return 0;
}
