#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void NewRecord();
void RetrieveByName();
void RetrieveByNum();
void ExitAndFree();

typedef struct employeeRecord
{
	char *name;
	char *address;
	short addressLength, nameLength;
	int phoneNumber;
}records;

int main (void)
{	
	records *ptr;
	records tempStruct;
	FILE *fp;
	int ch=0, 
	int i;
	int choices=0;
	int isAllocated;
	int maxFileSize;
	int recordNum;
	int currentFileSize;
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
			NewRecord();
		}
		
		if (ch==2) 
		{
			RetrieveByName();
		}
		
		if (ch==3) 
		{
			RetrieveByNum();
		}
		
	}
	
	ExitAndFree();	
}

void NewRecord()
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
	
	fwrite(ptr, sizeof(records), 1, fp);
	fseek(fp, -sizeof(records), SEEK_CUR);
	fread(&tempStruct, sizeof(records), 1, fp);
	
	fwrite(namest, sizeof(char)*tempStruct.nameLength, 1, fp);
	fwrite(addressst, sizeof(char)*tempStruct.addressLength, 1, fp);
	
	printf("\nRecord Stored Successfully!!\n");
	
	fclose(fp);
	
	choices++;
	isAllocated=1;
	ch=0;
}


void RetrieveByName()
{
	getchar();
	
	printf("\nEnter a name: ");
	fgets(tempName, 51, stdin);
	fflush(stdin);
	
	
	fp = fopen("employeeRecords", "r+");
	fseek(fp, 0L, SEEK_END);
	maxFileSize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	
	while (ftell(fp)!=maxFileSize)
	{
		fread(&tempStruct, sizeof(records), 1, fp);	
		
		namest = malloc(sizeof(char)*tempStruct.nameLength);
		addressst = malloc(sizeof(char)*tempStruct.addressLength);
		
		fread(namest, sizeof(char)*tempStruct.nameLength, 1, fp);
		fread(addressst, sizeof(char)*tempStruct.addressLength, 1, fp);
		
		if ((strcmp(namest, tempName)==0)) 
		{
			printf("\nMATCH FOUND!!\n");
			printf("Name: %s", namest);
			printf("Address: %s", addressst);
			printf("Telephone Number: %d\n", tempStruct.phoneNumber);
			break;	
		}
	}
	
	if ((ftell(fp)==maxFileSize) && (strcmp(namest, tempName)!=0)) {
		printf("\nMATCH NOT FOUND!!\n");
	}
	
	fclose(fp);
	
	choices++;
	ch=0;	
}


void RetrieveByNum()
{
	getchar();
	
	printf("\nEnter a record number: \n");
	scanf("%d", &recordNum);
	fflush(stdin);
	
	fp = fopen("employeeRecords", "r");
	fseek(fp, 0L, SEEK_END);
	maxFileSize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	
	for (i=1; i<recordNum; i++) 
	{
		fread(&tempStruct, sizeof(records), 1, fp);	
		fseek(fp, +tempStruct.nameLength+tempStruct.addressLength, SEEK_CUR);
	}
	
	currentFileSize=ftell(fp);
	
	if (currentFileSize<maxFileSize) 
	{
		fread(&tempStruct, sizeof(records), 1, fp);		
		
		namest = malloc(sizeof(char)*tempStruct.nameLength);
		addressst = malloc(sizeof(char)*tempStruct.addressLength);
		
		fread(namest, sizeof(char)*tempStruct.nameLength, 1, fp);
		fread(addressst, sizeof(char)*tempStruct.addressLength, 1, fp);
		printf("\nName: %s", namest);
		printf("Address: %s", addressst);
		printf("Telephone Number: %d\n", tempStruct.phoneNumber);
	}else 
		printf("\nRecord number too large!!\n");
	
	choices++;
	ch=0;
}


void ExitAndFree()
{
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

