#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
  
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(int v[], int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
  
    if (esquerda < n && v[esquerda] > v[maior])
      maior = esquerda;
  
    if (direita < n && v[direita] > v[maior])
      maior = direita;
  
    if (maior != i) {
      swap(&v[i], &v[maior]);
      heapify(v, n, maior);
    }
  }
  
  // Main function to do heap sort
  void heapSort(int v[], int n) {
    // Build max heap
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
      heapify(v, n, i);
  
    // Heap sort
    for (i = n - 1; i >= 0; i--) {
      swap(&v[0], &v[i]);
  
      // Heapify root element to get highest element at root again
      heapify(v, i, 0);
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
