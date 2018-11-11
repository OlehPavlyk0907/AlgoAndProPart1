#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
char str[255];
printf("Enter string line:");
fgets(str, 256, stdin);
fflush(stdin);
char newstr[255];


int i, n, result;

printf("%s\n", "Input string:");
scanf("%s", str);

result = 0;

n = strlen(str);
for(int i = 0; i < n; i++)
{
newstr[i] = tolower(str[i]);
}

for(i = 0; i < n/2; i++)
{
if(newstr[i] != newstr[n-i-1])

{
result = -1;
break;
}

}

printf("result = %d\n", result);
return 0;
}
