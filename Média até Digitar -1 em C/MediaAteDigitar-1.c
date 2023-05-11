#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>


	int main(){
	
	int numero;
	int contador;
	int soma;
	float media;
	
	while ( numero != -1) 
	{
	printf ("digite um numero (Para Finalizar digite -1): ");
	scanf ("%d", &numero);
	
	if (numero >= 0) {
	
	soma = numero+ soma;
	contador++;
		
		
	}
	
	}
	
	media = soma/contador;
	
	printf ("A media entre os números é: %f\n", media); 
	
	}

