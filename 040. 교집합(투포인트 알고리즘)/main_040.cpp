#include <iostream>

void swap(int& a, int& b) {
	int tmp{ a };
	a = std::move(b);
	b = tmp;
}

void sort(int list[], int len) {
	for (int i = 0; i < len - 1; i++) {
		int minIdx = i;
		for (int j = i + 1; j < len; j++) {
			if (list[j] < list[minIdx]) {
				minIdx = j;
			}
		}
		swap(list[i], list[minIdx]);
	}
}

int main() {
	using namespace std;

	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);

	int N, M;
	cin >> N;
	int* nList = new int[N];
	for (int i = 0; i < N; i++)
		cin >> nList[i];
	cin >> M;
	int* mList = new int[M];
	for (int i = 0; i < M; i++)
		cin >> mList[i];

	sort(nList, N);
	sort(mList, M);

	int nPoint = 0, mPoint = 0;
	while (true) {
		if (nPoint == N || mPoint == M) {
			break;
		}

		if (nList[nPoint] == mList[mPoint]) {
			cout << nList[nPoint] << ' ';
			nPoint++;	mPoint++;
			continue;
		}
		nList[nPoint] < mList[mPoint] ? nPoint++ : mPoint++;
	}

	delete[] nList, mList;
	return 0;
}