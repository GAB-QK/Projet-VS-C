#include <stdio.h>

int main (){
    unsigned char message[5] = {'h','e','l','l','o'};
    unsigned char key = 3;

    for( int i = 0; i < 5; i++){
        printf("%c", message[i] + key);
    }

    return 0;
}