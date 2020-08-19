// ���߱� ������ ��ǻ� Ʋ�� ����.
// ������ ������ �߻��߾���.
#include <iostream>
#include <vector>

class Work
{
private:
	int Ti;
	int Pi;
	bool ch = false;

public:
	Work(int ti, int pi)
		: Ti(ti), Pi(pi)
	{}

	int getTi()
	{
		return Ti;
	}
	int getPi()
	{
		return Pi;
	}
	bool getCh()
	{
		return ch;
	}
	void setCh(bool t)
	{

		ch = t;
	}
};

class Cal
{
private:
	std::vector<Work> vec;
	int maxMoney{ 0 };

public:
	Cal(int n)
	{
		for (int i = 0; i < n; i++)
		{
			int ti, pi;
			std::cin >> ti >> pi;
			vec.push_back(Work(ti, pi));
		}
	}

	Cal& DFS(int today = 0, int sum = 0)
	{
		// thereTi���� today�� �ƴ� i �� ���߾�� �ߴ�.  <- �̰� ������ Ʋ�Ⱦ���.
		for (int i = today; i < vec.size(); i++)
		{
			int thereTi = i + vec[i].getTi();
			int therePi = sum + vec[i].getPi();
			if (thereTi <= vec.size())
			{
				if (maxMoney < therePi)
				{
					maxMoney = therePi;
				}
				DFS(thereTi, therePi);
			}
		}
		return *this;
	}

	void printMax()
	{
		std::cout << maxMoney << std::endl;
		
	}
};

int main()
{
	using namespace std;

	static int N;
	cin >> N;

	Cal(N).DFS().printMax();

	return 0;
}