/*************************************************************************************************

*Filename: pp10.cpp
*Authors: Andrew Lamb
*Last Modified: 14/03/2012
*Description:	Program to calculate interest accrued

*************************************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

double compoundInterest (double principal, double rate, int numyears);	//function prototype for calculating compound interest
void clrscreen (void);	//function prototype for clearing the screen

int main ()
{
	// declare some variables
	double p; // for the principal
	double a;	// for the amount
	int n; // for the number of years
	double r; // for the rate 
	
	clrscreen();	//clearscreen
	//explain program to user
	cout << "*************************************************" << endl << "Program will calculate compound interest for you." << endl << endl << "*************************************************" << endl;
	clrscreen();	//clearscreen
	
	// read some values from the keyboard
	cout << "Input the principal:" << endl;
	cin >> p;
	cout << "Input the rate:" << endl;
	cin >> r;
	cout << "Input the number of years:" << endl;
	cin >> n;
	
	// do the calculation 
	a = compoundInterest(p, r, n);
	
	clrscreen();	//clearscreen
	clrscreen();	//clearscreen
	// output the result
	cout << "The amount accrued is: " << a << endl;
	
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
//DECLARE FUNCTION TO CALCULATE THE COMPOUND INTEREST ACCRUED
double compoundInterest (double principal, double rate, int numyears)
{
	double amountAccrued; // for the amount	ACCRUED???
	
	amountAccrued = principal*pow((1 + rate/100),numyears);
	
	return amountAccrued;
}
//END COMPOUNDINTEREST FUNCTION
/*******************************************************************************************************************************/