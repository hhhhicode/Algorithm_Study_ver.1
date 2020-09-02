// 틀린 문제 - 문제 이해를 잘 못하겠다.

#include <iostream>
#include <vector>
#include <algorithm>

class Choice
{
private:
	int _n;
	std::vector< std::vector<int> > students;

public:
	void solution()
	{
		init();
		pointAllocate();
		printPoint();
	}
	void init()
	{
		std::cin >> _n;
		students.assign(_n + 1, std::vector<int>(_n + 1, _n - 1));

		int a = 0, b = 0;
		while (true)
		{
			std::cin >> a >> b;
			if (a == -1 && b == -1) break;  // 틀린 부분
			students[a][b] = 1;
			students[b][a] = 1;  // 틀린 부분
		}

		for (int i = 1; i <= _n; i++)
			students[i][i] = 0;
	}

	void pointAllocate()
	{
		for (int k = 1; k <= _n; k++)
		{
			for (int i = 1; i <= _n; i++)
			{
				for (int j = 1; j <= _n; j++)
				{
					if (students[i][j] > students[i][k] + students[k][j])
					{
						students[i][j] = students[i][k] + students[k][j];
					}
				}
			}
		}
	}

	void printPoint()
	{
		int min = _n;
		int count = 0;
		int* list = new int[_n + 1];
		
		for (int i = 1; i <= _n; i++)
		{
			int iMax = 0;
			for (int j = 1; j <= _n; j++)
			{
				if (iMax < students[i][j])
					iMax = students[i][j];
			}

			if (min > iMax)
			{
				count = 1;
				min = iMax;
				list[count] = i;
			}
			else if (min == iMax)
			{
				list[++count] = i;
			}
		}

		std::cout << min << ' ' << count << std::endl;
		for (int i = 1; i <= count; i++)
			std::cout << list[i] << ' ';
	}

	void pS()
	{
		for (int i = 1; i <= _n; i++)
		{
			for (int j = 1; j <= _n; j++)
			{
				std::cout << students[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	using namespace std;

	Choice().solution();

	return 0;
}