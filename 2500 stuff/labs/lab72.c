/* Junior Samaroo      0663108 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
	int count;
	double total;
}info;

int main(void)
{
	FILE *fp;
	int i, size;
	info str[10];
	info str2;
	
	fp=fopen("infodata", "r+");
	for(i=0; i<10; i++)
	{
		str[i].count = i;
		str[i].total = i*2;
		fwrite(&str[i], sizeof(info), 1, fp);
	}
	
	fseek(fp, sizeof(info)*2, SEEK_SET);
	size = ftell(fp);
	printf("\nftell= %d", size);
	fread(&str2, sizeof(info), 1, fp);
	printf("\ncount[2]= %d total[2]= %f \n", str2.count, str2.total);
	
	fseek(fp, sizeof(info)*6, SEEK_SET);
	size = ftell(fp);
	printf("\nftell= %d", size);
	fread(&str2, sizeof(info), 1, fp);
	printf("\ncount[6]= %d total[6]= %f \n", str2.count, str2.total);
	
	fclose(fp);
	
	return(0);
	
}
