#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long compBs=0, compSs=0, compIs=0, compHs;

void troca(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b=temp;
}// fim troca
//----------------------
void geraVet(int v[], int n){
	int i;
	srand(time(NULL));
	for(i=0;i<n;i++)
	   v[i]=rand()%500;
}// fim geraV
//-----------------------------
void printVetor(int v[],int n){
	int i;
	for(i=0;i<n;i++)
	  printf("%d |",v[i]);
	printf("\n");  
}// fim printVetor
//-----------------------------
void printVetor2(int v[],int ini, int fim){
	int i;
	for(i=ini;ini<=fim;i++)
	  printf("%d |",v[i]);
	printf("\n");  
}// fim printVetor - Busca Binária
//--------- Bubble Sort -----------------
void bsort(int v[], int n){
	int i,j;
	for(i=1;i<n;i++){ // fases
		for(j=0;j<n-i;j++){ // comparações
			compBs++;//
			if(v[j]>v[j+1]){
				troca(&v[j],&v[j+1]);
			}// fim if
		}// fim for j
	}// fim for i
}
//------------- Selection Sort ---------------
int minIndex(int v[], int i, int n){
	int j, imenor = i;
	for(j=i+1;j<n;j++){
		compSs++;
		if(v[j]<v[imenor])
			imenor=j;
    }// fim for
	return imenor;		
}

void ssort(int v[], int n){
	int i, indiceMenor;
	for(i=0;i<n-1;i++){
		indiceMenor = minIndex(v,i,n);
		troca(&v[i], &v[indiceMenor]);
	}// fim for
}
//-------------- Isort--------------------------
void insert(int v[], int i){
	int eleito = v[i];
	int c = i-1;
	while(c>=0 && eleito<v[c]){
		compIs++; // mudar
		v[c+1] = v[c]; // deslocar
		c--;
	}//fim while
	compIs++;
	v[c+1] = eleito;
}

void isort(int v[], int n){
	int i;
	for(i=1;i<n;i++){
		insert(v,i);
	}//fim for
}
//--------------Heap Sort-------------------------
  void criaHeap(int v[], int n, int i) {
    int pai = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
  
    if (esquerda < n && v[esquerda] > v[pai]){
    	pai = esquerda;
  compHs++;
	}
      
    if (direita < n && v[direita] > v[pai]){
      pai = direita;
      compHs++;
  }
    if (pai != i) {
      troca(&v[i], &v[pai]);
      compHs++;
      criaHeap(v, n, pai);
    }
  }
  
  void hsort(int v[], int n) {
  	
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
      criaHeap(v, n, i);
  
    for (i = n - 1; i >= 0; i--) {
      troca(&v[0], &v[i]);
  
      criaHeap(v, i, 0);
    }
  }

