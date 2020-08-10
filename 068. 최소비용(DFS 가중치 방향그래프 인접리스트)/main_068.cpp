// vector, STL pair 자료구조 사용
// <utility>는 <algorithm>에서 include 하고 있다.
// pair<T, TT>, make_pair(v1, v2)

// 초기화는 언제나 언제나 반드시 명심하자.

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Path
{
private:
	int _N, _M;
	std::vector<std::pair<int, int> >* adj;
	bool* checkNode;
	int minWeight = std::numeric_limits<int>::max();

public:
	Path(const int& N, const int& M)
		: _N(N), _M(M)
	{
		adj = new std::vector<std::pair<int, int> >[N + 1];
		for (int i = 0; i < _M; i++)
		{
			int r, c, v;
			std::cin >> r >> c >> v;
			adj[r].push_back(std::make_pair(c, v));
		}

		checkNode = new bool[N + 1]();
		checkNode[1] = true;
	}
	~Path()
	{
		delete[] adj;
	}

	Path& Finder(const int& here = 1, const int& sum = 0)
	{
		if (here == _N)
		{
			if (minWeight > sum)
				minWeight = sum;
			return *this;
		}

		for (const auto& a : adj[here])
		{
			if (checkNode[a.first] == false)
			{
				checkNode[a.first] = true;
				Finder(a.first, sum + a.second);
				checkNode[a.first] = false;
			}
		}
		return *this;
	}
	int getMinWeight()
	{
		return minWeight;
	}
	
};

int main()
{
	using namespace std;
	//FILE* s;	freopen_s(&s, "input.txt", "rt", stdin);

	int N, M;
	cin >> N >> M;

	cout << Path(N, M).Finder().getMinWeight();
	return 0;
}