//�� �Է¼��� 
//ù ��° �ٿ��� �ڿ��� N(3 <= N <= 100, 000, 000)�� �־�����.
//�� ��¼���
//ù ��° �ٿ� ������ �Ѱ����� ����Ѵ�.

#include <iostream>

class Numbers2 {
private:
	int number;
	int count;

public:
	Numbers2() :count(0)
	{
		std::cin >> number;
	}
	Numbers2& gainNumber()
	{
		for (int i = 1; i <= number; i++)
		{
			int tmp = i;
			while (tmp)
			{
				tmp /= 10;
				count++;
			}
		}
		return *this;
	}

	void print()
	{
		std::cout << count;
	}
};

int main() {


	Numbers2().gainNumber().print();
	return 0;
}