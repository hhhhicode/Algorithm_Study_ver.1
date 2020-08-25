//Ʋ�� ����

// header, cpp �� �����°͵� ���ߴ�.

// 1�ʿ� �����¿� ������ �� ĭ�� �̵� ����.
// �ڽ��� ũ�⺸�� ū �䳢�� �ִ� ĭ�� ������ �� ����.
// �ڽ��� ũ�⺸�� ���� �䳢�� ���� �� �ְ�, ���� ũ��� ������ ���� ����.

// �䳢�� 1�������� ������ ����� �䳢�� ������ ����. ����� �䳢�� ���������̸� ���� ��, ���ʿ� �ִ� �䳢�� �Դ´�.
// �䳢�� 1�����̸� �� �䳢�� ������ ����.
// �䳢�� �� ������ �����Ϸ� ����.

#include <iostream>
#include <tuple>
#include <queue>

class Position
{
private:
	std::tuple<int, int> pos;

public:
	void setPosition(const int& x, const int& y)
	{
		pos = std::make_tuple(x, y);
	}
	auto getPosition() const
	{
		return pos;
	}
};


class Lion
{
private:
	Position position;
	int  size = 2;
	int  exp = 0;

public:
	void setPosition(const int& x, const int& y)
	{
		position.setPosition(x, y);
	}
	
	int getSize()
	{
		return size;
	}

	void eatRabbit()
	{
		exp++;
		if (size == exp)
		{
			size++;
			exp = 0;
		}
	}
};

class State
{
private:
	Position position;
	int distance;

public:
	State& setPosition(const int& x, const int& y)
	{
		position.setPosition(x, y);
		return *this;
	}
	State& setDistance(const int& d)
	{
		distance = d;
		return *this;
	}
	auto getPosition()
	{
		return position.getPosition();
	}
	int getDistance()
	{
		return distance;
	}

	bool operator < (const State& r2) const
	{
		if (this->distance == r2.distance)
		{
			auto [x1, y1] = this->position.getPosition();
			auto [x2, y2] = r2.position.getPosition();
			if (x1 == x2) return y1 > y2;
			else return x1 > x2;
		}
		else return this->distance > r2.distance;
	}
};

class Jungle
{
private:
	Lion simba;
	int _N;
	int res;
	int** map;
	bool** checkMap;
	std::priority_queue<State> q;

public:
	Jungle(const int& N) : _N(N)
	{
		init(_N);
	}
	void init(const int& _N)
	{
		checkMap = new bool* [_N];
		for (int i = 0; i < _N; i++)
		{
			checkMap[i] = new bool[_N]();
		}

		map = new int* [_N];
		for (int i = 0; i < _N; i++)
		{
			map[i] = new int[_N];
			for (int j = 0; j < _N; j++)
			{
				std::cin >> map[i][j];
				if (map[i][j] == 9)
				{
					simba.setPosition(i, j);
					map[i][j] = 0;
					q.push
					(
						State()
						.setPosition(i, j)
						.setDistance(0)
					);
					checkMap[i][j] = true;
				}
			}
		}
	}

	void searchPriorityTarget() //const int& hereX, const int& hereY
	{
		int xl[]{ -1, 0, 1, 0 };
		int yl[]{ 0, 1, 0, -1 };

		while (!q.empty())
		{
			State here = q.top();	q.pop();
			auto [hereX, hereY] = here.getPosition();
			int hereDis = here.getDistance();

			if (0 < map[hereX][hereY] && map[hereX][hereY] < 9 && map[hereX][hereY] < simba.getSize())
			{
				simba.eatRabbit();
				map[hereX][hereY] = 0;

				for (int i = 0; i < _N; i++)
					for (int j = 0; j < _N; j++)
					{
						checkMap[i][j] = false;
					}
				while (!q.empty())
				{
					q.pop();
				}
				res = hereDis;
			}

			for (int l = 0; l < 4; l++)
			{
				int thereX{ hereX + xl[l] };
				int thereY{ hereY + yl[l] };

				if (0 <= thereX && thereX < _N && 0 <= thereY && thereY < _N &&
					map[thereX][thereY] <= simba.getSize() && checkMap[thereX][thereY] == false)
				{
					checkMap[thereX][thereY] = true;
					q.push
					(
						State()
						.setPosition(thereX, thereY)
						.setDistance(hereDis + 1)
					);
				}
			}
		}
	}

	void printJungle()
	{
		for (int i = 0; i < _N; i++)
		{
			for (int j = 0; j < _N; j++)
			{
				std::cout << map[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	void printRes()
	{
		std::cout << res;
	}
};

int main()
{
	using namespace std;
	//FILE* s;	freopen_s(&s, "input.txt", "rt", stdin);

	int N;
	cin >> N;

	Jungle j(N);
	j.searchPriorityTarget();
	j.printRes();

	return 0;
}