//▣ 입력설명 첫 줄에 자연수의 개수 N(3 <= N <= 100)이 주어지고, 그 다음 줄에 N개의 자연수가 주어진다.
//각 자연수의 크기는 10, 000, 000를 넘지 않는다.
//▣ 출력설명 자릿수의 합이 최대인 자연수를 출력한다.자리수의 합이 최대인 자연수가 여러개인 경우 그
//중 값이 가장 큰 값을 출력합니다.

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