#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <locale.h>


// Assinatura do Menu
void menu ();

// Assinatura de Seletion Sort
void seletionSort ();

// Assinaturas de Quick Sort
int particiona_random();
void troca(); 
int particiona();
void quicksort();

// Assinaturas de Insert Sort
void insertSort();

// Assinaturas de Merge Sort
void mergeSort ();
void merge ();

// Assinaturas de Heap Sort
void heapSort ();
void criarHeapSort ();

void main() {
	setlocale(LC_ALL, "portuguese");
  	int opcao;
	int i;
	time_t tIni, tFim;
	int vetOriginal[3000];
	
	// popula um vetor aleatorio
	srand(time(NULL));
  	for ( i = 0; i < 3000; i++) {
    	vetOriginal[i] = rand() % 100;
  	}
	
  	while (opcao != 7) {
	 	 
  		menu ();
	  	printf("\n\nEscolha qual algoritmo de ordenações de dados utilizar: ");
	  	fflush(stdin);
	  	scanf("%d", &opcao); 
	  	
	  	printf("\n");
	  
	  	switch (opcao) {
		  	case 1:
		  		tIni = time(NULL);
			  	printf("\n----------------------------------RESULTADO-----------------------------------\n");
			    printf("\nSelect Sort: \n");
			    
			    seletionSort (&vetOriginal);

  				printf("\n------------------------------------------------------------------------------\n");
  				tFim = time(NULL);
				printf("\tTempo em segundos: %f\n\n", difftime(tFim, tIni));
				printf ("Todos os caso:   O (N^2)\n");
			    getch ();
			    system ("cls");
				break;
		    
			case 2:
				tIni = time(NULL);
				printf("\n----------------------------------RESULTADO-----------------------------------\n");
			    printf("\nInsert Sort: \n");
			    insertSort(&vetOriginal, 3000);
			    
				printf ("\n");
					
				for (i=0; i<3000; i++){
				printf ("%d  ", vetOriginal[i]);
				}
				
			    printf("\n------------------------------------------------------------------------------\n");
			    tFim = time(NULL);
				printf("\tTempo em segundos: %f\n\n", difftime(tFim, tIni));
				printf ("Melhor caso: O (N)\n");
				printf ("Pior caso:   O (N^2)\n");
			    getch ();
			    system ("cls");
				break;
			    
			case 3:
				tIni = time(NULL);
				printf("\n----------------------------------RESULTADO-----------------------------------\n");
			  	printf("\nMerge Sort: \n");
	
			  	mergeSort(&vetOriginal, 0, 3000);
				merge(&vetOriginal, 0, 1500, 3000);
	
				printf ("\n\n");
	
				for (i=0; i<=3000; i++){
				printf("\%d  ", vetOriginal[i]);
				}
			  	printf("\n------------------------------------------------------------------------------\n");
			  	tFim = time(NULL);
				printf("\tTempo em segundos: %f\n\n", difftime(tFim, tIni));
				printf ("Todos os casos: O (N log N)\n");
				getch ();
			    system ("cls");
				break;
				
			case 4:
				tIni = time(NULL);
				printf("\n----------------------------------RESULTADO-----------------------------------\n");
				printf("\nHeap Sort: \n");
				
				heapSort(&vetOriginal, 3000);
				criarHeapSort(&vetOriginal, 0, 3000);	
				
				printf ("\n\n");
		   		for (i=0; i<3000; i++){
				printf("%d  ", vetOriginal[i]);   
				}
				printf("\n------------------------------------------------------------------------------\n");
				tFim = time(NULL);
				printf("\tTempo em segundos: %f\n\n", difftime(tFim, tIni));
				printf ("Em todos os casos: O(N log N)\n");
				getch ();
			    system ("cls");
				break;
				
			case 5:
				printf("\n----------------------------------RESULTADO-----------------------------------\n");
			    printf("\nQuick Sort: \n");
			    
			    tIni = time(NULL);
				int tam_vet = sizeof(vetOriginal) / sizeof(int); // determina o tamanho do vetor
				
				quicksort(&vetOriginal, 0, tam_vet - 1); // chamada do quicksort
			
				// mostra o vetor ordenado
				for(i = 0; i < tam_vet; i++){
					printf("%d ", vetOriginal[i]);
				}
				printf("\n");
				
				tFim = time(NULL);
				printf("\tTempo em segundos: %f\n\n", difftime(tFim, tIni));
				printf ("Melhor caso: O (N log N)\n");
				printf ("Pior caso:   O (N^2)\n");
			    printf("\n------------------------------------------------------------------------------\n");
			    getch ();
			    system ("cls");
				break;
    		case 6: 
				printf ("-----------------INTEGRANTES-----------------\n");
				printf ("Nome: Daniel Sampaio    Matricula: 2021010365\n");
				printf ("Nome: Ithalo lucas      Matricula: 2021010396\n");
				printf ("Nome: Waik Breno        Matricula: 2021020777\n");
				printf ("Nome: Jhully Emilly     Matricula: 2021010509\n");
				printf ("Nome: Werbeson Oliveira Matricula: 2021020827\n");
				printf ("---------------------------------------------\n");	
				getch ();
				system ("cls");
				break;
				
			case 7:
				printf("\n------------------------------------------------------------------------------\n");
			    printf("\nSAINDO...\n");
			    printf("\n\n-------------------------------------FIM--------------------------------------\n\n");
			    exit(1);
				getch ();
			    system ("cls");
				break;
				
			default:
				printf("\n------------------------------------------------------------------------------\n");
			    printf("\n		  	       OPÇÃO INVÁLIDA\n");
			    printf("\n------------------------------------------------------------------------------\n");
			    getch ();
			    system ("cls");
	  	}
	}
}

