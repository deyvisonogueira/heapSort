#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
  
void heapSort(int v[], int n) {	
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
      criaHeap(v, n, i);
  
    for (i = n - 1; i >= 0; i--) {
      troca(&v[0], &v[i]);
       
      criaHeap(v, i, 0);
    }
  }
int main(){
	int *vet, n;
	printf("Tamanho do vetor:");
	scanf("%d",&n);
	vet = malloc(sizeof(int)*n);// alocando o vetor dinamicamente
	geraVet(vet,n);
	printVetor(vet,n);
	heapSort(vet,n);
	printf("Vetor ordenado:\n");
    printVetor(vet,n);  
	return 0;
}
