#include <stdio.h>

int main() {
  unsigned char message[6] = { 'h', 'e', 'l', 'l', 'o', '~' };
  unsigned char key = 3; //   +3   +3   +3   +3   +3    +3
                           //   'k'  'h'  'o'  'o'  'r'   ???

  for( int i = 0; i < 6; i++ ) {
    printf("%c", (message[i] + key) % 128);
  }
  printf("\n");

  return 0;
}
