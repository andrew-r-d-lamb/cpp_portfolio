/**************************************************************************************************

*Filename: fc.cpp
*Authors: Andrew Lamb
*Last Modified: 13/03/2013
*Description: Program compares 2 text files to see if they are the same

**************************************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

void clrscreen (void);	//declare function clrscreen

int main(int argc, char *argv[])	//allow command line arguments
{
	fstream strin_one;
	fstream strin_two;
	char testOne;
	char testTwo;
	
	clrscreen();
	//CHECK THAT CORRECT NUMBER OF COMMAND LINE ARGUMENTS HAVE BEEN ENTERED
	//IF INCORRECT NUMBER OF ARGUMENTS NOT ENTERED, PROMPT USER AS TO THE CORRECT USAGE AND END PROGRAM
	if (argc != 3)
	{
		cout << "This program will compare two text files to see if they are the same." << endl;
		cout << "Correct Usage:" << endl << argv[0] << " first_file_name.extension second_file_name.extension";
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		return 1;
	}	
	
	else	//if correct number of parameters are entered, run rest of program
	{
		strin_one.open(argv[1], ios::in);	//open first file
		/********check that file exists.  If file does not exist, end program.*************/
		if (strin_one == NULL)
		{
			cout << "Cannot open " << argv[1] << endl << "Check filename and try again" << endl;
			return 1;
		}
		
		strin_two.open(argv[2], ios::in);	//open second file
		/********check that file exists.  If file does not exist, end program.*************/
		if (strin_two == NULL)	
		{
			cout << "Cannot open " << argv[2] << endl << "Check filename and try again" << endl;
			return 1;
		}

		else
		{
			strin_one.get(testOne);	//read first character of first file into testOne
			strin_two.get(testTwo);	//read first character of second file into testTwo
			
			/***************Run Loop While testOne and testTwo are not at the end of file and while they are equal to each other**************/
			while ((!strin_one.eof()) && (!strin_two.eof()) && (testOne == testTwo))
			{
				strin_one.get(testOne);	//read character from first file into testOne
				strin_two.get(testTwo);	//read character from second file into testTwo
			}
			
			if (testOne == testTwo) cout << argv[1] << " & " << argv[2] << " are identical" << endl;	//if files were the same, tell user
			else cout << argv[1] << " & " << argv[2] << " are not identical" << endl;	//if files were not the same, tell user
			clrscreen();
		}
		
		strin_one.close();
		strin_two.close();
	}
	
	return 0;	//All OK
}	//end of main

/***************************************************************************************************************************/
//DEFINE FUNCTION TO CLEAR THE SCREEN
void clrscreen (void)
{
	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "****************************************************************************************" << endl;
	cout << "\n\n\n\n\n\n\n\n\n";
}
//END OF CLEARSCREEN FUNCTION
/***************************************************************************************************************************/