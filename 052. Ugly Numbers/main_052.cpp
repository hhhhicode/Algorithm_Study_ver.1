// 소인수분해 시 2, 3, 5로만 이루어진 수를 Ugly Number라고 한다.
// 2, 3, 5로만 이루어진 수는 2, 3, 5 끼리의 배수이다.

#include <iostream>

int main() {
	using namespace std;

	int N;
	cin >> N;
	int ugly_list[1501];

	int two_point	= 1;
	int three_point = 1;
	int five_point	= 1;
	ugly_list[1]	= 1;
	int idx			= 2;
	while (idx != 1501) {

		int  min = 2 * ugly_list[two_point] <= 3 * ugly_list[three_point] ? 2 * ugly_list[two_point] : 3 * ugly_list[three_point];
		min = min <= 5 * ugly_list[five_point] ? min : 5 * ugly_list[five_point];

		ugly_list[idx] = min;
		// 1, 2, 3, 5로만 소인수분해 되어야 하기 때문에 uglyNumber의 숫자에 2, 3, 5를 곱하여 구한다.
		// list에 넣어도 될듯?? 중복x인 곳이면 어디든..?
		if (min == 2 * ugly_list[two_point]) {
			two_point++;
		}
		if (min == 3 * ugly_list[three_point]) {
			three_point++;
		}
		if (min == 5 * ugly_list[five_point]) {
			five_point++;
		}
		//cout << ugly_list[idx] << endl;
		idx++;
	}

	cout << ugly_list[N];

	return 0;
}