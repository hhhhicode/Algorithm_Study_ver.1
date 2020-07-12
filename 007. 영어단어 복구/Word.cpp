#include "Word.h"

void Word::reword()
{
	for (unsigned i = 0; _preword[i] != '\0'; i++)
	{
		if ('a' <= _preword[i] && _preword[i] <= 'z')
			std::cout << _preword[i];
		else if ('A' <= _preword[i] && _preword[i] <= 'Z')
			std::cout << char(_preword[i] + 'a' - 'A');
	}
}
