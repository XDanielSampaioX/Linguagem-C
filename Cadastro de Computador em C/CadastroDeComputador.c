#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <dirent.h>
#include <windows.h>
#include <locale.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{

    setlocale(LC_ALL, "");
    char repetir_pesquisa, decidir_apagar, repetir_editar2, continuar_backup, repetir_editar;
    FILE *file;
    FILE *armazena;
    FILE *backup;
    char palavras_do_arquivo[100];
    DIR *dir;
    struct dirent *lsdir;
    int opcao, opcao1, opcao2, opcao3, opcao4, i;
    int quant = 0;
    FILE *pont_arq;
    FILE *arq;
    int pasta;
    char escolha_pesquisa[100];
    char aux[100];

    // Criando pasta onde os arquivos serão armazenados;
    if (CreateDirectory("Arquivos", NULL))
    {
    }

    else
    {
    }
    char *VarPasta = "Arquivos"; // Atribui à variável VarPasta a pasta criada no CreateDirectory;
    {
        chdir(VarPasta); // Modifica o caminho os dados serão salvos;
    }

    struct referencia
    {

        char nome_computador[100], ip[100], SO[100], Ver_SO[100], Responsavel[100], Departamento[100];

    }

    Cadastro[1000];

    char nome5[100];

    while (opcao != 9)
    {
        system("cls");
        printf("=========================================");
        printf("\n     Bem-vindos ao sistema Darth\n");
        printf("\n     Menu do sistema:");
        printf("\n     1- Cadastrar um novo computador");
        printf("\n     2- Consultar um computador");
        printf("\n     3- Alterar um computador");
        printf("\n     4- Excluir um computador");
        printf("\n     5- Listar todos os computadores");
        printf("\n     6- Gerar backup");
        printf("\n     7- Listar Desenvolvedores do projeto");
        printf("\n     8- Sair");
        printf("\n=========================================\n");

        printf("\n  >>>Digite aqui o que deseja fazer:");
        fflush(stdin);
        memset(&opcao, 0, sizeof(opcao));
        scanf("%d", &opcao);

        switch (opcao)

        {

        case 1:
            system("cls");
            printf("Informe quantos computadores quer cadastrar: \n");
            fflush(stdin);
            memset(&quant, 0, sizeof(quant));
            scanf("%d", &quant);

            for (i = 1; i <= quant; i++)
            {
                system("cls");
                printf("\n INICIANDO CADASTRO %d\n", i);
                printf("----------------\n");
                printf("\nNome do computador: ");
                fflush(stdin);
                scanf("%[^\n]s", Cadastro[i].nome_computador);
                printf("\nInforme o IP da máquina: ");
                fflush(stdin);
                scanf("%[^\n]s", Cadastro[i].ip);

                strcpy(aux, Cadastro[i].ip); // Copia um conteudo armazenado em uma variável para outra;

                printf("\nInforme qual o sistema operacional instalado: ");
                fflush(stdin);
                scanf("%[^\n]s", Cadastro[i].SO);
                printf("\nInforme qual a versão do SO: ");
                fflush(stdin);
                scanf("%[^\n]s", Cadastro[i].Ver_SO);
                printf("\nInforme qual o resposável pela máquina: ");
                fflush(stdin);
                scanf("%[^\n]s", Cadastro[i].Responsavel);
                printf("\nInforme qual o setor/departamento resposável poe ele: ");
                fflush(stdin);
                scanf("%[^\n]s", Cadastro[i].Departamento);
                system("pause");
                system("cls");

                strcat(aux, ".txt");        // Concatena a segunda palavra à primeira;
                pont_arq = fopen(aux, "w"); // Abre o arquivo e edita, caso ele não exista ele cria;

                fprintf(pont_arq, "%s\n", Cadastro[i].nome_computador); // fprintf: Escreve dentro do arquivo;
                fprintf(pont_arq, "%s\n", Cadastro[i].ip);
                fprintf(pont_arq, "%s\n", Cadastro[i].SO);
                fprintf(pont_arq, "%s\n", Cadastro[i].Ver_SO);
                fprintf(pont_arq, "%s\n", Cadastro[i].Responsavel);
                fprintf(pont_arq, "%s\n", Cadastro[i].Departamento);

                fclose(pont_arq); // Fecha o arquivo;
            }
            break;

        case 2:
            while (true)
            {
                system("cls");
                printf("\nDigite o computador que voce deseja pesquisar:");
                fflush(stdin);
                scanf("%s", &escolha_pesquisa);

                strcat(escolha_pesquisa, ".txt");

                armazena = fopen(escolha_pesquisa, "r"); // Lê arquivos;

                if (armazena == NULL)
                {
                    printf("ERROR\n");
                    getch();
                }

                system("cls");
                while (fgets(palavras_do_arquivo, 100, armazena) != NULL) // Exibe conteudo do arquivo
                {
                    printf("%s", palavras_do_arquivo);
                }
                fclose(armazena);

                printf("\nVoce deseja pesquisar algo mais? [S/N]");
                fflush(stdin);
                scanf("%s", &repetir_pesquisa);
                if (repetir_pesquisa == 'N' || repetir_pesquisa == 'n')
                {
                    break;
                }

                if (repetir_pesquisa == 'S' || repetir_pesquisa == 's')
                {
                }

                else
                {
                    system("cls");
                    printf("Opção Inválida.");
                    getch();
                }
            }
            break;
        case 3:

            while (repetir_editar != 's')
            {
                system("cls");
                printf("\nDigite o computador que voce deseja pesquisar:");
                fflush(stdin);
                scanf("%s", &escolha_pesquisa);

                strcat(escolha_pesquisa, ".txt");

                armazena = fopen(escolha_pesquisa, "r");

                if (armazena == NULL)
                {
                    printf("ERROR\n");
                    getch();
                    break;
                }

                while (repetir_editar2 != 'n')
                {
                    arq = fopen(escolha_pesquisa, "r");

                    system("cls");
                    char palavra[100];
                    fgets(palavra, 100, arq) != NULL;
                    printf("%s", palavra);

                    char palavra2[100];
                    fgets(palavra2, 100, arq) != NULL;
                    printf("%s", palavra2);

                    char palavra3[100];
                    fgets(palavra3, 100, arq) != NULL;
                    printf("%s", palavra3);

                    char palavra4[100];
                    fgets(palavra4, 100, arq) != NULL;
                    printf("%s", palavra4);

                    char palavra5[100];
                    fgets(palavra5, 100, arq) != NULL;
                    printf("%s", palavra5);
                    char palavra6[100];
                    fgets(palavra6, 100, arq) != NULL;
                    fclose(arq);
                    printf("%s", palavra6);

                    int decidir;
                    printf("\nDeseja editar qual linha? [1-6]");
                    fflush(stdin);
                    memset(&decidir, 0, sizeof(decidir));
                    scanf("%d", &decidir);
                    if (decidir == 1)
                    {
                        arq = fopen(escolha_pesquisa, "w");
                        char parte1[100];
                        printf("\nDigite o que quer escrever:");
                        fflush(stdin);
                        fgets(parte1, 100, stdin);
                        fprintf(arq, "%s", parte1);
                        fprintf(arq, "%s", palavra2);
                        fprintf(arq, "%s", palavra3);
                        fprintf(arq, "%s", palavra4);
                        fprintf(arq, "%s", palavra5);
                        fprintf(arq, "%s", palavra6);
                        fclose(arq);
                    }
                    if (decidir == 2)
                    {
                        arq = fopen(escolha_pesquisa, "w");
                        char parte2[100];
                        printf("\nDigite o que quer escrever:");
                        fflush(stdin);
                        fgets(parte2, 100, stdin);
                        ;
                        fprintf(arq, "%s", palavra);
                        fprintf(arq, "%s", parte2);
                        fprintf(arq, "%s", palavra3);
                        fprintf(arq, "%s", palavra4);
                        fprintf(arq, "%s", palavra5);
                        fprintf(arq, "%s", palavra6);

                        fclose(arq);
                        printf("\nGravado!");
                    }
                    if (decidir == 3)
                    {
                        arq = fopen(escolha_pesquisa, "w");
                        char parte3[100];
                        printf("\nDigite o que quer escrever:");
                        fflush(stdin);
                        fgets(parte3, 100, stdin);
                        fprintf(arq, "%s", palavra);
                        fprintf(arq, "%s", palavra2);
                        fprintf(arq, "%s", parte3);
                        fprintf(arq, "%s", palavra4);
                        fprintf(arq, "%s", palavra5);
                        fprintf(arq, "%s", palavra6);

                        fclose(arq);
                        printf("\nGravado!");
                    }
                    if (decidir == 4)
                    {
                        arq = fopen(escolha_pesquisa, "w");
                        char parte4[100];
                        printf("\nDigite o que quer escrever:");
                        fflush(stdin);
                        fgets(parte4, 100, stdin);
                        fprintf(arq, "%s", palavra);
                        fprintf(arq, "%s", palavra2);
                        fprintf(arq, "%s", palavra3);
                        fprintf(arq, "%s", parte4);
                        fprintf(arq, "%s", palavra5);
                        fprintf(arq, "%s", palavra6);

                        fclose(arq);
                        printf("\nGravado!");
                    }
                    if (decidir == 5)
                    {
                        arq = fopen(escolha_pesquisa, "w");
                        char parte5[100];
                        printf("\nDigite o que quer escrever:");
                        fflush(stdin);
                        fgets(parte5, 100, stdin);
                        fprintf(arq, "%s", palavra);
                        fprintf(arq, "%s", palavra2);
                        fprintf(arq, "%s", palavra3);
                        fprintf(arq, "%s", palavra4);
                        fprintf(arq, "%s", parte5);
                        fprintf(arq, "%s", palavra6);

                        fclose(arq);
                        printf("\nGravado!");
                    }

                    if (decidir == 6)
                    {
                        arq = fopen(escolha_pesquisa, "w");
                        char parte6[100];
                        printf("\nDigite o que quer escrever:");
                        fflush(stdin);
                        fgets(parte6, 100, stdin);
                        fprintf(arq, "%s", palavra);
                        fprintf(arq, "%s", palavra2);
                        fprintf(arq, "%s", palavra3);
                        fprintf(arq, "%s", palavra4);
                        fprintf(arq, "%s", palavra5);
                        fprintf(arq, "%s", parte6);

                        fclose(arq);
                        printf("\nGravado!");
                    }
                    else if (decidir > 6 || decidir < 1)
                    {
                        printf("\nOpcao invalida.");
                    }

                    printf("\nDeseja alterar mais alguma coisa? [S/N]");
                    fflush(stdin);
                    memset(&repetir_editar, 0, sizeof(repetir_editar));
                    scanf("%s", &repetir_editar);
                    if (repetir_editar == 's' || repetir_editar == 'S')
                    {
                    }

                    if (repetir_editar == 'n' || repetir_editar == 'N')
                    {
                        break;
                    }

                    if (repetir_editar != 's' && repetir_editar != 'S' && repetir_editar != 'N' && repetir_editar != 'n')
                    {
                        system("cls");
                        printf("Opção Inválida.");
                        getch();
                    }
                }
                break;
            }
            break;

        case 4:
            while (true)
            {
                system("cls");
                int arquivo;
                char arq[100];

                // A varíavel File está apontando para o endereço do arquivo.
                FILE *file;
                printf("\nNome do arquivo que você deseja deletar:");
                fflush(stdin);
                scanf("%s", &arq);

                strcat(arq, ".txt");

                // fopen abre o arquivo que foi concatenado, em modo de leitura.
                // a condição file = fopen(arq, "r")
                // significa que se o arquivo existir, ele deve fazer o que o if diz.
                if (file = fopen(arq, "r"))
                {
                    fclose(file);
                    printf("\nExiste!, apagando...");

                    arquivo = remove(arq); // remove faz com que o arquivo digitado seja deletado.
                    printf("Deletado.");

                    getch();
                }
                else
                {
                    system("cls");
                    printf("Erro, arquivo inexistente.");
                    getch();
                }
                system("cls");
                printf("\nDeseja tentar de novo? [S/N]");
                memset(&decidir_apagar, 0, sizeof(decidir_apagar));
                fflush(stdin);
                scanf("%s", &decidir_apagar);
                if (decidir_apagar == 'n' || decidir_apagar == 'N')
                {
                    break;
                }

                if (decidir_apagar == 's' || decidir_apagar == 'S')
                {
                }
                else
                {
                    system("cls");
                    printf("Opção Inválida.");
                    getch();
                }
            }

            break;

        case 5:
        {
            system("cls");
            DIR *folder;
            struct dirent *entry;

            folder = opendir("."); // opendir abre o diretório, no caso a pasta ''Arquivos''.
            printf("=========================================\n");

            /*
            Eses laço faz a leitura de todo o diretório "Arquivos"
            quando a leitura é concluida, o laço termina.
            */

            while ((entry = readdir(folder)))

            {
                // aqui é mostrado todos os arquivos dentro do diretório.
                printf("%s\n",
                       entry->d_name);
            }
            printf("=========================================");

            // o closedir fecha a pasta que antes foi aberta pelo opendir.

            closedir(folder);

            getch();
        }
        break;

        case 6:

            while (true)
            {
                system("cls");
                int rep;
                char escolha_backup[100];
                char auxiliar[100];
                char auxiliar1[100];
                printf("\n\nDigite o computador que voce deseja realizar o backup:");
                fflush(stdin);
                scanf("%s", &escolha_backup);

                strcpy(auxiliar1, escolha_backup);
                strcat(auxiliar1, ".txt");

                if (file = fopen(auxiliar1, "r"))
                {
                    fclose(file);
                    printf("\nVerificação completa, prosseguindo.");
                    strcpy(auxiliar, escolha_backup);
                    strcat(escolha_backup, ".txt");
                    strcat(auxiliar, ".bkp");
                    FILE *arq;
                    FILE *file1 = fopen(escolha_backup, "r");
                    FILE *file2 = fopen(auxiliar, "w");
                    char leitor[1000];

                    /*
                   Esse laço pega toda a informação do arquivo 1
                   e passa para o arquivo 2.
                   */

                    while (fgets(leitor, 1000, file1) != NULL)
                    {
                        fputs(leitor, file2);
                    }

                    fclose(file1);
                    fclose(file2);
                }
                else
                {
                    printf("Arquivo não existe.");
                    getch();
                }

                system("cls");
                printf("Deseja fazer backup de mais algum computador? [S/N]");
                fflush(stdin);
                scanf("%s", &continuar_backup);
                if (continuar_backup == 'N' || continuar_backup == 'n')
                {
                    break;
                }

                if (continuar_backup == 'S' || continuar_backup == 's')
                {
                }
                else
                {
                    system("cls");
                    printf("Opção Inválida.");
                    getch();
                }
            }
            break;

        case 7:

            system("cls");
            printf("===========================================================================");
            printf("\n     ALUNO: Francisco Daniel Sampaio da Silva // MATRÍCULA: 2021010365");
            printf("\n     ALUNO: Lucas     Nobre  Fernandes        // MATRÍCULA: 2021010536");
            printf("\n===========================================================================");
            getch();
            break;

        case 8:

            system("cls");
            printf("\n Você realmente deseja sair do sistem?\n");
            printf(" 1- Sim\n 2- Não");
            printf("\n\n");
            scanf("%d", &opcao2);

            switch (opcao2)
            {

            case 1:
                system("cls");
                printf("\n Obrigado por usar nosso sistema. Volte sempre !\n");
                system("pause");
                return 0;
                break;

            case 2:
                system("cls");
                break;

            default:
            	system ("cls");
            	printf ("Opção inválida");
            	getch ();
            	system ("cls");
                break;
            }
            break;
        default:
            printf("\nOpção inválida !\n");
            getch();
            break;
        }
    }
}
