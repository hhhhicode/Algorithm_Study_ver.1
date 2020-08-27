// 틀린 문제

// 최대 부분 증가 수열(LIS) : 각 요소를 마지막이라 했을 때 길이를 저장

#include <iostream>

int main()
{
	using namespace std;

	int N;
	cin >> N;

	auto u_p = std::make_unique<int[]>(N);
	for (int i = 0; i < N; i++)
		cin >> u_p[i];

	auto count = std::make_unique<int[]>(N);
	for (int i = 0; i < N; i++)
		count[i] = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (u_p[j] < u_p[i])
			{
				if (count[j] + 1 > count[i])
				{
					count[i] = count[j] + 1;
				}
			}
		}
	}

	int maxCount = 0;
	for (int i = 0; i < N; i++)
	{
		if (maxCount < count[i])
			maxCount = count[i];
	}
	cout << maxCount;

	return 0;
}