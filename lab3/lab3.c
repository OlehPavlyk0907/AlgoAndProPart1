#include <stdio.h>
#include <math.h>
int main()
{
double y, a = 0.1, b = 1, k = 10, SN = 0, SE = 0;
for(double x = a; x<=b; x+= (b-a)/k)
  {
      y = atan(x);
      for(int n = 1; n<40; n++)
      {
      SN = SN + pow(-1,n) * (pow(x,2*n + 1))/(2*n + 1);
      }
      int n = 1;
      do
      {
      SE = SE + pow(-1,n) * (pow(x,2*n + 1))/(2*n + 1);
      n++;
      }
      while (pow(-1,n) * (pow(x,2*n + 1))/(2*n + 1) > 0.0001);
      printf("X: %f SN: %f SE: %f Y: %f\n", x,SN,SE,y);
   }
}      
