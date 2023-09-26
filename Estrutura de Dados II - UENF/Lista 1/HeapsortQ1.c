#include <stdlib.h>
#include <stdio.h>

// Criação do heap a partir de certo elemento do array
void criaHeap(int *vet, int pai, int fim){
     int aux = vet[pai];
     int filho = 2 * pai + 1;
     while (filho <= fim){
           if (filho < fim){
                     if (vet[filho] < vet[filho + 1]){
                     filho++;
                     }
           }
           if( aux < vet[filho]) {
               vet[pai] = vet[filho];
               pai = filho;
               filho = 2* pai + 1;
           }else{
                 filho = fim + 1;
           }
     }
     vet[pai] = aux;
}

//Create heap & Sort data

void heapSort(int *vet, int N){
     int i, aux;
     for(i=(N - 1)/2; i>=0; i--){
              criaHeap(vet, i, N-1);
     }
     for (i= N-1; i>=0; i--){
         aux = vet[0];
         vet[0] = vet[i];
         vet[i] = aux;
         criaHeap(vet, 0, i-1);
     }
}

int main(){
//==============================================================================

    int vet[7] = {23,4,67,-8,90,54,21};
  
    int N = 7;

   
    printf("Sem ordenar:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    heapSort(vet, N);

    printf("Ordenado:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n")
    
//==============================================================================

    system("pause");
    return 0;
}


