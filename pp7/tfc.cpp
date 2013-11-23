/*************************************************************************************************

*Filename: tfc.cpp
*Authors: Andrew Lamb
*Last Modified: 13/03/2012
*Description:	Program copies text from one file to another

*************************************************************************************************/

#include <iostream>
#include <fstream>	//include file stream library

using namespace std;

void clrscreen (void);	//declare function clrscreen

int main(int argc, char*argv[])	//allow the use of command line arguments
{
	fstream strin;
	fstream strout;
	char temp;
	
	clrscreen();	//clears the screen
	
	//CHECK THAT CORRECT NUMBER OF COMMAND LINE ARGUMENTS HAVE BEEN ENTERED
	//IF INCORRECT NUMBER OF ARGUMENTS NOT ENTERED, PROMPT USER AS TO THE CORRECT USAGE AND END PROGRAM
	if (argc != 3)
	{
		cout << "This program will copy a text file." << endl;
		cout << "!!!CAUTION IF OUTPUT FILE ALREADY EXISTS IT WILL BE OVERWRITTEN!!!" << endl;
		cout << "Correct Usage:" << endl << argv[0] << " input_file_name.extension output_file_name.extension";
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		return 1;
	}
	
	//IF CORRECT NUMBER OF ARGUMENTS ENTERED COPY FILE
	else
	{
		strin.open(argv[1], ios::in);	//open file to read from
		strout.open(argv[2], ios::out);	//open file to write to

		while (!strin.eof())
		{
			temp = '\0';	//ON LAST RUN THROUGH WHILE LOOP, STOPS LAST CHARACTER FROM INPUT FILE WRITING A SECOND TIME TO THE OUTPUT FILE
			strin.get(temp);
			if (temp != '\0') strout << temp;
		} 
		
		strin.close();
		strout.close();

		cout << "Copy Completed";
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}

	return 0;	//all OK
}

/***************************************************************************************************************************/
//DEFINE FUNCTION TO CLEAR THE SCREEN
void clrscreen (void)
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "****************************************************************************************\n\n\n\n\n" << endl;
}
//END OF CLEARSCREEN FUNCTION
/***************************************************************************************************************************/