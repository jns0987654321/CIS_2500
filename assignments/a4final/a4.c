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

info *NameSort(info *ptr, info *nameRoot);	/* Function to sort list by name alphabetically */
info *AgeSort(info *ptr, info *ageRoot);	/* Function to sort list by age in ascending order */
void removeNode(char *name, info *nameRoot, info *ageRoot);	/* Function to remove a structure from the list */
void freeAndExit(info *ptr, info *nameRoot);	/* Function to free the structures and exit the program */

int main (void) 
{
	int ch=0;			/* User's choice flag */
	info *nameRoot;		/* Name sorted list pointer */
	info *ptr;			/* Pointer to step through list */
	info *ageRoot;		/* Age Sorted list pointer */
	char *nameString;	/* Name to be stored */
	char name[26];		/* Name to search for and remove */
	nameRoot = NULL;	
	ptr = NULL;			
	ageRoot = NULL;
	
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
			
			ptr->nextAge = ageRoot;			
			ptr->nextName = nameRoot;
			nameRoot = NameSort(ptr, nameRoot);	/* Calls function to sort list by name and returns new root */
			ageRoot = AgeSort(ptr,ageRoot);		/* Calls function to sort list by age and returns new root */
			
			ch=0;
		}
		
		if (ch==2) /* Selection that removes structure from list */
		{
			getchar();
			printf("Enter name of structure to remove: \n");
			fgets(name, 100, stdin);
			fflush(stdin);
			removeNode(name, nameRoot, ageRoot);	/* Calls function to remove structure */
			ch=0;
		}
		
		if (ch==3) /* Selection that prints list ordered by name */
		{
			getchar();	
			ptr=nameRoot;
		 
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
			ptr=ageRoot;
		 
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
			freeAndExit(ptr, nameRoot);	 /* Calls function to free and exit program */
		}
	}
	
    return 0;
}


info *AgeSort(info *ptr, info *ageRoot)
{	
	info *old;
	info *start;
	start = ageRoot;
	old = ageRoot;
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
		return ageRoot;	/* Returns new root */
	}
	
	if (old == start)	/* If node is not before root return sorted list */
	{
		ptr->nextAge = start;
		return ptr;
	}
	
	return 0;
}


info *NameSort(info *ptr, info *nameRoot)
{	
	info *old;
	info *start;
	start = nameRoot;
	old = nameRoot;
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
		return nameRoot;	/* Returns new root */
	}
	
	if (old == start)	/* If node is not before root return sorted list */
	{
		ptr->nextName = start;
		return ptr;
	}
	
	return 0;
}


void removeNode(char *name, info *nameRoot, info *ageRoot)
{
	int strcmpValue;
	info *start = NULL;
	info *old = nameRoot;
	info *startAge = ageRoot;
	
	while (nameRoot->name != NULL)	/* Loop that finds name in list to be removed */
	{
		strcmpValue = strcmp(name, nameRoot->name);
		if (strcmpValue == 0) 
			break;
		if (nameRoot->nextName == NULL) 
			break;
		old = nameRoot;
		nameRoot = nameRoot->nextName;
	}
	
	if (strcmpValue == 0)	/* If name found, removes structure */
	{
		old->nextName = nameRoot->nextName;
		start = nameRoot;
		free(nameRoot->name);
		free(nameRoot);		/* Frees strucutre */
		nameRoot = NULL;
		
		nameRoot = old;
		while (start != startAge)	/* Reorders pointers */
		{
			old = startAge;
			startAge = startAge->nextAge;
		}
		old->nextAge = startAge->nextAge;
	}
}


void freeAndExit(info *ptr, info *nameRoot)
{
	ptr=NULL;
	while (nameRoot != NULL)	/* Loop to advance through list and free structures */
	{
		ptr = nameRoot->nextName;
		if (nameRoot->name != NULL){
			free(nameRoot->name);
			free(nameRoot);}
		nameRoot = ptr;
	}
}

