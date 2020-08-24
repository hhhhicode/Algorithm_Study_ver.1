#include <iostream>
#include <queue>
#include <tuple>

class Sea
{
private:
	std::queue<std::tuple<int, int> > q;
	int xl[8]{ -1, -1, -1, 0, 1, 1, 1, 0 };
	int yl[8]{ -1, 0, 1, 1, 1, 0, -1, -1 };
	int _N;
	int count = 0;
	int** map;

public:
	Sea(int N)	: _N(N)
	{
		map = new int* [_N + 1];
		for (int i = 0; i < _N + 1; i++)
			map[i] = new int[_N + 1];

		for (int i = 1; i <= _N; i++)
		{
			for (int j = 1; j <= _N; j++)
			{
				std::cin >> map[i][j];
			}
		}
	}

	void Run()
	{
		for (int i = 1; i <= _N; i++)
		{
			for (int j = 1; j <= _N; j++)
			{
				if (map[i][j] == 1)
				{
					q.push(std::tuple(i, j));
					BFS();
					count++;
				}
			}
		}

		std::cout << count;
	}

	void BFS()
	{
		while (!q.empty())
		{
			std::tuple<int, int> hereTuple = q.front();	q.pop();
			int hereX = std::get<0>(hereTuple), hereY = std::get<1>(hereTuple);
			map[hereX][hereY] = 0;

			int thereX, thereY;
			for (int l = 0; l < 8; l++)
			{
				thereX = hereX + xl[l];
				thereY = hereY + yl[l];
				if (1 <= thereX && thereX <= _N && 1 <= thereY && thereY <= _N && map[thereX][thereY] == 1)
				{
					map[thereX][thereY] = -1;
					q.push(std::tuple(thereX, thereY));
				}
			}
		}
	}
};

int main()
{
	using namespace std;
	//FILE* s;	freopen_s(&s, "input.txt", "rt", stdin);

	int N;
	cin >> N;

	Sea(N).Run();

	return 0;
}