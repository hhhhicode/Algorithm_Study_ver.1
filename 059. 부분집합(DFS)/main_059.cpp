// 틀린 문제
// 레벨 탐색, 전위,중위,후위와는 다르다.
// { 1(레벨1), 2(레벨2), 3(레벨3), 4(레벨4), ... }

// 배열을 이용한 경우의 수 탐색
// 모든 배열의 요소의 경우의 수를 지정해줘야 하기 때문에 index + 1 로 접근

#include <iostream>

class DFS
{
private:
	int* list;
	int N;

public:
	DFS(const int& n, int* arr)
		: N(n), list(arr)
	{}

	void 중위(const int& idx = 1)
	{
		if (idx > N)
		{
			for (int i = 1; i <= N; i++)
			{
				if (list[i] == 1)
				{
					std::cout << i << ' ';
				}
			}
			std::cout << std::endl;
			return;
		}

		list[idx] = 1;
		중위(idx + 1);
		list[idx] = 0;
		중위(idx + 1);
	}

};



int main()
{
	using namespace std;

	int N;
	cin >> N;

	int* list = new int[N + 1]();

	DFS(N, list).중위();

	return 0;
}