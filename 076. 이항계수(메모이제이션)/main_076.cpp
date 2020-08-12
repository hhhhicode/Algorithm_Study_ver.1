// Ʋ�� ����

// ���װ�� : nCr = n-1Cr-1 + n-1Cr : n�� �� r���� �̾��� �� ~ r�� ���Ե� ��� + r�� ���Ե��� ���� ���

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