#include <stdio.h>
#include <stdlib.h>

int particiona(int *V, int inicio, int final){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = V[inicio];
    while (esq < dir){
          while(V[esq] <= pivo)
          esq++;
          while(V[dir] > pivo)
          dir--;
          if(esq < dir){
                 aux = V[esq];
                 V[esq] = V[dir];
                 V[dir] = aux;
                 }
          }
          V[inicio] = V[dir];
          V[dir] = pivo;
          return dir;
    }
    
void quickSort( int *V, int inicio, int fim){
     int pivo;
     if(fim > inicio){
             pivo = particiona(V, inicio, fim);
             quickSort(V, inicio, pivo-1);
             quickSort(V, pivo+1, fim);
     }
}

int main(){
	
	int tamanho;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tamanho);
	
	int *arr = (int *)malloc(tamanho * sizeof(int));
	printf("Digite os elementos do vetor: \n");
	for(int i =0;i<tamanho;i++){
		scanf("%d", &arr[i]);
	}
	
	quickSort(arr,0,tamanho-1);
	
	printf("Vetor ordenado: \n");
	for(int i=0; i< tamanho; i++){
		printf("%d", arr[i]);
	}
	
	free(arr);
	
	return 0;
}
