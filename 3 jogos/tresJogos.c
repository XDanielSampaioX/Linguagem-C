#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <time.h>

typedef struct{
    char frase[100];
    struct Palavra *ptr_prox;
}elemento;

elemento *ptr_primeira;
elemento *ptr_ultima;
int tamanho;

void jogoDaForca ();
void JokenPo ();
int JogoDaVelha ();

void Chances(int contador);
void ganhou(char tentativa);
void Forca(int contador,int flagInicio);
void MostrarLetrasErradas(int erro1,int erro2,int erro3,int erro4,int erro5,char tentativa,int contador);
void Tentativas(char qtdCaracter,char tentativa,int *certo,int *contador,char resposta[]);
void CapturaLetra(char *tentativa);
void VerificaSeErrou(char frase[],int qtdCaracter,int *contador,char tentativa,int *erro1,int *erro2,int *erro3,int *erro4,int *erro5,int *n);
int MenurPrincipal();
char* BuscarPalavra(char nomeArquivo[]);
void CriarListaVazia();
void incluirNaLista(elemento frase);
int SorteiaPalavra(int faixa);
void limparLista();


void jogoDaForca ()
{
    int i, contador, n, qtdCaracter, erro1, erro2, erro3, erro4, erro5, certo,opcao;
    char frase[100], resposta[100], tentativa, confirmar, continuar;
    do
    {
        MENU:
        system("cls");
        Forca(contador,1);

        opcao=MenuPrincipal();
        if(opcao==0)
        {
        exit(0);
        }
        else if(opcao==1)
        {
            strcpy(frase,BuscarPalavra("animais.txt"));
        }
        else if(opcao==2)
        {
            strcpy(frase,BuscarPalavra("profissoes.txt"));
        }
        else if(opcao==3)
        {
            strcpy(frase,BuscarPalavra("paises.txt"));
        }
        else if(opcao==4)
        {
            strcpy(frase,BuscarPalavra("filmes.txt"));
        }
        else if(opcao==5)
        {
            strcpy(frase,BuscarPalavra("seriados.txt"));
        }else{
            printf("\nOpção Invalida tente Novamente");
           // system("cls");
            goto MENU;
        }

        confirmar = 'n';
        while(confirmar != 'S')
        {
            certo = 0;
            qtdCaracter=0;
            n = 0;
            i=0;
            contador = 0;
            erro1 = ' ';
            erro2 = ' ';
            erro3 = ' ';
            erro4 = ' ';
            erro5 = ' ';
            tentativa=' ';
            printf("O jogo sera iniciado...\n");
            system("PAUSE");
            system("CLS");
            for(i = 0; i < 100; i++)
            {
                resposta[i]='_';
            }
            while(contador < 6)
            {
                n=0;
                certo=0;
                Forca(contador,0);

                for(i=0; i < 100; i++)
                {
                    if(frase[i]=='\0')
                    {
                        qtdCaracter = i;
                        break;
                    }
                    else
                    {
                        if(frase[i]==' ')
                        {
                            resposta[i]=' ';
                            printf("%c", resposta[i]);
                        }
                        else
                        {
                            if(frase[i]==tentativa)
                            {
                                resposta[i]=frase[i];
                            }
                        }
                    }
                    printf("%c ", resposta[i]);
                }

                MostrarLetrasErradas(erro1,erro2,erro3,erro4,erro5,tentativa,contador);
                Chances(contador);
                Tentativas(qtdCaracter,tentativa,&certo,&contador,resposta);
                if(certo!=qtdCaracter)
                {
                    CapturaLetra(&tentativa);

                }
                VerificaSeErrou(frase,qtdCaracter,&contador,tentativa,&erro1,&erro2,&erro3,&erro4,&erro5,&n);

                system("cls");
            }


            if(contador==6)
            {
                Forca(contador,0);
                for(i = 0; i < qtdCaracter; i++)
                {
                    if(resposta[i]==frase[i])
                    {
                        printf("%c ", resposta[i]);
                    }
                    else
                    {
                        printf("(%c) ", frase[i]);
                    }
                }
                MostrarLetrasErradas(erro1,erro2,erro3,erro4,erro5,tentativa,contador);
                printf("\n\n\nVoçê Morreu !!!!\n");
                system("PAUSE");
            }
            if(contador==7)
            {
               ganhou(tentativa);
            }
            confirmar = 'S';
            printf("Deseja jogar novamente (S/N)? ");
            fflush(stdin);
            continuar = toupper(getchar());
        }
    }
    while(continuar=='S');
    system("PAUSE");
}

