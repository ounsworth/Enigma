
#include "rotors.h"

Rotor::Rotor(char pos)
{
	if (pos >= 'A' && pos <= 'Z')
		m_pos = pos-'A';
	else
		m_pos = 0;
}

char Rotor::translate(char c)
{
	c = cleanChar(c);
	if (c == '-') return '-';
	return transitionTable[c-'A'];
}

char Rotor::inv_translate(char c)
{
	c = cleanChar(c);
	if (c == 1) return '-';
	return inv_transitionTable[c-'A'];
}


// Rotor I
bool Rotor1::advance() {
	m_pos = (m_pos + 1) % 26;
	
	return false;
}


// Rotor II
bool Rotor2::advance() {
	m_pos = (m_pos + 1) % 26;
	
	return false;
}
