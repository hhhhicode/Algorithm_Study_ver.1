

#include <iostream>

int main() {
	using namespace std;

	int N;
	cin >> N;

	int count = 0;
	int bias = 1;
	int tmp = N;
	while (1) {
		int divided_ten{ tmp % 10 };
		if (tmp < 3) break;
		if (3 == divided_ten) {
			count += (tmp / 10 * bias) + (N % bias + 1);
		}
		else if (3 < divided_ten) {
			count += (tmp / 10 + 1) * bias;
		}
		else {
			count += (tmp / 10) * bias;
		}
		tmp /= 10;
		bias *= 10;
	}


	cout << count << endl;

	return 0;
}