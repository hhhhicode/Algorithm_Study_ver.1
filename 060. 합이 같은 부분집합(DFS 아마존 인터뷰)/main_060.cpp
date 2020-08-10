// exit(0); �κ��� ������� ���ϴ�. �׳� ���� �÷ο츦 �����ϱ� �����. 
// �˱� ���� �� �� �ֵ��� �غ���.

#include <iostream>

class DFS
{
private:
	int N;
	int* arr;
	int* numList;

public:
	DFS(const int& N)
		: N(N)
	{
		arr = new int[N];
		numList = new int[N];
		for (int i = 0; i < N; i++)
		{
			std::cin >> numList[i];
		}
	}
	~DFS()
	{
		delete[] arr;
	}

	void searchEqualSum(const int idx = 0)
	{
		if (idx >= N)
		{
			int sum0 = 0;
			int sum1 = 0;
			for (int i = 0; i < N; i++)
			{
				if (arr[i] == 0) sum0 += numList[i];
				if (arr[i] == 1)sum1 += numList[i];
			}
			if (sum0 == sum1)
			{
				std::cout << "YES";
				exit(0);
			}
			return;
		}
		arr[idx] = 1;
		searchEqualSum(idx + 1);
		arr[idx] = 0;
		searchEqualSum(idx + 1);
	}
};

int main()
{
	using namespace std;

	int N;
	cin >> N;

	DFS(N).searchEqualSum();
	cout << "NO";

	return 0;
}