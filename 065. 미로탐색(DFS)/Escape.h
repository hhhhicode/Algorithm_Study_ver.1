#pragma once

#include <iostream>

class Escape
{
private:
	int map[7][7];
	int count{ 0 };
	int xScape[4]{ -1,0,1,0 };
	int yScape[4]{ 0,1,0,-1 };

public:
	Escape();

	void Go(int x = 0, int y = 0);

	void printCount();
};