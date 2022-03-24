#include <stdio.h>

int main() {

  int number = -500;
  int digits = 0;

  do {
    number /= 10;
    digits++;
  } while(number != 0);

  printf("%d\n", digits);

  return 0;
}
