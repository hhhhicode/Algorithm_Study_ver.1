//�� �Է¼��� ù �ٿ� �ڿ����� ���� N(3 <= N <= 100)�� �־�����, �� ���� �ٿ� N���� �ڿ����� �־�����.
//�� �ڿ����� ũ��� 10, 000, 000�� ���� �ʴ´�.
//�� ��¼��� �ڸ����� ���� �ִ��� �ڿ����� ����Ѵ�.�ڸ����� ���� �ִ��� �ڿ����� �������� ��� ��
//�� ���� ���� ū ���� ����մϴ�.

#include "my_func.h"

int main() {
	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);
	using namespace std;

	unsigned N;
	cin >> N;

	int number;
	int max = numeric_limits<int>::lowest();
	int result;
	for (unsigned i = 0; i < N; i++)
	{
		cin >> number;
		int sum = digit_sum(number);
		if (sum > max)
		{
			max = sum;
			result = number;
		}
		else if (sum == max)
		{
			if (result < number)
			{
				result = number;
			}
		}
	}

	cout << result;

	return 0;
}