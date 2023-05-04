#include <stdio.h>
#include <stdlib.h>

	int main (void){
		int **p;                                    		  /* A declara��o de uma matriz de 2 dimens�es exige um ponteiro para ponteiro. */
		int i,j,k,x;
		printf("\n Digite as dimensoes da matriz ->");
		scanf("%d %d", &i,&j);
		
		p =(int**) calloc (i,sizeof(int*));                   /* Aloca��o da primeira dimens�o. Internamente, a fun��o calloc far� uma multiplica��o da quantidade de elementos pelo tamanho de cada elemento para saber quanto de mem�ria deve ser alocada. */
		if (p == NULL){
			printf("\n Erro de alocacao de memoria");
			exit(1);
			}
			
		for( k=0; k<i; k++){
			p[k] =(int*) calloc(j, sizeof(int));
			if(p[k] == NULL){                         	   	/* Aloca��o das linhas de cada coluna (segunda dimens�o) */
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
			free(p[k]);                              		  /* Primeiro deve ser liberada a mem�ria para linha da matriz... */
		}
		
		for (x=0; x<j; x++){
			free(p);
		}
}
