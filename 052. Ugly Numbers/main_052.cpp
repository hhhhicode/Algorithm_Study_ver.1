// ���μ����� �� 2, 3, 5�θ� �̷���� ���� Ugly Number��� �Ѵ�.
// 2, 3, 5�θ� �̷���� ���� 2, 3, 5 ������ ����̴�.

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
		// 1, 2, 3, 5�θ� ���μ����� �Ǿ�� �ϱ� ������ uglyNumber�� ���ڿ� 2, 3, 5�� ���Ͽ� ���Ѵ�.
		// list�� �־ �ɵ�?? �ߺ�x�� ���̸� ����..?
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