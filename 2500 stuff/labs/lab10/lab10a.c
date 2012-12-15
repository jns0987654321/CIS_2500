#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
	char string[] = "abcABCabcABC";
	int length, i;
	char c;
	
	printf("%s\n", string);
	length = strlen(string);
	
	for (i=0; i<length; i++)
	{
		c = string[i];
		if (isupper(c))
		{
			c=tolower(c);
		}
		string[i] = c;
	}
	printf("%s\n", string);
	
	for (i=0; i<length; i++)
	{
		c = string[i];
		if (islower(c))
		{
			c = toupper(c);
		}
		string[i] = c;
	}
	printf("%s\n", string);
	
	return 0;
}