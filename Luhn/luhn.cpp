#include "luhn.h"

// check that the input is exactly 16 digits
bool isValidInput(const string& number)
{
	if (number.length() != 16)
	{
		return false;
	}

	// check every character
	for (int i = 0; i < 16; i++)
	{
		if (number[i] < '0' || number[i] > '9')
		{
			return false;
		}
	}

	return true;

}

// apply the luhn checksum algorithm
bool checkLuhn(const string& number)
{
	int sum = 0;
	bool doubleDigit = false;

	// start at rightmost digit and move left
	for (int i = 15; i >= 0; i--)
	{
		// convert character into integer
		int digit = number[i] - '0';

		// double every second digit
		if (doubleDigit)
		{
			digit = digit * 2;

			// if the result has two digits, subtract 9
			if (digit > 9)
			{
				digit = digit - 9;
			}
		}

		// add transformed digit to sum
		sum = sum + digit; 

		// alternate between doubling and not doubling
		doubleDigit = !doubleDigit;
	}

	// true if the sum is divisible by 10
	return (sum % 10 == 0);


}
