
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



void rotorFactory(int rotorNum, int pos, Rotor* dst)
{
	switch (rotorNum) {
  case 1:
     *dst = (Rotor) Rotor1(pos);
     break;
  case 2:
     *dst = (Rotor) Rotor2(pos);
     break;
  case 3:
     *dst = (Rotor) Rotor3(pos);
     break;
  case 4:
     *dst = (Rotor) Rotor4(pos);
     break;
  case 5:
     *dst = (Rotor) Rotor5(pos);
     break;
  default:
     *dst = (Rotor) Rotor1(pos);
	}
}
