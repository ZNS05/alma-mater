// удалить все буквы в файле и записать в отдельный файл
#include <stdio.h>
#define MAXLINE 1024
int main(void)
{
	FILE* fpin;
	FILE* fpout;
	char line[MAXLINE];
	char* ptr;
	char c;
	fpin = fopen("r5.txt", "r");
	if (fpin == NULL)
		return 1;
	fpout = fopen("w5.txt", "w");
	if (fpout == NULL)
		return 1;
	while (!feof(fpin))
	{
		ptr = fgets(line, MAXLINE, fpin);
		if (ptr == NULL)
			break;
		while (*ptr != '\0')
		{
			if (*ptr != '1' && *ptr != '2' && *ptr != '3' && *ptr != '4' && *ptr != '5' && *ptr != '6' && *ptr != '7' 
            && *ptr != '8' && *ptr != '9' && *ptr != '0' && *ptr != '\n') //if(((*ptr<='0')||(*ptr>='9'))&&(*ptr!='\n'))
			{
				*ptr = ' ';
			}
			ptr++;
		}
		fputs(line, fpout);
	}
	fclose(fpin);
	fclose(fpout);
	return 0;
}