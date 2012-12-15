#include <stdio.h>
#include <stdlib.h>

void fn(int a, int *b)
{
	a=5;
	*b=5;
}

int main (void) 
{
	int var1=3, var2=3;
	
	fn(var1, &var2);
	
	printf("%d %d", var1, var2);
	
	
    return 0;
}
