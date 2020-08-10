#include <iostream>

class Path
{
private:
	int _N;
	int _M;
	int count = 0;
	int** adj;
	bool* node;

public:
	Path(const int& N, const int& M)
		: _N(N), _M(M)
	{
		adj = new int* [N + 1];
		for (int i = 0; i < N + 1; i++)
			adj[i] = new int[N + 1]();

		for (int i = 0; i < M; i++)
		{
			int r, c;
			std::cin >> r >> c;
			adj[r][c] = 1;
		}
		node = new bool[N + 1]();
		node[1] = 1;
	}

	Path& Finder(const int& here = 1)
	{
		if (here == _N)
		{
			count++;
			return *this;
		}
		
		for (int c = 1; c <= _N; c++)
		{
			if (node[c] == 0 && adj[here][c] == 1)
			{
				node[c] = 1;
				Finder(c);
				node[c] = 0;
			}
		}
		return *this;
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

	Path(N, M).Finder().printCount();

	return 0;
}