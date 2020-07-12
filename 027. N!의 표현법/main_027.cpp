// �Ҽ����� ������ �̷���� -> ���μ� ���� ����
// uniform initialization
// �����Ҵ�迭 0���� �ʱ�ȭ
#include <iostream>

/* ���丮���� �� �ʿ䰡 ������. N! = 1*2*3*4*5*...*N �̹Ƿ� 1~N���� ���μ����� ���ָ� �ȴ�.
	���μ����ؿ� ���� ���ذ� �����Ͽ���.
	1. N! = 1*2*3*4*5*...*N �̹Ƿ� 1~N���� ���μ����� ���ָ� �ȴ�.
	2. ���� �� ���� �Ѱ���� ������ ������ ������ divisor�� ��� �Ҽ��̴�.
	3. ���μ����ظ� �Ͽ��� ������ 0�� �ƴ� ���� �Ҽ��̴�.
*/
//unsigned long long factorialN(int N)
//{
//	if (N == 1) return 1;
//	return N * factorialN(N - 1);
//}

void ���μ�����(const int& N, int* &check)
{
	using namespace std;

	cout << N << "! = ";
	for (int n = 2; n <= N; n++)
	{
		int tmp = n;
		int divisor{ 2 };
		while (tmp != 1)
		{
			if (tmp % divisor == 0)
			{
				// ���� �� ���� �Ѱ���� ������ ������ ������ divisor�� ��� �Ҽ��̴�.
				tmp /= divisor;
				check[divisor]++;
			}
			else
			{
				divisor++;
			}
		}
	}
}

int main() {
	using namespace std;

	int N;
	cin >> N;

	// N! = N * (N - 1) * ... �̴� ���� ū �μ��� N�ϰ��̴�.
	int* check = new int[N + 1](); // 0���� �ʱ�ȭ
	���μ�����(N, check);

	for (int i = 2; i <= N; i++)
	{
		// ���μ����ظ� �Ͽ��� ������ 0�� �ƴ� ���� �Ҽ��̴�.
		if (check[i] != 0)
		{
			cout << check[i] << ' ';
		}
	}

	return 0;
}