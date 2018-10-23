#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int n = 3;
int mat(int a[n][n])
{
int povt[100];
int max = 0;
int k = 0;
for(int i=0; i<n; i++)
{
for(int j=0; j<n; j++)
{
for(int t = 0; t < n; t++)
{
if(a[i][j] == a[1][t] || a[i]
   [j] == a[2][t] || a[i][j] == a[3][t])
{
povt[k] = a[i][j];
k++;
}
}
}
}

max = povt[0];
if(k>0)
{
for(int i=0;i<k; i++)
{
if(povt[i] > max) max=povt[i];
}
}
else
max = 0;
return max;
}
int main()
{
int arr[n][n];
int i,j;
int max = 0;
srand(time(NULL));
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
arr[i][j] = rand()%10;
printf("%d", arr[i][j]);
}
printf("\n");
}
printf("\n");

max = arr[0][0];
for(i=1; i<n; i++)
{
printf("\n");
for(j=0; j<n; j++)
{
if(arr[i][j] > max) max=arr[i][j];
}
}
printf("\n");
printf("max:%d", mat(arr));
getchar();
