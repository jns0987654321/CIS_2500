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

int main (void)
{	
	FILE *fp;
	int choice=0;
	int maxFileSize;
	int recordNum;
	int currentFileSize;
	records *ptr;
	records b;
	char namest[50];
	char addressst[50];
	char tempName[51];
	
	while(choice==0)
	{
		if (choice==0) 
		{
			//printf("\n");
			printf("\n1. Enter a new record. \n");
			printf("2. Retrieve a record by name. \n");
			printf("3. Retrieve a record by number. \n");
			printf("4. Exit \n");
			printf("Enter a number from 1-4: ");
			scanf("%d", &choice);
		}
		
		if (choice==1) 
		{	
			getchar();
			
			fp = fopen("employeeRecords", "ab+");
			
			ptr = malloc(sizeof(records));
			ptr->name = malloc(sizeof(char));
			printf("\nEnter the name: ");
			fgets(namest, 100, stdin);
			strcpy(ptr->name, namest);
			ptr->nameLength = strlen(ptr->name);
			
			ptr->address = malloc(sizeof(char));
			printf("\nEnter the address: ");
			fgets(addressst, 100, stdin);
			strcpy(ptr->address, addressst);
			ptr->addressLength = strlen(ptr->address);
			
			printf("\nEnter the phone number: ");
			scanf("%d", &ptr->phoneNumber);			
			
			fwrite(ptr, sizeof(records), 1, fp);
			fwrite(namest, sizeof(char)*50, 1, fp);
			fwrite(addressst, sizeof(char)*50, 1, fp);
			
			printf("Record Stored Successfully!!\n");
			
			fclose(fp);
			
			choice=0;
		}
		
		if (choice==2) 
		{
			getchar();
			
			printf("\nEnter a name: ");
			fgets(tempName, 51, stdin);
			
			fp = fopen("employeeRecords", "r");
			fseek(fp, 0L, SEEK_END);
			maxFileSize = ftell(fp);
			fseek(fp, 0L, SEEK_SET);
			
			while (ftell(fp)!=maxFileSize)
			{
				fread(&b, sizeof(records), 1, fp);					
				fread(namest, sizeof(char)*50, 1, fp);
				fread(addressst, sizeof(char)*50, 1, fp);
				if ((strcmp(namest, tempName)==0)) 
				{
					printf("\nMATCH FOUND!!\n");
					printf("Name: %s", namest);
					printf("Address: %s", addressst);
					printf("Telephone Number: %d\n", b.phoneNumber);
					break;	
				}
			}
			
			if ((ftell(fp)==maxFileSize) && (strcmp(namest, tempName)!=0)) {
				printf("\nMATCH NOT FOUND!!\n");
			}
			
			fclose(fp);
			
			choice=0;
		}
		
		if (choice==3) 
		{
			getchar();
			
			printf("\nEnter a record number: \n");
			scanf("%d", &recordNum);
			fp = fopen("employeeRecords", "r");
			fseek(fp, 0L, SEEK_END);
			maxFileSize = ftell(fp);
			fseek(fp, (+sizeof(records)+sizeof(char)*50+sizeof(char)*50)*(recordNum-1), SEEK_SET);
			//printf("max %d\n", x);
			currentFileSize=ftell(fp);
			//printf("current %d\n", y);
			
			if (currentFileSize<maxFileSize) 
			{
				fread(&b, sizeof(records), 1, fp);					
				fread(namest, sizeof(char)*50, 1, fp);
				fread(addressst, sizeof(char)*50, 1, fp);
				printf("\nName: %s", namest);
				printf("Address: %s", addressst);
				printf("Telephone Number: %d\n", b.phoneNumber);
			}else 
				printf("\nRecord number too large!!\n");
			
			
			choice=0;
		}
		
	}
	
	free(ptr->name);
	free(ptr->address);
	free(ptr);
	ptr=NULL;
	
    return 0;
}
