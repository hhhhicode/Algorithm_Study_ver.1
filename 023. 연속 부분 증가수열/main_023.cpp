// 함수포인터
// 동적할당 반환 함수
// 주소로 배열 접근
#include <iostream>

int* allocateN(const int& N)
{
	return new int[N]; // 동적할당된 주소를 반환
}

int main() {
	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);
	using namespace std;

	int N;
	cin >> N;
	int *(*funcptr)(const int&) = allocateN; //함수도 포인터이다. 함수포인터로 함수를 받았다.
	int* numbers = funcptr(N); // 함수포인터를 실행하면 동적할당된 주소를 반환한다.

	int max_seq = 1, cur_seq = 1;
	int pre_num = 0;
	for (unsigned i = 0; i < N; i++)
	{
		cin >> *(numbers + i); // numbers는 포인터, i는 주소(int)+
		if (pre_num <= *(numbers + i))
		{			
			cur_seq++;
		}
		else
		{
			cur_seq = 1;
		}

		if (max_seq < cur_seq)
			max_seq = cur_seq;
		pre_num = *(numbers + i);
	}

	cout << max_seq;
	
	return 0;
}