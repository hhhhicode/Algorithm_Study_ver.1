// Stack

#include <iostream>

class MyStack {
private:
	char stack[11];
	int len;
	int N;
	int K;

public:
	MyStack(int n, int k)
		: len(-1), N(n), K(k)
	{}

	void setStack(){
		int number = N;
		char number_table[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
		while (number) {
			len++;
			stack[len] = number_table[number % K];
			number /= K;
		}
	}

	void printStack() {
		int pointer = len;
		for (int p = pointer; p >= 0; p--) {
			std::cout << stack[p];
		}
	}
};

int main() {
	using namespace std;

	int N, K;
	cin >> N >> K;
	MyStack stack(N, K);
	stack.setStack();
	stack.printStack();

	return 0;
}