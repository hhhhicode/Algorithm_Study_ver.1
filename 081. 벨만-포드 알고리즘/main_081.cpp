// Ʋ�� ����

// ����-���� �˰���
//������ �ϳ��� �� �� �ִ�, �ѷ� �� �� �ִ�, ������ �� �� �ִ�........
//����Ŭ�� ���� ���� �� ������ ���̴� N - 1���̸�, N��°�� weight�� �۾����� ���� ����Ŭ�� �����ϴ� ���̴�.

//����������ڷ����� vector�� �̿��ϸ� k for���� ���� �� �ִ�.

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
		for (int i = 1; i < _N; i++) // 1 ~ _N - 1�� �������� �̷���� ����� �ּ� ���
		{
			for (int j = 1; j <= _N; j++) //here
			{
				for (int k = 1; k <= _N; k++) //there, ����������ڷ����� vector�� �̿��ϸ� k for���� ���� �� �ִ�.
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