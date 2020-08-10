#include "Escape.h"

Escape::Escape()
{
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			std::cin >> map[i][j];
	map[0][0] = 1;
}

void Escape::Go(int x, int y)
{
	if (x == 6 && y == 6) {
		count++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + xScape[i];
		int nextY = y + yScape[i];
		if (0 <= nextX && nextX <= 6 && 0 <= nextY && nextY <= 6 && map[nextX][nextY] != 1)
		{
			map[nextX][nextY] = 1;
			Go(nextX, nextY);
			map[nextX][nextY] = 0;
		}
	}
}

void Escape::printCount()
{
	std::cout << count;
}
