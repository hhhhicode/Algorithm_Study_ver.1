#include <iostream>


int main() {
	using namespace std;

	int N, M;
	cin >> N >> M;
	int* list = new int[N];

	int bottom = 1;
	int top = 0;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		top += list[i];
	}

	int result = 0;
	while (true) {
		if (bottom > top)	break;
		
		int mid = (bottom + top) / 2;
		int sum = 0, cnt = 1;
		for (int i = 0; i < N; i++) {
			if (sum + list[i] <= mid) {
				sum += list[i];
			}
			else {
				cnt++;
				sum = 0;
				sum += list[i];
			}
		}
		if (cnt <= M) {
			top = mid - 1;
			result = mid;
		}
		else {
			bottom = mid + 1;
		}
	}

	cout << result;

	delete[] list;
	return 0;
}