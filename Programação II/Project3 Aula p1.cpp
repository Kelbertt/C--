#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mostraVetor(int n, int va[]){
	int i;
	for(i=0; i<n; i++){
 			 printf(" %d", va[i]);
	}
}


int pos(int i, int *va, int a){
	while(i>0){
 			   if(va[i-1]>a){
 			   va[i]=va[i-1];
	 		   i--;
	   	  	   }
	 		   else {
					break;	
				}
			}
			return i;
}


int main (void){
	int h, i, *va, n, a, v;
	
	printf("Digite o tamanho do vetor:");
	scanf("%d", &n);
	
	va = (int*)malloc(n*sizeof(int));
	
	if(va == NULL){
		printf("Erro");
		exit(1);
	}
	
	srand(time(NULL));
	for(i=0; i<n; i++){
         a=rand()%100;
		 h=pos(i,va,a);
		 va[h]=a;
	}
	mostraVetor(n, va);
	free(va);
}
