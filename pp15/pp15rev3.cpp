/*
Filename:			pp15rev3.cpp 

Authors: 			Andrew Lamb / Neil Hurley's Square root calculation
Last Modified:	21/03/2013

PP15 Lab description:
In the ﬁle roundoff.cpp a while loop is provided that computes the
value of the square root of a given number. Using that while loop, write
a function with prototype deﬁnition
double mysqrt(double x);
that computes the square root of its input value x to 10 decimal places.
Compare the output of your mysqrt function with the cmath library function sqrt.
*/

#include <iostream>
#include <cstdlib>			//included for strtod function
#include <iomanip>		//included for setprecision() function
#include <cmath>			//included for sqrt function

using namespace std;

double mysqrt(double x);	//function prototype for calculating square root of a number

int main()	
{
	double number;	
	double root_of_number;
	double cmath_sqrt_of_number;
	cout << "************************************************************************" << endl;
	cout << "Comparison of lecturer's square root function with cmath sqrt function" << endl;
	cout << "Type in a positive number and press enter(-1 to exit): " << endl;	
	
	cin >> number;				//get number from user
	while (number > 0.0)		//run loop while user number is greater than 0.0
    {
		root_of_number = mysqrt(number);		//CALL FUNCTION TO CALCULATE THE SQUARE ROOT OF A NUMBER
		cmath_sqrt_of_number = sqrt(number);
		cout << "Neil's Calculation: " << setprecision(20) << number << "\troot=" << setprecision(20) << root_of_number << "\troot*root=" << setprecision(20) << root_of_number*root_of_number << endl;	
		cout << "cmath Calculation:  " << setprecision(20) << number << "\troot=" << setprecision(20) << cmath_sqrt_of_number << "\troot*root=" << setprecision(20) << cmath_sqrt_of_number*cmath_sqrt_of_number << endl;	
		cout << "Enter another number or -1 to exit" << endl;
		cin >> number;			//get another number from user
	}
	
	return 0;
}

/**************************************************************************************************/
//FUNCTION TO CALCULATE THE SQUARE ROOT OF A NUMBER
double mysqrt(double x)
{
	const int MAXITERS=100000;	
	const double EPSILON = 0.0;		
		
	double t = x;	
	// CALCULATE THE SQUARE ROOT
	int numiters=0;
	while ((fabs(t*t - x) > x*EPSILON) && (MAXITERS >= numiters))		//LOOP WHILE ABSOLUTE VALUE OF T*T*X IS GREATER THAN X*EPSILON AND WHILE MAXIMUM NUMBER OF LOOPS ALLOWED ISN'T REACH
	{
		t = (x/t + t) / 2.0;	//SQUARE ROOT CALCULATION
		numiters++;
	}
	if (numiters>MAXITERS) cout << "Exiting because loop condition not true after "  << MAXITERS << " iterations."<< endl;	//OUTPUT THIS IF LOOP REACHED MAX ALLOWED ITERATIONS
		
	cout << "Loop terminated after " << numiters << " iterations." << endl;
	
	return t;	//RETURN T - THE VALUE FOR THE SQUARE ROOT OF THE NUMBER
}
/**************************************************************************************************/