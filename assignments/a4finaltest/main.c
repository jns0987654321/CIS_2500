/*   Junior Samaroo    0663108   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to be used in the list */
typedef struct node{
	char *name;
	int age;
	struct node *nextName;
	struct node *nextAge;
}info;

info *NameSort(info *ptr, info *list);	/* Function to sort list by name alphabetically */
info *AgeSort(info *ptr, info *list);		/* Function to sort list by age in ascending order */
void removeNode(char *name, info *list);	/* Function to remove a structure from the list */
void freeAndExit(info *ptr, info *list);	/* Function to free the structures and exit the program */

int main (void) 
{
	int ch=0;			/* User's choice flag */
	info *list;			/* Name sorted list pointer */
	info *ptr;			/* Pointer to step through list */
	char *nameString;	/* Name to be stored */
	char name[26];		/* Name to search for and remove */
	
	list = malloc(sizeof(info)*1);
	
	while (ch==0) 
	{
		if (ch==0) /* Loop that checks user choice and returns back to menu */
		{
			printf("\n1. Add structure \n");
			printf("2. Remove structure \n");
			printf("3. Print names \n");
			printf("4. Print ages \n");
			printf("5. Exit \n");
			printf("Enter a number from 1-4: ");
			scanf("%d", &ch);
			fflush(stdin);
		}
		
		if (ch==1) /* Selection that adds structure to list */
		{
			getchar();			
			ptr = malloc(sizeof(info));			/* Allocates memory for pointer */
			ptr->name = malloc(sizeof(char));
			nameString = malloc(sizeof(char));	/* Allocates memory for name string */
			
			printf("\nEnter name:\n ");			/* Enters name to store in list */
			fgets(nameString, 100, stdin);
			fflush(stdin);
			strcpy(ptr->name, nameString);
			
			printf("Enter age:\n ");			/* Enters age to store in list */
			scanf("%d", &ptr->age);
			fflush(stdin);
			
			
			ptr->nextName = NULL;
			ptr->nextAge = NULL;	
			list = NameSort(ptr, list);	/* Calls function to sort list by name and returns new root */
			list = AgeSort(ptr,list);		/* Calls function to sort list by age and returns new root */

			

			
			ch=0;
		}
		
		if (ch==2) /* Selection that removes structure from list */
		{
			getchar();
			printf("Enter name of structure to remove: \n");
			fgets(name, 100, stdin);
			fflush(stdin);
			removeNode(name, list);	/* Calls function to remove structure */
			ch=0;
		}
		
		if (ch==3) /* Selection that prints list ordered by name */
		{
			getchar();	
			ptr=list;
			if (list->name == NULL){
				list = list->nextName;
			}
			
			while(ptr!=NULL)	/* Loop that advances through list and prints list ordered by name */
			{
				printf("Age:%d Name:%s", ptr->age, ptr->name);
				ptr = ptr->nextName;
			}
			
			ch=0;
		}
		
		if (ch==4) /* Selection that prints list ordered by age */
		{
			getchar();	
			ptr=list;
			if (list->age == -1){
				list = list->nextAge;
			}
			
			
			while(ptr!=NULL)	/* Loop that advances through list and prints list ordered by age */
			{
				printf("Age:%d Name:%s", ptr->age, ptr->name);
				ptr = ptr->nextAge;
			}
			
			ch=0;
		}
		
		if (ch==5) /* Selection that frees and exits program */
		{
			getchar();
			freeAndExit(ptr, list); /* Calls function to free and exit program */
		}
	}
	
    return 0;
}


info *AgeSort(info *ptr, info *list)
{	
	info *old;
	info *start;
	start = list;
	old = list;
	while(start != NULL)	/* Loop to find location to add/sort node */
	{
		if (ptr->age > start->age)	/* Sorts ages in ascending order */
		{
			old = start;
			start = start->nextAge;
		}
		else
			break;
	}
	
	if(old != start)	/* If node is before root add it */
	{
		old->nextAge = ptr;
		ptr->nextAge = start;
		return list;	/* Returns new root */
	}
	
	if (old == start)	/* If node is not before root return sorted list */
	{
		ptr->nextAge = start;
		return ptr;
	}
	
	return 0;
}


info *NameSort(info *ptr, info *list)
{	
	info *old;
	info *start;
	start = list;
	old = list;
	while(start != NULL)	/* Loop to find location to add/sort node */
	{
		if (strcmp(ptr->name, start->name) > 0)	/* Sorts names alphabetically */
		{
			old = start;
			start = start->nextName;
		}
		else
			break;
	}
	
	if(old != start)	/* If node is before root add it */
	{
		old->nextName = ptr;
		ptr->nextName = start;
		return list;	/* Returns new root */
	}
	
	if (old == start)	/* If node is not before root return sorted list */
	{
		ptr->nextName = start;
		return ptr;
	}
	
	return 0;
}


void removeNode(char *name, info *list)
{
	int strcmpValue;
	info *start = list;
	info *old = list;
	info *startAge = list;
	
	while (list->name != NULL)	/* Loop that finds name in list to be removed */
	{
		strcmpValue = strcmp(name, list->name);
		if (strcmpValue == 0) 
			break;
		if (list->nextName == NULL) 
			break;
		old = list;
		list = list->nextName;
	}
	
	if (strcmpValue == 0)	/* If name found, removes structure */
	{
		old->nextName = list->nextName;
		start = list;
		free(list->name);
		free(list);		/* Frees strucutre */
		list = NULL;
		
		list = old;
		while (start != startAge)	/* Reorders pointers */
		{
			old = startAge;
			startAge = startAge->nextAge;
		}
		old->nextAge = startAge->nextAge;
	}
}


void freeAndExit(info *ptr, info *list)
{
	ptr=NULL;
	while (list != NULL)	/* Loop to advance through list and free structures */
	{
		ptr = list->nextName;
		if (list->name != NULL) 
			free(list->name);
		free(list);
		list = ptr;
	}
}

