#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct temp {
	int info;
	struct temp*prox;
} TNo;

TNo *inicio = NULL;

// fun��o que cria lista vazia;
void criarLista () {
	inicio = NULL;
}

// Fun��o que insere um elemento no inicio da lista;
// Retorna;
//  0 - se n�o h� mem�ria suficiente;
//  1 - se conseguir inserir;

int inserir (int dado) {
	TNo *p;
	
	p = (TNo *) malloc(sizeof(TNo));
	
	if (p==NULL) {
		printf("Erro de aloca��o\n");
		return 0;
	}
	p -> info= dado;
	p -> prox= NULL;
	
	// caso em que a lista esteja vazia;
	if (inicio == NULL) {
		inicio= p;
	}
	else {
		p -> prox = inicio;
		inicio = p;
	}
	
	return 1;
}

// Fun��o que remove um elemento no inicio da lista;
// Retorna;
//  0 - se n�o h� mem�ria suficiente;
//  1 - se conseguir eliminar o no;

int removeDoInicio () {
	TNo *p;
	
	if (inicio==NULL) {
		printf("A lista est� vazia\n");
		return 0;
	}
	else {
		p = inicio;
		inicio = inicio -> prox;
		free (p);
		return 1;
	}
	
}
	
void imprime () {
	TNo *p;
	
	p = inicio;
	
	if (p== NULL){
		printf("Lista vazia");
		return;
	}
	else {
		while (p!=NULL) {
		printf("Info= %d", p->info);
		p= p->prox;
		}
	}
}

int main (){
	system ("cls");
	criarLista ();
	
	inserir (10);
	inserir (8);
	imprime ();
}
