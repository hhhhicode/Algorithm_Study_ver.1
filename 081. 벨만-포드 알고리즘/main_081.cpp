// 틀린 문제

// 벨만-포드 알고리즘
//간선을 하나로 갈 수 있다, 둘로 갈 수 있다, 셋으로 갈 수 있다........
//사이클이 없는 가장 긴 간선의 길이는 N - 1번이며, N번째에 weight가 작아지면 음의 사이클이 존재하는 것이다.

//사용자정의자료형과 vector를 이용하면 k for문을 없앨 수 있다.

#include <iostream>
#include <limits>

class Graph
{
private:
	int _N, _M;
	int _s, _e;
	int* dis;
	int** adj;

public:
	Graph(int n, int m)
		: _N(n), _M(m)
	{
		dis = new int[_N + 1];
		for (int i = 1; i <= _N; i++)
			dis[i] = std::numeric_limits<int>::max();

		adj = new int* [_N + 1];
		for (int i = 1; i < _N + 1; i++)
		{
			adj[i] = new int[_N + 1]();
		}

		for (int i = 0; i < _M; i++)
		{
			int a, b, c;
			std::cin >> a >> b >> c;
			adj[a][b] = c;
		}

		std::cin >> _s >> _e;
		dis[_s] = 0;
	}
	~Graph(){}

	void Run()
	{
		for (int i = 1; i < _N; i++) // 1 ~ _N - 1개 간선으로 이루어진 경로의 최소 비용
		{
			for (int j = 1; j <= _N; j++) //here
			{
				for (int k = 1; k <= _N; k++) //there, 사용자정의자료형과 vector를 이용하면 k for문을 없앨 수 있다.
				{
					if (dis[j] + adj[j][k] < dis[k] && adj[j][k] != 0)
					{
						dis[k] = dis[j] + adj[j][k];
					}
				}
			}
		}

		for (int j = 1; j <= _N; j++) //here
		{
			for (int k = 1; k <= _N; k++) //there
			{
				if (dis[j] + adj[j][k] < dis[k] && adj[j][k] != 0)
				{
					std::cout << "-1";
					return;
				}
			}
		}
		printResult();
	}

	void printResult()
	{
		std::cout << dis[_e];
	}
};

int main()
{
	using namespace std;

	int N, M;
	cin >> N >> M;

	Graph(N, M).Run();

	return 0;
}