#include <iostream>

class DFS
{
private:
	int N;
	int M;
	int* list;
	int* mul;
	int count;

public:
	DFS(int N, int M)
		: N(N), M(M), count(0)
	{
		list = new int[N];
		for (int i = 0; i < N; i++)
		{
			std::cin >> list[i];
		}
		mul = new int[N];
	}
	~DFS()
	{
		delete[] list, mul;
	}

	void searchPath(const int& idx = 0)
	{
		if (idx >= N)
		{
			int result = 0;
			for (int i = 0; i < N; i++)
			{
				result += list[i] * mul[i];
			}
			if (result == M)
			{
				count++;
			}
			return;
		}
		mul[idx] = 1;
		searchPath(idx + 1);
		mul[idx] = -1;
		searchPath(idx + 1);
		mul[idx] = 0;
		searchPath(idx + 1);
	}

	int getCount()
	{
		return count;
	}
};

int main()
{
	using namespace std;

	int N, M;
	cin >> N >> M;

	DFS jj(N, M);
	jj.searchPath();
	cout << jj.getCount();
	



	return 0;
}