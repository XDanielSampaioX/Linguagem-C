#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int i = 0, j = 10, cpf[9], mult1[9], mult2[10], resultado1, resultado2, digito1, digito2;

    srand(time(NULL));
    printf("Gerando numeros aleatorios: ");

    while (i < 9) {
        cpf[i] = rand() % 10; // Gerando números aleatórios entre 0 e 9
        mult1[i] = cpf[i] * j;
        j--;
        i++;
    }

    resultado1 = mult1[0] + mult1[1] + mult1[2] + mult1[3] + mult1[4] + mult1[5] + mult1[6] + mult1[7] + mult1[8];

    digito1 = (resultado1 % 11 <= 1) ? 0 : 11 - resultado1 % 11; // Calculo do primeiro digito verificador

    j = 11;
    i = 0;
    while (i < 9) {
        mult2[i] = cpf[i] * j;
        j--;
        i++;
    }
    mult2[9] = digito1 * 2;

    resultado2 = mult2[0] + mult2[1] + mult2[2] + mult2[3] + mult2[4] + mult2[5] + mult2[6] + mult2[7] + mult2[8] + mult2[9];

    digito2 = (resultado2 % 11 <= 1) ? 0 : 11 - resultado2 % 11; // Calculo do segundo digito verificador

    printf("Seu cpf e: %d%d%d.%d%d%d.%d%d%d-%d%d\n", cpf[0], cpf[1], cpf[2], cpf[3], cpf[4], cpf[5], cpf[6], cpf[7], cpf[8], digito1, digito2);

    return 0;
}

