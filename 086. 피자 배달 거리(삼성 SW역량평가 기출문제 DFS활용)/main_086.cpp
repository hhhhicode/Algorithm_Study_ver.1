// Ʋ�� ����

// ������ ������ DFS�� ������ �����ϸ�, ������ ������ �ǹ̸� �˾ƾ� �Ѵ�.
// ������ ���� ���ҵ��� ������ �ǹ̰� �ִ�.
// ������ ���� ���ҵ��� ������ �ǹ̰� ����.
// ���� ���� >= ���� ����
// ������ for�� ���鼭 DFS����, ó������ �� for ����, ������ for���鼭 DFS����, ����� �������� for�� ����.


#include <iostream>
#include <tuple>
#include <algorithm>
#include <limits>

class City
{
private:
	int _N, _M;
	std::tuple<int, int>* pizza;	int pIdx;
	std::tuple<int, int>* home;		int hIdx;
	int ch[13];
	int sum;
	int res = std::numeric_limits<int>::max();

public:
	City(int n, int m) : _N(n), _M(m)
	{
		pizza = new std::tuple<int, int>[_M];	pIdx = -1;
		home = new std::tuple<int, int>[_N];	hIdx = -1;
		for (int i = 1; i < _N + 1; i++)
		{
			for (int j = 1; j < _N + 1; j++)
			{
				int tmp;
				std::cin >> tmp;
				if (tmp == 1)
					home[++hIdx] = std::tuple(i, j);
				if (tmp == 2)
				{
					pizza[++pIdx] = std::tuple(i, j);
				}
			}
		}
	}
	~City()
	{
		delete[] pizza, home;
	}

	void DFS(int p = 0, int L = 0)
	{
		if (L == _M)
		{
			int sum = 0;
			int minDistance;
			for (int i = 0; i <= hIdx; i++)
			{
				int hX = std::get<0>(home[i]);
				int hY = std::get<1>(home[i]);

				minDistance = std::numeric_limits<int>::max();
				for (int j = 0; j < L; j++)
				{
					int pX = std::get<0>(pizza[ch[j]]);
					int pY = std::get<1>(pizza[ch[j]]);
					minDistance = std::min(minDistance, abs(hX - pX) + abs(hY - pY));
				}
				sum += minDistance;
			}
			if (res > sum)
			{
				res = sum;
			}
		}
		else
		{
			for (int i = p; i <= pIdx; i++)
			{
				ch[L] = i;
				DFS(i + 1, L + 1);
			}
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

	int N, M;
	cin >> N >> M;

	City c(N, M);
	c.DFS();
	c.printRes();

	return 0;
}