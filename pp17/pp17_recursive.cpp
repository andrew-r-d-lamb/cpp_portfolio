//******************************************************************************************************************************
//Filename		:		pp17_recursive.cpp
//Author			:		Andrew Lamb
//Version			:		Two - function to reverse a string of characters - recursive
//Description	:		Function takes a string in the form of an array of characters
//					:		as input and reverses the string.
//					:		Rewrite the function as a recursive function.
//******************************************************************************************************************************

#include <iostream>
#include <cstring>	//included for strlen function
using namespace std;

void reverse_str (char a_str_array[], int length_of_str_array, int position = 0);	//Function prototype to reverse characters in an array - takes character array and length of string as arguments.  Initial position set to 0 for start position of array

int main()
{	
	const int STR_LENGTH = 1000;
	char str[STR_LENGTH];
	
	cout << "Enter a sentence: " << endl;			//request input from user
	cin.getline(str, STR_LENGTH);					//get line of input from user and store in str array
	int length_of_str = strlen(str);						//get length of str array
	//cout << "length of string is: " << length_of_str;
	//cout << str << endl;
	reverse_str(str, length_of_str);					//call function to reverse characters in str array
	cout << str << endl;									//output modified str array
	
	return 0;	//all ok
}

//******************************************************************************************************************************
//RECURSIVE FUNCTION TO REVERSE CHARACTERS IN AN ARRAY
//Note that a call to function only does something if the lower position in the array is lower than the
//upper position of the array.  Otherwise the recursive call to the function completes immediately 
//and the rest of the function within the if statement can continue.
void reverse_str (char a_str_array[], int length_of_str_array, int position)
{
	if (position < length_of_str_array - 1)													//if lower position in array is less than upper position in array do this
	{
		reverse_str(a_str_array, length_of_str_array - 1, position + 1);			//recursive call to this function - when it gets to the last one of these that fulfills the if statement, the rest of this function is completed and then it goes back up to the next level
		
		//this section swaps the characters using a temporary char variable
		char tmp = a_str_array[position];													
		a_str_array[position] = a_str_array[length_of_str_array - 1];
		a_str_array[length_of_str_array - 1] = tmp;
	}
	//function does not need to return a value as all changes are made directly to the character array originally passed in by reference
}
//******************************************************************************************************************************