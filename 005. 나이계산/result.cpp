#include "��������.h"

int age(const char* jumin)
{
	int age = 0;
	if (int(jumin[7] - 48) <= 2)
	{
		// 1900��� ���ڿ� ����
		age = 2019 - 1900 - 10 * (int(jumin[0] - 48)) - int(jumin[1] - 48);

	}
	else
	{
		// 2000��� ���ڿ� ����
		age = 2019 - 2000 - 10 * (int(jumin[0] - 48)) - int(jumin[1] - 48);
	}
	return age + 1;
}