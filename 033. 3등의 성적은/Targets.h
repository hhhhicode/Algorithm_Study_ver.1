#pragma once

#include <iostream>

class Targets {
private:
	int N;
	int* score_list;

public:
	Targets();
	const int get_N() {
		return N;
	}
	int* get_Score_list() {
		return score_list;
	}
};