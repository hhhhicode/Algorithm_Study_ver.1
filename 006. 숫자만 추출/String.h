#pragma once

#include <iostream>

class String {
private:
	char* string = new char[50];
	int number;

public:
	String() {
		std::cin >> string;
		number = 0;
	}
	~String() {
		delete[] string;
	}

	String& searchNumber();

	void countDivisor();
};