#include "나이차이.h"

int age(const char* jumin)
{
	int age = 0;
	if (int(jumin[7] - 48) <= 2)
	{
		// 1900년대 남자와 여자
		age = 2019 - 1900 - 10 * (int(jumin[0] - 48)) - int(jumin[1] - 48);

	}
	else
	{
		// 2000년대 남자와 여자
		age = 2019 - 2000 - 10 * (int(jumin[0] - 48)) - int(jumin[1] - 48);
	}
	return age + 1;
}