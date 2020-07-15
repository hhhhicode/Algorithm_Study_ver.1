// C : 12g, H : 1g
// CaHb (1<=a, b<=100)
// a || b가 1이면 표기 하지 않음
#include <iostream>
#include <string>

int C_H_counter(const std::string& str) {
	static int i = 1;
	int count = 0;
	while (1) {
		if (str[i] == 'H' || i == str.size()) {
			i++;
			break;
		}
		int  num = int(str[i]) - int('0');
		count = count * 10 + num;
		i++;
	}
	// 1개라서 숫자가 표기되지 않아 잡히지 않은 경우
	if (count == 0) return 1;
	return count;
}

int main() {
	using namespace std;

	string str;
	cin >> str;

	int C_count = C_H_counter(str);
	int H_count = C_H_counter(str);	

	int C_gram = 12, H_gram = 1;
	int result = C_count * C_gram + H_count * H_gram;
	cout << result;

	return 0;
}