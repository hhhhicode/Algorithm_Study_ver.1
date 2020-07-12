#pragma once

#include <iostream>

class Numbers {
private:
	int number;
	int count;
public:
	Numbers()
		:count(0)
	{
		std::cin >> number;
	}

	Numbers& gainNumber()
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
	void print();
};