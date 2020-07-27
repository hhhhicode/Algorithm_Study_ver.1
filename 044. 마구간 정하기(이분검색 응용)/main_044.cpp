// 모르겠다.

// 배치된 말들의 거리를 구하려 하지말고, 거리 만큼 말들을 한마리씩 배치해보고 정해진 말 숫자만큼 안되면, 다른 거리를 선택하는 쪽으로 하라.

#include <iostream>

int cmp(const void* a, const void* b) {
	if (*(const int*)a < *(const int*)b) return -1;
	if (*(const int*)a > * (const int*)b) return 1;
	return 0;
}

int main() {
	using namespace std;

	// N : horse_home
	// C : horse
	int N, C;
	cin >> N >> C;
	int* horse_home = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> horse_home[i];
	}

	qsort(horse_home, N, sizeof(int), cmp);

	int result	= 0;
	int bottom	= horse_home[0];
	int top		= horse_home[N - 1];
	while (true) {
		if (bottom > top) break;

		int mid = (bottom + top) / 2;
		int horse_cnt = 1;
		int preIdx = 0;
		// 처음은 고정
		for (int i = 1; i < N; i++) {
			if (mid <= horse_home[i] - horse_home[preIdx]) {
				horse_cnt++;
				preIdx = i;
			}
			if (C <= horse_cnt) break;
		}
		if (horse_cnt < C) {
			top = mid - 1;
		}
		else {
			bottom = mid + 1;
			result = mid;
		}
	}

	cout << result;

	delete[] horse_home;
	return 0;
}