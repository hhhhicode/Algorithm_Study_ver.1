// Ʋ�� ����
// ���������� ���丸 �˰� ������ ������
// ���� ������ �Ѵ�.

// ���� ������ '������ȸ'�̴�.
// ����, ������ ��� ������ �Ŀ� Work

#include <iostream>

class MergeSort
{
private:
	int N;
	int* list;
	int* tmp;

public:
	MergeSort(const int& N)
		: N(N)
	{
		list = new int[N];
		for (int i = 0; i < N; i++)
		{
			std::cin >> list[i];
		}
		tmp = new int[N];
	}
	~MergeSort()
	{
		delete[] list, tmp;
	}

	void runMergeSort(const int& lt, const int& rt)
	{
		// ������ �Ϲ������� bottom < top �� ����Ѵ�.
		if (lt < rt)
		{
			int mid = (lt + rt) / 2;
			int lP = lt;
			int rP = mid + 1;
			int tP = lt;
			// �����ϱ�
			runMergeSort(lt, mid);
			runMergeSort(mid + 1, rt);

			// ��� ��忡�� �ϴ� ��
			while (lP <= mid && rP <= rt)
			{
				if (list[lP] < list[rP])
				{
					tmp[tP++] = list[lP++];
				}
				else
				{
					tmp[tP++] = list[rP++];
				}
			}
			while (lP <= mid)
			{
				tmp[tP++] = list[lP++];
			}
			while (rP <= rt)
			{
				tmp[tP++] = list[rP++];
			}
			for (int i = lt; i <= rt; i++)
			{
				list[i] = tmp[i];
			}
		}
	}

	void printList()
	{
		for (int i = 0; i < N; i++)
		{
			std::cout << list[i] << ' ';
		}
	}
};

int main()
{
	using namespace std;

	int N;
	cin >> N;
	MergeSort m(N);
	m.runMergeSort(0, N - 1);
	m.printList();

	return 0;
}