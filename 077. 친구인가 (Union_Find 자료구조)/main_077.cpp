// Ʋ�� ����

// Union() : ���� �̾��ִ� �޼���, Find() : �ٺ��� ��ͷ� ã���ִ� �޼���

#include <iostream>

class Class
{
private:
	int _N, _M;
	int* students;

public:
	Class(int n, int m)
		: _N(n), _M(m)
	{
		students = new int[_N + 1];
		for (int i = 1; i <= _N; i++)
		{
			students[i] = i;
		}
	}
	~Class()
	{
		delete[] students;
	}

	int Find(const int& n)
	{
		if (students[n] == n) return n;
		else
		{
			return students[n] = Find(students[n]);
		}
	}
	void Union(const int& a, const int& b)
	{
		int ra, rb;
		ra = Find(a);
		rb = Find(b);
		if (ra != rb) students[ra] = rb;
	}
	void Run()
	{
		int a, b;
		for (int i = 0; i < _M; i++)
		{
			std::cin >> a >> b;
			Union(a, b);
		}

		std::cin >> a >> b;
		// �̺κ� Ư�� ����. Ÿ�� Ÿ�� ���� �ٺ��� �κ��� ���ؾ� �Ѵ�.
		if (Find(a) == Find(b))
			std::cout << "YES";
		else std::cout << "NO";
	}
};

int main()
{
	using namespace std;

	int N, M;
	cin >> N >> M;

	Class(N, M).Run();

	return 0;
}