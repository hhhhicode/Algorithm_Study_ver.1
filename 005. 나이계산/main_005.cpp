//�� �Է¼��� ù �ٿ� �ֹε���� ��ȣ�� �Էµ˴ϴ�.
//�� ��¼��� ù �ٿ� ���̿� ������ ������ �������� ����ϼ���.������ ���ڴ� M(man), ���ڴ�
//W(Woman)�� ����Ѵ�.
// 2019�� ����

#include "��������.h"

int main() 
{
	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);
	using namespace std;

	char jumin[20];
	cin >> jumin; // 6 : -
	
	if (int(jumin[7] - 48) % 2 == 1)
	{
		cout << age(jumin) << " M";
	}
	else
	{
		cout << age(jumin) << " W";
	}

	return 0;
}