/* Junior Samaroo     0663108 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int a[100], b[100], i;
	FILE *fp;

	fp=fopen("tmpfile", "w");
	for(i=0; i<100; i++)
	a[i]=i;
	fwrite(a, sizeof(int), 100, fp);
	fclose(fp);

	fp=fopen("tmpfile", "r");
	fread(b, sizeof(int), 100, fp);
	fclose(fp);
	
	for(i=0; i<100; i++)
	printf("%d ", b[i]);

	return(0);
}
