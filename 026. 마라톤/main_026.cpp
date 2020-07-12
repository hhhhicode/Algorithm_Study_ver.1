// vector
#include <iostream>
#include <vector>

int main() {
	using namespace std;

	int N;
	cin >> N;

	vector<int> common_level(N);
	for (auto i = 0; i < N; i++)
	{
		cin >> common_level[i];
		int rec = 1;
		for (int j = 0; j < i; j++)
		{
			if (common_level[j] >= common_level[i])
			{
				rec++;
			}
		}
		cout << rec << ' ';
	}


	return 0;
}