#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char rua[50];
    char bairro[50];
    char cidade[50];
    char pais[50];
    int num, cep;
}Endereco;

typedef struct{
    int codigo;
    Data dataAss;
    char cargo[50];
    float salario;
}Contrato;

typedef struct{
    char nome[50];
    Data dataNas;
    Endereco end;
    Contrato contr;
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

// -------------- impressão das informações de uma Pessoa ------------------------

void imprimirData(Data d){
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

void imprimirEndereco(Endereco end){
    printf("\tEndereco:\n");
    printf("\t\tRua: %s", end.rua);
    printf("\t\tBairro: %s", end.bairro);
    printf("\t\tCidade: %s", end.cidade);
    printf("\t\tPais: %s", end.pais);
    printf("\t\tNumero: %d\n", end.num);
    printf("\t\tCep: %d\n", end.cep);
}

void imprimirContrato(Contrato c){
    printf("\tContrato %d:\n", c.codigo);
    printf("\t\tCargo: %s", c.cargo);
    printf("\t\tSalario R$%.2f\n", c.salario);
    printf("\t\tData de ad.: ");
    imprimirData(c.dataAss);
}

void imprirPessoa(Pessoa p){
    printf("\n\tNome: %s", p.nome);
    printf("\tData de nas.: ");
    imprimirData(p.dataNas);
    imprimirEndereco(p.end);
    imprimirContrato(p.contr);
}

// ------------ Leitura dos dados de uma Pessoa -------------------------

Data lerData(){
    Data d;
    printf("\nDigite a data no formato dd mm aaaa: ");
    fflush (stdin);
    scanf("%d//%d//%d", &d.dia, &d.mes, &d.ano);
    getchar();
    return d;
}

Endereco lerEndereco(){
    Endereco end;
    printf("\nRua: ");
    fflush (stdin);
	fgets(end.rua, 49, stdin);
    printf("\nBairro: ");
    fflush (stdin);
    fgets(end.bairro, 49, stdin);
    printf("\nCidade: ");
    fflush (stdin);
    fgets(end.cidade, 49, stdin);
    printf("\nPais: ");
    fflush (stdin);
    fgets(end.pais, 49, stdin);
    printf("\nNumero: ");
    fflush (stdin);
    scanf("%d", &end.num);
    printf("\nCep: ");
    fflush (stdin);
    scanf("%d", &end.cep);
    fflush (stdin);
    getchar();
    return end;
}

Contrato lerContrato(){
    Contrato c;
    printf("\nCodigo do contrato: ");
    fflush (stdin);
    scanf("%d", &c.codigo);
    printf("\nData de assinatura: ");
    fflush (stdin);
    c.dataAss = lerData();
    printf("\nCargo: ");
    fflush (stdin);
    fgets(c.cargo, 49, stdin);
    printf("\nSalario: R$");
    fflush (stdin);
    scanf("%f", &c.salario);
    fflush (stdin);
    getchar();
    return c;
}

Pessoa lerPessoa(){
    Pessoa p;
    printf("\nNome: ");
    fflush (stdin);
    fgets(p.nome, 49, stdin);
    printf("\nData de nascimento: ");
    fflush (stdin);
    p.dataNas = lerData();
    p.contr = lerContrato();
    p.end = lerEndereco();
    return p;
}


void inserir_na_fila(No **fila, Pessoa pessoa){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->p = pessoa;
        novo->proximo = NULL;
        if(*fila == NULL)
            *fila = novo;
        else{
            aux = *fila;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("\nErro ao alocar memoria.\n");
}

No* remover_da_fila(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }
    else
        printf("\tFila vazia\n");
    return remover;
}

void imprimir(No *fila){
    printf("\t------- FILA --------\n\t");
    while(fila){
        imprirPessoa(fila->p);
        fila = fila->proximo;
        if(fila)
            printf("\t-----------------------\n\t");
    }
    printf("\n\t------- FIM FILA --------\n");
}

int main(){
    No *r, *fila = NULL;
    int opcao;
    Pessoa p;

    do{
    	system ("cls");
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        fflush (stdin);
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
        case 1:
            p = lerPessoa();
            inserir_na_fila(&fila, p);
            system ("cls");
            break;
        case 2:
            r = remover_da_fila(&fila);
            if(r){
                imprirPessoa(r->p);
                free(r);
            }
            system ("pause");
            break;
        case 3:
            imprimir(fila);
            system ("pause");
            break;
        default:
            if(opcao != 0)
                printf("\nOpcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}
