#include <stdio.h>
#include <stdlib.h>

struct data {
	int number;
	struct data *next;
};

typedef struct data datatype;

int main() 
{
	datatype *root, *temp;
	int i;

	root = NULL;
	temp = NULL;

	/* create a linked list of five records */
	for(i=0; i<5; i++) 
	{
		temp = malloc(sizeof(datatype));
		temp->number=i;
		temp->next = root;
		root = temp;
	}

        /* step through the list starting with the head */
	while (temp != NULL) 
	{
		printf("%d\n", temp->number);
		temp = temp->next;
	}

	return(1);
}
