// 매 선택에 모든 경우를 고려해야 한다면 for로 DFS를 접근하자.

#include <iostream>
#include <limits>

class 수식
{
private:
	int _N;
	int* numList;
	int* calcList;
	int pmmd[4];
	int maxResult = std::numeric_limits<int>::lowest();
	int minResult = std::numeric_limits<int>::max();

public:
	수식(int n) : _N(n)
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
	~수식()
	{
		delete[] numList;
	}

	수식& makeCalcList(int calcListCounter = 0)
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

	수식(N).makeCalcList().printMaxMinResult();

	return 0;
}