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
	int ch=0;
	records *ptr;
	records b;
	char *namest;
	char *addressst;
	char *SearchName;
	char tempName[50];
	
	
	
	
	while(ch==0)
	{
		if (ch==0) 
		{
			printf("1. Enter a new record. \n");
			printf("2. Retrieve a record by name. \n");
			printf("3. Retrieve a record by number. \n");
			printf("4. Exit \n");
			printf("Enter a number from 1-4: ");
			scanf("%d", &ch);
		}
		
		if (ch==1) 
		{	
			getchar();
			//if ( (fp = fopen("employeeRecords.txt", "r+")) == NULL)
			//{
			fp = fopen("employeeRecords", "ab+");
			//}
			//else
			//{
			//	fp = fopen("employeeRecords", "r+");
			//}
			
			ptr = malloc(sizeof(records));
			ptr->name = malloc(sizeof(char));
			
			namest = malloc(sizeof(char)*b.nameLength);


			printf("Enter the name:\n ");
			fgets(namest, 100, stdin);
			strcpy(ptr->name, namest);
			ptr->nameLength = strlen(ptr->name);
			
			//printf("%d", ptr->nameLength);
			//printf("%s", ptr->name);
			
			ptr->address = malloc(sizeof(char));
			
			addressst = malloc(sizeof(char)*b.addressLength);

			printf("Enter the address:\n ");
			fgets(addressst, 100, stdin);
			strcpy(ptr->address, addressst);
			ptr->addressLength = strlen(ptr->address);
			//printf("%d", ptr->addressLength);
			//printf("%s", ptr->address);
			
			printf("Enter the phone number:\n ");
			scanf("%d", &ptr->phoneNumber);
			//printf("%d", ptr->phoneNumber);
			
			
			fwrite(ptr, sizeof(records), 1, fp);
		//	fseek(fp, -sizeof(records), SEEK_CUR);
		//	fread(&b, sizeof(records), 1, fp);
			
			//addressst = malloc(sizeof(char)*b.addressLength);
			//ptr = malloc(sizeof(char)*ptr->addressLength);
			//fseek(fp, sizeof(records), SEEK_CUR);
			fwrite(namest, sizeof(char)*b.nameLength, 1, fp);
			fwrite(addressst, sizeof(char)*b.addressLength, 1, fp);
			fclose(fp);
			
			/*
			
			fp = fopen("employeeRecords", "ab+");
			fseek(fp, 0L, SEEK_SET);
			//fseek(fp, (-sizeof(records)-sizeof(char)*b.nameLength-sizeof(char)*b.addressLength), SEEK_END);
			
			
			fread(&b, sizeof(records), 1, fp);
			//	fseek(fp, (sizeof(char)*b.nameLength+sizeof(char)*b.addressLength), SEEK_CUR);
			
			fread(namest, sizeof(char)*b.nameLength, 1, fp);
			fread(addressst, sizeof(char)*b.addressLength, 1, fp);
			

			//fread(&b, sizeof(records), 1, fp);
			
			//fread(namest, sizeof(char)*ptr->nameLength, 1, fp);
			//fread(addressst, sizeof(char)*ptr->addressLength, 1, fp);
			
			strcpy(namest, b.name);			
			strcpy(addressst, b.address);
			fclose(fp);
			printf("%s %s %d\n", b.name, b.address, b.phoneNumber);
			printf("%s\n", namest);
			printf("%s\n", addressst);
			printf("%d\n", b.nameLength);
			printf("%d\n", b.addressLength);
			
			*/
			
			
			ch=0;
		}
		
		if (ch==2) 
			
		{
			getchar();
			SearchName = malloc(sizeof(char)*99);
			printf("Enter a name:\n ");
			fgets(SearchName, 100, stdin);

			fp = fopen("employeeRecords", "r");
			fseek(fp, 0L, SEEK_CUR);
			
			fread(&b, sizeof(records), 1, fp);
			if (strcmp(b.name, SearchName)!=0)
			{
				fseek(fp, 0L, SEEK_CUR);
				
				fread(&b, sizeof(records), 1, fp);
				//	fseek(fp, (sizeof(char)*b.nameLength+sizeof(char)*b.addressLength), SEEK_CUR);
				
				fread(namest, sizeof(char)*b.nameLength, 1, fp);
				fread(addressst, sizeof(char)*b.addressLength, 1, fp);
				
			}
			fclose(fp);
			
			printf("yesss \n");
			
			
			
			ch=0;
		}
		
		if (ch==3) 
		{
			printf("do #3\n");
			ch=0;
		}
		
	}
    return 0;
}
