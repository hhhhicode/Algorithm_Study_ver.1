// 완전 틑린 문제

// < 노드 > - 잘못된 생각
// DFS로는 힘든것 같다? 특정 지점까지 가는 것이 아니라 모든것을 연결해야 하기 때문에 stop 조건이 애매하다...
// BFS는 될것 같다. ?? 갔던 곳 check 하는게 뭔가 애매하다..? check 안하면 왔던 곳 되돌아갈 것 같고...
// priorty_queue 쓰면 간단할 것 같다.

// < 간선 >
// check 하는 것을 Union & Find로 하면 된다.
// 노드가 주연이 아니고 간선이 주연이다. 간선을 class로 하고 오름차순한다.

#include <iostream>
#include <algorithm>

class Path
{
public:
	int n1, n2;
	int weight;

	// 이거 하느라 힘들었다.
	bool operator < (const Path& b)
	{
		return this->weight < b.weight;
	}
};

class PathConnector
{
private:
	int _V, _E;
	int minW = 0;
	int* gId;
	Path* p;

public:
	PathConnector(int v, int e)
		: _V(v), _E(e)
	{
		gId = new int[_V + 1];
		p = new Path[_E];
		for (int i = 0; i < _E; i++)
		{
			int here, there, weight;
			std::cin >> here >> there >> weight;
			p[i].n1		= here;		p[i].n2		= there;
			p[i].weight = weight;
		}
		for (int i = 1; i <= _V; i++)
		{
			gId[i] = i;
		}
	}

	void sortPath(Path* start, Path* end)
	{
		std::sort(start, end);
	}

	void Union(int i)
	{
		int rn1, rn2;
		rn1 = Find(p[i].n1);
		rn2 = Find(p[i].n2);
		if (rn1 != rn2)
		{
			minW += p[i].weight;
			gId[rn1] = rn2;
		}

	}

	int Find(int v)
	{
		if (v == gId[v]) return v;
		else
		{
			return gId[v] = Find(gId[v]);
		}
	}

	void Run()
	{
		sortPath(p, p + _E);
		for (int i = 0; i < _E; i++)
		{
			int rn1 = Find(p[i].n1);
			int rn2 = Find(p[i].n2);
			if (rn1 != rn2)
				Union(i);
		}
		std::cout << minW;
	}


	void printPath()
	{
		for (int i = 0; i < _E; i++)
		{
			std::cout << p[i].weight << ' ';
		}
	}
};

int main()
{
	using namespace std;

	int V, E;
	cin >> V >> E;
	PathConnector p(V, E);
	p.Run();

	return 0;
}