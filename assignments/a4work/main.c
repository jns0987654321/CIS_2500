#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char *name;
	int age;
	struct node *nextName;
	struct node *nextAge;
}info;

info *NameSort(info *ptr, info *root);
info *AgeSort(info *ptr, info *ageHead);

int main (void) 
{
	int ch=0;
	info *root;
	info *ptr;
	info *ageHead;
	char *nameString;
	root = NULL;
	ptr = NULL;
	ageHead = NULL;
	
	while (ch==0) 
	{
		if (ch==0) 
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
		
		if (ch==1) 
		{
			getchar();
			
			ptr = malloc(sizeof(info));
			ptr->name = malloc(sizeof(char));
			nameString = malloc(sizeof(char));
			
			printf("\nEnter name:\n ");			
			fgets(nameString, 100, stdin);
			fflush(stdin);
			strcpy(ptr->name, nameString);

			
			printf("Enter age:\n ");
			scanf("%d", &ptr->age);
			fflush(stdin);
			
			ptr->nextName = root;
			ptr->nextAge=ageHead;
			ageHead = AgeSort(ptr,ageHead);
			root = NameSort(ptr, root);
			
			ch=0;
		}
		
		if (ch==2) 
		{
			printf("Do #2\n");
			
			ch=0;
		}
		
		if (ch==3) 
		{
			getchar();	
			ptr=root;
			while(ptr!=NULL)
			{
				printf("Age:%d Name:%s", ptr->age, ptr->name);
				ptr = ptr->nextName;
			}
			
			ch=0;
		}
		
		if (ch==4) 
		{
			getchar();			
			ptr=ageHead;
			while(ptr!=NULL)
			{
				printf("Age:%d Name:%s", ptr->age, ptr->name);
				ptr = ptr->nextAge;
			}
			
			ch=0;
		}
		
	}
	
    return 0;
}

info *AgeSort(info *ptr, info *ageHead)
{
	static info *last = NULL;
	info *old, *start;
	
	start = ageHead;
	if (last == NULL) 
	{
		ptr->nextAge = NULL;
		last      = ptr;
		return (ptr);
	}
	old = NULL;
	while (ageHead !=NULL) 
	{
		if (ageHead->age < ptr->age)
		{
			old = ageHead;
			ageHead = ageHead->nextAge;
		}
		else 
		{
			if (old != NULL) 
			{
				old->nextAge = ptr;
				ptr->nextAge = ageHead;
				return (start);
			}
			ptr->nextAge = ageHead; 
			return (ptr);
		}
	}
	last->nextAge = ptr;
	ptr->nextAge  = NULL;
	last       = ptr;
	return (start);
}

info *NameSort(info *ptr, info *root)
{
	static info *last = NULL;
	info *old, *start;
	//working;
	
	start = root;
	if (last == NULL) 
	{
		ptr->nextName = NULL;
		last      = ptr;
		return (ptr);
	}
	old = NULL;
	while (root != NULL) 
	{
		if (strcmp(root->name, ptr->name) < 0)
		{
			old = root;
			root = root->nextName;
		}
		else 
		{
			if (old != NULL) 
			{
				old->nextName = ptr;
				ptr->nextName = root;
				return (start);
			}
			ptr->nextName = root; 
			return (ptr);
		}
	}
	last->nextName = ptr;
	ptr->nextName  = NULL;
	last       = ptr;
	return (start);
}
