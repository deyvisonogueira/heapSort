#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(){
	int *vetBs, *vetSs, *vetIs, *vetHs, n, i;
	float ini,fim, tempo;
	printf("Tamanho do vetor:");
	scanf("%d",&n);
	vetBs = malloc(sizeof(int)*n);// alocando o vetor dinamicamente
	vetSs = malloc(sizeof(int)*n);
	vetIs = malloc(sizeof(int)*n);
	vetHs = malloc(sizeof(int)*n);
	geraVet(vetBs,n);
	for(i=0;i<n;i++){
		vetSs[i] = vetBs[i];
		vetIs[i] = vetBs[i];
		vetHs[i] = vetBs[i];
	}//fim for
	//----------Bubble Sort----------
	ini = clock();
	bsort(vetBs,n);
	fim = clock();
	tempo = (fim - ini)/1000;
	printf("Tempo Bubble Sort(s):%.4f\n",tempo);
	printf("Comparacoes: %d\n",compBs);
	//----------Selection Sort----------
	ini = clock();
	ssort(vetSs,n);
	fim = clock();
	tempo = (fim - ini)/1000;
	printf("Tempo Selection Sort(s): %.4f\n",tempo);
	printf("Comparacoes: %d\n",compSs);
	//----------Insertion Sort----------
	ini = clock();
	isort(vetIs,n);
	fim = clock();
	tempo = (fim - ini)/1000;
	printf("Tempo Insertion Sort(s): %.4f\n",tempo);
	printf("Comparacoes: %d\n",compIs);		
	//----------Heap Sort----------
	ini = clock();
	hsort(vetHs,n);
	fim = clock();
	tempo = (fim - ini)/1000;
	printf("Tempo Heap Sort(s):%.4f\n",tempo);
	printf("Comparacoes: %d\n",compHs);
	return 0;
}

