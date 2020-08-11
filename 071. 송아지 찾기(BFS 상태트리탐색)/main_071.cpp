// check = _S > _E ? new bool[_S + 1] : new bool[_E + 1];을 했는데 뭔가 메모리에서 문제가 생겼다. 해제할때 문제인거 같기도 하다... 모르겠다.
// 다시 한 번 시도해 보는 것 도 좋다고 생각한다.

// +1, -1, +5 이동 가능하다.
// 이동횟수가 최소가 되도록.
// distance와 check는 check배열 하나로 통합하여 사용할 수 있다.

// std::unique_ptr<T> var(T*); 사용

#include <iostream>
#include <queue>

class Cowboy
{
private:
	int _S, _E;
	int move[3]{ -1,1,5 };
	int distance[10001]{ 0 };
	bool check[10001]{ 0 };

public:
	Cowboy(const int& S, const int& E)
		: _S(S), _E(E)
	{
		check[_S] = true;
		// unique_ptr 이렇게 쓰니까 뭔가 문제가 있었다...ㅠㅠ
		//std::unique_ptr<bool> up_check(check);
	}
	~Cowboy()
	{
	}

	// 레벨이 증가할수록 기하급수적으로 경우의 수가 증가하므로 
	// 필터링을 잘 해주는 것이 좋을 것 같다.
	void BFS()
	{
		std::queue<int> q;
		int here;
		int there;
		q.push(_S);
		while (!q.empty())
		{
			here = q.front();	q.pop();			

			for (int i = 0; i < 3; i++)
			{
				there = here + move[i];
				if (check[there] != true && 1 <= there && there <= 10000)
				{
					q.push(there);
					check[there] = true;
					distance[there] = distance[here] + 1;
					if (there == _E)
					{
						std::cout << distance[there];
						return;
					}
				}
			}
		}
		return;
	}

	void printCheck()
	{
		int len = _S > _E ? _S : _E;
		for (int i = 0; i <= len; i++)
			std::cout << check[i] << ' ';
	}
};

int main()
{
	using namespace std;

	int S, E;
	cin >> S >> E;

	Cowboy C(S, E);  C.BFS();

	return 0;
}