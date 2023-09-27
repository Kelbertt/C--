#include <stdlib.h>
#include <stdio.h>

// Struct "PriorityItem" para combinar a ordem de chegada e prioridade
typedef struct{
	int priority;
	int order;
}PriorityItem;

// Criação do heap a partir de certo elemento do array
void criaHeap(PriorityItem *vet, int pai, int fim){
    PriorityItem aux = vet[pai];
     int filho = 2 * pai + 1;
     while (filho <= fim){
           if (filho < fim){
                     if (vet[filho].priority < vet[filho + 1].priority){
                     filho++;
                     }
           }
           if( aux.priority < vet[filho].priority) {
               vet[pai] = vet[filho];
               pai = filho;
               filho = 2* pai + 1;
           }else{
                 filho = fim + 1;
           }
     }
     vet[pai] = aux;
}

//Função para construir o HeapMax
void criaHeapMax(PriorityItem *vet, int N){
	for(int i = (N-1)/2; i>=0; i--){
		criaHeapMax(vet, 0);
	}
}

// Criar heap & Ordenar dados
void heapSort(PriorityItem *vet, int N){
     int i;
	 PriorityItem aux;
     criaHeapMax(vet, N);
     for (i= N-1; i>=0; i--){
         aux = vet[0];
         vet[0] = vet[i];
         vet[i] = aux;
         criaHeap(vet, 0, i-1);
     }
}

int main(){
//==============================================================================

    PriorityItem vet[4] = {{23,4}, {22,4}, {22,6}, {21,5}};
  
    int N = 4;

   
    printf("Sem ordenar:\n");
    for (int i = 0; i < N; i++) {
        printf("%d,%d ", vet[i].priority, vet[i].order);
    }
    printf("\n");

    heapSort(vet, N);

    printf("Ordenado:\n");
    for (int i = 0; i < N; i++) {
         printf("%d,%d ", vet[i].priority, vet[i].order);
    }
    printf("\n");
    
//==============================================================================

    system("pause");
    return 0;
}

