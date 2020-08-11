// 틀린 문제

// 최대힙 : 완전 이진트리로 구현된 자료구조.
// 가장 크거나 작은 값을 사용하고, 나머지는 저절로 제정렬 된다 -> priority_queue

#include <iostream>
#include <queue>
int main()
{
	using namespace std;

	std::priority_queue<int> pQ;
	int tmp;
	while (true)
	{
		cin >> tmp;
		if (tmp == -1) break;
		if (tmp == 0)
		{
			cout << pQ.top() << endl;
			pQ.pop();
		}
		else {
			pQ.push(tmp);
		}
	}



	return 0;
}