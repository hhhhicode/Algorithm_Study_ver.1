#pragma once

#include <iostream>
#include <limits>

class NumString {
private:
	char* string;
	int numbers[10];
	int max;
public:
	NumString();
	NumString& gainNumber();
	void print();
};