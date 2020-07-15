#include <iostream>

int main() {
	using namespace std;

	int N;
	cin >> N;

	int* numList = new int[N];
	for (int i = 0; i < N; i++)
		cin >> numList[i];

	for (int i = 0; i < N - 1; i++) {
		int minIx = i;
		for (int j = i + 1; j < N; j++) {
			if (numList[j] < numList[minIx])
				minIx = j;
		}
		int tmp = numList[i];
		numList[i] = numList[minIx];
		numList[minIx] = tmp;
	}

	for (int i = 0; i < N; i++) {
		cout << numList[i] << ' ';
	}

	return 0;
}