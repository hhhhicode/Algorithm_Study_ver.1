// Ʋ�� ����

// ���� ���տ��� �������� �����Ѱ�?
// ------> �������� ������ �������� 'Ÿ�ӿ���' �ɷȴ�.

// ���� �˰��� : Knapsack algorithm
// ó�� ������ �ϳ��� �� ��´�. D[nowWeight] = d[nowWeight - stoneWeight] + stoneValue
// ���� ������ ������ �������Ѵ�.
// �� �������� �Ѵ�.

#include <iostream>

class Stone
{
private:
	int _val, _weight;

public:
	void setValue(const int& v, const int& w)
	{
		this->_val = v;
		this->_weight = w;
	}

	int getWeight()
	{
		return _weight;
	}
	int getValue()
	{
		return _val;
	}
};

class Sack
{
private:
	int _n, _maximumWeight;
	int* knapsack;
	Stone* stones;

public:
	void init()
	{
		std::cin >> _n >> _maximumWeight;
		stones = new Stone[_n];
		knapsack = new int[_maximumWeight + 1]();
		for (int i = 0; i < _n; i++)
		{
			int v, w;
			std::cin >> w >> v;
			stones[i].setValue(v, w);
		}
	}

	/*void choice1(int setIdx = 0, int nowValue = 0, int nowWeight = 0)
	{
		for (int idx = setIdx; idx < _n; idx++)
		{
			if (stones[idx].getWeight() + nowWeight > _maximumWeight)
			{
				if (_maxValue < nowValue)
				{
					_maxValue = nowValue;
				}
			}
			else
			{
				choice1(idx, stones[idx].getValue() + nowValue, stones[idx].getWeight() + nowWeight);

			}
		}
	}*/

	void choice2()
	{
		for (int i = 0; i < _n; i++)
		{
			int thisStoneWeight = stones[i].getWeight();
			int thisStoneValue = stones[i].getValue();
			for (int w = thisStoneWeight; w <= _maximumWeight; w++)
			{
				int thereKnapsackValue = knapsack[w - thisStoneWeight] + thisStoneValue;
				if (knapsack[w] < thereKnapsackValue)
				{
					knapsack[w] = thereKnapsackValue;
				}
			}
		}
	}

	void printMaxValue()
	{
		std::cout << knapsack[_maximumWeight];
	}

	void solution()
	{
		init();
		//choice1();
		choice2();
		printMaxValue();
	}
};



int main()
{
	using namespace std;

	Sack().solution();

	return 0;
}