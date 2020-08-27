// Top-Down, 재귀, 메모이제이션

#include <iostream>

int cutLine(const int& line)
{
	static int* memo = new int[line + 1]();

	if (line == 1) return 1;
	if (line == 2) return 2;
	if (memo[line] != 0)
		return memo[line];

	return memo[line] = cutLine(line - 1) + cutLine(line - 2);
}

int main()
{
	using namespace std;

	int N;
	cin >> N;

	cout << cutLine(N);

	return 0;
}