#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
#include "Translator.h"

//const int MAX_NUM_WORDS=2000;
//const int MAX_WORD_LEN=50;

//*********************************************************************************************************************************************
//*********************************************************************************************************************************************
Dictionary::Dictionary(const char dictionaryFileName[])
{
  fstream dictionaryIn;
  dictionaryIn.open(dictionaryFileName, ios::in);
	if (dictionaryIn.fail())
  {
    cout << "Could not open the dictionary file." << endl;
    return;
  }
  
  numEntries=0;
  isSortedinElvish=false;
  
  char englishTemporary[MAX_WORD_LEN];
  char elvishTemporary[MAX_WORD_LEN];
  
	int i=0;
	dictionaryIn >> englishTemporary;
	dictionaryIn >> elvishTemporary;
	addWord(englishTemporary,elvishTemporary);
	i++;
  
  while (!dictionaryIn.eof())
  {
		numEntries=i;
		dictionaryIn >> englishTemporary;
		dictionaryIn >> elvishTemporary;
		addWord(englishTemporary,elvishTemporary);
		i++;
  }
  
  numEntries=i;
}

//*********************************************************************************************************************************************
//*********************************************************************************************************************************************
//INSERTS WORDS INTO DICTIONARY IN ALPHABETICAL ORDER BY ENGLISH WORD
void Dictionary::addWord(const char englishTempWord[], const char elvishTempWord[])
{
  int i,j;
  if (numEntries==MAX_NUM_WORDS)
  {
    cout << "The dictionary is already full.\n";
    return;
  }
  // find the position to place englishTempWord in, so that
  // english words remain sorted in increasing order
  for (i=0; i<numEntries; i++)
    if (strcmp(english[i], englishTempWord) > 0)
      break;
  // push all values of englishWords that are greater
  // than englishTempWord forward one position (do same for elvishWords
  for (j=numEntries; j>i ;j--)
  {
    strcpy(english[j],english[j-1]);
    strcpy(elvish[j],elvish[j-1]);
	}
  // insert  at position i
  strcpy(english[i],englishTempWord);
  strcpy(elvish[i],elvishTempWord);
}

//*********************************************************************************************************************************************
//*********************************************************************************************************************************************
//SORT WORDS IN DICTIONARY ALPHABETICALLY BY ELVISH WORD
void Dictionary::sortByElvish(void)
{
	if (!isSortedinElvish)
	{
		int i,j;
		char tempElvishWord[MAX_WORD_LEN];
		char tempEnglishWord[MAX_WORD_LEN];
		for (i=0; i<numEntries-1; i++)
		{
			for (j=i+1; j<numEntries; j++)
			{
				if (strcmp(elvish[j],elvish[i]) < 0)
				{
					strcpy(tempElvishWord,elvish[j]);
					strcpy(tempEnglishWord,english[j]);
					strcpy(elvish[j],elvish[i]);
					strcpy(english[j],english[i]);
					strcpy(elvish[i],tempElvishWord);
					strcpy(english[i],tempEnglishWord);
				}
			}
		}
		isSortedinElvish = true;		
	}
}

//*********************************************************************************************************************************************
//*********************************************************************************************************************************************
//TRANSLATOR CONSTRUCTOR - TAKES IN DICTIONARY FILENAME AND INITIALIZES A VARIABLE
//DICT OF TYPE DICTIONARY
Translator::Translator(const char dictionaryFileName[]) : dict(dictionaryFileName)
{
}

//*********************************************************************************************************************************************
//*********************************************************************************************************************************************
//IF ENGLISH WORD IS IN DICTIONARY RETURN ELVISH EQUIVALENT, OTHERWISE DON'T
bool Dictionary::translateEngToElv(char wordOut[], const char wordIn[])
{
	//binary search elements of dictionary for matching word
  int bottom=0, top=numEntries, middle;
  bool found=false;

  while ((bottom<=top) && (!found))
  {
  	middle=bottom+(top-bottom)/2;
  	if((strcmp(english[middle], wordIn) == 0))
  		found=true;
  	else if ((strcmp(english[middle], wordIn) > 0))
  		top=middle-1;
  	else
  		bottom=middle+1;
  }
	if (found)
	{
		strcpy(wordOut, elvish[middle]);
		return true;
	}
	else return false;
}

