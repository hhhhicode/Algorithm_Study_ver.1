#include "subage.h"

int subAge(const int* age, const int& N)
{
	using namespace std;

	int max = numeric_limits<int>::min();
	int min = numeric_limits<int>::max();

	for (unsigned i = 0; i < N; i++)
	{
		if (max < age[i])
			max = age[i];
		if (min > age[i])
			min = age[i];
	}

	return max - min;
}