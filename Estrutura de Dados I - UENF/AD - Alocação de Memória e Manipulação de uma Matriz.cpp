/* programa_memoria_04.c */

#include <stdio.h>
#include <stdlib.h>

int **aloca(int i, int j);
void libera(int **p, int i, int j);
void leitura(int **p, int i, int j);
void imprime(int **p, int i, int j);

int main(void){
	int **p;
	int **p1;
	
	p = aloca(3,2);
	leitura(p, 3, 2);
	
	p1 = aloca (2,3);
	leitura(p1,2,3);
	
	imprime(p,3,2);
	imprime(p1,2,3);
	
	libera (p,3,2);
	libera (p1,2,3);
	
	return 0;
}

int **aloca(int i, int j){
	
	int **p; 
	int x;
	
	p =(int **) calloc(i, sizeof(int*));						/* alocação de linhas... */
	if( p == NULL){
		printf("\Erro de alocacao");
		exit(-1);
	}
	
	for(x=0; x<i; x++){
		p[x]=(int *) calloc (j, sizeof(int));				/* alocação de colunas */
		if(p[x]== NULL){
			printf("\n Erro de alocacao");
			exit(-1);
		}
	}
	return p;
}

void leitura( int **p, int i, int j){				/* 2 asteriscos indicam que a função recebe uma matriz */
	int x, y;
	for(x=0;x<i;x++){
		for(y=0;y<j;y++){
			printf(" Entre com o elemento %d,%d ->", x,y);
			scanf("%d", &p[x][y]);					/* uso da matriz no formato tradicional */
		}
	}
}

void imprime(int **p, int i, int j){
	int x,y;
	for(x=0;x<i;x++){
		for(y=0;y<j;y++){
			printf("\n Elemento %d,%d = %d", x,y,p[x][y]);
		}
	}
}

void libera (int **p, int i, int j){
	int x;
	for(x=0;x<i;x++){
		free(p[x]);								/* libera coluna */
	}
	free(p); 									/* libera as linhas */
}
