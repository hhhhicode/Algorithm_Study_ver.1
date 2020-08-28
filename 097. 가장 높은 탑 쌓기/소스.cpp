// 틀린 문제

// LIS(최대 부분 증가 수열)은 순서가 있는 리스트에 조건을 만족하는 수열(과 그에 대한 결과)을 찾는 것이다.
// 순서가 있는 리스트가 없을 시, 순서를 생성해 준다.

// 무게가 무거운 && 밑면이 넓은 벽돌이 아래

#include <iostream>
#include <algorithm>

class Stone
{
private:
	int _square;
	int _height;
	int _weight;

public:
	Stone() {}
	Stone(const int& s, const int& h, const int& w)
		: _square(s), _height(h), _weight(w)
	{}

	int getSquare()
	{
		return this->_square;
	}

	int getHeight()
	{
		return this->_height;
	}

	int getWeight()
	{
		return this->_weight;
	}

	bool operator < (const Stone& s2) const
	{
		return this->_square > s2._square;
	}
};

class Tower
{
private:
	int _n;
	Stone* stones;
	int* towerHeight;

public:
	void solution()
	{
		init();
		eachMaxHeight();
		printMaxHeight();
	}
	void init()
	{
		std::cin >> _n;
		stones = new Stone[_n];
		towerHeight = new int[_n]();
		int s, h, w;
		for (int i = 0; i < _n; i++)
		{
			std::cin >> s >> h >> w;
			stones[i] = Stone(s, h, w);
		}

		std::sort(stones, stones + _n);

		// 각각의 높이가 갱신이 안될 수 있기 때문에(앞에이 자신보다 가벼운 돌이라서) 모두 초기화 해준다.
		for (int i = 0; i < _n; i++)
		{
			towerHeight[i] = stones[i].getHeight();
		}
	}

	bool checkNextStone(const int& i, const int& j)
	{
		if (stones[i].getWeight() < stones[j].getWeight())
			return true;
		return false;
	}

	void eachMaxHeight()
	{
		for (int i = 0; i < _n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (checkNextStone(i, j))
				{
					int newHeight = towerHeight[j] + stones[i].getHeight();
					if (towerHeight[i] < newHeight)
					{
						towerHeight[i] = newHeight;
					}
				}
			}
		}
	}

	void printMaxHeight()
	{
		int maxHeight = 0;
		for (int i = 0; i < _n; i++)
		{
			maxHeight = std::max(maxHeight, towerHeight[i]);
		}
		std::cout << maxHeight;
	}

	void printStones()
	{
		std::cout << std::endl;
		for (int i = 0; i < _n; i++)
		{
			std::cout << stones[i].getSquare() << ' ' << stones[i].getHeight() << ' ' << stones[i].getWeight() << std::endl;
		}
	}
};

int main()
{
	using namespace std;

	Tower().solution();

	return 0;
}