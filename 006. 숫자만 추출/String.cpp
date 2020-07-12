#include "String.h"

String& String::searchNumber()
{
	for (unsigned i = 0; string[i] != '\0'; i++)
	{
		if (int('0') <= int(string[i]) && int(string[i]) <= int('9'))
		{
			number *= 10;
			number += int(string[i] - '0');
		}
	}
	std::cout << number << std::endl;
	return *this;
}

void String::countDivisor() {
	int count = 0;
	for (unsigned i = 1; i <= number / 2; i++)
	{
		if (number % i == 0)
			count++;
	}
	std::cout << count + 1;	// +1은 자기 자신.
}
