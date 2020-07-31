#include <iostream>

int main() {
	using namespace std;
	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);

	// map 만들기
	int H, W;
	cin >> H >> W;
	int** map = new int* [H + 1];
	for (int m = 0; m < H + 1; m++) {
		map[m] = new int[W + 1]();
	}
	for (int r = 1; r < H + 1; r++) {
		for (int c = 1; c < W + 1; c++) {
			cin >> map[r][c];
		}
	}

	// sum_map 만들기
	int** sum_map = new int* [H + 1];
	for (int m = 0; m < H + 1; m++) {
		sum_map[m] = new int[W + 1]();
	}
	for (int r = 1; r <= H; r++) {
		for (int c = 1; c <= W; c++) {
			sum_map[r][c] = map[r][c] + sum_map[r][c - 1] + sum_map[r - 1][c] - sum_map[r - 1][c - 1];
		}
	}

	// 최대 이득 영지 구하기
	int row, col;
	cin >> row >> col;
	int max = 0;
	for (int r = row; r <= H; r++) {
		for (int c = col; c <= W; c++) {
			int territory = sum_map[r][c] - sum_map[r][c - col] - sum_map[r - row][c] + sum_map[r - row][c - col];
			if (max < territory) {
				max = territory;
			}
		}
	}

	cout << max;

	for (int r = 0; r < H + 1; r++) {
		delete[] map[r], sum_map[r];
	}
	delete[] map, sum_map;

	return 0;
}