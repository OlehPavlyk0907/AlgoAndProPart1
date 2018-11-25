#include <stdio.h>

char* createArr(int size1)
{
 char** arr = malloc(sizeof(char*) * size1);
 for(int i = 0;i < size1;i++)
 {
  arr[i] = malloc(sizeof(char) * size1);
 }
 return arr;
}

void initialize(char** arr, int size1)
{
 for(int i = 0; i < size1+1; i ++)
 {
  if(i == 0)
   continue;
  if(i!= 1)
  printf("Print the string\n");
  gets(arr[i-1]);
 }
}

void print(char** arr, int size1)
{
 for(int i = 0; i < size1;i++)
 {
  if(i == 0)
   continue;
  printf("%d.%s\n",i,arr[i]);
 }
 printf("\n");
}

void killElement(char** arr, int size1,int num)
{
 free(arr[num]);
 for(int i = 0; i < size1;i++)
 {
  if(i == num || i == 0)
   continue;
  
  printf("%d.%s\n ",i,arr[i]);
 }
}
int main()
{
 int size1;
 printf("Enter number of strings\n");
 do
 {
  scanf("%d",&size1); 
 }
 while(size1 <= 0);
 size1++;
 char** arr = createArr(size1);
 initialize(arr,size1);
 print(arr,size1);
 printf("Enter the number of string which you want to delete\n");
 int num;
 scanf("%d",&num);
 killElement(arr,size1,num);
}
