#include <stdio.h>

int main(void) 
{
	long N;
	int copy = 1; 
	int count = 0; 
	scanf("%x", &N); 
	while (N != 0) 
	{	
		if (copy & N) break;
		N >>= 1; 
		count++; 
	}
	printf("%d", count); 
}
