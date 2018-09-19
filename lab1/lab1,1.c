#include <stdio.h>
#include <math.h>
int main()
{
double a, b, c;
a = 100;
b = 0.001;
c = ((a-b)*(a-b)*(a-b)*(a-b) - (a*a*a*a - 4*a*a*a*b + 6*a*a*b*b)) / (((b*b*b*b) - (4*a*b*b*b)));
printf("%f\n", c);
}
