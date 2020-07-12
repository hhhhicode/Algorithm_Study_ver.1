// 소수들의 곱으로 이루어짐 -> 소인수 분해 문제
// uniform initialization
// 동적할당배열 0으로 초기화
#include <iostream>

/* 팩토리얼을 할 필요가 없었다. N! = 1*2*3*4*5*...*N 이므로 1~N까지 소인수분해 해주면 된다.
	소인수분해에 대한 이해가 부족하였다.
	1. N! = 1*2*3*4*5*...*N 이므로 1~N까지 소인수분해 해주면 된다.
	2. 작은 값 부터 한계까지 나누기 때문에 나누는 divisor은 모두 소수이다.
	3. 소인수분해를 하였기 때문에 0이 아닌 것은 소수이다.
*/
//unsigned long long factorialN(int N)
//{
//	if (N == 1) return 1;
//	return N * factorialN(N - 1);
//}

void 소인수분해(const int& N, int* &check)
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
				// 작은 값 부터 한계까지 나누기 때문에 나누는 divisor은 모두 소수이다.
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

	// N! = N * (N - 1) * ... 이니 가장 큰 인수는 N일것이다.
	int* check = new int[N + 1](); // 0으로 초기화
	소인수분해(N, check);

	for (int i = 2; i <= N; i++)
	{
		// 소인수분해를 하였기 때문에 0이 아닌 것은 소수이다.
		if (check[i] != 0)
		{
			cout << check[i] << ' ';
		}
	}

	return 0;
}