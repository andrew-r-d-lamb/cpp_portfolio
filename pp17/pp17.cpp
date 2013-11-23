//******************************************************************************************************************************
//Filename		:		pp17.cpp
//Author			:		Andrew Lamb
//Version			:		One - function to reverse a string of characters - non recursive
//Description	:		Function takes a string in the form of an array of characters
//					:		as input and reverses the string.
//					:		Rewrite the function as a recursive function.
//******************************************************************************************************************************

#include <iostream>
#include <cstring>
using namespace std;

void reverse_str (char a_str_array[], int length_of_str_array);	//Function prototype to reverse characters in an array - takes character array and length of string as arguments

int main()
{	
	const int STR_LENGTH = 1000;
	char str[STR_LENGTH];
	
	cout << "Enter a sentence: " << endl;
	cin.getline(str, STR_LENGTH);
	int length_of_str = strlen(str);
	//cout << "length of string is: " << length_of_str;
	//cout << str << endl;
	
	reverse_str(str, length_of_str);
	cout << str << endl;
	
	return 0;	//all ok
}

//******************************************************************************************************************************
//FUNCTION TO REVERSE CHARACTERS IN AN ARRAY
void reverse_str (char a_str_array[], int length_of_str_array)
{
	int middle_of_str = length_of_str_array/2;
	for (int i=0; i<middle_of_str; i++)
	{
		int tmp = a_str_array[i];
		a_str_array[i] = a_str_array[length_of_str_array - 1 - i];
		a_str_array[length_of_str_array - 1 - i] = tmp;
	}
}
//******************************************************************************************************************************