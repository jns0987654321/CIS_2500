/*
 Roman Nahovitsyn
 Assingment Three 
 Due week of March 8
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Structure of records */
struct employeeRecord 
{
	char *name;
	char *address;
	short addressLength, nameLength;
	int phoneNumber;
};
/* rename "struct employeeRecord" to "structdef" for ease of writing */
typedef struct employeeRecord structDef;
/* - - - - - - - - - - writeRcrd - - - - - - - - - - */
void writeRcrd(int select)
{
	FILE *fp;
	structDef *records;
	records = malloc(sizeof(structDef));
	char nameTmp[100], addressTmp[100];
	int phoneTmp;
	short addressLngth, nameLngth;
	
	fp = fopen("records", "a");
	/* getting record from user */
	printf(" Enter Name: \n");
	scanf("%s", nameTmp);
	getchar();
	printf(" Enter Address: \n");
	scanf("%s", addressTmp);
	getchar();
	printf(" Enter Phone Number: \n");
	scanf("%d", &phoneTmp);
	
	nameLngth = (strlen(nameTmp));
	addressLngth = (strlen(addressTmp));
	
	records->name = malloc(sizeof(char)*nameLngth);
	records->address = malloc(sizeof(char)*addressLngth);
	records->addressLength = addressLngth;
	records->nameLength = nameLngth;
	records->phoneNumber = phoneTmp;
	
	strcpy(records->name, nameTmp);
	strcpy(records->address, addressTmp);
	
	fwrite(records, sizeof(structDef), 1, fp);
	fwrite(records->name, sizeof(char), nameLngth, fp);
	fwrite(records->address, sizeof(char), addressLngth, fp);
	
	printf(" - Record Stored - \n");
	fclose(fp);
	free(records->name);
	free(records->address);
}
/* - - - - - - - - - - searchRcrd - - - - - - - - - - */
void searchRcrd(int select)
{
	int ctr = 0, sLength,aLength, bLength, compare;
	/*long fLength;*/
	FILE *fp;
	structDef structTmp;
	//structTmp = malloc(sizeof(structDef));
	char nameSearch[100], nameBuffer[100], addressBuffer[100], *search, *buffer, *address;
	
	printf(" Please enter a name to search for: \n");
	scanf("%s", nameSearch);
	sLength = strlen(nameSearch);
	search = malloc(sizeof(char)*sLength);
	strcpy(search, nameSearch);
	
	fp = fopen("records", "r");
	
	
	/*
	 fp = fopen("records", "r");
	 fseek(fp, 0L, SEEK_END);
	 fLength = ftell(fp);
	 fseek(fp, 0L, SEEK_SET);
	 */
	while(!feof(fp))
	{
		fread(&structTmp, sizeof(structDef), 1, fp);
		buffer = malloc(sizeof(char)*structTmp.nameLength);
		address = malloc(sizeof(char)*structTmp.addressLength);
		fread(buffer, sizeof(char), structTmp.nameLength, fp);
		fread(address, sizeof(char), structTmp.addressLength, fp);
		//aLength = structTmp->addressLength;
		//bLength = structTmp->nameLength;
		strcpy(nameBuffer, buffer);
		//strcpy(address, addressBuffer);
		
		
		compare = strcmp(search, nameBuffer);
		printf(" search = %s buffer = %s \n", search, buffer);
		
		if(compare == 0)
		{
			ctr = ctr + 1;
			printf(" Record %d: \n", ctr);
			printf(" Name: %s \n", buffer);
			printf(" Address: %s \n", address);
			printf(" Phone #: %d \n", structTmp.phoneNumber);
			free(buffer);
			free(address);
			break;
		}
		/*
		else
		{
			free(buffer);
			free(address);	
		}
		*/
		/*
		fread(structTmp, sizeof(structDef), 1, fp);
		fread(nameBuffer, sizeof(char), structTmp->nameLength, fp);
		fread(addressBuffer, sizeof(char), structTmp->addressLength, fp);
		aLength = structTmp->addressLength;
		bLength = structTmp->nameLength;
		buffer = malloc(sizeof(char)*bLength - 1);
		address = malloc(sizeof(char)*aLength - 1);
		strcpy(address, addressBuffer);
		strcpy(buffer, nameBuffer);
		*/
	}
	/*while(ftell(fp) != fLength);*/
	
	printf("1 %s  2 %s\n", search, nameBuffer);
	
	printf("\n");
	printf(" Found %d Record(s) with name: %s \n", ctr, nameSearch);
	
	fclose(fp);
}
/* - - - - - - - - - - getRcrd - - - - - - - - - - */
void getRcrd(int recordNum)
{
	FILE *fp;
	int count = 1;
	structDef *structTmp;
	structTmp = malloc(sizeof(structDef));
	char *nameBuffer;
	char *addressBuffer;
	
	
	fp = fopen("records", "r");
	/*
	 fseek(fp, 0L, SEEK_END);
	 fLength = ftell(fp);
	 fseek(fp, 0L, SEEK_SET);
	 fLocation = ftell(fp);
	 */
	
	fread(structTmp, sizeof(structDef), 1, fp);
	nameBuffer = malloc(sizeof(char)*structTmp->nameLength);
	addressBuffer = malloc(sizeof(char)*structTmp->addressLength);
	fread(nameBuffer, sizeof(char), structTmp->nameLength, fp);
	fread(addressBuffer, sizeof(char), structTmp->addressLength, fp);
	printf("address length %d \n", structTmp->addressLength);
	
	while(!feof(fp))
	{
		if(count == recordNum)
		{
			printf(" Printing Desired Record ... \n");
			printf(" Name   : %s \n", nameBuffer);
			printf(" Address: %s \n", addressBuffer);
			printf(" Phone #: %d \n", structTmp->phoneNumber);
			break;
		}
		else if( count < recordNum )
		{
			/*fseek(fp, (sizeof(structTmp) + sizeof(char)*structTmp.nameLength + sizeof(char)*structTmp.addressLength), SEEK_CUR);*/
			fread(structTmp, sizeof(structDef), 1, fp);
			nameBuffer = malloc(sizeof(char)*structTmp->nameLength);
			addressBuffer = malloc(sizeof(char)*structTmp->addressLength);
			fread(nameBuffer, sizeof(char), structTmp->nameLength, fp);
			fread(addressBuffer, sizeof(char), structTmp->addressLength, fp);
			printf("address length %d \n", structTmp->addressLength);
			count = count + 1;
		}
	}
	if(feof(fp))
	{
		printf("Record not found.\n");
	}
	
	fclose(fp);
}
/* - - - - - - - - - - MAIN - - - - - - - - - - */
int main(void)
{
	/* - - Variable Decliration - - */
	int select;
	select = 0;
	FILE *fp;
	
	/* if to check if the file already exists or needs to be created */
	if ( (fp = fopen("records", "r")) == NULL)
	{
		fp = fopen("records", "w");
	}
	else
	{
		fp = fopen("records", "r");
	}
	
	/* Print statements to give illusion of menue */
	printf("   -- Main Menu -- \n");
	printf(" Please make a selection: \n");
	printf(" 1 - Input new records. \n");
	printf(" 2 - Search Records by entry. \n");
	printf(" 3 - Search Records by index. \n");
	printf(" 4 - Save and Exit. \n"); /* variable to know what the user wants to do */
	scanf("%d", &select);
	fclose(fp);
	
	/* while loop that keeps the user in the program */
	while(select != 4)
	{
		/* First selection, if to call input function */
		if( select == 1)
		{
			printf("   You have chosen to enter records,\n");
			writeRcrd(select);
			printf("   Returning to main menu ... \n");
			printf("\n");
		}
		/* Second selection, submenue to search by entry */
		else if( select == 2)
		{
			printf("   You have chosen to search for records by Name, \n");
			searchRcrd(select);
			printf(" Returning to main menu ... \n");
			printf(" \n");
		}
		/* Third selection, if to call record call function */
		else if( select == 3)
		{
			int recordNum;
			printf("   You have chosen to search by index, please enter desired record number: \n");
			scanf("%d", &recordNum);
			getRcrd(recordNum);
			printf(" Returning to main menu ... \n");
			printf(" \n");
		}
		/* Fourth selection, closes the file and breaks the loop exiting the program */
		else if( select == 4)
		{
			fclose(fp);
			break;
		}
		/* Defensive statement to prevent getting stuck in the program */
		else
		{
			printf(" Invalid Selection. Please try again \n");
			printf(" Returning to main menu ... \n");
			printf(" \n");
		}
		/* Menue appears a secon time so that it can be accesed in the loop */
		printf("   -- Main Menu -- \n");
		printf(" Please make a selection: \n");
		printf(" 1 - Input new records. \n");
		printf(" 2 - Search Records by entry. \n");
		printf(" 3 - Search Records by index. \n");
		printf(" 4 - Save and Exit. \n");
		scanf("%d", &select);/* variable to know what the user wants to do */
	}
	printf(" GoodBye. \n");
	
	return 0;
}
