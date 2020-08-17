// 1�� �������� ��� ���������� �ּ� �Ÿ������ ����ϴ� ���α׷� �ۼ�

#include <iostream>
#include <queue>
#include <limits>

class Graph
{
private:
	int _N, _M;
	int** adj;
	int* node;
	std::queue<int> q;
	int* distance;

public:
	Graph(int n, int m)
		: _N(n), _M(m)
	{
		// adj Allocation
		adj = new int* [_N + 1];
		for (int i = 0; i < _N + 1; i++)
		{
			adj[i] = new int[_N + 1]();
		}

		// adj init
		for (int i = 0; i < _M; i++)
		{
			int a, b, c;
			std::cin >> a >> b >> c;
			adj[a][b] = c;
		}

		// distance al, init
		distance = new int[_N + 1];
		for (int i = 1; i <= _N; i++)
			distance[i] = std::numeric_limits<int>::max();
		distance[1] = 0;

		// node Allocation & init
		node = new int[_N + 1];
		for (int i = 1; i <= _N; i++)
		{
			node[i] = i;
		}
	}
	~Graph()
	{

	}

	Graph& Tmp()
	{
		q.push(1);
		while (!q.empty())
		{
			int here = q.front();	q.pop();

			for (int there = 1; there <= _N; there++)
			{
				if (distance[here] + adj[here][there] < distance[there] && adj[here][there] != 0)
				{
					q.push(there);
					distance[there] = distance[here] + adj[here][there];
				}
			}
		}
		return *this;
	}

	void printDis()
	{
		for (int i = 2; i <= _N; i++)
		{
			if (distance[i] != std::numeric_limits<int>::max())
				std::cout << i << " : " << distance[i] << std::endl;
			else std::cout << "impossible" << std::endl;
		}
	}
};

int main()
{
	using namespace std;

	int N, M;
	cin >> N >> M;
	Graph(N, M).Tmp().printDis();

	return 0;
}

// ����� ������ ť�� �ְ�, �ƴϸ� ť�� �ȳ־ �� �� ����. ����� ũ�� �� ������ �̵� ��뵵 Ŭ�״ϱ�.