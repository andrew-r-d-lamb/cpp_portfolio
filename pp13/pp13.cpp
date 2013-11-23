/*************************************************************************************************

*Filename: pp13.cpp
*Authors: Andrew Lamb
*Last Modified: 20/03/2012
*Description:	Program converts date from DD-MMM-YYYY to DD/MM/YY and
				checks that date is valid

*************************************************************************************************/
#include <iostream>
#include <cstring>	//use for strlen function

using namespace std;

void clrscreen (void);	//function prototype for clearing the screen
bool convert_date (char in[], char out[]);
bool date_is_valid (int day, int month, int year);
bool is_a_leap_year (int year);

//int str_to_int (	//function prototype to covert string value to an integer value
//int monthNo (

int main (int argc, char *argv[])
{	
	clrscreen();	//clearscreen
	clrscreen();	//clearscreen
	if (argc != 2)
	{
		cout << argv[0] << " is a program to convert date format for you and tell you if it is a valid date" << endl;
		cout << "Usage: " << argv[0] << " DD-MMM-YYYY" << endl;
		cout << "Example: " << argv[0] << " 13-JAN-1999" << endl;
		return 1;
	}
	
	char date_out[9];	//date to output will be stored here eight (DD/MM/YY) plus one for null character
	bool valid_date = convert_date(argv[1], date_out);
	if (valid_date)
		cout << date_out << " is a valid date." << endl;
	else
		cout << date_out << " is not a valid date." << endl;

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
//DECLARE FUNCTION TO CONVERT THE DATE FROM DD-MMM-YYYY
bool convert_date (char in[], char out[])
{
	if (strlen(in) != 11)
	{
		out[0] = '\0';
		return false;
	}

//***************************DAYS**********************	
	//DAY to int
	int day_num = 0;
	for (int i=0; i<2; i++)
	{
		day_num = 10 * day_num + (in[i]-'0');
		out[i] = in[i];
	}
	out[2] = '/';

//***************************MONTHS**********************		
	//skip the '-', convert lower case to upper case and store in a temporary array
	char month_as_string[4];
	for (int i=0; i<3; i++)
	{
		if (in[i+3] >= 'a' && in[i+3] <= 'z')
			month_as_string[i] = in[i+3] - 'a' + 'A';
		else
			month_as_string[i] = in[i+3];
	}
	month_as_string[3] = '\0';
		
	const char months_of_year[12][4] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};	//DECLARE CONSTANT CHAR ARRAY FOR THE MONTHS OF THE YEAR AND INITIATE VALUES
	
	//compare month_as_string to months_of_year
	int month_num = 0;
	bool found = false;
	for (month_num=0; month_num<12 && !found; month_num++)
	{
		if (strcmp(months_of_year[month_num],month_as_string)==0)
			found = true;
	}
	//month_num++;	//add 1 final number to month as char months_of_year goes from 0 to 11 while calendar months go from 1 to 12
	
	if (found)	//if month is found convert month int to char and assign to out char array
	{
		out[3] = '0' + month_num/10;
		out[4] = '0' + month_num%10;
		out[5] = '/';
	}
	else 
		return false;
		
//***************************YEARS**********************		
	//YEAR to int
	int year_num = 0;
	for (int i=0; i<4; i++)
	{
		year_num = 10 * year_num + (in[i+7] - '0');
	}
	
	out[6] = '0' + (year_num%100)/10;
	out[7] = '0' + (year_num%100)%10;
	out[8] = '\0';
	
	return date_is_valid (day_num, month_num, year_num);
}
//END CONVERT DATE FUNCTION
/*******************************************************************************************************************************/

/*******************************************************************************************************************************/
//DECLARE FUNCTION TO CHECK THAT IT'S A VALID DATE
bool date_is_valid (int day, int month, int year)
{
	const int days_in_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	if (day<1 || day>31)	//check that day is between 1 and 31 inclusive
		return false;
		
	if (month<1 || month>12)	//check that month is between 1 and 12 inclusive
		return false;
		
	//check that number of days is within number of days in the month.  also call leap year function to check if it's a leap year
	if (day>days_in_month[month-1] && !(month==2 && day==29 && is_a_leap_year(year)))
		return false;
		
	return true;
}
//END VALID DATE FUNCTION
/*******************************************************************************************************************************/

/*******************************************************************************************************************************/
//DECLARE FUNCTION TO CHECK IF IT'S A LEAP YEAR
bool is_a_leap_year (int year)
{
	return (year%400==0) || ((year%100 != 100) && (year%4==0));
}
//END LEAP YEAR FUNCTION
/*******************************************************************************************************************************/