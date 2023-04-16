#include <stdio.h>
#define MAXLINE 1000
#define true 1
#define false 0

void process(char line[]);

int main(void)
{
    char line[MAXLINE];
    gets(line);
    process(line);
    puts(line);

    return 0;
}

void process(char line[])
{
    char c;
    int i = 0;
    int p = 0;
    int flag = false;
    int found = false;
    int start;
    int finish;

    do
    {
        c = line[i];
        if ( c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0')
        {
            if (flag == true)
            {
                finish = i - 1;
                for (int j = (start + 1); j < (finish + 1); j++)
                {   
                    if (line[j-1] == line[j])
                    {
                        found = true; 
                    }   
                }

                if (found == true)
                {
                    for (int j = start; j < (finish + 1); j++)
                    {
                        line[p++] = line[j];
                    }
                }

                found = false;
                flag = false;
            }
            line[p++] = c;
        }
        else
        {
            if (flag == false)
            {
                start = i;
                flag = true;
            }
        }
        i++;
    }
    while (c != '\0');
}