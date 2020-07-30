#include <iostream>

int main() {
	using namespace std;
	//FILE* stream; freopen_s(&stream, "input.txt", "rt", stdin);

	int matrix[9][9];
	for (auto& i : matrix) {
		for (auto& j : i) {
			cin >> j;
		}
	}

	int avg[9] = {};
	for (int i = 0; i < 9; i++) {
		for (const auto& j : matrix[i]) {
			avg[i] += j;
		}
		avg[i] = int(avg[i] / 9.0 + 0.5); // 연산에 실수가 있어야 실수로 나온다.
	}

	
	for (int i = 0; i < 9; i++) {
		int min = 100;
		int result;
		for (const auto& j : matrix[i]) {
			int tmp = std::abs(j - avg[i]);
			if (min > tmp) {
				min = tmp;
				result = j;
			}
			else if (min == tmp) {
				if (result < j) {
					result = j;
				}
			}
		}
		cout << avg[i] << ' ' << result << endl;
	}



	return 0;
}