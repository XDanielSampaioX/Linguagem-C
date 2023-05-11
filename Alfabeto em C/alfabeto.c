#include<stdio.h>
#include<stdlib.h>

int main() {
    char a = 'A';

    printf("Alfabeto MAIUSCULO\n");
    for (a = 'A'; a <= 'Z'; a++) {
        printf("%c ", a);
    }

    printf("\n\nAlfabeto minusculo\n");
    for (a = 'a'; a <= 'z'; a++) {
        printf("%c ", a);
    }

    printf("\n\n");
    system("pause");
    return 0;
}

