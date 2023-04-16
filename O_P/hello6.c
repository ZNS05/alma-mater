
#include <stdio.h>
#define I 3
#define J 4

int main(void)
{
    int x[I][J];
    int even;
    int i, j, k;
   
    for (i = 0; i < I; i++)
        for (j = 0; j < J; j++)
            scanf("%d",&x[i][j]);

    for (j = 0; j < J; j++) 
    {
        even = 0;
        for (i = 0; i < I; i++) 
        {
            if ((x[i][j]) % 2 != 0)
                even = even - 1;
            else
                even = even + 1;
        if (even > 0) 
        {
            for (k = 0; k< I; k++)
                x[k][j] = 0;
        }
    }
    

    for (i = 0; i < I; i++)
    {
        for (j = 0; j < J; j++)
            printf("%4d", x[i][j]);
        printf("\n");
    }
    return 0;
}