int MenuPrincipal()
{
    int opcao;
    printf("\n###############      MENU PRINCIPAL       ################");
    printf("\n#                                                        #");
    printf("\n#        Digite um comando para prosseguir:              #");
    printf("\n#                                                        #");
    printf("\n#        1 – Animais                                     #");
    printf("\n#        2 – Profissões                                  #");
    printf("\n#        3 – Países                                      #");
    printf("\n#        4 – Filmes                                      #");
    printf("\n#        5 – Sériados                                    #");
    printf("\n#        0 – Sair                                        #");
    printf("\n#                                                        #");
    printf("\n##########################################################\n");
    scanf("%d",&opcao);
    return opcao;
}
void Chances(int contador)
{
    switch(contador)
    {
    case 0:
        puts("\n\nVoce pode errar 5 vezes");
        break;
    case 1:
        puts("\n\nVoce pode errar 4 vezes");
        break;
    case 2:
        puts("\n\nVoce pode errar 3 vezes");
        break;
    case 3:
        puts("\n\nVoce pode errar 2 vezes");
        break;
    case 4:
        puts("\n\nVoce pode errar apenas mais uma vez");
        break;
    case 5:
        puts("\n\nSe errar agora você morre!!!!");
    }

}
void ganhou(char tentativa)
{
printf("\n******************************************************");
printf("\n***********          PARABÉNS            *************");
printf("\n***********            VOCÊ              *************");
printf("\n***********           GANHOU             *************");
printf("\n******************************************************\n");

    tentativa='_';
}
void Forca(int contador,int flagInicio)
{
    if(flagInicio==0)
    { 
        switch(contador)
        {
        case 0:
            printf("_____________\n");
			printf("|.|         |\n");
			printf("|.|        _|_\n");
			printf("|.|          \n");
			printf("|.|         \n");
			printf("|.|         \n");
			printf("|.| \n");
			printf("|.| \n");
			printf("|.| \n");
            break;

        case 1:
            printf("_____________\n");
			printf("|.|         |\n");
			printf("|.|        _|_\n");
			printf("|.|         O \n");
			printf("|.|         \n");
			printf("|.|         \n");
			printf("|.| \n");
			printf("|.| \n");
			printf("|.| \n");
            break;
            
        case 2:
            printf("_____________\n");
			printf("|.|         |\n");
			printf("|.|        _|_\n");
			printf("|.|         O \n");
			printf("|.|         | \n");
			printf("|.|          \n");
			printf("|.| \n");
			printf("|.| \n");
			printf("|.| \n");
            break;
            
        case 3:
            printf("_____________\n");
			printf("|.|         |\n");
			printf("|.|        _|_\n");
			printf("|.|         O \n");
			printf("|.|        /| \n");
			printf("|.|         \n");
			printf("|.| \n");
			printf("|.| \n");
			printf("|.| \n");
            break;
            
        case 4:
            printf("_____________\n");
			printf("|.|         |\n");
			printf("|.|        _|_\n");
			printf("|.|         O \n");
			printf("|.|        /|\\ \n");
			printf("|.|        \n");
			printf("|.| \n");
			printf("|.| \n");
			printf("|.| \n");
            break;

        case 5:
            printf("_____________\n");
			printf("|.|         |\n");
			printf("|.|        _|_\n");
			printf("|.|         O \n");
			printf("|.|        /|\\ \n");
			printf("|.|        / \n");
			printf("|.| \n");
			printf("|.| \n");
			printf("|.| \n");
            break;
        case 6:
            printf("_____________\n");
			printf("|.|         |\n");
			printf("|.|        _|_\n");
			printf("|.|         O \n");
			printf("|.|        /|\\ \n");
			printf("|.|        / \\ \n");
			printf("|.| \n");
			printf("|.| \n");
			printf("|.| \n");
            break;
        }

    }
    else
    {
        puts("_____________ ");
		puts("|.|         |   ");
		puts("|.|        _|_");
		puts("|.|         O    \t JOGO DA FORCA ");
		puts("|.|        /|\\   ");
		puts("|.|        / \\     ");
		puts("|.|       \t     ");
		puts("|.|     \t     ");
		puts("|.| ");
		puts("|.| ");
		puts("|.| ");
    }

}
void MostrarLetrasErradas(int erro1,int erro2,int erro3,int erro4,int erro5,char tentativa, int contador)
{
    if(contador==6)
    {
        printf("\n\n%c %c %c %c %c %c\n", erro1, erro2, erro3, erro4, erro5, tentativa);
    }
    else
    {
        printf("\n\n%c %c %c %c %c\n", erro1, erro2, erro3, erro4, erro5);
    }

}

