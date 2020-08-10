#include <iostream>

class Adj
{
private:
	int N;
	int M;
	int** matrix;

public:
	Adj(const int& N, const int& M)
		: N(N), M(M)
	{
		matrix = new int* [N + 1];
		for (int i = 0; i < N + 1; i++)
		{
			matrix[i] = new int[N + 1]();
		}
		for (int i = 0; i < M; i++)
		{
			int r, c, value;
			std::cin >> r >> c >> value;
			matrix[r][c] = value;
		}
	}
	~Adj()
	{
		for (int i = 1; i <= N; i++)
			delete[] matrix[i];
		delete[] matrix;
	}

	void printMatrix()
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				std::cout << matrix[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	using namespace std;
	FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);

	int N, M;
	cin >> N >> M;

	Adj run(N, M);
	run.printMatrix();

	return 0;
}