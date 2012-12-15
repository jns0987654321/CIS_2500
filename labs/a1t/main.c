#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ht, wd;

// part 1
int * create2DArray(int row, int column)
{
	int *array;
	array = malloc(sizeof(int)*(row*column));
	ht = column;
	wd = row;
	
	return (array);
}

void set2DElement(int *array, int row, int column, int value)
{
	array[row*wd+column] = value;
	
}			

int get2DElement(int *array, int row, int column)
{
	
	return array[row*wd+column];
	
}


void free2DArray(int *array)
{
	free(array);
	array = NULL;
	
}


// part 2
char ** createStringArray(int size)
{
	int i = 0;
	char **array = malloc(sizeof(char*)*size);
	
	for(i = 0; i<size ; i++)
	{
        array[i] =  malloc(sizeof(char)*100);
	}	
	return array;
}

void setStringArray(char **array, int i, char *string)
{
	
	strcpy(array[i],string);	
	
}

char * getStringArray(char **array, int i)
{
	return array[i];
	
	
}

void freeStringArray(char **array, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		free(array[i]);
	}
		free(array);
	
	
}

// part 3
int ** createArray(int row , int column)
{
	int i;
	int **array = malloc(sizeof(char)*row);
	for(i=0; i<row; i++){
	array[i] = malloc(sizeof(char)*column);
	}
	return array;
	
}

void freeArray(int **array, int size)
{
	int i;
	for(i=0; i<size; i++){
		free(array[i]);
	}
	free(array);
}


int main(int argc, char *argv[]) {
	int *array;
	int width, height;
	int value;
	char **stringPtr;
	int **matrix;
	
	/* testing for part 1 */
	printf("Testing Part 1\n");
	width = 5;
	height = 6;
	
	array = create2DArray(height, width);
	
	printf("Store value 7 at [3,4].\n");
	set2DElement(array, 3, 4, 7);
	
	value = get2DElement(array, 3, 4);
	printf("Retrieve value %d from [3,4]\n\n", value);
	
	free2DArray(array);
	
	
	/* testing for part 2 */
	printf("Testing Part 2\n");
	stringPtr = createStringArray(100);
	
	printf("Store string - fred\n");
	setStringArray(stringPtr, 44, "fred");
	printf("Store string - barney\n");
	setStringArray(stringPtr, 80, "barney");
	
	printf("Get string - %s\n", getStringArray(stringPtr, 44));
	printf("Get string - %s\n", getStringArray(stringPtr, 80));
	/* test with NULL string */
	printf("Get string - %s\n\n", getStringArray(stringPtr, 3));
	
	freeStringArray(stringPtr, 100);
	
	
	/* testing for part 3 */
	printf("Testing Part 3\n");
	matrix = createArray(100, 100);
	
	printf("Store 33 44 55\n");
	matrix[22][76] = 33;
	matrix[83][29] = 44;
	matrix[99][65] = 55;
	
	printf("Retrieve %d %d %d\n", matrix[22][76], matrix[83][29],
		   matrix[99][65]);
	
	freeArray(matrix, 100);
	
	return(1);
}	


