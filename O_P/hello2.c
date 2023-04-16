#include <stdio.h>

#define NO 0
#define YES 1 

int main(void)
{
    int found = False;
    int c;
    int counter = 0;
    int last;


    while ((c = getchar()) != EOF)
    {
        if ((c == ' ')|| (c == '.') || (c == ',') || (c == '\n'))
        {
            if (found == YES)
            {
                counter += 1;      
                found = NO;
            }
        }
        else
        {
            if (c == last)
            {
                found = YES;
            }
        }
        last = c;
    }

    printf("%i\n", counter);
}
        
       