// a list of data in memory where each data item contains the
// address of the next data item is called a singly linked list
// in this case we are creating a sorted singly linked list
// tested with Pelles C     vegaseat    18dec2004

#include <stdio.h>
#include <stdlib.h>   // malloc()
#include <string.h>   // strcmp()

struct list {
	char name[31];
	int  age;
	struct list *next;  // pointer to next data item in list
} prsn;

struct list *top;     // establish start of list

// proto types
struct list *sort_store(struct list *new, struct list *top);
void display(struct list *start);

int main()
{
	struct list *person, *sort_store();
	
	printf("\nEnter a number of names and ages (q to exit loop)\n");
	for (;;) 
	{
		person = (struct list *) malloc(sizeof(prsn));
		if (!person) 
		{ 
			puts("\nOut of memory!"); 
			break; 
		}
		printf("\nEnter name : ");
		// use fgets() to allow for names with spaces
		fgets( person->name, sizeof(person->name), stdin);
		// remove frigging fgets() trailing '\n'
		if (person->name[strlen(person->name)-1] == '\n')
			person->name[strlen(person->name)-1] = '\0';     
		// mimic an AND situation		
		if (strlen(person->name) == 1)
		{      
			if (person->name[0] == 'q') break;
		}
		printf("Enter age  : ");
		int e;
		e = scanf("%d",&person->age);
		// trap non-numeric entry
		if (e == 0)
			person->age = 0;
		// flush the input stream in case of bad input
		fflush(stdin);
		// store data and update top of list		
		top = sort_store(person,top);
	}
	// display the sorted list from the top
	display(top);
	
	getchar();  // wait
	return 0;
}

//
// insert new data to the list in sorted order
//
struct list *sort_store(struct list *new, struct list *top)
{
	static struct list *last = NULL;
	struct list *old, *start;
	
	start = top;
	if (!last) 
	{
		new->next = NULL;
		last      = new;
		return (new);
	}
	old = NULL;
	while (top) 
	{
		// sort by name in ascending order
		if (strcmp(top->name, new->name) < 0) 
		{
			old = top;
			top = top->next;
		}
		else 
		{
			if (old) 
			{
				old->next = new;
				new->next = top;
				return (start);
			}
			new->next = top; 
			return (new);
		}
	}
	last->next = new;
	new->next  = NULL;
	last       = new;
	return (start);
}

//
// walk through the linked list and display the content
//
void display(struct list *start)
{
	while (start) 
	{
		printf("\nName = %-30s  Age = %2d", start->name, start->age);
		start = start->next;
	}
	printf("\n");
}