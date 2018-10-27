#include <cs50.h>

#include "helpers.h"

bool search(int value, int values[], int n)
{
    bool found;
    if(n < 0)
        return -1;
    for(int i =0; i < n; i++)
    {
        if(value == values[i])
        {
            found = true;
        }
    }
    if(found)
        return true;
    else 
        return false;
}

void sort(int values[], int n)
{
   
    for(int i = 0; i < n; i ++)
    {
        for(int k = 0; k < n; k++)
        {
            if(values[i] < values[k])
            {
                int num = values[k];
                values[k] = values[i];
                values[i] = num;    
            }
        }
    }
    
   
}
