#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main()
{
int m, n, r1, r2, r3;
printf("input n");
scanf("%i", &n);
printf("input m");
scanf("%i", &m);

r1 = n++ -m;
printf("r1=%i\n", r1);

r2 = m-- > n;
printf("r2=%i\n", r2);

r3 = n-- > m;
printf("r3=%i\n", r3);
return 0;
}