//*********************************************************************************************************************************************
//*********************************************************************************************************************************************
//IF ELVISH WORD IS IN DICTIONARY RETURN ENGLISH EQUIVALENT, OTHERWISE DON'T
bool Dictionary::translateElvToEng(char wordOut[], const char wordIn[])
{
  //binary search elements of dictionary for matching word
  int bottom=0, top=numEntries, middle;
  bool found=false;
  while ((bottom<=top) && (!found))
  {
  	middle=bottom+(top-bottom)/2;
  	if((strcmp(elvish[middle], wordIn) == 0))
  		found=true;
  	else if ((strcmp(elvish[middle], wordIn) > 0))
  		top=middle-1;
  	else
  		bottom=middle+1;
  }
	if (found)
	{
		strcpy(wordOut, english[middle]);
		return true;
	}
	else return false;
}

//*********************************************************************************************************************************************
//*********************************************************************************************************************************************
//TAKE IN AN ENGLISH LINE OF TEXT, TRANSLATE AND RETURN ELVISH LINE OF TEXT
void Translator::toElvish(char elvishLineOut[], const char englishLineIn[])
{
	strcpy(elvishLineOut, "");	//Ensure that line out is overwritten at start of each call to function
	int lengthOfSentence = strlen(englishLineIn);
	int i, j, k;
	char englishWord[MAX_WORD_LEN];
	char elvishWord[MAX_WORD_LEN];
	bool endOfLine = false;
	for (j=0;j<MAX_WORD_LEN && !endOfLine;j++)
	{
		for (i=0;i<lengthOfSentence;i++)
		{
			//DEAL WITH WORDS BETWEEN '*'s (that have to be output as they are without the stars
			//if first element is a '*' do this
			if (englishLineIn[i] == '*' && ((englishLineIn[i+1]>='a' && englishLineIn[i+1]<='z') || (englishLineIn[i+1]>='A' && englishLineIn[i+1]<='Z') || 
				(englishLineIn[i+1] == '-')))
			{
				k=i+1;	//assign k to the first element after the star
				
				while(englishLineIn[k] != '*')	//loop while element k doesn't reach the * after the word
				{
					englishWord[j] = englishLineIn[k];	//assign element k of sentence to element j of the word
					j++;	//increment j
					k++;	//increment k
				}
				
				englishWord[j] = '\0';	//end the word with null

				//As between the stars, elvishWord is in fact an englishWord so no need to translate
				strcat(elvishLineOut, englishWord);	//add word to sentence out
				i=i+j;	//add count of number of letters in word to i
				i++;	//increment past final star after word
				j=0;	//reset counter j for start of next word
			}
			//DEAL WITH EVERYTHING ELSE
			else
			{
				//!!!
				//if is a letter add letter to englishword OR
				//if is a '-' and previous is a letter, add to englishword
				if ((englishLineIn[i]>='a' && englishLineIn[i]<='z') || (englishLineIn[i]>='A' && englishLineIn[i]<='Z') 
						|| (englishLineIn[i]=='-' && englishLineIn[i-1]>='a' && englishLineIn[i-1]<='z'))
				{	
					englishWord[j++] = englishLineIn[i];
				}

				//!!!
				//if is punctuation (exluding '-' and '*') and previous is a letter
				//end word, translate word, add translated word to line, add punctuation to line
				//reset j;
				if ((englishLineIn[i]>=' ' && englishLineIn[i]<=')') && 
							((englishLineIn[i-1]>='a' && englishLineIn[i-1]<='z') || (englishLineIn[i-1]>='A' && englishLineIn[i-1]<='Z')) || 
						(englishLineIn[i]>-'+' && englishLineIn[i]<=',') && 
							((englishLineIn[i-1]>='a' && englishLineIn[i-1]<='z') || (englishLineIn[i-1]>='A' && englishLineIn[i-1]<='Z')) ||
						(englishLineIn[i]>='.' && englishLineIn[i]<='@') && 
							((englishLineIn[i-1]>='a' && englishLineIn[i-1]<='z') || (englishLineIn[i-1]>='A' && englishLineIn[i-1]<='Z')) ||
						(englishLineIn[i]>='[' && englishLineIn[i]<='`') && 
							((englishLineIn[i-1]>='a' && englishLineIn[i-1]<='z') || (englishLineIn[i-1]>='A' && englishLineIn[i-1]<='Z')) ||
						(englishLineIn[i]>='{' && englishLineIn[i]<='~') && 
							((englishLineIn[i-1]>='a' && englishLineIn[i-1]<='z') || (englishLineIn[i-1]>='A' && englishLineIn[i-1]<='Z')))
				{
					englishWord[j]='\0';	//end word with a null character
					if (englishWord[0]>='A' && englishWord[0]<='Z')	//if first letter is capital
					{
						for(int k=0;k<strlen(englishWord);k++)	//loop through word
						{
							if (englishWord[k]>='A' && englishWord[k]<='Z')	//for any capital letter
							{	
								englishWord[k] = englishWord[k] - 'A' + 'a';	//make lower case
							}
						}
						if(dict.translateEngToElv(elvishWord, englishWord))	//if word is translated
						{						
							elvishWord[0] = elvishWord[0] - 'a' + 'A';	//make first letter uppercase
							strcat(elvishLineOut, elvishWord);	//add word to sentence

							char punctuation[2];	//create array punctuation
							punctuation[0] = englishLineIn[i];	//assign sentence punctuation character to first element
							punctuation[1] = '\0';	//assign null to second element
							strcat(elvishLineOut, punctuation);	//add punctuation to sentence
							j=0;	//reset counter j for start of next word
						}
						else	//(if word is not translated)
						{
							englishWord[0] = englishWord[0] - 'a' + 'A';	//make first letter uppercase
							strcat(elvishLineOut, "*");	//add star to sentence out
							strcat(elvishLineOut, englishWord);	//add word to sentence out
							strcat(elvishLineOut, "*");	//add star to sentence out
							
							char punctuation[2];	//create array punctuation
							punctuation[0] = englishLineIn[i];	//assign sentence punctuation character to first element
							punctuation[1] = '\0';	//assign null to second element
							strcat(elvishLineOut, punctuation);	//add punctuation to sentence
							j=0;	//reset counter j for start of next word
						}
					}
					else //(if first letter is not capital)
					{
						for(int k=0;k<strlen(englishWord);k++)	//loop through word
						{
							if (englishWord[k]>='A' && englishWord[k]<='Z')	//if any element is capital
							{	
								englishWord[k] = englishWord[k] - 'A' + 'a';	//make lower case
							}
						}
						if(dict.translateEngToElv(elvishWord, englishWord))	//if word is translated
						{
							strcat(elvishLineOut, elvishWord);	//add word to sentence out
							
							char punctuation[2];	//create array punctuation
							punctuation[0] = englishLineIn[i];	//assign sentence punctuation to first element
							punctuation[1] = '\0';	//assign null to second element
							strcat(elvishLineOut, punctuation);	//add punctuation to sentence out
							j=0;	//reset counter j for next word
						}
						else	//(if word is not translated)
						{
							strcat(elvishLineOut, "*");	//add star to sentence out
							strcat(elvishLineOut, englishWord);	//add word to sentence out
							strcat(elvishLineOut, "*");	//add star to sentence out

							char punctuation[2];	//create array punctuation
							punctuation[0] = englishLineIn[i];	//assign sentence punctuation to first element
							punctuation[1] = '\0';	//assign null to second element
							strcat(elvishLineOut, punctuation);	//add punctuation to sentence out
							j=0;	//reset counter j for next word
						}
					}
				}

				//!!!
				//if is punctuation (including '-' and previous is not a letter
				//strcat punctuation
				//reset j;
				if ((englishLineIn[i]>=' ' && englishLineIn[i]<=')') && 
							!((englishLineIn[i-1]>='a' && englishLineIn[i-1]<='z') || (englishLineIn[i-1]>='A' && englishLineIn[i-1]<='Z')) || 
						(englishLineIn[i]>='+' && englishLineIn[i]<=',') && 
							!((englishLineIn[i-1]>='a' && englishLineIn[i-1]<='z') || (englishLineIn[i-1]>='A' && englishLineIn[i-1]<='Z')) ||
						(englishLineIn[i]>='.' && englishLineIn[i]<='@') && 
							!((englishLineIn[i-1]>='a' && englishLineIn[i-1]<='z') || (englishLineIn[i-1]>='A' && englishLineIn[i-1]<='Z')) || 
						(englishLineIn[i]>='[' && englishLineIn[i]<='`') && 
							!((englishLineIn[i-1]>='a' && englishLineIn[i-1]<='z') || (englishLineIn[i-1]>='A' && englishLineIn[i-1]<='Z')) || 
						(englishLineIn[i]>='{' && englishLineIn[i]<='~') && 
							!((englishLineIn[i-1]>='a' && englishLineIn[i-1]<='z') || (englishLineIn[i-1]>='A' && englishLineIn[i-1]<='Z')) ||
						(englishLineIn[i]=='-') && 
							!((englishLineIn[i-1]>='a' && englishLineIn[i-1]<='z') || (englishLineIn[i-1]>='A' && englishLineIn[i-1]<='Z')))
				{
					char punctuation[2];	//create array punctuation
					punctuation[0] = englishLineIn[i];	//assign sentence punctuation to first element
					punctuation[1] = '\0';	//assign null to second element

					if (englishLineIn[i]=='-')	//special case for '-': needs to be treated as an unknown dictionary word so add '*'s
					{
						strcat(elvishLineOut, "*");	//add star to sentence
						strcat(elvishLineOut, punctuation);	//add '-' to sentence
						strcat(elvishLineOut, "*");	//add star to sentence
					}
					else
					{
						strcat(elvishLineOut, punctuation);	//add any other punctuation to sentence
					}
					j=0;	//reset counter j for next word
				}

				//!!!
				//if i equals lengthOfSentence-1 and is a lower-case letter then do this
				//i.e. catch words at the end of a line that have no space/punctuation after them
				if (i==lengthOfSentence-1 && englishLineIn[i]>='a' && englishLineIn[i]<='z')
				{
					englishWord[j]='\0';	//end word with a null character

					if (englishWord[0]>='A' && englishWord[0]<='Z')	//if first element of word is capital letter, do this
					{
						for(int k=0;k<strlen(englishWord);k++)	//loop through word
						{
							if (englishWord[k]>='A' && englishWord[k]<='Z')	//if any element is capital letter
							{	
								englishWord[k] = englishWord[k] - 'A' + 'a';	//set it to lowercase letter
							}
						}

						if(dict.translateEngToElv(elvishWord, englishWord))	//if word is found in dictionary
						{					
							elvishWord[0] = elvishWord[0] - 'a' + 'A';	//reset first element of word found to uppercase
							strcat(elvishLineOut, elvishWord);	//add word to sentence out
							j=0;	//reset counter j for next word
						}
						else	//if word is not found in dictionary (surround word with stars)
						{
							englishWord[0] = englishWord[0] - 'a' + 'A';	//reset first element of english word to uppercase
							strcat(elvishLineOut, "*");	//add star to sentence
							strcat(elvishLineOut, englishWord);	//add word to sentence
							strcat(elvishLineOut, "*");	//add star to sentence
							j=0;	//reset counter j for next word
						}
					}
					else	//if first element of word is lower case do this
					{
						for(int k=0;k<strlen(englishWord);k++)	//loop through word
						{
							if (englishWord[k]>='A' && englishWord[k]<='Z')	//if any element is capital letter
							{	
								englishWord[k] = englishWord[k] - 'A' + 'a';	//set it to lowercase letter
							}
						}
						if(dict.translateEngToElv(elvishWord, englishWord))	//if word is found in dictionary
						{
							strcat(elvishLineOut, elvishWord);	//add word to sentence out
							j=0;	//reset counter j for next word
						}
						else	//if word is not found in dictionary (surround by stars)
						{
							strcat(elvishLineOut, "*");	//add star to sentence out
							strcat(elvishLineOut, englishWord);	//add word to sentence out
							strcat(elvishLineOut, "*");	//add star to sentence out
							j=0;	//reset counter j for next word
						}
					}
				}
			}
		}
		if (i==lengthOfSentence)	//if i counter has reached the end of the sentence break the loop
		{
			endOfLine=true;	//way of breaking out of loop
		}
	}
}

