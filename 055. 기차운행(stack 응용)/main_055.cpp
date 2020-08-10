#include <iostream>
#include <string>

class Stack
{
private:
	int memory[30];
	int top = -1;
	std::string result = "";

public:
	Stack() {}

	void pushMemory(const int& num)
	{
		++top;
		if (0 <= top && top <= 30)
		{
			memory[top] = num;
			result += "P";
		}
	}

	void popMemory()
	{
		if (0 <= top)
		{
			top--;
			result += "O";
		}
	}

	const int getTop() const
	{
		return top;
	}
	const int getTopValue() const
	{
		return memory[top];
	}
	const std::string getResult() const
	{
		return result;
	}
};

int  main() {
	using namespace std;

	int N;
	cin >> N;

	Stack s;
	int seq = 1;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		s.pushMemory(tmp);
		while (s.getTopValue() == seq)
		{
			seq++;
			s.popMemory();
		}
	}

	if (s.getTop() != -1)
	{
		cout << "impossible";
	}
	else
	{
		cout << s.getResult();
	}

	return 0;
}