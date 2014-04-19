// Written by Zack Rosales
// Advanced C++ Programming ITSE 2431 1001
// Program from page 1136, #11
// Program uses a recursive method to determine if a string is a palindrome

#include <fstream> // for using files
#include <iostream> // for cout and cin
#include <iomanip> // for formatting
#include <string> // for strings
#include <cstdlib> // for rand and srand
#include <vector> // for vectors
#include <cctype> // for character functions
#include <cstring> // for C-strings
#include <ctime> // for using time/date functions
#include <algorithm> // for STL algorithms
#include "conio.h" 
using namespace std;

// method prototypes
string getString();
bool palindromeTest(string, int, int, bool);

int main() // main method start
{
	// local variable
	char enterAnother;
	string str;

	do
	{
		str = getString();
		if (palindromeTest(str, 0, str.length() - 1, true))
		{
			cout << "It is a palindrome.\n\n";
		} // end if
		else
		{
			cout << "It is NOT a palindrome.\n\n";
		} // end else
		cout << "\nWould you like to enter another phrase/sentence? enter \'y\' or \'Y\' to keep going.";
		cin >> enterAnother;
	} while (tolower(enterAnother) == 'y');

	cout << "Have a good day.";
	_getch();
	return 0;
} // main method end

// getString method gets string from user input
string getString() // getString method start
{
	// local variable
	string str;

	// getting user input
	cout << "Enter a phrase or sentence to test:\n";
	cin.ignore();
	getline(cin, str);

	return str;
} // getString method end

// recursive palindromeTest method tests the string to see if it is a palindrome
bool palindromeTest(string str, int forward, int backward, bool match) // palindromeTest method start
{
	if (backward < forward && match)
	{
		return true;
	} // end if
	else if (!match)
	{
		return false;
	} // end else if
	else
	{
		while (!isalpha(str[forward]))
		{
			forward++;
		} // end while
		while (!isalpha(str[backward]))
		{
			backward--;
		} // end while
		if (tolower(str[forward]) == tolower(str[backward]))
		{
			match = palindromeTest(str, forward + 1, backward -1, match);
			return match;
		} // end if
		else
		{
			return false;
		} // end else
	} // end else
} // palindromeTest method end