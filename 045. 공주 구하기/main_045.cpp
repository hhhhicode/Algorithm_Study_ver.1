#include <iostream>

int main() {
	using namespace std;

	int N, K;
	cin >> N >> K;
	bool* prins = new bool[N + 1];
	for (int i = 1; i <= N; i++) {
		prins[i] = true;
	}

	int cnt = 0;
	int idx = 0;
	int alive = N;
	while (alive != 1) {
		idx %= N;
		idx++;
		
		if (prins[idx] == true) {
			cnt++;

			if (cnt == K) {
				prins[idx] = false;
				alive--;
				cnt = 0;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (prins[i] == true)cout << i;
	}

	return 0;
}