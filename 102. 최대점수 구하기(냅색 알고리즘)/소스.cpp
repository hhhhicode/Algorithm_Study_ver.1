// Ʋ�� ����

// �̰� �������� �� �� ������..?
// ���� �� �ȵǳ�....�Ф�



#include <iostream>
#include <algorithm>

class Quest
{
private:
	int _point;
	int _weight;

public:
	void init(const int& p, const int& w)
	{
		this->_point = p;
		this->_weight = w;
	}

	int getPoint()
	{
		return this->_point;
	}

	int getWeight()
	{
		return this->_weight;
	}

	bool operator < (const Quest& q2) const
	{
		return this->_weight < q2._weight;
	}
};

class Problem
{
private:
	int _n;
	int _timeLimit;
	int _maxPoint = 0;
	Quest* _q;
	int* _timer;

public:
	~Problem()
	{
		delete[] _q, _timer;
	}
	void solution()
	{
		init();
		//questSort();
		//����();
		knapsack();
		printMaxPoint();
	}

	void init()
	{
		std::cin >> _n >> _timeLimit;
		_timer = new int[_timeLimit + 1]();
		_q = new Quest[_n];
		for (int i = 0; i < _n; i++)
		{
			int p, w;
			std::cin >> p >> w;
			_q[i].init(p, w);
		}
	}

	/*void questSort()
	{
		std::sort(_q, _q + _n);
	}*/

	/*void ����(int s = 0, int point = 0, int weight = 0)
	{
		for (int i = s; i < _n; i++)
		{
			int therePoint = point + _q[i].getPoint();
			int  thereWeight = weight + _q[i].getWeight();
			if (thereWeight > _timeLimit)
			{
				if (_maxPoint < point)	_maxPoint = point;
				break;
			}
			else {
				����(s + 1, therePoint, thereWeight);
			}			
		}
	}*/

	void printMaxPoint()
	{
		std::cout << _timer[_timeLimit] << std::endl;
		/*for (int i = 1; i <= _timeLimit; i++)
		{
			std::cout << _timer[i] << ' ';
		}*/
	}

	void knapsack()
	{
		for (int i = 0; i < _n; i++)
		{
			for (int j = _timeLimit; j >= 1; j--)
			{
				if (0 <= j - _q[i].getWeight()) // 0 <= �� �ؾ��Ѵ�. �������, 3 - 3 == 0�϶� �Ұ��� �ϸ� �ȵǹǷ�.
				{
					int therePoint = _timer[j - _q[i].getWeight()] + _q[i].getPoint();
					if (_timer[j] < therePoint)
						_timer[j] = therePoint;
				}
			}
		}
	}
};

int main()
{
	using namespace std;

	Problem().solution();

	return 0;
}