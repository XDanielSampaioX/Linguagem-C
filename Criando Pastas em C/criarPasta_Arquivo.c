#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <dirent.h>
 
int main(void){
	// Define o caminho onde ser� criada a pasta
    char *ponteiro = "C:\\Users\\DANIE\\OneDrive\\�rea de Trabalho\\exemplo\\criar pasta\\dire";
    
    // Cria a pasta usando o comando "system()"
    system("mkdir dire");
	
	// Muda o diret�rio corrente para a pasta criada
	chdir(ponteiro);

	// Define o caminho e o nome do arquivo a ser criado dentro da pasta
	char *nomeArquivo = "dire\\arquivo.txt";

	// Cria o arquivo usando a fun��o "CreateFile()"
    HANDLE hArquivo = CreateFile(
    	nomeArquivo, // Nome do arquivo
    	GENERIC_WRITE, // Tipo de acesso (escrita)
    	0, // Nenhum compartilhamento
    	NULL, // Atributos de seguran�a padr�o
    	CREATE_NEW, // Cria um novo arquivo ou falha se j� existir
    	FILE_ATTRIBUTE_NORMAL, // Atributos do arquivo padr�o
    	NULL); // Nenhum template de arquivo

    // Verifica se o arquivo foi criado com sucesso
    if (hArquivo != INVALID_HANDLE_VALUE){
        printf("Arquivo criado com sucesso!\n\n");
        CloseHandle(hArquivo); // Fecha o arquivo
    } else {
        printf("Erro ao criar o arquivo.\n\n");
    }
}

