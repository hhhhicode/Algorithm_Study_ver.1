//▣ 입력설명 첫 줄에 주민등록증 번호가 입력됩니다.
//▣ 출력설명 첫 줄에 나이와 성별을 공백을 구분으로 출력하세요.성별은 남자는 M(man), 여자는
//W(Woman)로 출력한다.
// 2019년 기준

#include "나이차이.h"

int main() 
{
	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);
	using namespace std;

	char jumin[20];
	cin >> jumin; // 6 : -
	
	if (int(jumin[7] - 48) % 2 == 1)
	{
		cout << age(jumin) << " M";
	}
	else
	{
		cout << age(jumin) << " W";
	}

	return 0;
}