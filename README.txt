Programs:

Portfolio Program 1
C Revision
Write a C program to read two integers N and n such that n<=N from the
user and
(a) sum all the integers between 1 and N;
(b) sum the squares of all the even numbers between 1 and N;
(c) create a random array of length N of integers and get the product of
all the multiples of 5 or 11 in the array.
(d) using the random array of length N, compute the n th largest number
in the array;

C++ programming
Portfolio Program 2
Write a program that asks the user to enter 2 numbers. The 2 numbers
should be stored in int variables. Add the 2 numbers and display the
result to the user. Subtract the 2 numbers and display the result to the
user.

Portfolio Program 3
Write a program that lets the user input any number of words. Count
how often each alphabetic character occurs in the input, and print out the
results, such as:
a=3
b=0
c=2
d=4
...
...
...

Portfolio Program 4
Write a program to receive a double ﬂoating point number as input from
the user and calculate the arctan of that number to 20 decimal places
using the following series
arctan(x) = x −
x 3
3
+
x 5
5
−
x 7
7
− . . .

Portfolio Program 5
Write a program to calculate π ≈ 3.14159 . . . to 10 decimal places using
the following method
π = 4 arctan(1.0) (2)
Get your program to write out the values it has calculated at each itera-
tion.
Notice the following issue:
• Although the mathematical formula in equation (2) is correct, and
the inﬁnite series is correct, this method is almost useless as the
inﬁnite series converges very slowly – that is, it takes a very large
number of terms before the correct answer is reached.

Portfolio Program 6
Write a program to calculate π ≈ 3.14159 . . . using the following method
π = 4 × (4arctan(1/5) − arctan(1/239))
• Notice that this formula converges much more quickly.

Portfolio Program 7
Write a program that can copy a text ﬁle:
filecopy inputfile outputfile
This is a repeat of portfolio program 30 from COMP30400 – change your
original program to use C++ input and output streams and the >> and
<< operators.

Portfolio Program 8
Write a program that compares two ﬁles and tells the user if they are
identical or not. The user can specify the two ﬁlenames on the command
line:
filecompare inputfile outputfile

Portfolio Program 9
Write a program to display ﬁle contents 20 lines at a time. The program
pauses after displaying 20 lines until the user presses either Q to quit or
return to display the next 20 lines. The user speciﬁes the ﬁle name on
the command line:
filedisplay inputfile

Portfolio Program 10
Based on the compound interest program in the notes, write a function
double compoundInterest(double principal, double rate, int numyears);
that computes the amount that accrues in numyears years if the interest
rate is rate and the starting principal is principal.

Portfolio Program 11
Rewrite the compound interest program to instead compute the principal,
given the amount accrued after a given number of years, at a given interest
rate.

Portfolio Program 12
Write a function capitalise that takes an array of characters as input
and makes all of the alphabetic characters in the array uppercase.

Portfolio Program 13
Write a function that takes a date string in the form DD-MMM-YYYY
as input, where DD is a 2-digit integer (01–31), MMM is a 3-letter ab-
breviation of a month (Jan, Feb,...,Dec) and YYYY is a 4-digit year, and
outputs the date in the form DD/MM/YY, where DD is the same 2-digit
integer, MM is a 2-digit month number (01–12), and YY is a 2-digit year
number, e.g. 13, to represent the year 2013. The function should return
true if the date is a valid date and false otherwise e.g. 31-Apr-2013 is
not a valid date. A good implementation would take into account leap
years, using the function presented in class.
The prototype of the function should be:
bool convertFormat(char inputFormat[], char outputFormat[]);

Portfolio Program 14
Portfolio Program 4 was a program to calculate the arctan of a double
ﬂoating point number. Package the arctan program into a function with
the following prototype:
double arctan(double x, double precision=10e-10);
Write a main program that compares the output of your arctan function
with the cmath library function atan.

Portfolio Program 15
In the ﬁle roundoff.cpp a while loop is provided that computes the
value of the square root of a given number. Using that while loop, write
a function with prototype deﬁnition
double mysqrt(double x);
that computes the square root of its input value x to 10 decimal places.
Compare the output of your mysqrt function with the cmath library func-
tion sqrt.

Portfolio Program 16 Write a function
double rthroot(double x double r);
that computes the r th root of a number x. (For example, given r = 3, the
function should return the cube root).

Portfolio Program 17
Write a function that takes a string in the form of an array of characters
as input and reverses the string. See, for example, the question on the
ﬁrst MCQ about reversing the contents of an array, using a simple loop.
When you have a simple version implemented, see if you can rewrite the
function as a recursive function.

Portfolio Program 18
Implement a recursive function to solve the Towers of Hanoi problem.
