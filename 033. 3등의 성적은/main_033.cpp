// class & DI ¿¬½À
#include "Targets.h"
#include "Algorithms.h"


int main() {
	using namespace std;

	Targets target0;
	Algorithms algo(target0);

	algo.selectionSort();
	//algo.print();
	std::cout << algo.rankScorePrint(3);



	return 0;
}