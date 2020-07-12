// ▣ 입력설명 입력파일은 input.txt로 한다.
//첫 줄에 자연수 N(2 <= N <= 100)이 입력되고, 그 다음 줄에 N개의 나이가 입력된다.
// ▣ 출력설명 출력파일은 output.txt로 한다.
//첫 줄에 최대 나이차이를 출력합니다.

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