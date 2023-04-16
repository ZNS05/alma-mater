#include <stdio.h>
int main( void )
{
    float s; 
    float a ; 
    float x; 
    int z; 
    int n; 
    int i; 
    int sign; 


    printf ("- ?  = ");
    scanf ("%d", &n);
    printf ("? ? ? = ");
    scanf ("%f", &x);


    s = 1;
    a = 1;
    z = 2; 
    sign = 1;
    i = 0;


    while ( i < n)
    {
        a = (a * ((x * x) / (z * (z - 1))));
        s = s + (a * -sign);
        sign = -sign;
        z = z + 2;
        i = i + 1;
    }

    printf("? ??? = %f\n", s);

    return 0;
}