#include <iostream>

int main() {
	using namespace std;

	int N;
	cin >> N;

	int n = 1;
	int nSum = 1;
	int cnt = 0;
	while (true) {
		if (N <= nSum)	break;
		n++;
		nSum += n;
		int m = (N - nSum) / n;
		if (m * n + nSum == N) {
			for (int i = 1; i < n; i++) {
				cout << m + i << " + ";
			}
			cout << m + n << " = " << N << endl;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}