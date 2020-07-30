#include <iostream>

int main() {
	using namespace std;
	//FILE* stream; freopen_s(&stream, "input.txt", "rt", stdin);

	int H, W;
	cin >> H >> W;
	
	int** matrix = new int* [H];
	for (int i = 0; i < H; i++) {
		matrix[i] = new int[W];
		for (int idx = 0; idx < W; idx++) {
			cin >> matrix[i][idx];
		}
	}

	int row, col;
	cin >> row >> col;

	int max = 0;
	for (int i = 0; i <= H - row; i++) {
		for (int j = 0; j <= W - col; j++) {
			int sum = 0;
			for (int r = 0; r < row; r++) {
				for (int c = 0; c < col; c++) {
					sum += matrix[i + r][j + c];
				}
			}
			if (max < sum) {
				max = sum;
			}
		}
	}

	cout << max;

	for (int i = 0; i < H; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}