// �� �Է¼��� �Է������� input.txt�� �Ѵ�.
//ù �ٿ� �ڿ��� N(2 <= N <= 100)�� �Էµǰ�, �� ���� �ٿ� N���� ���̰� �Էµȴ�.
// �� ��¼��� ��������� output.txt�� �Ѵ�.
//ù �ٿ� �ִ� �������̸� ����մϴ�.

#include "subage.h"

int main()
{
	FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);
	using namespace std;

	int N;
	cin >> N;

	int* age = new int[N];
	for (unsigned i = 0; i < N; i++)
	{
		cin >> age[i];
	}

	cout << subAge(age, N);

	return 0;
}