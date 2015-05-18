#include "reflectors.h"

char Reflector::translate(char c)
{
	c = cleanChar(c);
	if (c == '-') return '-';
	return transitionTable[c-'A'];
}


