#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mostraVetor(int n, int v[100]){
	int i, j; 
	for(i=0; i<n; i++){
		printf("%d ", v[i]);
	}
}

int CalPosCerta(int n, int *va, int m , int *vb, int q, int *vc){
	int i, j, h;
	i=j=h=0;	
		while((i<=n)&&(j<=m)){
 		   if(va[i] > vb[j]){
 		   vc[h]=vb[j];
 		   j++;
 		   h++;
		}
		   else if (vb[j]> va[i]){
		   }
		

	}
	return(*vb);
}


int main (void){
	int va, vb, vc, n, m, q, h;
	
	printf("Qual o valor do vetor A:");
	scanf("%d", &n);
	srand(time(NULL));
	va= (int*) malloc(n*sizeof(int));
	criarVetor(va,n);
	ordenaQuick(0, n-1, va, n);
	mostrarvetor(n, va);
	
	
	printf("Qual o valor do vetor B:");
	scanf("&d", &m);
	vb= (int*) malloc(m*sizeof(int));
	criarVetor(vb,m);
	ordenaQuick(0, m-1, vb, m);
	mostrarvetor(m, vb);    
    
    q = n + m
    
preencherVetor(n, va, m, vb, q, vc);  
 printf("\n");
 mostraVetor(q,vc);
}
