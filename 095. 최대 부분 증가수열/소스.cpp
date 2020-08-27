// Ʋ�� ����

// �ִ� �κ� ���� ����(LIS) : �� ��Ҹ� �������̶� ���� �� ���̸� ����

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