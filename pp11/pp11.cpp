/*************************************************************************************************

*Filename: pp11.cpp
*Authors: Andrew Lamb
*Last Modified: 14/03/2012
*Description:	Program to calculate principal based on compound interest accrued

*************************************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

double principal (double amountAccrued, double rate, int numyears);	//function prototype for calculating principal
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
	cout << "Input the rate:" << endl;
	cin >> r;
	cout << "Input the number of years:" << endl;
	cin >> n;
	cout << "Input the amount accrued:" << endl;
	cin >> a;
	
	// do the calculation 
	p = principal(a, r, n);
	
	clrscreen();	//clearscreen
	clrscreen();	//clearscreen
	// output the result
	cout << "The principal is: " << p << endl;
	
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
//DECLARE FUNCTION TO CALCULATE THE PRINCIPAL
double principal (double amountAccrued, double rate, int numyears)
{
	double principal; // for the principal
	
	principal = amountAccrued/pow((1 + rate/100),numyears);
	
	return principal;
}
//END PRINCIPAL FUNCTION
/*******************************************************************************************************************************/