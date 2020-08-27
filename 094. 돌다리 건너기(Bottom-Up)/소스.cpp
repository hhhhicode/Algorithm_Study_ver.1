// Bottom-Up, std::unique_ptr

#include <iostream>

int main()
{
	using namespace std;

	int N;
	cin >> N;

	std::unique_ptr<int[]> unique_stone(new int[N + 1]());
	
	unique_stone[0] = 1;
	unique_stone[1] = 2;
	
	for (int i = 2; i <= N; i++)
	{
		unique_stone[i] = unique_stone[i - 1] + unique_stone[i - 2];
	}

	cout << unique_stone[N];

	return 0;
}