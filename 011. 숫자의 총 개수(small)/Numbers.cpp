#include "Numbers_2.h"

Numbers2& Numbers::gainNumber()
{
	for (int i = 1; i <= number; i++)
	{
		int tmp = i;
		while (tmp)
		{
			tmp /= 10;
			count++;
		}
	}
	return *this;
}

void Numbers2::print()
{
	std::cout << count;
}