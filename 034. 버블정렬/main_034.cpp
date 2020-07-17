// 버블정렬
// 어떤 로직에 의한 값을 맨 뒤로 차곡차곡 밀어 쌓는 알고리즘이다.
// 가장 큰 수를 맨 뒤로 차곡차곡 민다.
// 정렬 자체의 성능은 좋지 않다.

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