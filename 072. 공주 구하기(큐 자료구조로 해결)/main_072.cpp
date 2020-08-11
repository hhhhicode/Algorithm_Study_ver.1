#include <iostream>
#include <queue>

int main()
{
	using namespace std;

	int N, K;
	cin >> N >> K;

	std::queue<int> q;

	for (int i = 1; i <= N; i++)
		q.push(i);

	int hero;
	int count(0);
	while (!q.empty())
	{
		hero = q.front();	q.pop();
		if (++count != K)
		{
			q.push(hero);
		}
		else {
			count = 0;
		}
	}

	cout << hero;

	return 0;
}