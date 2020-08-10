// Ʋ�� ����
// ���� Ž��, ����,����,�����ʹ� �ٸ���.
// { 1(����1), 2(����2), 3(����3), 4(����4), ... }

// �迭�� �̿��� ����� �� Ž��
// ��� �迭�� ����� ����� ���� ��������� �ϱ� ������ index + 1 �� ����

#include <iostream>

class DFS
{
private:
	int* list;
	int N;

public:
	DFS(const int& n, int* arr)
		: N(n), list(arr)
	{}

	void ����(const int& idx = 1)
	{
		if (idx > N)
		{
			for (int i = 1; i <= N; i++)
			{
				if (list[i] == 1)
				{
					std::cout << i << ' ';
				}
			}
			std::cout << std::endl;
			return;
		}

		list[idx] = 1;
		����(idx + 1);
		list[idx] = 0;
		����(idx + 1);
	}

};



int main()
{
	using namespace std;

	int N;
	cin >> N;

	int* list = new int[N + 1]();

	DFS(N, list).����();

	return 0;
}