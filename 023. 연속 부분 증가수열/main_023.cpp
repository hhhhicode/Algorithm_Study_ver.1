// �Լ�������
// �����Ҵ� ��ȯ �Լ�
// �ּҷ� �迭 ����
#include <iostream>

int* allocateN(const int& N)
{
	return new int[N]; // �����Ҵ�� �ּҸ� ��ȯ
}

int main() {
	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);
	using namespace std;

	int N;
	cin >> N;
	int *(*funcptr)(const int&) = allocateN; //�Լ��� �������̴�. �Լ������ͷ� �Լ��� �޾Ҵ�.
	int* numbers = funcptr(N); // �Լ������͸� �����ϸ� �����Ҵ�� �ּҸ� ��ȯ�Ѵ�.

	int max_seq = 1, cur_seq = 1;
	int pre_num = 0;
	for (unsigned i = 0; i < N; i++)
	{
		cin >> *(numbers + i); // numbers�� ������, i�� �ּ�(int)+
		if (pre_num <= *(numbers + i))
		{			
			cur_seq++;
		}
		else
		{
			cur_seq = 1;
		}

		if (max_seq < cur_seq)
			max_seq = cur_seq;
		pre_num = *(numbers + i);
	}

	cout << max_seq;
	
	return 0;
}