void Tentativas(char qtdCaracter,char tentativa,int *certo,int *contador,char resposta[])
{
    int i;
    for(i = 0; i <= qtdCaracter; i++)
    {
        if(tentativa!=' ')
        {
            if(resposta[i]!='_')
            {
                *certo=*certo+1;
                if(*certo==qtdCaracter)
                {
                    *contador=7;
                    break;
                }
            }
        }
    }

}
void CapturaLetra(char *tentativa)
{
    char tecla;
    printf("\n\nDigite uma letra: ");
    fflush(stdin);
    scanf("%c",&tecla);
    *tentativa=tecla;
    *tentativa = tolower(*tentativa);
}

void VerificaSeErrou(char frase[],int qtdCaracter,int *contador,char tentativa,int *erro1,int *erro2,int *erro3,int *erro4,int *erro5,int *n)
{
    int i;
    for(i = 0; i < qtdCaracter; i++)
    {
        if(tentativa!=frase[i])
        {
            *n=*n+1;
            if(*n==qtdCaracter)
            {
                *contador=*contador+1;
                if(*contador==1)
                {
                    *erro1 = tentativa;
                }
                if(*contador==2)
                {
                    *erro2 = tentativa;
                }
                if(*contador==3)
                {
                    *erro3 = tentativa;
                }
                if(*contador==4)
                {
                    *erro4 = tentativa;
                }
                if(*contador==5)
                {
                    *erro5 = tentativa;
                }
            }
        }
    }

}
char* BuscarPalavra(char nomeArquivo[])
{
    FILE *pont_arq;
    char linha[1024]; // variável do tipo string
    char palavraSorteada[100];
    elemento frase;
    pont_arq = fopen(nomeArquivo, "r");
    if(pont_arq == NULL)
    {
        printf("Erro na abertura do arquivo!");
        exit ;
    }
    int i=0;
    tamanho=0;
    CriarListaVazia();
    while(fscanf(pont_arq, " %[^\n]s",linha)!=EOF)
    {
        char *ptr;
        ptr=strtok(linha,";");
        strcpy(frase.frase,ptr);
        ptr=strtok(NULL,";");
        incluirNaLista(frase);
        tamanho++;

    }
    fclose(pont_arq);

    elemento lista[tamanho-1];
    elemento *palavraAux;
    //palavraAux= ptr_primeira->ptr_prox;
    i=0;
    int numero=SorteiaPalavra(tamanho-1);
    while(palavraAux!= NULL){
        if(i==numero){
             strcpy( palavraSorteada,palavraAux->frase);
        }
        //palavraAux=palavraAux->ptr_prox;
        i++;
    }
    limparLista();
    return palavraSorteada;
}
void CriarListaVazia(){
    ptr_primeira=(elemento *)malloc(sizeof(elemento));
    ptr_ultima=ptr_primeira;
}
void incluirNaLista(elemento frase){
    elemento *palavraAux;
    palavraAux = (elemento *)malloc(sizeof(elemento));

    strcpy( palavraAux->frase,frase.frase);

    ptr_ultima->ptr_prox=palavraAux;
    ptr_ultima=ptr_ultima->ptr_prox;
    palavraAux->ptr_prox=NULL;
}
int SorteiaPalavra(int faixa){
    srand( (unsigned)time(NULL) );
    return  rand() % faixa;
}

void limparLista()//Remove todos os nós da Lista
{
    elemento *no = ptr_primeira, *aux;
    while (no != NULL)
    {
        aux = no;
        no = no->ptr_prox;
        free (aux);
    }
    ptr_primeira = NULL;
    ptr_ultima=NULL;
}

