#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>



typedef struct cadastro {
	
	char nome[50];
	char telefone[50];
	struct cadastro *proximo;
} No;

void menu ();
void cadastrar ();
No* buscar_e_remover();
No* buscar_e_alterar();
No* buscando ();
void imprimir ();

void main (){
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	char busca[50], buscaAlterar[50], buscaExcluir[50];
	No *removido, *alterado, *buscado, cadastro, *lista= NULL;
	
	while (opcao!= 7){
		while (1){
			menu();
			scanf ("%d", &opcao);
			fflush (stdin);
			if ((opcao== 1) || (opcao==2) || (opcao== 3) || (opcao==4) || (opcao== 5) || (opcao== 6) || (opcao==7)){
				switch (opcao){
					case 1: 
					
					printf ("Digite o nome: \n");
					scanf ("%s", &cadastro.nome);
					fflush (stdin);
					printf ("Digite o número de telefone: \n");
					scanf ("%s", &cadastro.telefone);
					fflush (stdin);
					cadastrar(&lista, cadastro);
					getch();
					system ("cls");
					break;
					
					case 2:
					
					printf ("Digite o nome do contato a ser buscado: \n");
					scanf ("%s", &busca);
					buscado= buscando(&lista, busca);
					if (buscado != NULL){
					printf ("\n Contato encontrado: ");
					printf("\n\t%s\n", buscado->nome);
					printf("\t%s\t\n", buscado->telefone);
					} else {
						printf ("Contato não encontrado !!!");
					}
					getch ();
					system ("cls");
					break;
						
					case 3:
					imprimir(lista);	
					getch();
					system ("cls");
					break;
					
					case 4:
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
						
					}else {
						printf ("Contato não encontrado");
					}
					getch();
					system ("cls");
					break;
					
					case 5:
					
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
					
					case 6:
						printf ("Nome: Francisco Daniel Sampaio Da Silva | Matrícula: 2021010365\n");
						printf ("Nome: Antonio Leonardo Silva Costaa     | Matrícula: 2019021375");
						getch();
						system ("cls");
						break;
					
					case 7:
						if (opcao==7){
						   printf("Obrigado por usar !!!");
							getch();
							system ("cls");
							break;
						 }
					
					default:
		   					printf("Opção inválida !!!\n\n");
		   					getch ();
				}
			break;
			} else{
				printf ("Opção Inválida");
				getch ();
				system ("cls");
			}
		}
	}
}

void menu (){
	printf ("------------------------MENU--------------------------\n");
	printf ("|----------> 1- Cadastrar                <-----------|\n");
	printf ("|----------> 2- Consultar                <-----------|\n");
	printf ("|----------> 3- Listar Todos os contatos <-----------|\n");
	printf ("|----------> 4- Alterar                  <-----------|\n");
	printf ("|----------> 5- Deletar (Busca e Remove) <-----------|\n");
	printf ("|----------> 6- Listar Integrantes       <-----------|\n");
	printf ("|----------> 7- Sair                     <-----------|\n");
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

No* buscando (No **lista, char *nome){
	No *aux, *buscar= NULL;
	
	if (*lista!= NULL) {
		aux= *lista;
		if (strcmp(aux->nome, nome)== 0){
			buscar= *lista;
	} else{
			while (aux->proximo && strcmp(aux->proximo->nome, nome)!=0){
				aux= aux->proximo;
			}
			if (aux->proximo){
				buscar= aux->proximo;	
			}
		}
	}
	return buscar;
}

void imprimir (No *no){
	printf ("\n Lista Telefonica: ");
	if (no == NULL){
		printf("A lista esta vazia!\n");
	}
	else{
	while (no!= NULL){
		printf ("\n\t%s", no->nome);
		printf ("\n\t%s\n", no->telefone);
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
