#include <stdio.h>
#include <stdlib.h>

int sum(int k, ...)
{
    int Sum = 0;
    int *p = &k;
    p++;
    for (int i = 0; i < k - 1; i++)
    {
        if (p[i] % 2 == 1)
        {
            Sum = p[i] * p[i + 1];
        }
        else 
        {
            Sum = p[i] * p[i + 1];
        }
    }
return Sum;
}

int main(void)
{
    int Suma1 = 0;
    int Suma2 = 0;
    int Suma3 = 0;
    
    Suma1 = sum(5, 1,2,3,4,5);
    Suma2 = sum(10, 1,2,3,4,5,6,7,8,9,10);
    Suma3 = sum(12, 1,2,3,4,5,6,7,8,9,10,11,12);
    
    printf("%d\n", Suma1);
    printf("%d\n", Suma2);
    printf("%d\n", Suma3);
}