void JokenPo(){
	int ponto_jogador = 0, ponto_computador = 0;
	int Jogador;
	int i;
	int computador_jogada, controlador;
	int melhor_de;
	printf("Digite quantas vezes você quer jogar:");
	scanf("%d", &melhor_de);
	system("cls");
	for (i = 0; i < melhor_de; i++){
		printf("======================================");
		printf("\n 1 - PEDRA | 2 - PAPEL | 3 - TESOURA\n");
		printf("======================================\n");
		printf("JOGADA: ");
		scanf("%d", &Jogador);
		while (1){
		if (Jogador < 1 || Jogador > 3){
			printf("Tente novamente:");
			scanf("%d", &Jogador);
		}
		else{
			break;
		}
		}
		srand(time(NULL));
		computador_jogada = rand();
		while (computador_jogada != 3 && computador_jogada != 2 && computador_jogada != 1){
		computador_jogada = rand();
	}
	if (Jogador == 1 && computador_jogada == 1){
		printf("Empate.");
	}
	if (Jogador == 1 && computador_jogada == 2){
		printf("Você perdeu! Papel vence Pedra.");
		ponto_computador += 1;
	}
	if (Jogador == 1 && computador_jogada == 3){
		printf("Você venceu! Pedra vence Tesoura.");
		ponto_jogador += 1;
	}
	if (Jogador == 2 && computador_jogada == 1){
		printf("Você venceu! Papel vence Pedra.");
		ponto_jogador += 1;
	}
	if (Jogador == 2 && computador_jogada == 2){
		printf("Empate!");
	}
	if (Jogador == 2 && computador_jogada == 3){
		printf("Você perdeu! Tesoura vence Papel.");
		ponto_computador += 1;
	}
	if (Jogador == 3 && computador_jogada == 1){
		printf("Você perdeu! Pedra vence Tesoura.");
		ponto_computador += 1;
	}
	if (Jogador == 3 && computador_jogada == 2){
		printf("Você venceu! Tesoura vence Papel.");
		ponto_jogador += 1;
	}
	if (Jogador == 3 && computador_jogada == 3){
		printf("Empate!");
	}
	
	fflush(stdin);
	printf("\n=======================");
	printf("\nPontuação atual:");
	printf("\nJOGADOR:    %d", ponto_jogador);
	printf("\nCOMPUTADOR: %d", ponto_computador);
	printf("\n========================");
	getch();
	system("cls");
}
	if (ponto_jogador > ponto_computador){
		printf("\n=======================");
		printf("\nVENCEDOR: JOGADOR.");
		printf("\nVenceu com %d a %d", ponto_jogador, ponto_computador);
		printf("\n=======================");
	}
	
	if (ponto_jogador < ponto_computador){
		printf("\n=======================");
		printf("\nVENCEDOR: COMPUTADOR.");
		printf("\nVenceu com %d a %d", ponto_computador, ponto_jogador);
		printf("\n=======================");
	}
	
	if (ponto_jogador == ponto_computador){
		printf("\n=======================");
		printf("\nEmpate!");
		printf("\nEmpatou de %d a %d", ponto_jogador, ponto_computador);
		printf("\n=======================");
	}
	
}

