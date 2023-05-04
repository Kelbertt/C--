#include <stdio.h>
#include <stdlib.h>

	int main(void){
		
		int *p;
		int i, k, n;
		
		printf("Digite a quantidade de números que serao digitados: ");
		scanf("%d", &i);
      	
		p = malloc(i * sizeof(int)); /* A funcao malloc reserva espaco suficiente para um vetor de inteiros. * Caso sejam digitados i elementos, serao reservados i * sizeof(int) bytes, * que correspondem a i inteiros na memoria. */
       	if( p == NULL){
       		printf("Erro de alocação de memória");
       		exit(1);
       		
	   	}
	   
	   for (k=0; k<i; k++){
	   		printf("Digite o número para o indice %d: ", k)
	   		
	   }
	   
	   for (k=0; k<i; k++){
	   		printf(" O numero do indice %d e %d\n", k, p[k]);
	   		
	   }
	   
	   printf(" Digite quantos elementos quer adicionar ao vetor:");
	   scanf("%d", &n);
	   
	   int* new_p= realloc(p, (i+n)* sizeof(int)); /* A funcao realloc aumenta ou diminui o tamanho do vetor dinamicamente.* Ela recebe o ponteiro para o vetor anterior e retorna o novo espaco alocado. */
	   if (new_p == NULL) {
	   		printf( " Erro de realocaçao de memoria");
	   		exit(1);
	   		
	   }
	   
	   p = new_p;
	   
	   for (k = i; k< (i + n); k++){
	   		printf( "Digite o numero para o indice %d: ", k);
	   		scanf(" %d", &p[k]);
	   		
	   }
	   
	   for (k = 0; k<(i+n); k++){
	   		printf( " O numero do indice %d e %d\n", k, p[k]);
	   }
	   
	   free(p);
	   
	   return 0;
	}
