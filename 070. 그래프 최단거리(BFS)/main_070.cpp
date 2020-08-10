// 틀린 문제
// BFS : 이동 횟수(레벨) 별 탐색
// 방문하는 최소 횟수를 구하기 위해서는 'BFS + 큐'를 이용한다.

#include <iostream>

class Map
{
private:
	int _N, _M;
	bool** adj;
	int* distance;
	bool* ch;
	int queue[100];
	int back = -1, front = -1;

public:
	Map(int N, int M)
		: _N(N), _M(M)
	{
		adj = new bool* [_N + 1];
		for (int i = 0; i < _N + 1; i++)
			adj[i] = new bool[_N + 1]();
		for (int i = 0; i < _M; i++)
		{
			int here, target;
			std::cin >> here >> target;
			adj[here][target] = true;
		}
		distance = new int[_N + 1]();
		ch = new bool[_N + 1]();
		ch[1] = true;

		queue[++front] = 1;
	}
	~Map()
	{
		for (int i = 0; i < _N + 1; i++)
			delete[] adj[i];
		delete[] adj;
	}

	Map& DFS(int here = 1, int d = 0)
	{
		if (distance[here] >= d)
			distance[here] = d;
		else
		{
			return *this;
		}
		for (int t = 1; t <= _N; t++)
		{
			if (ch[t] == false && adj[here][t] == true)
			{
				ch[t] = true;
				DFS(t, d + 1);
				ch[t] = false;
			}
		}
		return *this;
	}

	// 이게 큰 문제였다.
	// 재귀가 진행될 수록 값이 커지는게 아니라, 레벨이 증가할 때 값이 커져야 한다.
	/*Map& BFS(int d = 0)*/
	Map& BFS()
	{
		if (back < front)
		{
			int here = queue[++back];
			// 이게 큰 문제였다.
			/*distance[here] = d;*/
			for (int i = 2; i <= _N; i++)
			{
				if (adj[here][i] == true && ch[i] == false)
				{
					ch[i] = true;
					queue[++front] = i;
					distance[i] = distance[here] + 1;
				}
			}
			// 이게 큰 문제였다.
			/*BFS(d + 1);*/
			BFS();
		}
		return *this;
	}

	void printDistance()
	{
		for (int i = 2; i <= _N; i++)
		{
			std::cout << i << " : " << distance[i] << std::endl;
		}
	}
};

int main()
{
	using namespace std;

	int N, M;
	cin >> N >> M;

	Map(N, M).BFS().printDistance();

	return 0;
}