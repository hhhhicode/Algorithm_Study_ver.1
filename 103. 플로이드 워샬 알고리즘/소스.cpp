// Ʋ�� ����

// �÷��̵� ���� �˰����� ��� �������� ��� �������� ���� �ִܰŸ��� ���Ѵ�.
// Knapsack �˰���� ������ �ִ�.

// 1. adj�� �ʱ� matrix�� �Ѵ�. i�� ������̸� j�� �������̴�.
// 2. min(dis[i][j], dis[i][k] + dis[k][j]), �������Ǵ� ������ Knapsack�� ��Ҵ�.
// k�� 4���, 1 -> 2, 1 -> 3, 2 -> 1, 2 -> 3 �� ��� �̵��� 4�� ��带 ����ϰ� �Ǵ� ���̹Ƿ�
// 1 -> 3 �̵��� ��ǥ���� ��
// 1 -> 2 -> 3 �̵��� �ּҿ��ٰ� 
// 2 -> 3�� 2 -> 4 -> 3���� ������ �Ǿ��ٰ� ġ��
// 1 -> 2 -> 4 -> 3�� �ǹǷ� 1 -> 3 �� ������ �ȴ�.?

// ������ �ȴٸ�, k ��带 ���İ��°ɷ� ���� �ȴٴ� ���̴�. 
// 1 <= k <= n �̴ϱ� n���� ��� ���� ���� ���� n���� ��带 ���İ��� ���� ��� ����� ���� �ȴ�.

#include <iostream>
#include <vector>
#include <limits>

class Graph
{
private:
	int _n, _m;
	std::vector< std::vector<int> > weights;

public:
	void solution()
	{
		init();
		relaxWeight();
		printWeights();
	}
	void init()
	{
		std::cin >> _n >> _m;
		weights.assign(_n + 1, std::vector<int>(_n + 1, 20000)); // 2���迭�� �����

		int a, b, w;
		for (int i = 0; i < _m; i++)
		{
			std::cin >> a >> b >> w;
			weights[a][b] = w;
		}
	}

	void relaxWeight()
	{
		for (int k = 1; k <= _n; k++)
		{
			for (int i = 1; i <= _n; i++)
			{
				for (int j = 1; j <= _n; j++)
				{
					if (weights[i][j] > weights[i][k] + weights[k][j])
					{
						weights[i][j] = weights[i][k] + weights[k][j];
					}
					else if (i == j)
						weights[i][j] = 0;
				}
			}
		}
	}

	void printWeights()
	{
		for (int i = 1; i <= _n; i++)
		{
			for (int j = 1; j <= _n; j++)
			{
				if (weights[i][j] == 20000)
				{
					std::cout << "M ";
					continue;
				}
				std::cout << weights[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	using namespace std;

	Graph().solution();

	return 0;
}