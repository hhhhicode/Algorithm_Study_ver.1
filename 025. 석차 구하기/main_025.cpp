// vector
// for-each

#include <iostream>
#include <vector>
int main() {
	using namespace std;

	int N;
	cin >> N;

	vector<int> records(N); // 0 0 0 ..
	vector<int> students(N);
	for (auto& s : students)
		cin >> s;
	for (const auto& s : students)
	{
		for (int i = 0; i < N; i++)
		{
			// 자신보다 작은 학생의 등수를 1씩 올리기
			if (students[i] < s)
				records[i]++;
		}
	}

	for (const auto& r : records)
	{
		cout << r + 1 << ' '; // because record{0, 0, ..}
	}

	return 0;
}