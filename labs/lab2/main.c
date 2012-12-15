/* Junior Samaroo     (Student# 0663108) */

#include <stdio.h>

int main (void)
{
	int i, j, x, y;	
	
	// Input
	printf("Enter # of rows:");
	scanf("%d", &x);
	printf("Enter # of columns:");
	scanf("%d", &y);
	int array[x][y];
	
	// Calculations
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		array[i][j] = i + j + 2;
	}
	
	// Print Output
	for (i = 0; i < x; i++)
	{
		for ( j = 0; j < y; j++ )
		printf( "%d", array[i][j] );
		printf( "\n" );
	}
	
    return 0;

}
