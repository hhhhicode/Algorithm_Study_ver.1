#include <iostream>

int main() {
	using namespace std;

	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);

	int N, M;
	cin >> N;
	int* N_list = new int[N];
	for (int n = 0; n < N; n++) {
		cin >> N_list[n];
	}
	cin >> M;
	int* M_list = new int[M];
	for (int m = 0; m < M; m++) {
		cin >> M_list[m];
	}

	int nIdx = 0, mIdx = 0;
	while (true) {
		if (nIdx == N || mIdx == M)
			break;

		if (N_list[nIdx] < M_list[mIdx]) {
			cout << N_list[nIdx] << ' ';
			nIdx++;
		}
		else {
			cout << M_list[mIdx] << ' ';
			mIdx++;
		}
	}

	for (; nIdx < N; nIdx++) {
		cout << N_list[nIdx] << ' ';
	}
	for (; mIdx < M; mIdx++) {
		cout << M_list[mIdx] << ' ';
	}

	return 0;
}