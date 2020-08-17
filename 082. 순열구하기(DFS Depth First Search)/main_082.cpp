#include <iostream>

class List
{
private:
	int _N, _R;
	int count = 0;
	int* numList;
	int* result;
	bool* check;

public:
	List(int n, int r) : _N(n), _R(r)
	{
		numList = new int[_N];
		result = new int[_R]();
		check = new bool[_N]();
		for (int i = 0; i < _N; i++)
			std::cin >> numList[i];
	}

	List& DFS(int n = 0)
	{
		if (n == _R)
		{
			for (int i = 0; i < _R; i++)
			{
				std::cout << result[i] << ' ';
			}
			std::cout << std::endl;
			count++;
			return *this;
		}

		for (int i = 0; i < _N; i++)
		{
			if (check[i] == false)
			{
				check[i] = true;
				result[n] = numList[i];
				DFS(n + 1);
				check[i] = false;
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

	int N, R;
	cin >> N >> R;

	List(N, R).DFS().printCount();

	return 0;
}