/*************************************************************************************************

*Filename: pp3.cpp
*Authors: Andrew Lamb
*Last Modified: 03/03/2013
*Description:	User inputs some words - 	program 
												counts number of each letter and displays totals
												
*************************************************************************************************/

#include <iostream>

using namespace std;

const int SENTENCE_LENGTH = 1000;

int main()
{
	char sentence[SENTENCE_LENGTH];
	char alphabet[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};	//Create char array and initialise values to the letters of the alphabet
	int alphabetSum[27] = {0};
	
	cout << "Please enter some words" << endl;
	cin.getline(sentence, SENTENCE_LENGTH);
	//cout << sentence;
//********************************//	
	cout << "Your sentence contains" << endl;
	for (int i = 0; alphabet[i] != '\0'; i++)	//loop through alphabet letters one at a time
	{
		for (int j = 0; sentence[j] != '\0'; j++)	//loop through words sentence one at a time and compare to alphabet letter
		{
			if (alphabet[i] == sentence[j])	
			{
				//cout << sentence[j] << endl;
				alphabetSum[i] = alphabetSum[i] + 1;				//if equal, add to sum
				//cout << alphabet[i] << alphabetSum[i] << alphabetSum[i] + 1 << endl;
			}
		}
	}
	
	for (int i = 0; alphabet[i] != '\0'; i++)
	{
		cout << alphabet[i] << "=" << alphabetSum[i] << endl;
	}
	
	return 0;
}