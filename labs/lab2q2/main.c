/* Junior Samaroo     (Student# 0663108) */

#include <stdio.h>
#include <math.h>

int main (void)
{
	int i, high=0;
	int high_i;
	int array[10];
	
	// Input
	printf("Enter each number and press enter:");
	for(i=0; i<=9; i++)
	scanf("%d", &array[i]);
	
	// Calculations
	for(i=0; i<=9; i++)
	{
		if (array[i] > high)
		{
			high=array[i];
			high_i=i;
		}
	}
		
	for(i=high_i-1; i>=0; i--)
		array[i+1] = array[i];
	
	array[0]=high;
	
	// Output
	for(i=0; i<=9; i++)
		printf("%d ", array[i]);
	
	return 0;
}

