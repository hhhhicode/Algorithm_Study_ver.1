// auto 사용
// 함수 포인터
// 동적할당 주소 반환
// uniform initialization
// direct initialization
#include <iostream>

auto* allocateMemory(const int& N)
{
	return new int[N](); // 동적할당배열 모두 0으로 초기화
}

int main() {
	using namespace std;

	unsigned N;
	cin >> N;

	auto* (*allocate_func)(const int&) { allocateMemory };

	auto* numbers{ allocate_func(N) };

	int pre, cur;
	cin >> pre;
	for (unsigned i = 1; i < N; i++)
	{
		cin >> cur;
		unsigned ix( abs(pre - cur) );  // direct initialization
		if (0 == ix || ix >= N || numbers[ix] == 1)
		{
			cout << "NO\n";
			return 0;
		}
		else
		{
			numbers[ix] = 1;
		}
		pre = cur;
	}
	cout << "YES\n";

	return 0;
}