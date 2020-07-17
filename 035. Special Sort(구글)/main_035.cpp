#include <iostream>

void Swap(int& a, int& b) {
	int tmp{ a };
	a = std::move(b);
	b = tmp;
}

int main() {
	using namespace std;

	int N;
	cin >> N;
	int* num_list = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> num_list[i];
	}

	int start = 0, end = N - 1;
	for (int i = end; i >= start; i--) {
		for (int j = start; j < i; j++) {
			if (0 < num_list[j] && num_list[j + 1] < 0)
				Swap(num_list[j], num_list[j + 1]);
		}
	}

	for (int i = start; i <= end; i++) {
		cout << num_list[i] << ' ';
	}

	delete[] num_list;
	return 0;
}