// Ʋ�� ����

// ���(����) ����

// ��� Adj�� pQ�� �ְ� ������, ���� ��� 8->9�� �����ϰ� 9->8�� �ߺ� �����ϰ� �ȴ�.(�� �ʵ� ���õ��� ���� ��Ȳ���� weight�� ���� ���)
// �׷��Ƿ�, ��带 �ϳ� �߰��� �� ���� Adj�� push ����� �Ѵ�.

#include <iostream>
#include <queue>
#include <vector>

class Node
{
public:
	bool check = false;
};

class Adj
{
public:
	int n1, n2;
	int weight;

	Adj& setN1(int n)
	{
		n1 = n;
		return *this;
	}
	Adj& setN2(int n)
	{
		n2 = n;
		return *this;
	}
	Adj& setWeight(int w)
	{
		weight = w;
		return *this;
	}
	
	// <�� <�� �����ϸ� ���� �״���� ��Ȳ == max��
	// <�� >�� �����ϸ� �ݴ� ��Ȳ == min��
	bool operator < (const Adj& b) const
	{
		return this->weight > b.weight;
	}
};

class PathFinder
{
private:
	int _V, _E;
	int sumWeight = 0;
	Node* node;
	std::vector<Adj>* vec;
	std::priority_queue<Adj> pQ;

	bool isCheck(const Adj& a)
	{
		if (node[a.n2].check == false)
			return false;
		else return true;
	}

	void checkNode(const Adj& a)
	{
		node[a.n2].check = true;
	}

public:
	PathFinder(const int& v, const int& e)
		: _V(v), _E(e)
	{
		node = new Node[_V + 1];
		vec = new std::vector<Adj>[_V + 1];

		for (int i = 0; i < _E; i++)
		{
			int n1, n2, weight;
			std::cin >> n1 >> n2 >> weight;
			vec[n1].push_back(Adj()
				.setN1(n1)
				.setN2(n2)
				.setWeight(weight));
			vec[n2].push_back(Adj()
				.setN1(n2)
				.setN2(n1)
				.setWeight(weight));
		}

		pQ.push(Adj()
			.setN1(0)
			.setN2(1)
			.setWeight(0));
	}

	

	PathFinder& Finder()
	{
		while (!pQ.empty())
		{
			Adj a = pQ.top();	pQ.pop();
			if (!isCheck(a))
			{
				sumWeight += a.weight;
				checkNode(a);
				for (int i = 0; i < vec[a.n2].size(); i++)
				{
					pQ.push(vec[a.n2][i]);
				}
			}
		}
		return *this;
	}

	void printSumWeight()
	{
		std::cout << sumWeight << std::endl;
	}
};

int main()
{
	using namespace std;

	int V, E;
	cin >> V >> E;

	PathFinder(V, E).Finder().printSumWeight();

	return 0;
}