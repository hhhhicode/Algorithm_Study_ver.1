#include <iostream>

class Stack
{
private:
	char stack[31];
	int top;
	char gwalgo[31];


public:
	Stack()
		: top(-1)
	{
		std::cin >> gwalgo;
	}

	void checkGwalho()
	{
		for (int i = 0; gwalgo[i] != '\0'; i++)
		{
			char thisCharacter = gwalgo[i];
			if (thisCharacter == '(')
			{
				if (!pushStack(thisCharacter))
				{
					std::cout << "NO";
					return;
				}
			}
			if (thisCharacter == ')')
			{
				if (!popStack())
				{
					std::cout << "NO";
					return;
				}
			}
		}

		if (top != -1)
		{
			std::cout << "NO";
		}
		else
		{
			std::cout << "YES";
		}
	}

	bool pushStack(char c)
	{
		++top;
		if (0 <= top && top <= 30)
		{
			stack[top] = c;
			return true;
		}
		return false;
	}

	bool popStack()
	{
		if (top >= 0)
		{
			top--;
			return true;
		}
		return false;
	}

};

int main()
{
	using namespace std;

	Stack s;
	s.checkGwalho();

	return 0;
}