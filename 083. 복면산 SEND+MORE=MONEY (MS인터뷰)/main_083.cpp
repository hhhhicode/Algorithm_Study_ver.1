// ¾Ö¸ÅÇÔ
#include <iostream>

class Quiz
{
private:
	int alpha[26];
	char list[8]; // S0, E1, N2, D3, M4, O5, R6, Y7
	bool ch[10] = {};

public:
	Quiz()
	{
		
	}

	int Send()
	{
		return list[0] * 1000 + list[1] * 100 + list[2] * 10 + list[3] * 1;
	}
	int More()
	{
		return list[4] * 1000 + list[5] * 100 + list[6] * 10 + list[1] * 1;
	}
	int Money()
	{
		return list[4] * 10000 + list[5] * 1000 + list[2] * 100 + list[1] * 10 + list[7] * 1;
	}

	void Tmp(int n = 0)
	{
		if (n == 8)
		{
			if (Send() + More() == Money())
			{
				printResult();
			}
			return;
		}
		for (int i = 0; i < 10; i++)
		{
			if (list[4] == 0 || list[0] == 0) return;
			if (ch[i] == false)
			{
				ch[i] = true;
				list[n] = i;
				Tmp(n + 1);
				list[n] = 10;
				ch[i] = false;
			}
		}
	}

	void printResult()
	{
		std::cout << Send() << std::endl;
		std::cout << "+ " << More() << "\n---------" << std::endl;
		std::cout << Money();
	}
};

int main()
{
	using namespace std;

	Quiz q;
	q.Tmp();



	return 0;
}