#include <stdio.h>
#include <stdlib.h>

int sum(int k, ...)
{
  	int sum = 180*(k-2);
  	int kyt;
  	int* p = &k;
	kyt =(k-2)*180/k;
	return kyt;
}

int main(void)
{
    int Suma1 = 0;
    int Suma2 = 0;
    int Suma3 = 0;
    
    Suma1 = sum(3,5,5,5);
    Suma2 = sum(4,5,5,5,5);
    Suma3 = sum(5,5,5,5,5,5);
    
    printf("%d\n", Suma1);
    printf("%d\n", Suma2);
    printf("%d\n", Suma3);
}
