// check = _S > _E ? new bool[_S + 1] : new bool[_E + 1];�� �ߴµ� ���� �޸𸮿��� ������ �����. �����Ҷ� �����ΰ� ���⵵ �ϴ�... �𸣰ڴ�.
// �ٽ� �� �� �õ��� ���� �� �� ���ٰ� �����Ѵ�.

// +1, -1, +5 �̵� �����ϴ�.
// �̵�Ƚ���� �ּҰ� �ǵ���.
// distance�� check�� check�迭 �ϳ��� �����Ͽ� ����� �� �ִ�.

// std::unique_ptr<T> var(T*); ���

#include <iostream>
#include <queue>

class Cowboy
{
private:
	int _S, _E;
	int move[3]{ -1,1,5 };
	int distance[10001]{ 0 };
	bool check[10001]{ 0 };

public:
	Cowboy(const int& S, const int& E)
		: _S(S), _E(E)
	{
		check[_S] = true;
		// unique_ptr �̷��� ���ϱ� ���� ������ �־���...�Ф�
		//std::unique_ptr<bool> up_check(check);
	}
	~Cowboy()
	{
	}

	// ������ �����Ҽ��� ���ϱ޼������� ����� ���� �����ϹǷ� 
	// ���͸��� �� ���ִ� ���� ���� �� ����.
	void BFS()
	{
		std::queue<int> q;
		int here;
		int there;
		q.push(_S);
		while (!q.empty())
		{
			here = q.front();	q.pop();			

			for (int i = 0; i < 3; i++)
			{
				there = here + move[i];
				if (check[there] != true && 1 <= there && there <= 10000)
				{
					q.push(there);
					check[there] = true;
					distance[there] = distance[here] + 1;
					if (there == _E)
					{
						std::cout << distance[there];
						return;
					}
				}
			}
		}
		return;
	}

	void printCheck()
	{
		int len = _S > _E ? _S : _E;
		for (int i = 0; i <= len; i++)
			std::cout << check[i] << ' ';
	}
};

int main()
{
	using namespace std;

	int S, E;
	cin >> S >> E;

	Cowboy C(S, E);  C.BFS();

	return 0;
}