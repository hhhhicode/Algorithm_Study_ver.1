#include <iostream>

class BottomUp
{
private:
	int _n;
	int** map;
	int** energy;
public:
	void solution()
	{
		init();
		go();
		printMinEnergy();
	}

	void init()
	{
		std::cin >> _n;
		map = new int* [_n + 1];
		for (int i = 0; i < _n + 1; i++)
		{
			map[i] = new int[_n + 1]();
		}
		for (int i = 1; i < _n + 1; i++)
		{
			for (int j = 1; j < _n + 1; j++)
			{
				std::cin >> map[i][j];
			}
		}
	}

	void go()
	{
		for (int i = 2; i < _n + 1; i++)
		{
			map[1][i] = map[1][i] + map[1][i - 1];
			map[i][1] = map[i][1] + map[i - 1][1];
		}
		for (int i = 2; i < _n + 1; i++)
		{
			for (int j = 2; j < _n + 1; j++)
			{
				int newEnergyRl = map[i - 1][j] + map[i][j];
				int newEnergyCl = map[i][j - 1] + map[i][j];
				map[i][j] = newEnergyRl < newEnergyCl ? newEnergyRl : newEnergyCl;
			}
		}
	}

	void printMinEnergy()
	{
		std::cout << map[_n][_n];
	}

	void printMap()
	{
		std::cout << std::endl;
		for (int i = 1; i < _n + 1; i++)
		{
			for (int j = 1; j < _n + 1; j++)
			{
				std::cout << map[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	using namespace std;

	BottomUp().solution();

	return 0;
}