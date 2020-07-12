//▣ 입력설명 첫 줄에 숫자가 썪인 문자열이 주어집니다.문자열의 길이는 50을 넘지 않습니다.
//▣ 출력설명 첫 줄에 자연수를 출력하고, 두 번째 줄에 약수의 개수를 출력합니다

#include "String.h"

int main() {
	using namespace std;

	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);

	String start;
	start.searchNumber().countDivisor();
	
	return 0;	
}