// 푸는 방법을 잘 모르겠던 문제.

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
int main()
{
	using namespace std;

	std::priority_queue<int> pQ;
	std::vector<int>* v;
	int N;
	cin >> N;
	v = new vector<int>[10001];
	for (int i = 0; i < N; i++)
	{
		int M, D;
		cin >> M >> D;
		v[D].push_back(M);
	}

	int sum = 0;
	for (int i = 10000; i >= 1; i--)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			pQ.push(v[i][j]);
		}
		if (!pQ.empty())
		{
			sum += pQ.top();
			pQ.pop();
		}
	}
	cout << sum;

	delete[] v;
	return 0;
}