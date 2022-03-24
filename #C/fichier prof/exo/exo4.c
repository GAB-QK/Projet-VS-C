/*

       *
      * *
    * * * * 
  * * * * * *
* * * * * * * *

*/

#include <stdio.h>

void printStars( unsigned int number ) {
  for(unsigned int i = 0; i < number; i++) {
    printf("* ");
  }
}

void printSpaces( unsigned int number ) {
  for(unsigned int i = 0; i < number; i++) {
    printf(" ");
  }
}

void printLayer( unsigned int spaces, unsigned int stars ) {
  printSpaces( spaces );
  printStars( stars );
  printf("\n");
}

int main() {
  unsigned int base = 10;

  printLayer( base - 1, 1 );
  for(int removed = base; removed >= 0; removed -= 2) {
    if(removed != base) {
      printLayer( removed, base - removed );
    }
  }

  return 0;
}
