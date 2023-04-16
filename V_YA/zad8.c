// заменить разделители аргументом
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1024

int main(int argc, char* argv[]) 
{
    FILE* source = fopen("z8r.txt", "r");
    if (source == NULL)
    {
        printf("ошибка\n");
        return 1;
    }

	FILE* result = fopen("z8w.txt", "w");
    if (result == NULL)
    {
        printf("ошибка\n");
        return 1;
    }
	
    char line[MAXLINE];
    char* pointer;
        
    while (!feof(source))
    {
        pointer = fgets(line, MAXLINE, source);
        
        if (pointer == NULL)
        {
            break;
        }

        while (*pointer != '\0')
        {
            if (*pointer == ' ' || *pointer == ';' || *pointer == ':' || *pointer == ',' || *pointer == '.')
            {
                // printf("%s", argv[1]);
				fputs(argv[1], result);
            }
            else
            {
                // printf("%c", *pointer);
				fputc(*pointer, result);

            }
            pointer++;
        }
    }
    
    fclose(source);
	fclose(result);

    return 0;
}