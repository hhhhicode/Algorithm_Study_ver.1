// Bottom-up은 작은것으로부터 큰것으로 풀어간다.



#include <iostream>

int main()
{
	using namespace std;

	int N;
	cin >> N;

	int* line = new int[N + 1]();
	line[1] = 1;
	line[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		line[i] = line[i - 1] + line[i - 2];
	}

	cout << line[N];

	return 0;
}