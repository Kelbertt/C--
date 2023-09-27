#include <stdio.h>

void CountingSort(int array[], int n){
	
	int i, b[n];
	
	//Find the largest element of the array
	
	int max = array[0];
	for(i=1;i<n;i++)
	{
		if(array[i]>max)
			max=array[i];
	}
	
	int count[max+1];
	
	//Initializing the count array with all zeros
	for(i=0; i<=max; i++)
	{
		count[i]=0;
	}
	
	//Store the number of occurance of each element in the count array
	for(i=0;i<n;i++)
	{
		count[array[i]]++;
	}
	
	//Update the count array
	for(i=1;i<=max;i++)
	{
		count[i]=count[i]+count[i-1];
	}
	
	
	//Finding the index of each elements and place the elements in the output array i.e. in array b//
	for(i=n-1;i>=0;i--)
	{
		b[--count[array[i]]]=array[i];
	}
	
	//Copy the sorted elements into the original array from array b
	for(i=0;i<n;i++)
	{
		array[i]=b[i];
	}
}

int main()
{
	int n, i;
	printf("Enter the number of elements in the array:");
	scanf("%d",&n);
	int array[n];
	
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&array[i]);
	
	CountingSort(array,n);
	
	printf("The sorted array;\n");
	for(i=0;i<n;i++)
	{
		printf("%d", array[i]);
	
	}
	return 0;
}

