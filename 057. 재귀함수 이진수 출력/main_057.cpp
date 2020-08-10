#include <iostream>

void binaryRecursive(const int& N)
{
	if (N == 0) return;
	binaryRecursive(N / 2);
	std::cout << N % 2;
}

int main()
{
	using namespace std;

	int N;
	cin >> N;
	binaryRecursive(N);

	return 0;
}