// 삽입정렬
// end에서부터 로직에 맞는것을 오른쪽으로 하나씩 민다.
// 로직에 맞지 않는 것 다음은 로직에 맞는 것이고, 이미 오른쪽으로 밀렸을 테니까 로직에 맞지 않는 것 다음 자리에 넣는다.

#include <iostream>

int main() {
	using namespace std;

	int N;
	cin >> N;
	int* num_list = new int[N];
	int start = 0, end = N - 1;
	for (int i = start; i <= end; i++) {
		cin >> num_list[i];
	}

	// 자신 백업
	// 큰건 오른쪽으로 밀기
	// 작은거 나오면 멈추기
	// 멈춘곳 다음에 넣기
	for (int i = start + 1; i <= end; i++) {
		// 자신 백업
		int this_number{ num_list[i] };
		int j = i - 1;
		// ★★★for문은 -1 인덱스 까지 가서 조건에 맞지않아 멈추는 것을 기억합시다!!!!★★★
		for (; j >= start; j--) {
			// 큰건 오른쪽으로 밀기
			if (this_number < num_list[j]) {
				num_list[j + 1] = num_list[j];
			}
			// 작은거 나오면 멈추기
			else {				
				break;
			}			
		}
		// 멈춘곳 다음에 넣기
		num_list[j + 1] = this_number;
	}

	for (int i = start; i <= end; i++) {
		cout << num_list[i] << ' ';
	}
	cout << endl;

	return 0;
}