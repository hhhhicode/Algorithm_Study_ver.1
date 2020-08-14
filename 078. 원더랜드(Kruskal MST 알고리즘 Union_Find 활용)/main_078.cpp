// ���� �z�� ����

// < ��� > - �߸��� ����
// DFS�δ� ����� ����? Ư�� �������� ���� ���� �ƴ϶� ������ �����ؾ� �ϱ� ������ stop ������ �ָ��ϴ�...
// BFS�� �ɰ� ����. ?? ���� �� check �ϴ°� ���� �ָ��ϴ�..? check ���ϸ� �Դ� �� �ǵ��ư� �� ����...
// priorty_queue ���� ������ �� ����.

// < ���� >
// check �ϴ� ���� Union & Find�� �ϸ� �ȴ�.
// ��尡 �ֿ��� �ƴϰ� ������ �ֿ��̴�. ������ class�� �ϰ� ���������Ѵ�.

#include <iostream>
#include <algorithm>

class Path
{
public:
	int n1, n2;
	int weight;

	// �̰� �ϴ��� �������.
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