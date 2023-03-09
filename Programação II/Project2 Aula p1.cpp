#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int mostraVetor(int n, int v[100]){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", v[i]);
	}
}

int CalPosCerta(int v[],int a,int b){
	int pivo, f;
	pivo = v[a];
	a++;
	while(a<=b){
		while(pivo>=v[a]){
			a++;
		}
		while (pivo< v[b]){
			b--;
		}
		if(a<b){
			f = v[a];
			v[a]=v[b];
			v[b]=f;
		}
		

	}
	return(b);
}
int ordena(int v[], int a, int b){
	int p, f;
	
	p = CalPosCerta(v, a, b);
	f = v[a];
	v[a] = v[p];
	v[p] = f;
	if((p-1) > a){
	ordena(v, a, p-1);
}
	if(b > (p+1)){
	ordena(v, p+1, b);
}
}

int main (void){
	int v[100], n, p, f, h;
	
	printf("Qual o valor do vetor:");
	scanf("%d", &n);
	
	//srand(time(NULL));
	for (p = 0; p<n; p++){
		v[p] = rand()%100;
	}
	mostraVetor(n,v);
    
    ordena(v, 0, n-1);

 printf("\n");
 mostraVetor(n,v);
	
 

	
}
