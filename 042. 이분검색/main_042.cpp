#include <iostream>

// qsort�� ���Լ� �����α�
int compare_ints(const void* a, const void* b) {
	if (*(const int*)a < *(const int*)b) return -1;
	if (*(const int*)a > * (const int*)b) return 1;
	return 0;
}

int main() {
	using namespace std;

	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);

	int N, M;
	cin >> N >> M;
	int* nList = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> nList[i];
	}

	// qsort ��� ��� �����α�
	qsort(nList, N, sizeof(nList[0]), compare_ints);

	int bottom = 0, top = N - 1;
	while (true) {
		int mid = (bottom + top) / 2;
		if (top < bottom)
			break;
		if (nList[mid] == M) {
			// �迭�� 0���� �����ϹǷ� + 1
			cout << mid + 1;
			break;
		}
		else if (nList[mid] < M) {
			bottom = mid + 1;
		}
		else {
			top = mid - 1;
		}
	}

	return 0;
}