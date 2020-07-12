#include "add.h"

void add(const int& N)
{
	using namespace std;

	int result{ 1 };
	cout << "1";
	for (unsigned i = 2; i <= N / 2; i++)
	{
		if (N % i == 0)
		{
			cout << " + " << i;
			result += i;
		}
	}
	cout << " = " << result;
}