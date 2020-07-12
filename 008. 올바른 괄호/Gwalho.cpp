#include "Gwalho.h"

void Gwalho::check()
{
	for (unsigned i = 0; _string[i] != '\0'; i++)
	{
		if (baseline < 0)
		{
			std::cout << "NO" << std::endl;
			return;
		}
		if (_string[i] == '(')
			baseline++;
		else
			baseline--;
	}
	if (baseline == 0)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
}
