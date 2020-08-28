#include <iostream>

int main()
{
	using namespace std;

	int N;
	cin >> N;
	
	auto u_p = std::make_unique<int[]>(N + 1);
	for (int i = 1; i < N + 1; i++)
		cin >> u_p[i];

	auto count = std::make_unique<int[]>(N + 1);
	for (int i = 1; i < N + 1; i++)
		count[i] = 1;

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j != i; j++)
		{
			if (u_p[j] < u_p[i])
			{
				if (count[i] < count[j] + 1)
					count[i] = count[j] + 1;
			}
		}
	}

	int maxCount = 0;
	for (int i = 1; i < N + 1; i++)
		if (maxCount < count[i]) maxCount = count[i];

	cout << maxCount;

	return 0;
}