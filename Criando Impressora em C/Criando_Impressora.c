#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nome[50];
	char tamanho[50];
} Dados;

typedef struct no
{
	Dados p;
	struct no *proximo;
} No;

void imprimirDados(Dados p)
{
	printf("\n\tNOME DO ARQUIVO: %s", p.nome);
	printf("\n\tTAMANHO DO ARQUIVO: %s", p.tamanho);
}

void GravarDados(Dados p)
{
	FILE *pont_arq;
	pont_arq = fopen("Fila de impressão.txt", "w");
	fprintf(pont_arq, "%s", p.nome);
	fprintf(pont_arq, "%s", p.tamanho);
	fclose(pont_arq);
}

Dados lerDados()
{
	Dados p;
	printf("\nDigite o nome do arquivo: ");
	fgets(p.nome, 49, stdin);
	fflush (stdin);
	printf("\nDigite o tamanho do arquivo: ");
	fgets(p.tamanho, 49, stdin);
	fflush (stdin);
	return p;
}

void inserir_fila(No **fila, Dados dados)
{
	No *aux, *novo = malloc(sizeof(No));
	if (novo)
	{
		novo->p = dados;
		novo->proximo = NULL;
		if(*fila == NULL)
			*fila = novo;
		else
		{
			aux = *fila;
			while(aux->proximo)
				aux = aux->proximo;
			aux->proximo = novo;
		}
	}
	else
	{
		printf("\ERRO AO ALOCAR MEMORIA.\n");
	}
}

void inserir_do_arquivo(No **fila, Dados auxiliar)
{

	No *aux, *novo = malloc(sizeof(No));

	if (novo)
	{
		novo->p = auxiliar;
		novo->proximo = NULL;
		if(*fila == NULL)
			*fila = novo;
		else
		{
			aux = *fila;
			while(aux->proximo)
				aux = aux->proximo;
			aux->proximo = novo;
		}
	}
	else
	{
		printf("\ERRO AO ALOCAR MEMORIA.\n");
	}
}

void imprimir(No *fila)
{
	printf("\nFILA DE IMPRESSAO:");
	while(fila)
	{
		imprimirDados(fila->p);
		fila = fila -> proximo;
		if(fila)
			printf("\t----------------\n\t");
	}

	printf("\n\t----- FIM FILA -------\n");
}

Dados restaurar()
{
	No *fila = NULL;
	Dados p, h;
	system("cls");
	FILE *arq= fopen ("fila de impressão.txt","r");
	if (arq== NULL) {
		printf("\nERRO NA ABERTURA!");
		getch();
		exit (1);
	}
	while (1) {
		fgets(p.nome, sizeof(p.nome), arq);
		fflush(stdin);
		fgets(p.tamanho, sizeof(p.tamanho), arq);
		fflush(stdin);
		if (feof(arq)){
			break;
		}
		return p;
		
	}
	fclose(arq);
	getchar();
	
}

void gravar(No *fila)
{
	printf("\nGRAVANDO...");
	while(fila)
	{
		GravarDados(fila->p);
		fila = fila -> proximo;
		if(fila)
			printf("\n");
	}
	printf("FIM");
}


No* remover_da_fila(No **fila)
{
	No *remover = NULL;

	if(*fila)
	{
		remover = *fila;
		*fila = remover->proximo;
	}
	else
	{
		printf("\tFILA VAZIA\n");
	}
	return remover;
}

void limpar_fila(No **fila)
{
	No *r , *limpar = NULL;
	while(*fila)
	{
		if(*fila)
		{
			limpar = *fila;
			*fila = limpar->proximo;
			r = *fila;
			free(r);
		}
	}
	printf("\nFIM");
}

int main()
{
	FILE *pont_arq;
	No *r, *fila = NULL;
	int opcao;
	Dados p;
	char nome[20];
	int i;

	do
	{
		system("cls");
		printf("\n*****");
		printf("\n**   Gerenciador de Impressao   *");
		printf("\n\nMenu de  operacoes:\n");
		printf("\n 1 - Adicionar um arquivo para impressao");
		printf("\n 2 - Remover um arquivo da fila de impressao");
		printf("\n 3 - Listar trabalhos da fila de impressao");
		printf("\n 4 - Limpar fila de impressao");
		printf("\n 5 - Guardar fila de impressao");
		printf("\n 6 - Restaurar fila de impressao");
		printf("\n 7 - Sair do Gerenciador de impressao");
		printf("\n 8 - Creditos");
		printf("\n\nDigite a opcao desejada: ");
		scanf("%d", &opcao);
		getchar();
		printf("\n\n*****");
	
		switch(opcao)
		{
		case 1:
			p = lerDados();
			inserir_fila(&fila, p);
			system("cls");
			break;
		case 2:
			r = remover_da_fila(&fila);
			if (r)
			{
				imprimirDados(r->p);
				free(r);
			}
			system("cls");
			break;
		case 3:
			system("cls");
			imprimir(fila);
			getchar();
			break;

		case 4:
			system("cls");
			limpar_fila(&fila);
			break;

		case 5:
			system("cls");
			gravar(fila);
			break;
			
		case 6:
			p = restaurar();
			inserir_do_arquivo(&fila, p);
			break;
		
		case 7:
			system("cls");
			printf("\n\tSAINDO...");
			exit(1);
		
		case 8: 
			system("cls");
			printf("===========================================================================");
		    printf("\n     ALUNO: Francisco Daniel Sampaio da Silva // MATRICULA: 2021010365");
		    printf("\n     ALUNO: Lucas     Nobre  Fernandes        // MATRICULA: 2021010536");
		    printf("\n     ALUNA: Jhully Emilly Aires de Oliveira   // MATRICULA: 2021010509");
		    printf("\n===========================================================================");
		    getchar();
		    
		    break; 
		    
		default:
			if(opcao != 0)
				printf("\nOPCAO INVALIDA!\n");
		}
	}
	while(opcao != 0);

	return 0;
}
