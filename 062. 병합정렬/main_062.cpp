// 틀린 문제
// 병합정렬의 개념만 알고 구현을 몰랐음
// 구현 익혀야 한다.

// 병합 정렬은 '후위순회'이다.
// 왼쪽, 오른쪽 모두 내려간 후에 Work

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
		// 범위는 일반적으로 bottom < top 을 사용한다.
		if (lt < rt)
		{
			int mid = (lt + rt) / 2;
			int lP = lt;
			int rP = mid + 1;
			int tP = lt;
			// 분할하기
			runMergeSort(lt, mid);
			runMergeSort(mid + 1, rt);

			// 모든 노드에서 하는 일
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