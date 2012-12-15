#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) 
{
	int size;
	int i=0;
	char arraystring[100];
	char **array;
	
	scanf("%d", &size);
	
	array = malloc(sizeof(char*)*size);
		
    for(i = 0; i<size; i++)
    {
		array[i] = malloc(sizeof(char)*100);
		scanf("%s", arraystring);
		strcpy(array[i], arraystring);
    }
	
	for(i=0; i<size; i++)
	{
		printf("%s", array[i]);
		printf("\n");
	}
	
    return 0;
}
