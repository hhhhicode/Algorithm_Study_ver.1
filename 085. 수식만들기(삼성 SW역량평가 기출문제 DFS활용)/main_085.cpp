// �� ���ÿ� ��� ��츦 ����ؾ� �Ѵٸ� for�� DFS�� ��������.

#include <iostream>
#include <limits>

class ����
{
private:
	int _N;
	int* numList;
	int* calcList;
	int pmmd[4];
	int maxResult = std::numeric_limits<int>::lowest();
	int minResult = std::numeric_limits<int>::max();

public:
	����(int n) : _N(n)
	{
		numList = new int[_N];
		calcList = new int[_N - 1];

		for (int i = 0; i < _N; i++)
		{
			std::cin >> numList[i];
		}
		for (int i = 0; i < 4; i++)
			std::cin >> pmmd[i];
	}
	~����()
	{
		delete[] numList;
	}

	����& makeCalcList(int calcListCounter = 0)
	{
		if (calcListCounter == _N - 1)
		{
			int idx = 0;
			int calcResult = numList[idx];
			for (int i = 0; i < _N - 1; i++)
			{
				switch (calcList[i])
				{
				case 0: // +
					calcResult += numList[++idx];
					break;
				case 1:	// -
					calcResult -= numList[++idx];
					break;
				case 2:	// *
					calcResult *= numList[++idx];
					break;
				case 3:	// /
					calcResult /= numList[++idx];
					break;
				}
			}
			if (maxResult < calcResult)
				maxResult = calcResult;
			if (minResult > calcResult)
				minResult = calcResult;
			return *this;
		}
		for (int i = 0; i < 4; i++)
		{
			if (pmmd[i] != 0)
			{
				pmmd[i]--;
				calcList[calcListCounter] = i;
				makeCalcList(calcListCounter + 1);
				pmmd[i]++;
			}
		}
		return *this;
	}

	void printMaxMinResult()
	{
		std::cout << maxResult << std::endl << minResult;
	}
};

int main()
{
	using namespace std;

	int N;
	cin >> N;

	����(N).makeCalcList().printMaxMinResult();

	return 0;
}