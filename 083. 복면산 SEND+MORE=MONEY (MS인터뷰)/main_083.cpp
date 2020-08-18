// «œ±‚ Ω»¿Ω
#include <iostream>

class Quiz
{
private:
	int alpha[26];
	char A[100];

public:
	Quiz()
	{
		std::cin >> A;
	}

	void print()
	{
		std::cout << A;
	}
};

int main()
{
	using namespace std;

	Quiz q;
	q.print();



	return 0;
}