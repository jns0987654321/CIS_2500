#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	
	FILE *fp;
	int sum = 0;
	int randNum = 0;
	int i = 0;
	
	fp = fopen("randomNumbers.txt", "w");
	for(i = 0; i < 100; i = i + 1)
	{
		randNum = rand() % 20;
		fprintf(fp, "%d ", randNum);
	}
	fclose(fp);
	
	fp = fopen("randomNumbers.txt", "r");
	for (i = 0; i < 100; i++)
	{
		fscanf(fp, "%d ", &randNum);
		sum = sum + randNum;
	}
	fclose(fp);
	
	printf("Sum of random numbers is: %d \n", sum);
	
	return 0;
}
