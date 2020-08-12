// 틀린 문제

// 이항계수 : nCr = n-1Cr-1 + n-1Cr : n개 중 r개를 뽑았을 때 ~ r에 포함될 경우 + r에 포함되지 않을 경우

#include <iostream>

class Q076
{
private:
	int memo[21][21];

public:

	int DFS(const int& N, const int& R)
	{
		if (N == R || R == 0)
		{
			return memo[N][R] = 1;
		}
		return memo[N][R] = DFS(N - 1, R) + DFS(N - 1, R - 1);
	}
};

int main()
{
	using namespace std;

	int N, R;
	cin >> N >> R;
	
	cout << Q076().DFS(N, R);

	return 0;
}