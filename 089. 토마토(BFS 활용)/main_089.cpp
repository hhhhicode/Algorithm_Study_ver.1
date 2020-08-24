#include <iostream>
#include <queue>
#include <tuple>

int main()
{
	using namespace std;
	//FILE* s; freopen_s(&s, "input.txt", "rt", stdin);

	int M, N;
	cin >> M >> N;

	std::queue<std::tuple<int, int> > q;
	int** box = new int* [N + 1];

	for (int i = 1; i < N + 1; i++)
	{
		box[i] = new int[M + 1]();
		for (int j = 1; j < M + 1; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
			{
				box[i][j] = 0;
				q.push(std::tuple(i, j));
			}
		}
	}

	int xl[]{ -1,0,1,0 };
	int yl[]{ 0,1,0,-1 };
	while (!q.empty())
	{
		auto [hereX, hereY] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int thereX{ hereX + xl[i] };
			int thereY{ hereY + yl[i] };
			if (1 <= thereX && thereX <= N && 1 <= thereY && thereY <= M)
			{
				if (box[thereX][thereY] == 0)
				{
					box[thereX][thereY] = box[hereX][hereY] + 1;
					q.push(tuple(thereX, thereY));
				}
			}
		}
	}

	int maxDay = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (box[i][j] == 0)
			{
				cout << -1;
				exit(0);
			}
			if (maxDay < box[i][j])
				maxDay = box[i][j];
		}
	}
	cout << maxDay;

	for (int i = 1; i < N + 1; i++)
		delete[] box[i];
	delete[] box;

	return 0;
}