
// 각 요소는 자신보다 큰 수들의 개수
// 큰 수가 값을 결정하므로, 큰 수 부터 하나씩 놓는다.
// 자신보다 큰 것은 count++ 하고, count가 값과 ==이면 작은것들 다음에 inject 한다.

#include <iostream>

int main() {
	using namespace std;

	int N;
	cin >> N;

	int* num_list = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> num_list[i];
	}

	int end = N - 1;
	int start = 0;
	// 모두 0으로 초기화
	int* sequence = new int[N]();
	
	for (int i = end; start <= i; i--) {
		int high_values = num_list[i];
		int number = i + 1;
		int count = 0;

		for (int j = start; j <= end; j++) {
			// 자신보다 큰 수들의 개수가 == 되면 j포함 전부 앞으로 민다
			if (count == high_values) {
				for (int k = end; j < k; k--) {
					sequence[k] = sequence[k - 1]; // index 관리좀 잘하자 제발 제발 제발 제발
				}
				sequence[j] = number;
				break;
			}

			if (number < sequence[j]) {
				count++;
			}
		}
	}

	for (int i = start; i <= end; i++) {
		cout << sequence[i] << ' ';
	}

	delete[] num_list, sequence;
	return 0;
}