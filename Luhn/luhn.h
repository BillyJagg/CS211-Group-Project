#ifndef LUHN_H
#define LUHN_H

#include<string>
using namespace std;

// checks whether the input contains exactly 16 digits
bool isValidInput(const string& number);

// calculates whether the numbers passes the luhn checksum
bool checkLuhn(const string& number);

#endif
