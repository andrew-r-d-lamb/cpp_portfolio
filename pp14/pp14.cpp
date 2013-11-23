/*************************************************************************************************

*Filename: pp14.cpp
*Authors: Andrew Lamb
*Last Modified: 21/03/2013
*Description:	User enters a double floating point number
				program calculates the arctan of the number to 20 decimal places
				NB!!!  FLOAT PRECISE TO ABOUT 7 DIGITS, DOUBLE PRECISE TO ABOUT 16 DIGITS BEFORE GARBAGE.

Lab description:
Package the arctan program into a function with
the following prototype:
double arctan(double x, double precision=10e-10);

Write a main program that compares the output of your arctan function
with the cmath library function atan.					
*************************************************************************************************/

#include <iostream>
#include <cmath>		//included for the cmath atan function as a comparison
#include <iomanip>	//included for setprecision() function
//#include <cstdlib>		//included for the strtod function which converts a string to a double

/*
	ARCTAN (x) = x - x^3/3 + x^5/5 - x^7/7 ...............
*/

using namespace std;

double arctan_calculation(double x, double precision);

int main()
{
	double dX, arctanX = 0.0;
	double max_decimals = 10e-10;	//New double value to measure against number of decimal places
	int i;	//counter
	
	cout << "Please enter a floating point number between -1 and +1, excluding 0:" << endl;
	cin >> dX;
	
	// ENSURE THAT VALUE ENTERED IS BETWEEN -1 AND +1
	// LOOP RUNS 4 TIMES TO GIVE USER A TOTAL OF 5 CHANCES TO ENTER A CORRECT NUMBER
	for (int i=0; i<5 && ((dX < (-1)) || (dX > 1)); i++)		
	{
		if (i == 4) return 4;
		else
		{
			cout << "Invalid number entered, please try again:" << endl;
			cin >> dX;
		}
	} 
	
	// RUN ARCTAN_CALCULATION FUNCTION HERE
	arctanX = arctan_calculation(dX, max_decimals);

	// OUTPUT THE RESULT OF THE ARCTAN CALCULATION
	cout << "The arctan of " << dX << " to 20 decimal places is: ";
	cout << setprecision (20) << arctanX << endl;	
	cout << "cmath atan of " << dX << " is: " << setprecision (20) << atan(dX) << endl;
	
	// COMPARE MY ARCTAN_CALCULATION WITH CMATH ATAN FUNCTION
	cout << "The difference between arctan_calculation and cmath atan is: " << setprecision(20) << fabs(atan(dX) - arctanX) << endl;
	
	return 0;
}

/*********************************************************************************************************************/
//DECLARE ARCTAN_CALCULATION FUNCTION
double arctan_calculation(double x, double precision)
{
	double arctanX = 0.0;
	double term = x;
	
	for (int i = 0; fabs(term) > precision; i++)
	{
		term = pow(x, (2 * i + 1)) / (2 * i + 1);
		switch (i % 2)
		{
			case 0:	// if i  is an even number do this:
			{
				arctanX = arctanX + term;
				//cout << "Added:" << arctanX << endl;	//test value of arctanX
				break;
			}
			case 1:	// if i is an odd number,do this:
			{
				arctanX = arctanX - term;
				//cout << "Subtracted:" << arctanX << endl;	//test value of arctanX
				break;
			}
		}
		cout << "i: " << i << " term: " << term << " sum: " << arctanX << endl;
	}
	
	return arctanX;
}
//END ARCTAN_CALCULATION
/*********************************************************************************************************************/	