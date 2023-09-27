#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um elemento na fila de prioridade (Max Heap)
typedef struct {
    int priority;
    int order;
} PriorityItem;

// Função para criar o Max Heap
void criaMaxHeap(PriorityItem *vet, int N) {
    for (int i = 1; i < N; i++) {
        int filho = i;
        while (filho > 0) {
            int pai = (filho - 1) / 2;
            if (vet[filho].priority <= vet[pai].priority) {
                break;
            }
            PriorityItem temp = vet[filho];
            vet[filho] = vet[pai];
            vet[pai] = temp;
            filho = pai;
        }
    }
}

// Função para ordenar a fila de prioridade usando Heap Sort
void heapSort(PriorityItem *vet, int N) {
    criaMaxHeap(vet, N);
    for (int i = N - 1; i > 0; i--) {
        PriorityItem temp = vet[0];
        vet[0] = vet[i];
        vet[i] = temp;

        int pai = 0;
        while (1) {
            int filho = 2 * pai + 1;
            if (filho >= i) {
                break;
            }
            if (filho + 1 < i && vet[filho].priority < vet[filho + 1].priority) {
                filho++;
            }
            if (vet[pai].priority >= vet[filho].priority) {
                break;
            }
            temp = vet[pai];
            vet[pai] = vet[filho];
            vet[filho] = temp;
            pai = filho;
        }
    }
}

int main() {
    PriorityItem vet[7] = {{23, 0}, {4, 1}, {67, 2}, {-8, 3}, {90, 4}, {54, 5}, {21, 6}};
    int N = 7;

    printf("Sem ordenar:\n");
    for (int i = 0; i < N; i++) {
        printf("(%d,%d) ", vet[i].priority, vet[i].order);
    }
    printf("\n");

    heapSort(vet, N);

    printf("Ordenado:\n");
    for (int i = 0; i < N; i++) {
        printf("(%d,%d) ", vet[i].priority, vet[i].order);
    }
    printf("\n");

    return 0;
}