//*********************************************************************************************************************************************
//*********************************************************************************************************************************************
//TAKE IN ELVISH LINE OF TEXT, TRANSLATE, AND RETURN ENGLISH LINE OF TEXT
void Translator::toEnglish(char englishLineOut[], const char elvishLineIn[])
{
	dict.sortByElvish();	//call dictionary sortByElvish function - this function will only perform sort the first time it is called
	strcpy(englishLineOut, "");	//set sentence out to blank
	int lengthOfSentence = strlen(elvishLineIn);	//get length of sentence
	int i, j, k;
	char englishWord[MAX_WORD_LEN];
	char elvishWord[MAX_WORD_LEN];
	bool endOfLine = false;	//condition to break out of loop

	for (j=0;j<MAX_WORD_LEN && !endOfLine;j++)
	{
		for (i=0;i<lengthOfSentence;i++)
		{
			//DEAL WITH WORDS BETWEEN '*'s (that have to be output as they are without the stars
			//if first element is a '*' do this
			if (elvishLineIn[i] == '*' && ((elvishLineIn[i+1]>='a' && elvishLineIn[i+1]<='z') || (elvishLineIn[i+1]>='A' && elvishLineIn[i+1]<='Z') || 
				(elvishLineIn[i+1] == '-')))
			{
				k=i+1;	//assign k to the first element after the star
				
				while(elvishLineIn[k] != '*')	//loop while element k doesn't reach the * after the word
				{
					elvishWord[j] = elvishLineIn[k];	//assign element k of sentence to element j of the word
					j++;	//increment j
					k++;	//increment k
				}
				
				elvishWord[j] = '\0';	//end the word with null

				//As between the stars, elvishWord is in fact an englishWord so no need to translate
				strcat(englishLineOut, elvishWord);	//add word to sentence out
				i=i+j;	//add count of number of letters in word to i
				i++;	//increment past final star after word
				j=0;	//reset counter j for start of next word
			}
			//DEAL WITH EVERYTHING ELSE
			else
			{
				//!!!
				//if is a letter add letter to englishword OR
				//if is a '-' and previous is a letter, add to englishword
				if ((elvishLineIn[i]>='a' && elvishLineIn[i]<='z') || (elvishLineIn[i]>='A' && elvishLineIn[i]<='Z') 
						|| (elvishLineIn[i]=='-' && elvishLineIn[i-1]>='a' && elvishLineIn[i-1]<='z'))
				{	
					elvishWord[j++] = elvishLineIn[i];
				}
				
				//!!!
				//if is punctuation (exluding '-' and '*') and previous is a letter
				//end word, translate word, add translated word to line, add punctuation to line
				//reset j;
				if ((elvishLineIn[i]>=' ' && elvishLineIn[i]<=')') && 
							((elvishLineIn[i-1]>='a' && elvishLineIn[i-1]<='z') || (elvishLineIn[i-1]>='A' && elvishLineIn[i-1]<='Z')) || 
						(elvishLineIn[i]>-'+' && elvishLineIn[i]<=',') && 
							((elvishLineIn[i-1]>='a' && elvishLineIn[i-1]<='z') || (elvishLineIn[i-1]>='A' && elvishLineIn[i-1]<='Z')) ||
						(elvishLineIn[i]>='.' && elvishLineIn[i]<='@') && 
							((elvishLineIn[i-1]>='a' && elvishLineIn[i-1]<='z') || (elvishLineIn[i-1]>='A' && elvishLineIn[i-1]<='Z')) ||
						(elvishLineIn[i]>='[' && elvishLineIn[i]<='`') && 
							((elvishLineIn[i-1]>='a' && elvishLineIn[i-1]<='z') || (elvishLineIn[i-1]>='A' && elvishLineIn[i-1]<='Z')) ||
						(elvishLineIn[i]>='{' && elvishLineIn[i]<='~') && 
							((elvishLineIn[i-1]>='a' && elvishLineIn[i-1]<='z') || (elvishLineIn[i-1]>='A' && elvishLineIn[i-1]<='Z')))
				{
					elvishWord[j]='\0';
					
					//deal with words that start with a capital letter
					if (elvishWord[0]>='A' && elvishWord[0]<='Z')
					{
						for(int k=0;k<strlen(elvishWord);k++)
						{
							if (elvishWord[k]>='A' && elvishWord[k]<='Z')
							{	
								elvishWord[k] = elvishWord[k] - 'A' + 'a';	//set all letters to lowercase
							}
						}

						if(dict.translateElvToEng(englishWord, elvishWord))	//for words that are found
						{				
							englishWord[0] = englishWord[0] - 'a' + 'A';	//reset first letter to uppercase
							strcat(englishLineOut, englishWord);
							
							char punctuation[2];
							punctuation[0] = elvishLineIn[i];
							punctuation[1] = '\0';
							strcat(englishLineOut, punctuation);
							j=0;
						}
						else	//for words that are not found - surround word by stars
						{
							elvishWord[0] = elvishWord[0] - 'a' + 'A';	//reset first letter to uppercase
							strcat(englishLineOut, "*");
							strcat(englishLineOut, elvishWord);
							strcat(englishLineOut, "*");

							char punctuation[2];
							punctuation[0] = elvishLineIn[i];
							punctuation[1] = '\0';
							strcat(englishLineOut, punctuation);
							j=0;
						}
					}
					//deal with words that do not start with a capital letter
					else
					{
						for(int k=0;k<strlen(elvishWord);k++)
						{
							if (elvishWord[k]>='A' && elvishWord[k]<='Z')
							{	
								elvishWord[k] = elvishWord[k] - 'A' + 'a';	//set all letters to lowercase
							}
						}
						if(dict.translateElvToEng(englishWord, elvishWord))	//for words that are found
						{
							strcat(englishLineOut, englishWord);

							char punctuation[2];
							punctuation[0] = elvishLineIn[i];
							punctuation[1] = '\0';
							strcat(englishLineOut, punctuation);
							j=0;
						}
						else	//for words that are not found
						{
							strcat(englishLineOut, "*");
							strcat(englishLineOut, elvishWord);
							strcat(englishLineOut, "*");

							char punctuation[2];
							punctuation[0] = elvishLineIn[i];
							punctuation[1] = '\0';

							strcat(englishLineOut, punctuation);
							j=0;
						}
					}
				}
				//!!!
				//if is punctuation (including '-' and previous is not a letter
				//strcat punctuation
				//reset j;
				if ((elvishLineIn[i]>=' ' && elvishLineIn[i]<=')') && 
							!((elvishLineIn[i-1]>='a' && elvishLineIn[i-1]<='z') || (elvishLineIn[i-1]>='A' && elvishLineIn[i-1]<='Z')) || 
						(elvishLineIn[i]>='+' && elvishLineIn[i]<=',') && 
							!((elvishLineIn[i-1]>='a' && elvishLineIn[i-1]<='z') || (elvishLineIn[i-1]>='A' && elvishLineIn[i-1]<='Z')) ||
						(elvishLineIn[i]>='.' && elvishLineIn[i]<='@') && 
							!((elvishLineIn[i-1]>='a' && elvishLineIn[i-1]<='z') || (elvishLineIn[i-1]>='A' && elvishLineIn[i-1]<='Z')) || 
						(elvishLineIn[i]>='[' && elvishLineIn[i]<='`') && 
							!((elvishLineIn[i-1]>='a' && elvishLineIn[i-1]<='z') || (elvishLineIn[i-1]>='A' && elvishLineIn[i-1]<='Z')) || 
						(elvishLineIn[i]>='{' && elvishLineIn[i]<='~') && 
							!((elvishLineIn[i-1]>='a' && elvishLineIn[i-1]<='z') || (elvishLineIn[i-1]>='A' && elvishLineIn[i-1]<='Z')) ||
						(elvishLineIn[i]=='-') && 
							!((elvishLineIn[i-1]>='a' && elvishLineIn[i-1]<='z') || (elvishLineIn[i-1]>='A' && elvishLineIn[i-1]<='Z')))
				{
					char punctuation[2];
					punctuation[0] = elvishLineIn[i];
					punctuation[1] = '\0';

					if (elvishLineIn[i]=='-')	//special case - treat '-' as if it is a word that is not in the dictionary
					{
						strcat(englishLineOut, "*");
						strcat(englishLineOut, punctuation);
						strcat(englishLineOut, "*");
					}
					else	//for all other punctuation
					{
						strcat(englishLineOut, punctuation);
					}
					j=0;
				}

				//!!!
				//if i equals lengthOfSentence-1 and is a lower-case letter then do this
				//deal with words at the end of a sentence that have no punctuation after them
				if (i==lengthOfSentence-1 && elvishLineIn[i]>='a' && elvishLineIn[i]<='z')
				{
					elvishWord[j]='\0';
					
					if (elvishWord[0]>='A' && elvishWord[0]<='Z')	//if word starts with a capital letter
					{
						for(int k=0;k<strlen(elvishWord);k++)
						{
							if (elvishWord[k]>='A' && elvishWord[k]<='Z')
							{	
								elvishWord[k] = elvishWord[k] - 'A' + 'a';	//set all letters to lowercase
							}
						}
						if(dict.translateElvToEng(englishWord, elvishWord))	//if word is found
						{						
							englishWord[0] = englishWord[0] - 'a' + 'A';	//reset first letter to uppercase
							strcat(englishLineOut, englishWord);
							j=0;
						}
						else	//if word is not found surround by stars
						{
							elvishWord[0] = elvishWord[0] - 'a' + 'A';	//reset first letter to uppercase
							strcat(englishLineOut, "*");
							strcat(englishLineOut, elvishWord);
							strcat(englishLineOut, "*");
							j=0;
						}
					}
					else	//if word does not start with a capital letter
					{
						for(int k=0;k<strlen(elvishWord);k++)
						{
							if (elvishWord[k]>='A' && elvishWord[k]<='Z')
							{	
								elvishWord[k] = elvishWord[k] - 'A' + 'a';	//set all letters to lowercase
							}
						}
						if(dict.translateElvToEng(englishWord, elvishWord))	//if word is found
						{
							strcat(englishLineOut, englishWord);
							j=0;
						}
						else	//if word is not found surround by stars
						{
							strcat(englishLineOut, "*");
							strcat(englishLineOut, elvishWord);
							strcat(englishLineOut, "*");
							j=0;
						}
					}
				}
			}
		}
		//!!!
		if (i==lengthOfSentence)	//condition to break out of loop
		{
			endOfLine=true;
		}
	}
}
