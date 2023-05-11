#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	float altura, pesoIdeal;
	char sexo[8];
	int i = 0;
	
	
	
	printf ("Qual seu genero [M][F]:\n");
	scanf ("%s", &sexo);
		
	// Transformando caracteres em minúsculo
	while (sexo[i] != '\0') {
  	  sexo[i] = tolower(sexo[i]);
  	  i++;
	}
		
	printf ("Insira sua altura:\n");
	scanf ("%f", &altura);	
	
	if ((strcmp(sexo, "masculino")) == 0 || (strcmp(sexo, "m") == 0)) {
	   pesoIdeal = ((72.7*altura) - 58);
	   printf ("Seu peso ideal e [M]: %.2f", pesoIdeal);	   
	} else if (strcmp(sexo, "feminino") == 0 || strcmp(sexo, "f") == 0) {
 	   pesoIdeal = ((62.1*altura) - 44.7);
	   printf ("Seu peso ideal e [F]: %.2f", pesoIdeal);
    } else {
	   printf("Sexo Inválido");
    }
	
	return 0;
}