// Menu

void menu (){
	printf("\n-------------------------------------MENU-------------------------------------\n");
  	printf("\n1- Select Sort");
  	printf("\n2- Insert Sort");
  	printf("\n3- Merge Sort");
  	printf("\n4- Heap Sort");
  	printf("\n5- Quick Sort");
  	printf("\n6- Listar Integrantes");
  	printf("\n7- Sair");
	printf("\n------------------------------------------------------------------------------\n");
}

// Seletion Sort
void seletionSort (int *ptrVetOriginal){
	
	int i, x, aux;
   	 for (i = 0; i < 3000; ++i){
		for (x = i; x < 3000; ++x){
			if (ptrVetOriginal[i] > ptrVetOriginal[x]){
   	 		   aux = ptrVetOriginal[i];
 			   ptrVetOriginal[i] = ptrVetOriginal[x];
  			   ptrVetOriginal[x] = aux;
   		 	}
	  	}
		printf("%d  ", ptrVetOriginal[i]);
	}
}

// Insert Sort
void insertSort(int *ptrVetOriginal, int tam){
int i, j;
int aux;

	for(i=1; i <tam; i++){
		aux= ptrVetOriginal[i];
		
		for(j=i; (j>0)&&(aux< ptrVetOriginal[j-1]);j--){
			ptrVetOriginal[j]= ptrVetOriginal[j-1];
       }
   ptrVetOriginal[j]=aux;
   }
}

// Merge Sort
void mergeSort (int *ptrVetoriginal, int inicio, int fim){
	
	int meio;
	if (inicio< fim){
		meio= floor((inicio+fim)/2); // Dividir arredondando para o meio
		mergeSort(ptrVetoriginal, inicio, meio); // Chamadas recursivas para Dividir ate a primeira metade 
		mergeSort(ptrVetoriginal, meio+1, fim); // Chamadas recursivas para Dividir ate a Segunda metade 
		merge (ptrVetoriginal, inicio, meio, fim); // Reorganizar vetor Conquistar
	}
}

