#include <iostream>
#include <queue>
int main()
{
	using namespace std;

	std::priority_queue<int> pQ;
	int tmp;
	while (1)
	{
		cin >> tmp;
		if (tmp == -1)	break;
		if (tmp == 0)
		{
			cout << -pQ.top() << endl;
			pQ.pop();
		}
		else
		{
			pQ.push(-tmp);
		}
	}


	return 0;
}