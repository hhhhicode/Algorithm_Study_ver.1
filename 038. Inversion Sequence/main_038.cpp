
// �� ��Ҵ� �ڽź��� ū ������ ����
// ū ���� ���� �����ϹǷ�, ū �� ���� �ϳ��� ���´�.
// �ڽź��� ū ���� count++ �ϰ�, count�� ���� ==�̸� �����͵� ������ inject �Ѵ�.

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
	// ��� 0���� �ʱ�ȭ
	int* sequence = new int[N]();
	
	for (int i = end; start <= i; i--) {
		int high_values = num_list[i];
		int number = i + 1;
		int count = 0;

		for (int j = start; j <= end; j++) {
			// �ڽź��� ū ������ ������ == �Ǹ� j���� ���� ������ �δ�
			if (count == high_values) {
				for (int k = end; j < k; k--) {
					sequence[k] = sequence[k - 1]; // index ������ ������ ���� ���� ���� ����
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