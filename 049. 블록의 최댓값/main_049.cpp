#include <iostream>

void printMatrix(int** matrix, const int& N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

int sumMatrix(int** matrix, const int& N) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum+= matrix[i][j];
		}
	}
	return sum;
}

int main() {
	using namespace std;
	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);

	int N;
	cin >> N;

	int** matrix = new int* [N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new int[N];
	}

	for (int j = 0; j < N; j++) {
		cin >> matrix[0][j];
		for (int i = 0; i < N; i++) {
			matrix[i][j] = matrix[0][j];
		}
	}

	for (int i = N-1; i >= 0; i--) {
		int tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] > tmp) {
				matrix[i][j] = tmp;
			}
		}
	}

	cout << sumMatrix(matrix, N);

	for (int i = 0; i < N; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;


	return 0;
}