/*************************************************************************************************

*Filename: fr.cpp
*Authors: Andrew Lamb
*Last Modified: 13/03/2012
*Description:	Program reads text file 20 lines at a time.  Return to continue.  Q to quit.

*************************************************************************************************/

#include <iostream>
#include <fstream>	//include file stream library

using namespace std;

const int MAX_LENGTH = 500;

void clrscreen (void);	//declare function clrscreen

int main(int argc, char*argv[])	//allow the use of command line arguments
{
	fstream strin;
	char templine[MAX_LENGTH];
	bool q = false;
	char temp;
	
	clrscreen();	//clears the screen
	
	//CHECK THAT CORRECT NUMBER OF COMMAND LINE ARGUMENTS HAVE BEEN ENTERED
	//IF INCORRECT NUMBER OF ARGUMENTS NOT ENTERED, PROMPT USER AS TO THE CORRECT USAGE AND END PROGRAM
	if (argc != 2)
	{
		cout << "This program will read a text file 20 lines at a time." << endl;
		cout << "Correct Usage:" << endl << argv[0] << " filename.extension";
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		return 1;
	}
	
	//IF CORRECT NUMBER OF ARGUMENTS ENTERED READ FILE
	else
	{
		strin.open(argv[1], ios::in);	//open file to read from
		
		//CHECK THAT FILE EXISTS.  IF DOESN'T EXIST, PROMPT USER AND END PROGRAM
		if (strin == NULL)
		{
			cout << "Cannot open " << argv[1] << endl << "Check filename and try again" << endl;
			return 1;
		}
		
		//IF FILE EXISTS READ LINES FROM FILE
		else
		{
			int linecount = 1;	//INITIATE A LINECOUNT TO LINE 1
			for (int i = 1; !strin.eof() && !q; i++)	//CONTINUE LOOP WHILE NOT END OF FILE AND NOT Q
			{
				strin.getline(templine, MAX_LENGTH);	//READ LINE FROM FILE INTO TEMPLINE ARRAY
				cout << linecount << "   " << templine << endl;	//OUTPUT LINECOUNT AND LINE FROM FILE
				linecount++;	//INCREMENT LINECOUNT
				
				if (i == 20)	//IF I IS 20 DO THIS:
				{
					i = 0;	//REASSIGN I TO 0 (VALUE OF I WILL BE ONE AGAIN WHEN FOR LOOP INCREMENTS)
					cout << "\n\n\nPress RETURN to continue or 'q' to quit" << endl << endl << endl;	//GIVE USER OPTION TO VIEW 20 MORE LINES OR QUIT
					cin.get(temp);	//GET CHARACTER FROM USER
					if (temp == 'q') q = true;	//IF USER ENTERS q, ASSIGN TRUE TO q BOOLEAN - THIS WILL EXIT THE LOOP
				}
			} 
		}
		strin.close();	//close file stream
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