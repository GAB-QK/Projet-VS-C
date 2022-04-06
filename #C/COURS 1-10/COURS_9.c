  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  
  int main( int argc, char **argv ) {
  
    unsigned int global_size = 1;
  
    char *concat = malloc( global_size );
    concat[0] = '\0';
  
  
    for( int i = 0; i < argc; i++ ) {
      char *str = argv[i];
      unsigned int str_size = strlen(str);
      global_size += str_size + 1;
      realloc(concat, global_size);
      strcat(concat, str);
      strcat(concat, " ");
    }
  
    printf("%s \n", concat);
  
    free(concat);
  
    return 0;
  }
