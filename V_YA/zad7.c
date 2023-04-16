// необходимо из записанный символов в фале записать их в виде таблицы в другой файл
#include <stdio.h>
#define MAXLINE 500
#define N 10
#define N1 3
int main(void)
{
	FILE* fpin;
	FILE* fpout;
	char line[MAXLINE];
	char* ptr;
	char line1[MAXLINE];
	char* ptr1;
	char line2[MAXLINE];
	char* ptr2;
	int count = 0;
	int count2 = 0; // движение по строке переноса
	int flag= 0;//признак первого пробела
	int flag1 = 0;// признак найденного переноса
	int flag2 = 0;// признак вывода строки переноса
	fpin = fopen("r7.txt", "r");
	if (fpin == NULL)
		return 1;
	fpout = fopen("w7.txt", "w");
	if (fpout == NULL)
		return 1;
	while (!feof(fpin))
	{
		ptr = fgets(line, MAXLINE, fpin);
		ptr1 = line1;
		ptr2 = line2;
		if (ptr == NULL)
			break;
		flag2 = 0;
		while (*ptr == ' ')// чтобы первый пробел не смещал таблицу
		{
			ptr++;
		}
		while (*ptr != '\0')
		{
			if ((*ptr != ' ')&&(*ptr != '\n') && (flag1 == 0))// копирование символов
			{
				flag = 0;
				count++;
				*ptr1++ = *ptr;
				if ((count == (N+1)) && (*ptr != ' ') && (*ptr != '\n') && (flag1 == 0)) //перенос слова 
				{
					flag2++;
					flag1++;
					count = N+1;
					count2 = 1;
					*(ptr1 - 1) = ' ';
					*ptr2++ = '-';
					*ptr2++ = *(ptr1 - 2);
					*(ptr1-2) = '-';
					while ((*ptr != ' ')&& (*ptr != '\n'))
					{
						*ptr2++ = *ptr;
						ptr++;
						count2++;
					}
					ptr--;
				}
			}
			else 
			{
				if (flag == 0) 
				{
					flag = 1;
					while (count != (N+N1)) // формирование таблицы
					{
						count++;
						*ptr1++ = ' ';
						
					}
					if (flag1 == 0)// сдвиг указателя строки переноса 
					{
						count2 = 0;
						while (count2 != (N + N1))
						{
							count2++;
							*ptr2++ = ' ';

						}
					}
					else 
					{
						while (count2 != ((N + N1)-1))// сдвиг указателя строки переноса без переноса
						{
							count2++;
							*ptr2++ = ' ';

						}
					}
				}
				flag1 = 0;
				count = 0;
			}
			ptr++;
		}
		*ptr1++ = '\n';
		*ptr1++ = *ptr;
		*ptr2++ = '\n';
		*ptr2++ = *ptr;
		if (flag2 != 0) 
		{
			fputs(line1, fpout);
			fputs(line2, fpout);
			//fprintf(fpout, "\n");
		}
		else 
		{
			fputs(line1, fpout);
			//fprintf(fpout, "\n");
		}
	}
	fclose(fpin);
	fclose(fpout);
	return 0;
}
*/

#include <stdio.h>
#define MAXLINE 1024
#define NO 0
#define YES 1

int main() 
{
  FILE* file1;
  FILE* file2;

  char line[MAXLINE];
  char* ptr1; 
  int flag = NO;

  file1 = fopen("r7.txt", "rt");
  file2 = fopen("w7.txt", "wt");

  while (!feof(file1)) 
  {
    ptr1 = fgets(line, MAXLINE, file1);
    while (*ptr1 != '\0') 
    {
      if (*ptr1 == ' ' || *ptr1 == '.') {
        *ptr1 = '\t';
      }
      fputc(*ptr1, file2);
      ptr1++;
    }
    ptr1++;
  }
  fclose(file1);
  fclose(file2);
  return 0;
}