#include <iostream>
#include <algorithm>

int main() {
	using namespace std;

	int N;
	cin >> N;

	int two_count = 0;
	int five_count = 0;
	for (int i = 2; i <= N; i++) {
		int tmp{ i };
		while (tmp % 2 == 0) {
			tmp /= 2;
			two_count++;
		}
		while (tmp % 5 == 0) {
			tmp /= 5;
			five_count++;
		}
	}

	cout << min(two_count, five_count);


	return 0;
}