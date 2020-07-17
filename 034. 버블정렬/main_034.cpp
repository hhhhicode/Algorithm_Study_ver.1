// ��������
// � ������ ���� ���� �� �ڷ� �������� �о� �״� �˰����̴�.
// ���� ū ���� �� �ڷ� �������� �δ�.
// ���� ��ü�� ������ ���� �ʴ�.

// std::move()
#include <iostream>

void Swap(int &a, int &b) {
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

	for (int i = 0; i < N; i++) {
		cout << num_list[i] << ' ';
	}
	cout << endl;

	for (int i = N - 1; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			if (num_list[j + 1] < num_list[j])
				Swap(num_list[j + 1], num_list[j]);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << num_list[i] << ' ';
	}
	cout << endl;


	return 0;
}