int JogoDaVelha(){

    // estrutura de dados?
    // L e C representam localizações numa matriz para o tabuleiro 3x3 do jogo da velha.
    int l, c, linha, coluna, jogador, ganhou, jogadas, opcao, limit;
    char jogo[3][3];
    
    do{ // deseja jogar novamente?
        jogador = 1;
        ganhou = 0;
        jogadas = 0;
        // como inicializar nossa estrutura de dados?
        for(l = 0; l < 3; l++){
            for(c = 0; c < 3; c++){
                jogo[l][c] = ' ';
            }
        }
        stop:
		fflush(stdin);
		limit = 0;

        do{ // esse laço fica rodando até completar as 9 jogadas (quando o tabuleiro estara completo ou até alguém ganhar.
            // esse laço também desenha todo o tabuleiro, \t serve para dar um espaçamento, diferente do \n que é uma quebra de linha.
            // 
            printf("\n\n\t 0   1   2\n\n");
            for(l = 0; l < 3; l++){
                for(c = 0; c < 3; c++){
                    if(c == 0)
                        printf("\t");
                    printf(" %c ", jogo[l][c]);
                    if(c < 2)
                        printf("|");
                    if(c == 2)
                        printf("  %d", l);
                }
                if(l < 2)
                    printf("\n\t-----------");
                printf("\n");
            }

            // ler coordenadas
            
            do{
                printf("\nJOGADOR 1 = 0\nJOGADOR 2 = X\n");
                printf("\nJOGADOR %d: Digite a linha e a coluna que deseja jogar: ", jogador);
                scanf("%d", &linha);
                scanf("%d", &coluna);
                limit ++;
                
                if (limit == 19){
                	system("cls");
					goto stop;
				}
                

                
            }while(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');

            // salvar coordenadas
            if(jogador == 1){
                jogo[linha][coluna] = '0';
                jogador++;
                limit = 0;
                system("cls");
            }
            else{
                jogo[linha][coluna] = 'X';
                jogador = 1;
                limit = 0;
                system("cls");
            }
            jogadas++;

            // alguém ganhou por linha
            if(jogo[0][0] == '0' && jogo[0][1] == '0' && jogo[0][2] == '0' ||
               jogo[1][0] == '0' && jogo[1][1] == '0' && jogo[1][2] == '0' ||
               jogo[2][0] == '0' && jogo[2][1] == '0' && jogo[2][2] == '0'){
                printf("\nParabens! O jogador 1 venceu por linha!\n");
                ganhou = 1;
                limit = 0;
            }

            if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
               jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
               jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X'){
                printf("\nParabens! O jogador 2 venceu por linha!\n");
                ganhou = 1;
                limit = 0;
            }

            // alguém ganhou por coluna
            if(jogo[0][0] == '0' && jogo[1][0] == '0' && jogo[2][0] == '0' ||
               jogo[0][1] == '0' && jogo[1][1] == '0' && jogo[2][1] == '0' ||
               jogo[0][2] == '0' && jogo[1][2] == '0' && jogo[2][2] == '0'){
                printf("\nParabens! O jogador 1 venceu por coluna!\n");
                ganhou = 1;
                limit = 0;
            }

            if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
               jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
               jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X'){
                printf("\nParabens! O jogador 2 venceu por coluna!\n");
                ganhou = 1;
                limit = 0;
            }

            // alguém ganhou na diagonal principal
            if(jogo[0][0] == '0' && jogo[1][1] == '0' && jogo[2][2] == '0'){
                printf("\nParabens! O jogador 1 venceu na diag. principal!\n");
                ganhou = 1;
                limit = 0;
            }

            if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X'){
                printf("\nParabens! O jogador 2 venceu na diag. principal!\n");
                ganhou = 1;
                limit = 0;
            }

            // alguém ganhou na diagonal secundária
            if(jogo[0][2] == '0' && jogo[1][1] == '0' && jogo[2][0] == '0'){
                printf("\nParabens! O jogador 1 venceu na diag. secindaria!\n");
                ganhou = 1;
                limit = 0;
            }

            if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X'){
                printf("\nParabens! O jogador 2 venceu na diag. secundaria!\n");
                ganhou = 1;
                limit = 0;
            }
        }while(ganhou == 0 && jogadas < 9);

        // imprimir jogo
        printf("\n\n\t 0   1   2\n\n");
        for(l = 0; l < 3; l++){
            for(c = 0; c < 3; c++){
                if(c == 0)
                    printf("\t");
                printf(" %c ", jogo[l][c]);
                if(c < 2)
                    printf("|");
                if(c == 2)
                    printf("  %d", l);
            }
            if(l < 2)
                printf("\n\t-----------");
            printf("\n");
        }

        if(ganhou == 0){
            printf("\nO jogo finalizou sem ganhador!\n");
        }
        
        getch();
        system("cls");
        printf("\nDigite 1 para jogar novamente: \n");
        scanf("%d", &opcao);
        system("cls");
    }while(opcao == 1);
	
    return 0;
}

void main(){
	setlocale(LC_ALL, "");	
	
	int jogo;
	
	topo: 
	system ("cls");
	
	printf("****** Bem-vindos ao D&L-Games ******\n");
	printf ("************* J O G O S *************\n");
	printf ("1 –Forca\n2 –Jogo da Velha\n3 –JokenPo\n4- Listar Integrantes\n5- Sair\n");
	printf ("*************************************\n");
	fflush (stdin);
	scanf ("%d", &jogo);
	system ("cls");
	
	switch (jogo){
	
	case 1:
	jogoDaForca ();
	break;
	
	case 2:
	JogoDaVelha();
	break;
	
	case 3: 
	JokenPo();
	break;
	
	case 4:

    system("cls");
    printf("===========================================================================");
    printf("\n     ALUNO: Francisco Daniel Sampaio da Silva // MATRÍCULA: 2021010365");
    printf("\n     ALUNO: Lucas     Nobre  Fernandes        // MATRÍCULA: 2021010536");
    printf("\n===========================================================================");
    getch();
    goto topo;
    break;
    
    case 5:
    
    printf("Obrigado por jogar !!!");
    break;
	
	default:
	printf ("Opção inválida");
	}
}
