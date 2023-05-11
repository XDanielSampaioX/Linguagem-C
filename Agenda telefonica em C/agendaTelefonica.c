#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>



typedef struct cadastro {
	
	char nome[50];
	char telefone[50];
	char nome_empresa[50];
	struct cadastro *proximo;
} No;

void menu ();
void cadastrar ();
No* buscar_e_remover();
No* buscar_e_alterar();
void imprimir ();

void main (){
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	char buscaAlterar[50], buscaExcluir[50];
	No *removido, *alterado, cadastro, *lista= NULL;
	
	while (opcao!= 6){
		
		menu();
		scanf ("%d", &opcao);
		switch (opcao){
			case 1: 
			
			printf ("Digite o nome: \n");
			scanf ("%s", &cadastro.nome);
			fflush (stdin);
			printf ("Digite o número de telefone: \n");
			scanf ("%s", &cadastro.telefone);
			fflush (stdin);
			printf ("Digite o nome da empresa: \n");
			scanf ("%s", &cadastro.nome_empresa);
			fflush (stdin);
			cadastrar(&lista, cadastro);
			getch();
			system ("cls");
			break;
			
			case 2:
			imprimir(lista);	
			getch();
			system ("cls");
			break;
			
			case 3:
			printf ("Digite o nome do contato a ser alterado: \n");
			scanf ("%s", &buscaAlterar);
			alterado= buscar_e_alterar(&lista, buscaAlterar);
			if (alterado!= NULL){
				printf ("Digite o nome do novo contato\n");
				scanf ("%s", &alterado->nome);
				fflush (stdin);
				printf ("Digite o número do novo contato\n");
				scanf ("%s", &alterado->telefone);
				fflush (stdin);
				printf ("Digite o nome da nova empresa do contato\n");
				scanf ("%s", &alterado->nome_empresa);
				fflush (stdin);
				
			}else {
				printf ("Contato não encontrado");
			}
			getch();
			system ("cls");
			break;
			
			case 4:
			
			printf ("Digite nome do contato a ser excluído: \n");
			scanf ("%s", &buscaExcluir);
			removido= buscar_e_remover(&lista, buscaExcluir);
			if (removido!= NULL){
				printf ("Contato apagado %s", removido->nome);
				
				
			}else {
				printf ("Contato não encontrado");
			}
			getch();
			system ("cls");
			free(removido);
			break;
			
			case 5:
				printf ("Nome: Francisco Daniel Sampaio Da Silva | Matrícula: 2021010365\n");
				printf ("Nome: Werbeson Da Silva Oliveira        | Matrícula: 2021020827");
				getch();
				system ("cls");
			
			case 6:
				if (opcao==6){ 	
					getch();
					system ("cls");
					break;
				 }
			
			default:
				if (opcao!= 6){
				   printf("Opção inválida !!!\n\n");
				}
		}
	}
}

void menu (){
	printf ("------------------------MENU--------------------------\n");
	printf ("|----------> 1- Cadastrar                <-----------|\n");
	printf ("|----------> 2- Consultar                <-----------|\n");
	printf ("|----------> 3- Alterar                  <-----------|\n");
	printf ("|----------> 4- Deletar (Busca e Remove) <-----------|\n");
	printf ("|----------> 5- Listar Integrantes       <-----------|\n");
	printf ("|----------> 6- Sair                     <-----------|\n");
	printf ("------------------------------------------------------\n");
}

void cadastrar (No **lista, No cadastro){
	No *aux, *novo= malloc (sizeof(No));
	
	if (novo != NULL){
		*novo = cadastro;
		novo->proximo= NULL;
				
		if (*lista== NULL) {
			*lista= novo;
		} else {
			aux= *lista;
			while (aux->proximo != NULL){
				aux= aux->proximo;
			}
			aux->proximo= novo;
		}
	} else {
		printf ("Erro !!!");
	}
	printf("\nPressione qualquer tecla para continuar:...\n");
}

void imprimir (No *no){
	printf ("\n Lista Telefonica: ");
	if (no == NULL){
		printf("A lista esta vazia!\n");
	}
	else{
	while (no!= NULL){
		printf ("\n\t%s", no->nome);
		printf ("\n\t%s", no->telefone);
		printf ("\n\t%s\n", no->nome_empresa);
		no= no->proximo;
	}
	printf ("\n\n");
		}
	}

No* buscar_e_alterar (No **lista, char *nome){
	No *aux, *alterar= NULL;
	
	if (*lista!= NULL) {
		aux= *lista;
		if (strcmp(aux->nome, nome)== 0){
			alterar= *lista;
	} else{
			while (aux->proximo && strcmp(aux->proximo->nome, nome)!=0){
				aux= aux->proximo;
			}
			if (aux->proximo){
				alterar= aux->proximo;
				
			}
		}
	}
	return alterar;
}

No* buscar_e_remover (No **lista, char *nome){
	No *aux, *remover= NULL;
	
	if (*lista!= NULL) {
		aux= *lista;
		if (strcmp(aux->nome, nome)== 0){
			remover= *lista;
			*lista= remover->proximo;
	} else{
			while (aux->proximo && strcmp(aux->proximo->nome, nome)!=0){
				aux= aux->proximo;
			}
			if (aux->proximo){
				remover= aux->proximo;
				aux->proximo = remover->proximo;
			}
		}
	}
	return remover;
}
