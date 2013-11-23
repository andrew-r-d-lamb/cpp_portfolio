/*************************************************************************************************

*Filename: pp12.cpp
*Authors: Andrew Lamb
*Last Modified: 14/03/2012
*Description:	Program to convert lowercase to uppercase letters

*************************************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

void clrscreen (void);	//function prototype for clearing the screen
void capitalise (char array[]);	//functions prototype for capitalising an array of letters

const int MAX_LENGTH = 1000;

int main ()
{
	char sentence[MAX_LENGTH];
//	char test = 'c';
//	cout << int(test) << endl;	//(Output integer value of 'c'
	
	clrscreen();	//clearscreen
	//explain program to user
	cout << "*************************************************" << endl << "Program will convert lowercase letters to uppercase." << endl << endl << "*************************************************" << endl;
	clrscreen();	//clearscreen
	
	// read some values from the keyboard
	cout << "Input a sentence:" << endl;
	cin.getline(sentence, MAX_LENGTH);
	
	// call function to capitalise array sentence
	capitalise(sentence);
	
	clrscreen();	//clearscreen
	clrscreen();	//clearscreen
	// output the result
	cout << "The sentence has been changed to: " <<  sentence << endl;
	
	return 0;
}

/*******************************************************************************************************************************/
//DECLARE FUNCTION TO CLEAR THE SCREEN
void clrscreen (void)
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
//END CLRSCREEN FUNCTION
/*******************************************************************************************************************************/

/*******************************************************************************************************************************/
void capitalise (char array[])	//functions prototype for capitalising an array of letters
{
	for (int i = 0; i < MAX_LENGTH && array[i] != '\n'; i++)	//LOOP RUNS UNTIL MAX LENGTH OF ARRAY OR A NEWLINE CHARACTER
	{
		if (array[i] >= 'a' && array[i] <= 'z')	//IF ARRAY ELEMENT IS A LOWER CASE LETTER BETWEEN 'a' and 'z' DO THIS
			array[i] = ('A' + array[i] - 'a');			/*CONVERT ARRAY ELEMENT TO A CAPITAL LETTER, 
			ADDS DECIMAL VALUES OF 'A' (65) 
			TO ARRAY ELEMENT e.g. 'c' (99) 
			AND SUBTRACTS DECIMAL VALUE OF 'a' (97)
			GIVING A DECIMAL VALUE OF (67) OR 'C'
			*/
	}
}
/*******************************************************************************************************************************/
