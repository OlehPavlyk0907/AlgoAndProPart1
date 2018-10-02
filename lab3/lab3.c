#include <stdio.h>
#include <math.h>
int main()

{
float x,y,a = 0.1, b = 1, k = 10, SN = 0, SE = 0;
for(x = a; x<= b; x+= (b-a)/k)
       {
double c = atan(x);
y = c;

int n = 40;
SN = SN + pow(-1,n) * (pow(x,2*n + 1))/(2*n + 1);

do
{
int n = 1;
SE = SE + pow(-1,n) * (pow(x,2*n + 1))/(2*n + 1);
n++;
}
while (pow(-1,n) * (pow(x,2*n + 1))/(2*n + 1) > 0.0001);

printf("X: %f SN: %f SE: %f Y: %f ATAN %f \n", x,SN,SE,y,c);
     }
}

