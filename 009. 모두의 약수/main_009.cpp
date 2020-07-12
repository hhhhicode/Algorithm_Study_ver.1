//�� �Է¼��� 
//ù ��° �ٿ� �ڿ��� N(5 <= N <= 50, 000)�� �־�����.
//�� ��¼���
//ù ��° �ٿ� 1���� N���� ����� ������ ������� ����Ѵ�.

#include <iostream>

class Divisors {
private:
	int number;
	int* divisors;

public:
	Divisors()
	{
		std::cin >> number;
		divisors = new int[number + 1];
		for (unsigned i = 0; i <= number; i++)
			divisors[i] = 0;
	}
	~Divisors()
	{
		delete[] divisors;
	}

	Divisors& searchDiv()
	{
		for (unsigned i = 1; i <= number; i++)
		{
			for (unsigned j = 1; i * j <= number; j++)
			{
				divisors[i * j]++;
			}
		}
		return *this;
	}
	void print()
	{
		for (unsigned i = 1; i <= number; i++)
		{
			std::cout << divisors[i] << ' ';
		}
	}
};

int main() {
	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);

	Divisors().searchDiv().print();

	return 0;
}