#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct part
{
	char name[30];
	int number;
	float cost;
};

struct part *function()
{
	struct part *ptr;
	ptr = malloc(sizeof(struct part));
	ptr ->number = 4;
	ptr ->cost = 44.4;
	strcpy(ptr->name, "john");
	
	return ptr;
}

int main (void) 
{
	struct part *ptr;
	ptr = function();
	
	printf("\ndynamic name is %s \ndynamic number is %d \ndynamic cost is %.1lf", ptr->name, ptr->number, ptr->cost);
	
    return 0;
}

