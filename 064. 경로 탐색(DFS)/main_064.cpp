// 각 노드마다 모든 노드를 확인하려고 할 때, for을 이용해서 DFS를 구현한다.

#include <iostream>

class Path
{
private:
	int m_N;
	int m_M;
	int count;
	int** adj;
	bool* checkPoint;

public:
	Path(const int& N, const int& M)
		: m_N(N), m_M(M), count(0)
	{
		adj = new int* [m_N + 1];
		for (int i = 0; i < m_N + 1; i++)
		{
			adj[i] = new int[m_N + 1]();
		}
		for (int i = 0; i < m_M; i++)
		{
			int r, c;
			std::cin >> r >> c;
			adj[r][c] = 1;
		}
		checkPoint = new bool[m_N + 1]();
		checkPoint[1] = true;
	}
	~Path()
	{
		for (int i = 0; i < m_N + 1; i++)
			delete[] adj[i];
		delete[] adj, checkPoint;
	}

	void Go(const int& here)
	{
		for (int i = 1; i <= m_N; i++)
		{
			if (here == m_N)
			{
				count++;
				return;
			}
			if (here == i) continue;
			if (adj[here][i] != 0 && checkPoint[i] != true)
			{
				checkPoint[i] = true;
				Go(i);
				checkPoint[i] = false;
			}
		}
	}

	void printCount()
	{
		std::cout << count;
	}
};

int main()
{
	using namespace std;
	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);

	int N, M;
	cin >> N >> M;

	Path p(N, M);
	p.Go(1);
	p.printCount();

	return 0;
}