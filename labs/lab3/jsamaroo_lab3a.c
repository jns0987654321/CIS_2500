#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) 
{
	srand( time(NULL) );
	int i, j;
	int **array =  malloc(sizeof(int)*5);
	
    for(i = 0; i<5 ; i++)
    {
		array[i] =  malloc(sizeof(int)*5);
		for (j = 0; j < 5; j++)
		{
			array[j] =  malloc(sizeof(int)*5);
			array[i][j] = rand() %99+1;
			printf("%3d ", array[i][j]);
			if (j==4)
				printf("\n");
		}
	}

	return 0;
}
