#include <iostream>
#include <string>
#include "luhn.h"

using namespace std;

int main()
{
	string number;
	string choice = "y";

	cout << "LUHN CHECKSUM VALIDATOR" << endl;

	while (choice == "y" || choice == "Y")
	{
		cout << "\nEnter a 16-digit number: ";

		if (!getline(cin, number))
		{
			break;
		}

		// step 1: validate input format
		if (!isValidInput(number))
		{
			cout << "Invalid input. Please enter exactly " <<
				"16 digits with no spaces or letters." <<
				endl;
		}

		// step 2: run checksum if input is valid
		else if (checkLuhn(number))
		{
			cout << "The number passes the Luhn checksum." << endl;
		}
		else
		{
			cout << "The number fails the Luhn checksum." << endl;
		}

		// step 3: ask whether the user wants to continue
		cout << "\nWould you like to check another number?"
			<< "(y/n): ";

		if (!getline(cin, choice))
		{
			break;
		}

		while (choice != "y" && choice != "Y" && choice != "n" && choice != "N")
		{
			cout << "Please enter y or n: ";
			
			if (!getline(cin, choice))
			{
				cout << "\nProgram ended." << endl;
				return 0;
			}
		}
	}

	cout << "\nProgram ended." << endl;
	
	return 0;
}
