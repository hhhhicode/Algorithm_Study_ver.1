//▣ 입력설명 첫 줄에 자연수 A, B가 공백을 사이에 두고 차례대로 입력된다. (1 <= A < B <= 100)
//▣ 출력설명 첫 줄에 더하는 수식과 함께 합을 출력합니다.

#include "addLoad.h"

int main() {
	using namespace std;

	int A, B;
	cin >> A >> B;

	addLoad(A, B);

	return 0;
}