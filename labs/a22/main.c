#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int isvowel(int c)
{
	switch (c){
		case 'a': ;
		case 'e': ;
		case 'i': ;
		case 'o': ;
		case 'u': ;
		case 'y': return 1;
			break;
		default : return 0;
	}
}

int main (void) 
{
	int alpha=0, x=0, word=0, punct=0, beta=0, gamma=0, vowel=0, vowel2=0, vowel3=0, vowel4=0, vowel5=0, vowele=0, ve=0, vee=0, digit=0;
	char ch;
	while ((ch = getchar()) != EOF)
	{	
		if(isalpha(ch)){
			alpha=1;
			beta=1;}
		
		if(ch=='-'){
			gamma++;}
		
		if(isgraph(ch)){
			alpha=1;}
		
		if(ch=='.' && beta==1){
			punct=punct+1;
			beta=0;}
		
		if(ch==' ' && alpha==1 || gamma>1){
			word=word+1;
			alpha =0;
			gamma=0;}
		
		x=isvowel(ch);
		
		if(x==1){
			vowel++;
			vowel2++;
			vowel5++;}
		if(x==0 && vowel2>=1 && (isalpha(ch) || isspace(ch) || ch=='\n' || ch=='.')){
			vowel3++;
			vowel2=0;}
		
		//printf("\n%c %d\n", ch, vowel3);
		
		if(vowel5>=1 && ch=='e'){
			ve=1;
			vowele++;}
		if(ve==1 && (ch==' ' || ch=='.' || ch=='\n')){
			vee = vowel3-1;
			vowel4++;
			//vowel4=vowele-vowel4;
			ve=0;}
		//printf("\n%c %d\n", ch, vowel4);
		
		//printf("\n%c %d\n", ch, vowel4);
		
		//	if(vowel5!=1){
		//		vowel4++;
		//	vowel5=0;
		//	vee=0;
		// vowel5=0;}
		if(x==0 && (ch!=' ' || ch!='.' || ch!='\n')){
			ve=0;}
		//if(ve==1 && (ch==' ' || ch=='.' || ch=='-' || ch=='\n')){
		//	vowele++;
		//	ve=0;}
		//	if(vowel5>=1){
		//		vowel4++;
		//		vowel5=0;
		//	vee=0;}
		
	}
	
	printf("\n%d", word);
	printf("\n%d", punct);
	printf("\n%d", vowel3);
	printf("\n%d", vee);
	printf("\n%d", vowel5);
	printf("\n%d", vowele);
	printf("\n%d", vowel4);
	
    return 0;
	
}
