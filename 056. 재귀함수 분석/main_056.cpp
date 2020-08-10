#include <iostream>

void recursiveFunction(const int& num)
{
	static int number = 1;
	if (number > num)	return;

	std::cout << number++ << ' ';
	recursiveFunction(num);
}

int main()
{
	using namespace std;

	int N;
	cin >> N;
	recursiveFunction(N);

	return 0;
}