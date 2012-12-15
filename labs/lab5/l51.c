#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char *ptr;
	ptr = malloc(sizeof(char)*10);
	strcpy(ptr,"fred");
	printf("\n%s", ptr);
	printf("\n%p", ptr);
	
	ptr = realloc(ptr,sizeof(char)*20000);
	printf("\n%s", ptr);
	printf("\n%p", ptr);

	ptr = realloc(ptr,sizeof(char)*2);
	printf("\n%s", ptr);
	printf("\n%p", ptr);
   
    return 0;
}
