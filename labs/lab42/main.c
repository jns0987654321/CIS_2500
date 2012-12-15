#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct part{
	char name[30];
	int number;
	float cost;
};

void change(struct part *ptr, struct part st)
{
	ptr ->number = 7;
	ptr ->cost = 77.7;
	strcpy(ptr->name, "johnathan");
	
	st.number = 8;
	st.cost = 88.8;
	strcpy(st.name, "johnnytest");
	
}

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
	
	change(ptr,st);
	
	printf("\n\nstatic name is %s \nstatic number is %d \nstatic cost is %.1lf", st.name, st.number, st.cost);
	printf("\ndynamic name is %s \ndynamic number is %d \ndynamic cost is %.1lf", ptr->name, ptr->number, ptr->cost);
	
    return 0;
}

