#include <iostream>

class Table {
private:
	int N;
	int** matrix;
	int spot_count = 0;

public:
	Table(const int& N){
		this->N = N;
	}
	~Table() {
		for (int i = 1; i <= N; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	Table& setTable() {
		matrix = new int* [N + 2];
		for (int i = 0; i < N + 2; i++) {
			matrix[i] = new int[N + 2](); // 0으로 초기화
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				std::cin >> matrix[i][j];
			}
		}
		return *this;
	}
	
	Table& searchSpot() {
		int x[4] = { -1,0,1,0 };
		int y[4] = { 0,1,0,-1 };
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				bool is_spot = true;
				for (int xy = 0; xy < 4; xy++) {
					int x_ = x[xy] + i;
					int y_ = y[xy] + j;
					if (matrix[i][j] <= matrix[x_][y_]) {
						is_spot = false;
					}
				}
				if (is_spot) spot_count++;
			}
		}
		return *this;
	}
	void printSpot() {
		std::cout << spot_count;
	}
	void printMaxtrix() {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				std::cout << matrix[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
};

int main() {
	using namespace std;
	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);

	int N;
	cin >> N;
	Table(N).setTable().searchSpot().printSpot();

	return 0;
}