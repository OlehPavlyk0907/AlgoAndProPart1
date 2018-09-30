#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
string a = GetString();
int n = strlen(a);
if(a[0] != ' ')
printf("%c",toupper(a[0]));
for(int i = 0; i <= n; i++)
{
if(a[i-1] == ' ')
{
printf("%c", toupper(a[i]));
}
}
printf("\n");
}
