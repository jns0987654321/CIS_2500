#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
    char *name;
    int age;
    struct node *nextName;
    struct node *nextAge;
};

void addStruct(struct node *);
void removeStruct();
void printListByName(struct node *);
void printListByAge(struct node *);
void sortByName(struct node *, struct node *);
void sortByAge( struct node *, struct node *);

int main(void){
	
    struct node *list;
    short int exit = 0;
    char input;
	
    list = malloc( sizeof(struct node) * 1);
    list->name = NULL;
    list->age = -1;
    list->nextName = NULL;
    list->nextAge = NULL;
	
    do {
		
        printf("1. Add Structure\n2. Remove Structure\n3. Print names\n4. Print ages\n5. Exit\n\nOption: ");
		
        do {
            input = getchar();
        } while (input == '\n');
        while(getchar() != '\n');
		
        switch (input){
            case '1':
                addStruct(list);
                break;
            case '2':
                removeStruct(list);
                break;
            case '3':
                printListByName(list);
                break;
            case '4':
                printListByAge(list);
                break;
            case '5':
                exit = 1;
                break;
        }
		
        printf("\n");
		
    } while (exit == 0);
	
	
    /* Free all by name.  It doesn't matter whether we progress
	 through the list by age or name, as long as we make sure we
	 go all the way through the list. */
    struct node *next;
	
    do {
        next = list->nextName;
        if (list->name != NULL) free(list->name);
        free(list);
        list = next;
    } while (list != NULL);
	
    return 0;
}

void addStruct(struct node* list){
	
	struct node *newNode;
	newNode = malloc( sizeof(struct node) * 1);
	if (newNode == NULL) {
		printf("Error allocating memory...\n");
		return;
	}
	
	char c, newName[255];
	int i;
	
	printf("\n\tName: ");
	for ( i = 0; i < 255; i++){
		c = getchar();
		if (c == '\n') break;
		
		newName[i] = c;
	}
	newName[i] = '\0';
	
	newNode->name = malloc( sizeof(char) * i+1 );
	strncpy(newNode->name, newName, i+1);
	
	printf("\tAge: ");
	for ( i = 0; i < 3; i++ ){
		c = getchar();
		if (c == '\n') break;
		
		newName[i] = c;
	}
	newName[i] = '\0';
	
	newNode->age = atoi(newName);
	newNode->nextName = NULL;
	newNode->nextAge = NULL;
	
	sortByName(list, newNode);
	sortByAge(list, newNode);
	
	return;
}

void sortByName(struct node *list, struct node *n){
	
    int cmpResult;
    while (list->nextName != NULL){
        cmpResult = strcmp(list->nextName->name, n->name);
        if (cmpResult >= 0) break;
        if (list->nextName == NULL) break;
		
        list = list->nextName;
    }
	
    n->nextName = list->nextName;
    list->nextName = n;
    return;
}

void sortByAge( struct node *list, struct node *n){
	
    while ( list->nextAge != NULL ){
        if ((list->nextAge->age) > (n->age)) break;
        if (list->nextAge == NULL) break;
		
        list=list->nextAge;
    }
	
    n->nextAge = list->nextAge;
    list->nextAge = n;
    return;
}

void removeStruct(struct node *list){
	
    if ((list->nextName == NULL) && (list->name == NULL)){
        printf("No records to remove...\n");
        return;
    }
	
    char c, name[255];
    int i;
	
    struct node *currAge = list;
	
    printf("Enter name to remove: ");
	
    for (i = 0; i < 255; i++){
        c = getchar();
        if (c == '\n') break;
		
        name[i] = c;
    }
    name[i] = NULL;
    printf("\n");
	
    /* Compare names */
    struct node *curr, *prev = list;
    if( list->name == NULL) list = list->nextName;
	
    int cmpResult;
    do {
        cmpResult = strcmp(name, list->name);
		
        if (cmpResult == 0) break;
        if (list->nextName == NULL) break;
		
        prev = list;
        list = list->nextName;
    } while (list->name != NULL);
	
    if (cmpResult == 0){
        /* Remove appropriate entry */
        prev->nextName = list->nextName;
		
        curr = list;
        free(list->name);
        free(list);
		
        list = prev;
		
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


void printListByName(struct node *list){
	
    printf("\n");
	
    printf("\tSorted by name:\n\n");
    while (list != NULL){
        printf("\tName: %s\t\tAge: %d\n", list->name, list->age);
        list = list->nextName;
    }
}

void printListByAge(struct node *list){
	
    printf("\n");
	
    printf("\tSorted by age:\n\n");
    while (list != NULL){
        printf("\tAge: %d\t\tName: %s\n", list->age, list->name);
        list = list->nextAge;
    }
}