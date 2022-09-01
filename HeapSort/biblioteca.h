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
//--------------------------------
void hsort (int *x, int n) { 
int i, e, s, f; 
for (i=1; i<n; i++)
{
	e = x[i];
	s = i;
	f = (s-1)/2;
	while (s>0 && x[f]<e){
		x[s] = x[f];
		s = f;
		f = (s-1)/2;
		compHs++;
	}
	x[s] = e;
}
}
