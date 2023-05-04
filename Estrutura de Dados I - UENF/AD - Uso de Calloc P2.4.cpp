#include <stdio.h>
#include <stdlib.h>

	int main (void){
		int **p;                                    		  /* A declaração de uma matriz de 2 dimensões exige um ponteiro para ponteiro. */
		int i,j,k,x;
		printf("\n Digite as dimensoes da matriz ->");
		scanf("%d %d", &i,&j);
		
		p =(int**) calloc (i,sizeof(int*));                   /* Alocação da primeira dimensão. Internamente, a função calloc fará uma multiplicação da quantidade de elementos pelo tamanho de cada elemento para saber quanto de memória deve ser alocada. */
		if (p == NULL){
			printf("\n Erro de alocacao de memoria");
			exit(1);
			}
			
		for( k=0; k<i; k++){
			p[k] =(int*) calloc(j, sizeof(int));
			if(p[k] == NULL){                         	   	/* Alocação das linhas de cada coluna (segunda dimensão) */
				printf("\n Erro de alocacao de memoria");
				exit(1);
			}	
		}
		
		for (k=0; k<i; k++){
			for(x=0; x<j; x++){
				printf(" Digite o numero para o indice %d, %d ->", k,x);
				scanf("%d", &p[k][x]);
			}
		}
		
		for ( k=0; k<i; k++){
			for(x=0; x<j;x++){
				printf(" O numero do indice %d, %d e %d\n",k,x,p[k][x]);
			}
		}
		
		printf("\n Liberando memoria alocada");
		for (k=0;k<i; k++){
			free(p[k]);                              		  /* Primeiro deve ser liberada a memória para linha da matriz... */
		}
		
		for (x=0; x<j; x++){
			free(p);
		}
}
