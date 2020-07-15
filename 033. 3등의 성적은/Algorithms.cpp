#include "Algorithms.h"

Algorithms::Algorithms(Targets& targets) {
	size = targets.get_N();
	score_list = targets.get_Score_list();
}

void Algorithms::selectionSort() {
	for (int i = 0; i < size - 1; i++) {
		int min = score_list[i];
		int minIx = i;
		for (int j = i + 1; j < size; j++) {
			if (score_list[j] < min) {
				min = score_list[j];
				minIx = j;
			}
		}
		swapScore(i, minIx);
	}
}

void Algorithms::swapScore(int aIx, int bIx) {
	int tmp = score_list[aIx];
	score_list[aIx] = score_list[bIx];
	score_list[bIx] = tmp;
}

int Algorithms::rankScorePrint(int n) {
	// 범위 벗어난 랭킹은?
	while (true) {
		int rank_score = score_list[size - 1];
		int rank = 1;
		for (int i = size - 2; i >= 0; i--) {
			if (rank_score != score_list[i]) {
				rank_score = score_list[i];
				rank++;
			}
			if (rank == n) {
				return score_list[i];
			}
			
		}
		std::cout << rank << "등 까지 존재합니다.\n";
	}
}

void Algorithms::print() {
	for (int i = 0; i < size; i++) {
		std::cout << score_list[i] << ' ';
	}
	std::cout << std::endl;
}
