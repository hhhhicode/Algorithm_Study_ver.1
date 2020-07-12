// ▣ 입력설명 첫 줄에 자연수 N이 주어집니다. (3<N<=100)
// ▣ 출력설명 첫 줄에 더하는 수식과 함께 합을 출력합니다.
// 진약수 : 자기 자신을 제외한 약수

#include "add.h"

int main() {
	using namespace std;

	int N;
	cin >> N;

	add(N);

	return 0;
}