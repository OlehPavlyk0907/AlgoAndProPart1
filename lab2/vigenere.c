#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{   
   if(argc != 2)
   {
       return 1;
   }
   string keyword = argv[1];
   for(int i = 0; i < strlen(keyword); i++)
   {
        if(keyword[i] < 65 || (keyword[i] > 90 && keyword[i] < 97)  || keyword[i] > 122 )
            return 1;
   }
   
    printf("Write a word which need to be encrypted\n");  
    string phrase = GetString();                          
    printf("ciphertext: ");                   
    for(int i = 0, j = 0; i < strlen(phrase); i++)               
    { 
        if(i < strlen(keyword))
        {
            j = i;       
        }
        else
        {
            if(j >= strlen(keyword))
                j = 0;     
        }
        if (phrase[i] < 65 || (phrase[i] > 90 && phrase[i] < 97) || phrase[i] > 122 )
        {
            printf("%c", phrase[i]);
        }
        
        else
        {
            if (phrase[i] >= 65 && phrase[i] <= 90)
            {       
                phrase[i] = (((phrase[i] - 65 + toupper(keyword[j]) -65 ) % 26) + 65);
                printf("%c", phrase[i]);
                ++j;
            }
            else if (phrase[i] >= 97 && phrase[i] <= 122)
            
            {
                
               phrase[i] = (((phrase[i] - 97 +toupper(keyword[j]) - 65) % 26) + 97);
               printf("%c", phrase[i]);
                ++j;
            }
        
        }
    }
    
    
    printf("\n");
    return 0;
}
