#pragma once

#include <iostream>

class Word {
private:
	char* _preword = new char[100];

public:
	Word()
	{
		std::cin.getline(_preword, 100);
	}
	~Word()
	{
		delete[] _preword;
	}

	void reword();
};