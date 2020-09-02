// 틀린 문제

// 플로이드 워샬 알고리즘은 모든 정점에서 모든 정점으로 가는 최단거리를 구한다.
// Knapsack 알고리즘과 관련이 있다.

// 1. adj를 초기 matrix로 한다. i가 출발점이면 j는 도착점이다.
// 2. min(dis[i][j], dis[i][k] + dis[k][j]), 릴렉스되는 과정이 Knapsack과 닮았다.
// k가 4라면, 1 -> 2, 1 -> 3, 2 -> 1, 2 -> 3 등 모든 이동에 4번 노드를 고려하게 되는 것이므로
// 1 -> 3 이동이 목표였을 때
// 1 -> 2 -> 3 이동이 최소였다가 
// 2 -> 3이 2 -> 4 -> 3으로 릴렉스 되었다고 치면
// 1 -> 2 -> 4 -> 3이 되므로 1 -> 3 도 릴렉스 된다.?

// 릴레스 된다면, k 노드를 거쳐가는걸로 적용 된다는 뜻이다. 
// 1 <= k <= n 이니까 n까지 모두 돌고난 뒤의 값은 n개의 노드를 거쳐가는 것을 모두 고려한 값이 된다.

#include <iostream>
#include <vector>
#include <limits>

class Graph
{
private:
	int _n, _m;
	std::vector< std::vector<int> > weights;

public:
	void solution()
	{
		init();
		relaxWeight();
		printWeights();
	}
	void init()
	{
		std::cin >> _n >> _m;
		weights.assign(_n + 1, std::vector<int>(_n + 1, 20000)); // 2차배열로 만들기

		int a, b, w;
		for (int i = 0; i < _m; i++)
		{
			std::cin >> a >> b >> w;
			weights[a][b] = w;
		}
	}

	void relaxWeight()
	{
		for (int k = 1; k <= _n; k++)
		{
			for (int i = 1; i <= _n; i++)
			{
				for (int j = 1; j <= _n; j++)
				{
					if (weights[i][j] > weights[i][k] + weights[k][j])
					{
						weights[i][j] = weights[i][k] + weights[k][j];
					}
					else if (i == j)
						weights[i][j] = 0;
				}
			}
		}
	}

	void printWeights()
	{
		for (int i = 1; i <= _n; i++)
		{
			for (int j = 1; j <= _n; j++)
			{
				if (weights[i][j] == 20000)
				{
					std::cout << "M ";
					continue;
				}
				std::cout << weights[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	using namespace std;

	Graph().solution();

	return 0;
}