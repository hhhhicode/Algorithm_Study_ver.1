#include "addLoad.h"

void addLoad(const int& A, const int& B)
{
	using namespace std;
	int tmp{ A };
	int result = 0;
	while (tmp <= B)
	{
		if (tmp != B)
		{
			result += tmp;
			cout << tmp++ << " + ";
		}
		else
		{
			result += tmp;
			cout << tmp++ << " = " << result;
		}
	}

	return;
}