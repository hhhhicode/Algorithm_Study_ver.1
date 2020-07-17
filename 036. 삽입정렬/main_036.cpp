// ��������
// end�������� ������ �´°��� ���������� �ϳ��� �δ�.
// ������ ���� �ʴ� �� ������ ������ �´� ���̰�, �̹� ���������� �з��� �״ϱ� ������ ���� �ʴ� �� ���� �ڸ��� �ִ´�.

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

	// �ڽ� ���
	// ū�� ���������� �б�
	// ������ ������ ���߱�
	// ����� ������ �ֱ�
	for (int i = start + 1; i <= end; i++) {
		// �ڽ� ���
		int this_number{ num_list[i] };
		int j = i - 1;
		for (; j >= start; j--) {
			// ū�� ���������� �б�
			if (this_number < num_list[j]) {
				num_list[j + 1] = num_list[j];
			}
			// ������ ������ ���߱�
			else {				
				break;
			}			
		}
		// ����� ������ �ֱ�
		num_list[j + 1] = this_number;
	}

	for (int i = start; i <= end; i++) {
		cout << num_list[i] << ' ';
	}
	cout << endl;

	return 0;
}