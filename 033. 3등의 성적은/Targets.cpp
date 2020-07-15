#include "Targets.h"

Targets::Targets() {
	std::cin >> N;
	score_list = new int[N];
	for (int i = 0; i < N; i++) {
		std::cin >> score_list[i];
	}
}
