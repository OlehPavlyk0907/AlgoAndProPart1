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
	// Â³äêðèâàþòüñÿ ïîòîêè äëÿ çàïèñó òåêñòó â ôàéë 1 ³ äëÿ êîï³þâàííÿ â  ôàéë 2  ç ïðàâàìè çàïèñó
	FILE* fp = fopen("lab9Oleh.txt","w");
	FILE* fpout = fopen("lab9Olehout.txt","w");
	// Çàâåðøèòè ïðîãðàìó, ÿêùî ïîò³ê íå âäàëîñü â³äêðèòè
	if(fp == NULL || fpout == NULL)
		return -1;

    putTextInFile(fp);
    freopen("lab9Oleh.txt","r",fp);
	copyFile(fp,fpout);
	freopen("lab9Olehout.txt","r",fpout);
	printf("\nStrings of start file:\n");
	Print(fp);
	printf("\nStrings after copying in second file:\n");
	Print(fpout);
	freopen("lab9Olehout.txt","r",fpout);
	printf("Number of prigolosnix %d\t",prigInLast(fpout));
	fclose(fp);
	fclose(fpout);
	return 0;	
}

//Ôóíêö³ÿ êîï³þâàííÿ òåêñòó ç ôàéëó 1 â ôàéë 2
void copyFile(FILE* fp,FILE* fpout)
{
	// Áóôåð äëÿ òåêñòó
	char buffer[1024];
	// Êîï³þºìî ïåðøó ñòð³÷êó, îñê³ëüêè çà óìîâîþ âîíà ìàº áóòè ñêîï³éîâàíà.
	fgets(buffer,sizeof(buffer),fp);
	// çàïèñóºìî ïåðøó ñòð³÷êó
	fputs(buffer,fpout);
	// Áóôåð äëÿ êëþ÷îâîãî ñëîâà, çà ÿêèì áóäåìî êîï³þâàòè
	char word[1024];
	int i = 0;
	// Çàïîâíþºìî áóôåð êëþ÷îâîãî ñëîâà ïåðøèì ñëîâîì ïåðøî¿ ñòð³÷êè
	while(1)
	{
		if(buffer[i] == ' ' || buffer[i] == '\0' || buffer[i] == '\n')
		break;
		word[i] = buffer[i];
		i++;
	}
	// Âñòàâëÿºìî ñèìâîë ê³íöÿ ñëîâà
	word[i+1] = '\0';
	// Ïåðåâ³ðÿºìî ÷è ïåðøå ñëîâî ïåðøî¿ ñòð³÷êè ñï³âïàäàº ç ïåðøèì ñëîâîì ³íøèõ ñòð³÷îê
	while(fgets(buffer,1024,fp))
	{
		int j = 0;
		// Áóôåð ïåðøîãî ñëîâà ³íøèõ ñòð³÷îê
		char tempword[1024];
		// Çàïîâíþºìî áóôåð ïåðøèì ñëîâîì ³íøî¿ ñòð³÷êè
		while(1)
		{
			if(buffer[j] == ' ' || buffer[j] == '\0' || buffer[j] == '\n')
				break;
			tempword[j] = buffer[j];
			j++;
		}
		tempword[j+1] = '\0';
		// Ïîð³âíþºìî ö³ 2 ñëîâà,ÿêùî âîíè îäíàêîâ³ òî êîï³þºìî â ôàéë 2
		if(strncmp(word,tempword,strlen(word)) == 0)
			fputs(buffer,fpout);
	}
}

// Ê³ëüê³ñòü ïðèãîëîñíèõ â îñòàíí³é ñòð³÷ö³
int prigInLast(FILE* fpout)
{
	// Áóôåð äëÿ ñòð³÷êî
	char buffer[1024];
	int i;
	int count;
	// Îòðèìóºìî ïî îäí³é ñòð³÷ê³ ïîêè íå íàñòàâ ê³íåöü ôàéëó
	while(fgets(buffer,sizeof(buffer),fpout))
	{
		i = 0;
		count = 0;
		while(buffer[i] != '\0')
		{
			// Ïåðåâ³ðêà, ÿêùî öå áóêâà ³ ÷è º öÿ áóêâà ïðèãîëîñíîþ
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
	// Êóðñîð íà ïî÷àòîê ôàéëó.
	fseek (fp,0,SEEK_SET);
	fgetpos(fp,0);
	char buffer[1024];
	// Îòðèìóºìî ñòð³÷êó ³ âèâîäèìî ¿¿
	while(fgets(buffer,sizeof(buffer),fp))
	{
		printf("%s",buffer);
	}	
}


void putTextInFile(FILE* fp)
{
	// Ê³ëüê³ñòü ñòð³÷îê , ÿê³ ìè õî÷åìî ââåñòè
	int n;
	printf("How many lines do u want to write?\n");
	scanf("%d",&n);
	for(int i = 0; i < n+1;i++)
	{
		// Áóôåð, äëÿ ñòð³÷êè, ÿêó ìè ââîäèìî
		char tempbuffer[1024];
		// Ââîäèìî ñòð³÷êó
		gets(tempbuffer);
		if(i != 0)
		{
			// Çàïèñóºìî ñòð³÷êó é â ê³íåöü ñòàâèìî ñèìâîë íîâîãî ðÿäêà
			fputs(tempbuffer,fp);	
			fputc('\n',fp);	
		}
	}
}
