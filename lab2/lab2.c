#include <stdio.h>
#include <math.h>
double factorial(double f)
{
if(f==0)
return 1;
return(f * factorial(f-1));
}
int main()
{
double sum,a,n;
sum=0;
for(n=1;n<=13;n++)
{
a = log(factorial(n))/(n*n);
sum+=a;
}
printf("%f\n",sum);
}
