#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

void copyFile(FILE* fp,FILE* fpout);
void Print(FILE* fp);
int prigInLast(FILE* fpout);
void putTextInFile(FILE* fp);

int main(int argc, char* argv[])
{
	
	FILE* fp = fopen("lab9.txt","w");
	FILE* fpout = fopen("lab9out.txt","w");
	
	if(fp == NULL || fpout == NULL)
		return -1;

    putTextInFile(fp);
    freopen("lab9.txt","r",fp);
	copyFile(fp,fpout);
	freopen("lab9out.txt","r",fpout);
	printf("\nStrings of start file:\n");
	Print(fp);
	printf("\nStrings after copying in second file:\n");
	Print(fpout);
	freopen("lab9out.txt","r",fpout);
	printf("Number of prigolosnix %d\t",prigInLast(fpout));
	fclose(fp);
	fclose(fpout);
	return 0;	
}


void copyFile(FILE* fp,FILE* fpout)
{
	
	char buffer[1024];

	fgets(buffer,sizeof(buffer),fp);

	fputs(buffer,fpout);

	char word[1024];
	int i = 0;

	while(1)
	{
		if(buffer[i] == ' ' || buffer[i] == '\0' || buffer[i] == '\n')
		break;
		word[i] = buffer[i];
		i++;
	}
  
	word[i+1] = '\0';

	while(fgets(buffer,1024,fp))
	{
		int j = 0;
		
		char tempword[1024];
		
		while(1)
		{
			if(buffer[j] == ' ' || buffer[j] == '\0' || buffer[j] == '\n')
				break;
			tempword[j] = buffer[j];
			j++;
		}
		tempword[j+1] = '\0';
		
		if(strncmp(word,tempword,strlen(word)) == 0)
			fputs(buffer,fpout);
	}
}


int prigInLast(FILE* fpout)
{

	char buffer[1024];
	int i;
	int count;
	
	while(fgets(buffer,sizeof(buffer),fpout))
	{
		i = 0;
		count = 0;
		while(buffer[i] != '\0')
		{
			
			if(isalpha(buffer[i]))
			{
				if(buffer[i] != 65 && buffer[i] != 69 && buffer[i] != 73 && buffer[i] != 79 && buffer[i] != 85 &&  buffer[i] != 89 && buffer[i] != 97 && buffer[i] != 101 && buffer[i] != 105 && buffer[i] != 111 && buffer[i] != 117 && buffer[i] != 121)
				{
					count++;
				}
					
			}	
			i++;
		}
		
	}
	return count;	
}

void Print(FILE* fp)
{

	fseek (fp,0,SEEK_SET);
	fgetpos(fp,0);
	char buffer[1024];
	
	while(fgets(buffer,sizeof(buffer),fp))
	{
		printf("%s",buffer);
	}	
}


void putTextInFile(FILE* fp)
{

	int n;
	printf("How many lines do u want to write?\n");
	scanf("%d",&n);
	for(int i = 0; i < n+1;i++)
	{
		
		char tempbuffer[1024];
		
		gets(tempbuffer);
		if(i != 0)
		{
			
			fputs(tempbuffer,fp);	
			fputc('\n',fp);	
		}
	}
}
