#include <iostream>
#include <limits>

class Path
{
private:
	int _N, _M;
	int** adj;
	bool* node;
	int minWeight = std::numeric_limits<int>::max();
	int sumWeight = 0;

public:
	Path(const int& N, const int& M)
		: _N(N), _M(M)
	{
		adj = new int* [N + 1];
		for (int i = 1; i <= N; i++)
		{
			adj[i] = new int[N + 1];
			for (int j = 1; j <= N; j++)
				adj[i][j] = std::numeric_limits<int>::max();
		}
		
		for (int i = 0; i < _M; i++)
		{
			int r, c, v;
			std::cin >> r >> c >> v;
			adj[r][c] = v;
		}

		node = new bool[N + 1]();
		node[1] = true;
	}

	Path& Finder(const int& here = 1)
	{
		if (here == _N)
		{
			if (minWeight > sumWeight)
				minWeight = sumWeight;
			return *this;
		}

		for (int t = 1; t <= _N; t++)
		{
			if (node[t] == false && adj[here][t] != std::numeric_limits<int>::max())
			{
				sumWeight += adj[here][t];
				node[t] = true;
				Finder(t);
				node[t] = false;
				sumWeight -= adj[here][t];
			}
		}
		return *this;
	}

	void printAdj()
	{
		for (int i = 1; i <= _N; i++)
		{
			for (int j = 1; j <= _N; j++)
			{
				std::cout << adj[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	int getMinWeight()
	{
		return minWeight;
	}
};

int main()
{
	using namespace std;
	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);

	int N, M;
	cin >> N >> M;

	cout << Path(N, M).Finder().getMinWeight();

	return 0;
}