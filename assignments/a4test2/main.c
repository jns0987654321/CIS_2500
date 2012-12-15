#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char *name;
	int age;
	struct node *nextName;
	struct node *nextAge;
}info;

info *NameSort(info *ptr, info *nameRoot);
info *AgeSort(info *ptr, info *ageRoot);
void removeStruct(info *ageRoot);

int main (void) 
{
	int ch=0;
	info *nameRoot; 
	info *ptr; 
	info *ageRoot;
	char *nameString;
	char name[26];
	nameRoot = NULL;
	ptr = NULL;
	ageRoot = NULL;
	
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
			printf("Do #1\n");
			
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
			
			ptr->nextName = nameRoot;
			ptr->nextAge = ageRoot;
			ageRoot = AgeSort(ptr,ageRoot);
			nameRoot = NameSort(ptr, nameRoot);
			
			ch=0;
		}
		
		if (ch==2) 
		{
	
			printf("test\n");
			removeStruct(ageRoot);
			printf("testtt\n");
			ch=0;
		}
		
		if (ch==3) 
		{
			getchar();	
			ptr=nameRoot;
			if (ptr->name == NULL){
				ptr = ptr->nextName;
			}
			
			
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
			ptr=ageRoot;
			if (ptr->age == -1){
				ptr = ptr->nextAge;
			}
			
			
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

info *AgeSort(info *ptr, info *ageRoot)
{	
	info *old;
	info *start;
	start = ageRoot;
	old = ageRoot;
	while(start != NULL)
	{
		if (ptr->age > start->age)
		{
			old = start;
			start = start->nextAge;
		}
		else
			break;
	}
	
	if(old != start)
	{
		old->nextAge = ptr;
		ptr->nextAge = start;
		return ageRoot;
	}
	
	if (old == start)
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
	while(start != NULL)
	{
		if (strcmp(ptr->name, start->name) > 0)
		{
			old = start;
			start = start->nextName;
		}
		else
			break;
	}
	
	if(old != start)
	{
		old->nextName = ptr;
		ptr->nextName = start;
		return nameRoot;
	}
	
	if (old == start)
	{
		ptr->nextName = start;
		return ptr;
	}
	
	return 0;
}

void removeStruct(info *ageRoot){
	
    if ((ageRoot->nextName == NULL) && (ageRoot->name == NULL)){
        printf("No records to remove...\n");
        return;
    }
	
    char c, name[255];
    int i;
	
    struct node *currAge = ageRoot;
	
    printf("Enter name to remove: ");
	
	getchar();
	printf("Enter name of structure to remove: \n");
	fgets(name, 100, stdin);
	fflush(stdin);
	
    /* Compare names */
    struct node *curr, *prev = ageRoot;
    if( ageRoot->name == NULL) ageRoot = ageRoot->nextName;
	
    int cmpResult;
    do {
        cmpResult = strcmp(name, ageRoot->name);
		
        if (cmpResult == 0) break;
        if (ageRoot->nextName == NULL) break;
		
        prev = ageRoot;
        ageRoot = ageRoot->nextName;
    } while (ageRoot->name != NULL);
	
    if (cmpResult == 0){
        /* Remove appropriate entry */
        prev->nextName = ageRoot->nextName;
		
        curr = ageRoot;
        free(ageRoot->name);
        free(ageRoot);
		
        ageRoot = prev;
		
        while (curr != currAge){
            prev = currAge;
            currAge = currAge->nextAge;
        }
		
        prev->nextAge = currAge->nextAge;
        return;
    }
	
    printf("No match found in records...\n");
    return;
}

