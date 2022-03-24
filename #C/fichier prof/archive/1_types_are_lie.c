#include <stdio.h>

int main() 
{
  printf("\n");
  printf("les types sont des mensonges.\n");
  printf("la mémoire est la seule réalité !\n");
  printf("\n");
  printf("EXEMPLE : \n");

  unsigned int u_int   = 4294967295; // 4o
  int          s_int   = -1;         // 4o

  printf("\n");
  printf("unsigned int u_int   = 4294967295; \n");
  printf("int          s_int   = -1; \n");
  printf("\n");
  printf("----------------------------------------------------------\n");
  printf("'u_int' et 's_int' sont contiennent la même valeur binaire\n");
  printf("----------------------------------------------------------\n");
  printf("u_int(%%x): 0x%x \t s_int(%%x): 0x%x \n",   u_int, s_int);
  printf("u_int(%%u): %u \t s_int(%%u): %u \n",   u_int, s_int);
  printf("u_int(%%d): %d \t\t s_int(%%d): %d \n", u_int, s_int);

  char letter = 'a';

  printf("\n");
  printf("char letter = 'a'; \n");
  printf("\n");
  printf("-----------------------------------\n");
  printf("'letter' possède une valeur binaire\n");
  printf("-----------------------------------\n");
  printf("letter(%%x): 0x%x \n", letter);
  printf("letter(%%c): %c \n", letter);
  printf("letter(%%u): %u \n", letter);

  letter++;

  printf("\n");
  printf("letter++; \n");
  printf("\n");
  printf("-------------------------------------------\n");
  printf("la veleur de 'letter' peut être incrémentée\n");
  printf("-------------------------------------------\n");
  printf("letter(%%x): 0x%x \n", letter);
  printf("letter(%%c): %c \n", letter);
  printf("letter(%%u): %u \n", letter);

  return 0;
}
