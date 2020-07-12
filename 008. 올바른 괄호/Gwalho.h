#pragma once

#include <iostream>

class Gwalho {
private:
	char* _string = new char[30];
	int  baseline;

public:
	Gwalho()
		:baseline(0)
	{
		std::cin >> _string;
	}
	~Gwalho()
	{
		delete[] _string;
	}
	void check();
};