#include <iostream>
#include <algorithm>
class Map
{
private:
	int _n;
	int** _map;
	int** _eMap;

public:
	void init()
	{
		std::cin >> _n;
		_map = new int* [_n + 1];
		_eMap = new int* [_n + 1];
		for (int i = 0; i < _n + 1; i++)
		{
			_map[i] = new int[_n + 1];
			_eMap[i] = new int[_n + 1]();
			if (i != 0)
			{
				for (int j = 1; j < _n + 1; j++)
				{
					std::cin >> _map[i][j];
				}
			}
		}
	}

	int topDown(const int& i, const int& j)
	{
		if (_eMap[i][j] != 0)
			return _eMap[i][j];
		else
		{
			if (i == 1 && j == 1)
				return _eMap[i][j] = _map[i][j];
			else if (i == 1)
			{
				return _eMap[i][j] = topDown(i, j - 1) + _map[i][j];
			}
			else if (j == 1)
			{
				return _eMap[i][j] = topDown(i - 1, j) + _map[i][j];
			}
			else
			{
				int choicedDirection = std::min(topDown(i, j - 1), topDown(i - 1, j));
				return _eMap[i][j] = choicedDirection + _map[i][j];
			}
		}
	}

	void solution()
	{
		init();
		std::cout << topDown(_n, _n);
	}
};

int main()
{
	using namespace std;

	Map().solution();

	return 0;
}