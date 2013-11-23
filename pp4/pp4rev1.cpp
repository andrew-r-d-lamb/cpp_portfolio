/*************************************************************************************************

*Filename: pp4.cpp
*Authors: Andrew Lamb
*Last Modified: 03/03/2013
*Description:	User enters a double floating point number
				program calculates the arctan of the number to 20 decimal places
				NB!!!  FLOAT PRECISE TO ABOUT 7 DIGITS, DOUBLE PRECISE TO ABOUT 16 DIGITS BEFORE GARBAGE.
												
*************************************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>	//included for setprecision() function

/*
	ARCTAN (x) = x - x^3/3 + x^5/5 - x^7/7 ...............
*/

using namespace std;

int main()
{
	double dX, arctanX = 0.0;
	//const double MAX_DECIMALS = 1e-20;	//New double value to measure against number of decimal places
	int i;	//counter
	
	cout << "Please enter a floating point number between -1 and +1, excluding 0:" << endl;
	cin >> dX;
	
	// ENSURE THAT VALUE ENTERED IS BETWEEN -1 AND +1
	for (int i=0; i<5 && ((dX < (-1)) || (dX > 1)); i++)									//	(i<5 && (dX < (-1))) || (i<5 && (dX > 1)); i++)	
	{
		if (i == 4) return 4;
		else
		{
			cout << "Invalid number entered, please try again:" << endl;
			cin >> dX;
		}
	} 
	
	for (int i = 0; i < 20; i++)
	{
		switch (i % 2)
		{
			case 0:	// if i  is an even number do this:
			{
				arctanX = arctanX + (pow(dX, (2 * i + 1))) / (2 * i + 1);
				cout << "Added:" << arctanX << endl;	//test value of arctanX
				break;
			}
			case 1:	// if i is an odd number,do this:
			{
				arctanX = arctanX - (pow(dX, (2 * i + 1))) / (2 * i + 1);
				cout << "Subtracted:" << arctanX << endl;	//test value of arctanX
				break;
			}
		}
	}
	
	cout << "The arctan of " << dX << " to 20 decimal places is: ";
	cout.precision (20);
	cout << arctanX << endl;
	
/*	Could also use this for precision:	
	cout << fixed;
	cout << setprecision (20) << arctanX << endl;		
*/	
	
	return 0;
}