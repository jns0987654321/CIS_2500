/* Junior Samaroo    0663108 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int size;
	char String[sizeof(float)*3];
	float num1, num2, num3;
	
	printf("Please enter three numbers:\n");
	fgets(String, (sizeof(float)*3)+1, stdin);
	size=strlen(String);
	
	sscanf(String, "%f %f %f", &num1, &num2, &num3);
	
	printf("num1=%f num2=%f num3=%f \n", num1, num2, num3); 
	
	char newString[size];
	
	sprintf(newString, "%f %f %f", num1, num2, num3);
	
	printf("%s\n", newString);
	
	return 0;
}
