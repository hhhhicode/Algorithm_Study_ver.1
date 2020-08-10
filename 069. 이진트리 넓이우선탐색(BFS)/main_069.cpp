// Queue 자료구조를 이용한다.
// 넣는 front pointer, 빼는 back pointer 2개가 필요하다.
// front == back : 비어있음
// front < back  : 들어있음
// front > back  : error

#include <iostream>

class Queue
{
private:
	int queue[10];
	int top{ -1 };
	int bottom{ -1 };

public:
	void setQueue(int n)
	{
		queue[++top] = n;
	}
	int* getQueue()
	{
		return queue;
	}
	int getTop()
	{
		return top;
	}
	int getBottom()
	{
		return bottom;
	}
	int pop()
	{
		return queue[++bottom];
	}
};

class BFS
{
private:
	Queue q;
	int N{ 6 };
	bool adj[8][8];

public:
	BFS()
	{
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				adj[i][j] = false;
		for (int i = 0; i < 6; i++)
		{
			int here, target;
			std::cin >> here >> target;
			adj[here][target] = true;
		}
		q.setQueue(1);
	}

	void Go()
	{
		int here = q.pop();
		std::cout << here << ' ';
		for (int t = 1; t < 8; t++)
		{
			if (adj[here][t] == true)
			{
				q.setQueue(t);
			}
		}
		if(q.getBottom() < q.getTop())
			Go();
	}
};

int main()
{
	using namespace std;

	BFS().Go();

	return 0;
}