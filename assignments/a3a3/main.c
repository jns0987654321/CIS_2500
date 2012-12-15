
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

void choice1(records *ptr, FILE *fp, records *tempStruct, char *namest, char *addressst);
void choice2(FILE *fp, int *maxFileSize, records *tempStruct, char *namest, char *addressst, char tempName[51]);
void choice3(int i, int *recordNum, records *tempStruct, FILE *fp, int *currentFileSize, int *maxFileSize, char *namest, char *addressst);
void FreeAndExit(int *choices, char *namest, char *addressst, int *isAllocated, records *ptr);

int main (void)
{	
	FILE *fp;
	int ch=0; 
	int i;
	int choices=0;
	int isAllocated;
	int maxFileSize;
	int recordNum;
	int currentFileSize;
	records *ptr;
	records tempStruct;
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
			getchar();
			fp = fopen("employeeRecords", "ab+");
			
			ptr = malloc(sizeof(records));
			ptr->name = malloc(sizeof(char));
			namest = malloc(sizeof(char)*tempStruct.nameLength);
			
			printf("Enter the name:\n ");
			fgets(namest, 100, stdin);
			fflush(stdin);
			strcpy(ptr->name, namest);
			ptr->nameLength = strlen(ptr->name)+1;
			
			ptr->address = malloc(sizeof(char));
			addressst = malloc(sizeof(char)*tempStruct.addressLength);
			printf("Enter the address:\n ");
			fgets(addressst, 100, stdin);
			fflush(stdin);
			strcpy(ptr->address, addressst);
			ptr->addressLength = strlen(ptr->address)+1;
			
			printf("Enter the phone number:\n ");
			scanf("%d", &ptr->phoneNumber);
			fflush(stdin);
			
			choice1(ptr, fp, &tempStruct, namest, addressst);
			
			printf("\nRecord Stored Successfully!!\n");
			
			fclose(fp);
			choices=choices+1;
			isAllocated=1;
			ch=0;
		}
		
		if (ch==2) 
		{
			getchar();
			
			printf("\nEnter a name: ");
			fgets(tempName, 51, stdin);
			fflush(stdin);
			
			fp = fopen("employeeRecords", "r+");
			fseek(fp, 0L, SEEK_END);
			maxFileSize = ftell(fp);
			fseek(fp, 0L, SEEK_SET);
			
			choice2(fp, &maxFileSize, &tempStruct, namest, addressst, tempName);
			
			fclose(fp);
			choices=choices+1;
			ch=0;
		}
		
		if (ch==3) 
		{
			getchar();
			
			printf("\nEnter a record number: \n");
			scanf("%d", &recordNum);
			fflush(stdin);
			
			fp = fopen("employeeRecords", "r");
			fseek(fp, 0L, SEEK_END);
			maxFileSize = ftell(fp);
			fseek(fp, 0L, SEEK_SET);
			
			choice3(i, &recordNum, &tempStruct, fp, &currentFileSize, &maxFileSize, namest, addressst);
			
			fclose(fp);
			choices=choices+1;
			ch=0;
		}
	}
	
	FreeAndExit(&choices, namest, addressst, &isAllocated, ptr);
	
    return 0;
}

void choice1(records *ptr, FILE *fp, records *tempStruct, char *namest, char *addressst)
{
	fwrite(ptr, sizeof(records), 1, fp);
	fseek(fp, -sizeof(records), SEEK_CUR);
	fread(tempStruct, sizeof(records), 1, fp);
	fwrite(namest, sizeof(char)*tempStruct->nameLength, 1, fp);
	fwrite(addressst, sizeof(char)*tempStruct->addressLength, 1, fp);
}

void choice2(FILE *fp, int *maxFileSize, records *tempStruct, char *namest, char *addressst, char tempName[51])
{
	while (ftell(fp)!=*maxFileSize)
	{
		fread(tempStruct, sizeof(records), 1, fp);	
		namest = malloc(sizeof(char)*tempStruct->nameLength);
		addressst = malloc(sizeof(char)*tempStruct->addressLength);
		fread(namest, sizeof(char)*tempStruct->nameLength, 1, fp);
		fread(addressst, sizeof(char)*tempStruct->addressLength, 1, fp);
		
		if ((strcmp(namest, tempName)==0)) 
		{
			printf("\nMATCH FOUND!!\n");
			printf("Name: %s", namest);
			printf("Address: %s", addressst);
			printf("Telephone Number: %d\n", tempStruct->phoneNumber);
			break;	
		}
	}
	
	if ((ftell(fp)==*maxFileSize) && (strcmp(namest, tempName)!=0)) 
	{
		printf("\nMATCH NOT FOUND!!\n");
	}	
	
}

void choice3(int i, int *recordNum, records *tempStruct, FILE *fp, int *currentFileSize, int *maxFileSize, char *namest, char *addressst)
{
	for (i=1; i<*recordNum; i++) 
	{
		fread(tempStruct, sizeof(records), 1, fp);	
		fseek(fp, +tempStruct->nameLength+tempStruct->addressLength, SEEK_CUR);
	}
	
	*currentFileSize=ftell(fp);
	
	if (*currentFileSize<*maxFileSize) 
	{
		fread(tempStruct, sizeof(records), 1, fp);		
		namest = malloc(sizeof(char)*tempStruct->nameLength);
		addressst = malloc(sizeof(char)*tempStruct->addressLength);
		fread(namest, sizeof(char)*tempStruct->nameLength, 1, fp);
		fread(addressst, sizeof(char)*tempStruct->addressLength, 1, fp);
		
		printf("\nName: %s", namest);
		printf("Address: %s", addressst);
		printf("Telephone Number: %d\n", tempStruct->phoneNumber);
		
	}else 
		printf("\nRecord number too large!!\n");	
	
}

void FreeAndExit(int *choices, char *namest, char *addressst, int *isAllocated, records *ptr)
{
	if (*choices>=1) 
	{
		namest=NULL;
		addressst=NULL;
		
		if (*isAllocated==1) 
		{
			free(ptr->name);
			free(ptr->address);
			free(ptr);
		}
	}		
}

