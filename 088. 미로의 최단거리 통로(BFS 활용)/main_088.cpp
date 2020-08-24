#include <iostream>
#include <queue>

class Position
{
public:
	int m_x;
	int m_y;

	Position(const int& x, const int& y)
	{
		init(x, y);
	}
	void init(const int& x, const int& y)
	{
		this->m_x = x;
		this->m_y = y;
	}
};

int main()
{
	using namespace std;
	FILE* s;	freopen_s(&s, "input.txt", "rt", stdin);

	int maze[8][8];
	for (int i = 1; i <= 7; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			cin >> maze[i][j];
		}
	}

	std::queue<Position> q;
	q.push(Position(1, 1));

	int hereX, hereY;
	int thereX, thereY;
	while (!q.empty())
	{
		static int xl[4] = { -1, 0, 1, 0 };
		static int yl[4] = { 0, 1, 0, -1 };
		hereX = q.front().m_x;
		hereY = q.front().m_y;
		q.pop();
		if (hereX == 7 && hereY == 7)
			cout << maze[hereX][hereY];

		for (int l = 0; l < 4; l++)
		{
			thereX = hereX + xl[l];
			thereY = hereY + yl[l];
			if (1 <= thereX && thereX <= 7 && 1 <= thereY && thereY <= 7)
			{
				if (maze[thereX][thereY] == 0)
				{
					maze[thereX][thereY] = maze[hereX][hereY] + 1;
					q.push(Position(thereX, thereY));
				}
			}
		}
	}


	return 0;
}