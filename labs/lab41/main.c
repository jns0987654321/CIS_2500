#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct part{
	char name[30];
	int number;
	float cost;
};

int main (void) 
{
	struct part *ptr;
	ptr = malloc(sizeof(struct part));
	ptr ->number = 4;
	ptr ->cost = 44.4;
	strcpy(ptr->name, "john");
	
	struct part st;
	st.number = 5;
	st.cost = 33.3;
	strcpy(st.name, "johnny");
	
	printf("static name is %s \nstatic number is %d \nstatic cost is %.1lf", st.name, st.number, st.cost);
	printf("\ndynamic name is %s \ndynamic number is %d \ndynamic cost is %.1lf", ptr->name, ptr->number, ptr->cost);

    return 0;
}
