#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char* argv[])
{
	
	int arr [100];
	int maxSize = 12;
	int k;
	int* parr;
	parr = &arr[0];
	printf("Initial elements of the array:\n");
	for(int i = 0; i < maxSize; i++)
	{
		arr[i] = rand()%20;
		printf("%d\t", arr[i]);
	} 
	printf("\nFrom which element to start the output of the array?\nK = ");
	scanf("%d", &k);
	int count = maxSize -1;
	printf("Elements are dawn along the ring to the left, starting with K to K - 1:\n");
	for(int i = k - 1; i>= -maxSize +3 ; i--)
	{
		if(i < 0)
		{
			printf("%d\t",*(parr+count));		
			count--;
			continue;	
		}
		printf("%d\t", *(parr+i));
	}
	
	int arrcopy[100];
	for(int i = 0; i < maxSize; i++)
	{
		arrcopy[i] = arr[i];
	}
	int temp = maxSize;
	maxSize +=4;
	for(int i = 0; i < maxSize; i++)
	{
		arr[i+1] = arrcopy[i];
	}
	arr[0] = rand()%10;
	for(int i = temp+1; i < maxSize; i++)
	{
		arr[i] = rand()%20;
	}
	printf("\nAdd the first and last three elements in the ring:\n");
	for(int i = 0; i < maxSize; i++)
	{
		printf("%d\t", arr[i]);
	}
	
	count = 0;
	printf("\nElements are dawn in a ring to the right, starting with K to K + 1:\n");
	for(int i = k - 1; i < maxSize + 2; i++)
	{
		if(i >= maxSize)
		{
			printf("%d\t", *(parr+count));
			count ++;
			continue;
		}
		printf("%d\t", arr[i]);
	}
	return 0;
}
