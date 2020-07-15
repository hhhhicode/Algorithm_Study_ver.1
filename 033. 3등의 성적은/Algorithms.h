#pragma once
#include "Targets.h"

class Algorithms {
private:
	int size;
	int* score_list;
public:
	Algorithms(Targets& targets);
	void selectionSort();
	void swapScore(int aIx, int bIx);
	int rankScorePrint(int n);
	void print();
};