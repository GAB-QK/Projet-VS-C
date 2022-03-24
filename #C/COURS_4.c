#include <stdio.h>

void cesar(char mot[], int shift) {
  int i = 0;

  while (mot[i] != '\0') {
    if (mot[i] >= 'A' && mot[i]<= 'Z') {
        char c = mot[i] - 'A';
        c += shift;
        c = c % 26;
        mot[i] = c + 'A';
    }
    i++;
  }
  printf("%s", mot);                                                                                                                                                                                                                                                                                              
}

int main()
{
    char mot[] = "MORGANE";
    cesar(mot, 3);
    return 0;
}