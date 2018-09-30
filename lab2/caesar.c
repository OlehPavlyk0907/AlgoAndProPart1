#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{   
   if(argc != 2)
   {
        return 1;
   }
   
   int keyword = atoi(argv[1]);
   
    printf("Write a word which need to be encrypted\n");  
    string phrase = GetString();                          
      printf("ciphertext: ");                   
    for(int i = 0; i < strlen(phrase); i++)               
    {
        if (phrase[i] < 65 || (phrase[i] > 90 && phrase[i] < 97) || phrase[i] > 122 )
        {
            printf("%c", phrase[i]);
        }
        
        else
        {
            if (phrase[i] >= 65 && phrase[i] <= 90)
            {       
                phrase[i] = (((phrase[i] - 65 + keyword) % 26) + 65);
                printf("%c", phrase[i]);
            }
            else if (phrase[i] >= 97 && phrase[i] <= 122)
            
            {
                
               phrase[i] = (((phrase[i] - 97 + keyword) % 26) + 97);
               printf("%c", phrase[i]);
            }
        
        }
    }
    
    
    printf("\n");
    return 0;
}