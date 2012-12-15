/* 	Junior Samaroo            Student ID #0663108
	CIS 2500 Assignment #2
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void CountWords(char ch, int *Alpha, int *SentChk, int *punct, int *Words, int *totalSents, int *onlyVowel_e);				/* Function to counts number of words */
void CountSentences(char ch, int *SentChk, int *totalSents, int *onlyVowel_e);								/* Function to count number of sentences */
int vowel(int c);															/* Switch function to check for vowels */
void CountSyllables(char ch, int *isVowel, int *vowelChk, int *syllables, int *Vowel_e, int *onlyVowel_e, int *endVowel_e);		/* Function to count number of syllables */

int main (void) 
{
	int Alpha=0;		/* letter of alphabeth variable 	*/
	int SentChk=0;		/* end of sentence identifier 		*/
	int punct=0;		/* punctuation counter 			*/
	int Words=0;		/* words ended by whitespace counter 	*/
	int totalSents=0;	/* total amount of sentences 		*/
	int onlyVowel_e=0;	/* only the vowel 'e' counter 		*/
	int isVowel=0;		/* vowel identifier 			*/
	int vowelChk=0;		/* number of vowels in a word 		*/
	int syllables=0;	/* number of syllables 			*/
	int Vowel_e=0;		/* number of vowels 'e' 		*/
	int endVowel_e=0;	/* word that ends in the vowel 'e' 	*/
	int totalSylls=0;	/* total number of syllables 		*/
	int totalWords=0;	/* total number of words 		*/
	int index;		/* legibility index 			*/
	char ch;		/* a character read from stdin 		*/
	
	while ((ch = getchar()) != EOF)	/* loop that reads each character from stdin until the end of file is reached */
	{			
		CountWords(ch, &Alpha, &SentChk, &punct, &Words, &totalSents, &onlyVowel_e);			/* Calls function to count words 	*/
		isVowel=vowel(ch);										/* Calls function to check vowels 	*/
		CountSyllables(ch, &isVowel, &vowelChk, &syllables, &Vowel_e, &onlyVowel_e, &endVowel_e);	/* Calls function to count syllables	*/
	}
	
	totalWords=Words+totalSents;													/* Calculates total words */
	totalSylls=syllables-endVowel_e;												/* Calculates total syllables */
	index= floor(206.835 - 84.6 * ((float)totalSylls/(float)totalWords) - 1.015 * ((float)totalWords/(float)totalSents)+0.5);	/* Calculates legibility index */
	
	/* Output of calculated data */
	printf("\nLegibility Index = %d", index);
	printf("\nSyllable count   = %d", totalSylls);
	printf("\nWord count       = %d", totalWords);
	printf("\nSentence count   = %d\n", totalSents);
	
    return 0;	
}

void CountWords(char ch, int *Alpha, int *SentChk, int *punct, int *Words, int *totalSents, int *onlyVowel_e)
{
	if(isalpha(ch))		/* loop to check for letters of alphabeth */
	{
		*Alpha=1;
		*SentChk=1;
	}
	
	if(ch=='.' || ch==':' || ch==';' || ch=='?' || ch=='!')		/* loop to check for sentence identifiers */
	{
		*punct=*punct+1;
		
		if (*punct>=1 && (ch=='.' || ch==':' || ch==';' || ch=='?' || ch=='!'))		/* loop to check for multiple sentence identifiers at end of word */
		{
			*Words=*Words-1;
			*punct=0;
		}
	}
	
	if(ispunct(ch))		/* loop to check for punctuation (character that is neither alphanumeric nor a space) */
	{
		*Alpha=1;
	}
	
	CountSentences(ch, SentChk, totalSents, onlyVowel_e);		/* Calls function to count number of sentences */
	
	if(((ch==' ' || ch=='\n' || ch=='.' || ch==':' || ch==';' || ch=='?' || ch=='!')) && (*Alpha==1))		/* loop to check for words ended by whitespace and punctuation */
	{
		*Words=*Words+1;
		*Alpha =0;
	}		
	
}

void CountSentences(char ch, int *SentChk, int *totalSents, int *onlyVowel_e)
{
	if((ch=='.' || ch==':' || ch==';' || ch=='?' || ch=='!') && *SentChk==1)	/* loop to check for sentence identifiers and counts sentences */
	{
		*totalSents=*totalSents+1;
		*SentChk=0;
		*onlyVowel_e =0;
	}
}

int vowel(int ch)
{
	switch (ch){
		case 'a': ;
		case 'e': ;
		case 'i': ;
		case 'o': ;
		case 'u': ;
		case 'y': return 1;	
			break;
		default : return 0;	/* if vowel identified return 1 else return 0 */
	}
}

void CountSyllables(char ch, int *isVowel, int *vowelChk, int *syllables, int *Vowel_e, int *onlyVowel_e, int *endVowel_e)
{
	if(*isVowel==1)		/* loop to check for vowels in a word */
	{
		*vowelChk=*vowelChk+1;
	}
	
	if((*isVowel==0 && *vowelChk>=1) && (isalpha(ch) || isspace(ch))) 	 /* loop to count number of syllables */
	{
		*syllables=*syllables+1;
		*vowelChk=0;
	}
	
	if((*Vowel_e==1) && ((isspace(ch)) || (ch=='.')))	/* loop to count words that end with vowel 'e' */
	{	
		if(*onlyVowel_e > 1)		/* loop to count words that end with more than one vowel */
		{
			*endVowel_e=*endVowel_e+1;
		}
		
		*onlyVowel_e=0;
		*Vowel_e=0;
	}
	
	if(ch=='e')		/* loop to count the vowel 'e' in words */
	{
		*Vowel_e=*Vowel_e+1;
		*onlyVowel_e=*onlyVowel_e+1;
	}
	else
	{
		*Vowel_e=0;
	}

}
