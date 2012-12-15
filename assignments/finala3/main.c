
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct employeeRecord
{
	char *name;
	char *address;
	short addressLength, nameLength;
	int phoneNumber;
}records;

void Choice1(FILE *fp, records *ptr, char *namest, records *b, char *addressst, int *choices, int *isAllocated, int *ch);
void Choice2(char tempName[51], FILE *fp, int maxFileSize, records *b, char *namest, char *addressst, int *choices, int *ch);
void Choice3(int recordNum, FILE *fp, int *maxFileSize, int i, records *b, int *currentFileSize, char *namest, char *addressst, int *choices, int *ch);



int main (void)
{	
	FILE *fp;
	int ch=0, i;
	int choices=0;
	int isAllocated;
	int maxFileSize;
	int recordNum;
	int currentFileSize;
	records *ptr;
	records b;
	char *namest;
	char *addressst;
	char tempName[51];
	
	while(ch==0)
	{
		if (ch==0) 
		{
			printf("\n1. Enter a new record. \n");
			printf("2. Retrieve a record by name. \n");
			printf("3. Retrieve a record by number. \n");
			printf("4. Exit \n");
			printf("Enter a number from 1-4: ");
			scanf("%d", &ch);
			fflush(stdin);
			
		}
		
		if (ch==1) 
		{	
			Choice1(fp, ptr, namest, &b, addressst, &choices, &isAllocated, &ch);
		}
		
		if (ch==2) 
		{
			Choice2(tempName, fp, maxFileSize, &b, namest, addressst, &choices, &ch);
		}
		
		if (ch==3) 
		{
			Choice3(recordNum, fp, &maxFileSize, i, &b, &currentFileSize, namest, addressst, &choices, &ch);
		}
		
	}
		
	if (choices>=1) 
	{
		free(namest);
		free(addressst);
		if (isAllocated==1) 
		{
			free(ptr->name);
			free(ptr->address);
			free(ptr);
		}
	}
	
	
    return 0;
}

void Choice1(FILE *fp, records *ptr, char *namest, records *b, char *addressst, int *choices, int *isAllocated, int *ch)
{
	getchar();
	
	fp = fopen("employeeRecords", "ab+");
	
	ptr = malloc(sizeof(records));
	ptr->name = malloc(sizeof(char));
	namest = malloc(sizeof(char)*b->nameLength);
	
	
	printf("Enter the name:\n ");
	fgets(namest, 100, stdin);
	fflush(stdin);
	strcpy(ptr->name, namest);
	ptr->nameLength = strlen(ptr->name)+1;
	
	ptr->address = malloc(sizeof(char));
	
	addressst = malloc(sizeof(char)*b->addressLength);
	
	printf("Enter the address:\n ");
	fgets(addressst, 100, stdin);
	fflush(stdin);
	
	strcpy(ptr->address, addressst);
	ptr->addressLength = strlen(ptr->address)+1;
	
	printf("Enter the phone number:\n ");
	scanf("%d", &ptr->phoneNumber);
	fflush(stdin);
	
	fwrite(ptr, sizeof(records), 1, fp);
	fseek(fp, -sizeof(records), SEEK_CUR);
	fread(&b, sizeof(records), 1, fp);
	
	fwrite(namest, sizeof(char)*b->nameLength, 1, fp);
	fwrite(addressst, sizeof(char)*b->addressLength, 1, fp);
	
	printf("\nRecord Stored Successfully!!\n");
	
	fclose(fp);
	
	*choices=*choices+1;
	*isAllocated=1;
	*ch=0;
	
}


void Choice2(char tempName[51], FILE *fp, int maxFileSize, records *b, char *namest, char *addressst, int *choices, int *ch)
{
	getchar();
	
	printf("\nEnter a name: ");
	fgets(tempName, 51, stdin);
	fflush(stdin);
	
	
	fp = fopen("employeeRecords", "r+");
	fseek(fp, 0L, SEEK_END);
	maxFileSize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	
	while (ftell(fp)!= maxFileSize)
	{
		fread(&b, sizeof(records), 1, fp);	
		
		namest = malloc(sizeof(char)*b->nameLength);
		addressst = malloc(sizeof(char)*b->addressLength);
		
		fread(namest, sizeof(char)*b->nameLength, 1, fp);
		fread(addressst, sizeof(char)*b->addressLength, 1, fp);
		
		printf("1 %s\n", b->name);
		printf("2 %s\n", namest);

		if ((strcmp(namest, tempName)==0)) 
		{
			printf("error!!\n");

			printf("\nMATCH FOUND!!\n");
			printf("Name: %s", namest);
			printf("Address: %s", addressst);
			printf("Telephone Number: %d\n", b->phoneNumber);
			break;	
		}
	}
	
	if ((ftell(fp)==maxFileSize) && (strcmp(namest, tempName)!=0)) {
		printf("\nMATCH NOT FOUND!!\n");
	}
	printf("1 %s\n", namest);
	printf("2 %s\n", tempName);
	fclose(fp);
	
	*choices=*choices+1;
	*ch=0;
	
}

void Choice3(int recordNum, FILE *fp, int *maxFileSize, int i, records *b, int *currentFileSize, char *namest, char *addressst, int *choices, int *ch)
{
	getchar();
	
	printf("\nEnter a record number: \n");
	scanf("%d", &recordNum);
	fflush(stdin);
	
	fp = fopen("employeeRecords", "r");
	fseek(fp, 0L, SEEK_END);
	*maxFileSize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	
	for (i=1; i<recordNum; i++) 
	{
		fread(b, sizeof(records), 1, fp);	
		fseek(fp, +b->nameLength+b->addressLength, SEEK_CUR);
	}
	
	*currentFileSize=ftell(fp);
	
	if (*currentFileSize<*maxFileSize) 
	{
		fread(b, sizeof(records), 1, fp);		
		
		namest = malloc(sizeof(char)*b->nameLength);
		addressst = malloc(sizeof(char)*b->addressLength);
		
		fread(namest, sizeof(char)*b->nameLength, 1, fp);
		fread(addressst, sizeof(char)*b->addressLength, 1, fp);
		printf("\nName: %s", namest);
		printf("Address: %s", addressst);
		printf("Telephone Number: %d\n", b->phoneNumber);
	}else 
		printf("\nRecord number too large!!\n");
	
	*choices=*choices+1;
	*ch=0;
}