void merge (int *ptrVetoriginal, int inicio, int meio, int fim){
	int *espacoReservado, inicioParte01, inicioParte02, tamanho, i, j, k;
	int fim1= 0, fim2=0;
	tamanho= fim-inicio+1; 
	inicioParte01= inicio; // Primeira Metade
	inicioParte02= meio+ 1; // Segunda Metade
	espacoReservado= (int *)malloc(tamanho*sizeof(int)); // Alocando Memória
	
	if (espacoReservado!= NULL){
		for (i=0; i<tamanho; i++){
			if (!fim1 && !fim2){
				if (ptrVetoriginal[inicioParte01]< ptrVetoriginal[inicioParte02]){
					espacoReservado[i]= ptrVetoriginal[inicioParte01++];
				} else {
					espacoReservado[i]= ptrVetoriginal[inicioParte02++];
				} if (inicioParte01> meio){
					fim1= 1;
				} if (inicioParte02> fim){
					fim2=1;
				}
			} else {
				if (!fim1){
					espacoReservado[i]= ptrVetoriginal[inicioParte01++]; // Serve para quando não há valores a serem comparados
				} else {
					espacoReservado[i]= ptrVetoriginal[inicioParte02++]; // Serve para quando não há valores a serem comparados
				}
			}
		}
	}
	for (j=0, k= inicio; j< tamanho; j++, k++){
		ptrVetoriginal[k]= espacoReservado[j];
	}
	free (espacoReservado); // Desalocar o Espaço reservado para não ficar ocupando espaço na memória 
}

// Heap Sort
void heapSort (int *ptrVetOriginal, int posicao){
	
	int i, aux;
	for ((i=(posicao-1)/2); i>=0; i--){
		criarHeapSort (ptrVetOriginal, i, posicao-1);
	}
	for (i= posicao-1; i>=1; i--){
		aux= ptrVetOriginal[0];
		ptrVetOriginal[0]= ptrVetOriginal[i];
		ptrVetOriginal[i]= aux;
		criarHeapSort (ptrVetOriginal, 0, i-1);
	}
}

void criarHeapSort (int *ptrVetOriginal, int inicio, int fim){
	
	int auxPai= ptrVetOriginal[inicio];
	int filho= inicio*2+ 1;
	while (filho<= fim){
		if (filho< fim){
			if (ptrVetOriginal[filho] < ptrVetOriginal[filho+1]){
				filho= filho+1;
			}
		} if (auxPai< ptrVetOriginal[filho]){
			ptrVetOriginal[inicio]= ptrVetOriginal[filho];
			inicio= filho;
			filho= 2*inicio+ 1;
		} else {
			filho= fim+ 1;
		}
	}
	ptrVetOriginal[inicio]= auxPai;
}

// Quick Sort
// escolhe um pivô aleatório para não acontecer o pior caso do quicksort
int particiona_random(int *ptrVetOriginal, int inicio, int fim) {
	int indice_pivo = (rand() % (fim - inicio + 1)) + inicio; // seleciona um número entre fim e inicio
	troca(ptrVetOriginal, indice_pivo, fim); // faz a troca para colocar no fim o pivô
	return particiona(ptrVetOriginal, inicio, fim);
}

// função que realiza a troca entre dois elementos
void troca(int *ptrVetOriginal, int i, int j) {
	int aux = ptrVetOriginal[i];
	ptrVetOriginal[i] = ptrVetOriginal[j];
	ptrVetOriginal[j] = aux;
}

// particiona e retorna o índice do pivô
int particiona(int *ptrVetOriginal, int inicio, int fim) {
	int pivo, indice_pivo, i;
	
	pivo = ptrVetOriginal[fim]; // supondo que o pivô é sempre o último elemento
	indice_pivo = inicio;
	
	for(i = inicio; i < fim; i++) {
		// verifica se o elemento é <= ao pivô
		if(ptrVetOriginal[i] <= pivo){
			troca(ptrVetOriginal, i, indice_pivo); // realiza a troca
			indice_pivo++;
		}
	}

	troca(ptrVetOriginal, indice_pivo, fim); 	// troca o pivô
	return indice_pivo;
}

void quicksort(int *ptrVetOriginal, int inicio, int fim) {
	if(inicio < fim) {
		int indice_pivo = particiona_random(ptrVetOriginal, inicio, fim); // retorna o índice do pivô
		// chamadas recursivas do quick_sort
		quicksort(ptrVetOriginal, inicio, indice_pivo - 1);
		quicksort(ptrVetOriginal, indice_pivo + 1, fim);
	}
}
