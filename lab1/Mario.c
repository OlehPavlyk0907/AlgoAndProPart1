#include <stdio.h>
#include <cs50.h>
int main(void)
{
printf("give this pyramid a height from 1 to 23:\n");
int n = GetInt();
if (n<23)
    {
        printf("u picked %i,enjoy your pyramid\n",n);
        int i;
        int spaces;
        int dashes;
        for (i=0;i<n;i++)
        {
        for(spaces = (n - i);spaces>=0;spaces--)
        {
        printf(" ");
        }
        for (dashes =1; dashes<=(i+1); dashes++)
        {
            printf("#");
            }
            printf("\n");
        }
        }
    else
    {
    do
    {
        printf("take a number form 1 to 23:\n");
        n = GetInt();
        }
    while (n>23);
    printf("u picked %i,enjoy your pyramid\n",n);
        int i;
        int spaces;
        int dashes;
        for (i=0;i<n;i++)
        {
        for(spaces = (n - i);spaces>=0;spaces--)
        {
        printf(" ");
        }
        for (dashes =1; dashes<=(i+1); dashes++)
        {
            printf("#");
            }
            printf("\n");
        }
