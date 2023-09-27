#include <stdio.h>

int findmax(int array[], int n){
	int max = array[0];
	for (int i = 1; i<n;i++){
		if(array[i]>max){
			max = array[i];
		}
	}
	return max;
}

void countingSort(int array[],int n, int exp){
	int output[n];
	int count[10]= {0};
	
	for(int i = 0; i<n; i++){
		count[(array[i]/ exp) %10]++;
	}
	
	for(int i= 1; i<10; i++){
		count[i] += count [i-1];
	}
	
	for (int i = n-1; i>=0; i--){
		output[count[(array[i]/exp)%10]-1] = array[i];
		count[(array[i]/exp)%10]--;
	}
	
	for(int i = 0; i<n; i++){
		array[i]= output[i];
	}
}

void radixSort(int array[], int n){
	int max = findmax(array, n);
	
	for(int exp = 1; max / exp >0; exp*=10){
		countingSort(array, n , exp);
	}
}

int main(){
	int n;
	
	printf("Insira o numero de elementos no array:");
	scanf("%d", &n);
	
	int array[n];
	
	printf("Insira os elementos: \n");
	for( int i= 0; i<n; i++){
		scanf("%d", &array[i]);
	}
	
	radixSort(array,n);
	
	printf("Array ordenado: \n");
	for (int i = 0; i<n; i++){
		printf("%d -", array[i]);
	}
	
	return 0;
}
