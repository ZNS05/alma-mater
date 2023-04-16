#include <stdio.h>

int main()
{
    FILE *a;
    FILE *b;

    a = fopen("input.txt", "r");
    b = fopen("output.txt", "w");

    while (!feof(a))
    {
        char line[100];
        char hol;
        char *buf = fgets(line, 100, a);
        char *in_hol;
        char *new_line;
        in_hol = line;
        new_line = line;

    do
    {
        hol = *in_hol;
        if ('A' <= hol && hol <= 'Z' || hol == '\n' || hol == '\0' ) 
        {
            new_line++;
        }
        else *new_line++ = ' ';
        in_hol++;

    }while (hol != '\0');
        fputs(line, b);
    }
fclose(a);
fclose(b);
return 0;
}