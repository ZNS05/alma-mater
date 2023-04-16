#include <stdio.h>
#define N 10

int main( void )
{
    int x[N]; 
    int n = 0; 
    int i = 0;
    int r; 
    int max; 
    
        for( i = 0; i < N; i++ )
        {
            scanf("%d", &x[i]); 
        }
        max = (x[0] + x[1]);
        i = 1;
        n = 1;

        while (i < N-1)
        {
            if ((r = (x[i] + x[i + 1])) >= max)
            {
                max = r;
                n = i + 1;
            }
            ++i;
        }
        printf("namber %d\nsum %i\n", n, max);

    return 0;
}





