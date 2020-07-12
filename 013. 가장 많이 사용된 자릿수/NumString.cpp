#include "NumString.h"

NumString::NumString()
{
	string = new char[101];
	std::cin >> string;
	for (int i = 0; i < 10; i++)
		numbers[i] = 0;
	max = std::numeric_limits<int>::lowest();
}

NumString& NumString::gainNumber()
{
	for (int i = 0; string[i] != '\0'; i++)
	{
		numbers[int(string[i] - '0')]++;
	}
	return *this;
}

void NumString::print()
{
	for (int i = 0; i < 10; i++)
	{
		if (max <= numbers[i])
		{
			max = i;
		}
	}
	std::cout << max;
}
