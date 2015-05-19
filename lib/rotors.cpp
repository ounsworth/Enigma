
#include "rotors.h"


Rotor::Rotor(char pos)
{
	if (pos >= 'A' && pos <= 'Z')
		m_pos = pos-'A';
	else
		m_pos = 0;
}

void Rotor::advance() 
{ 
	m_pos = (m_pos+1) % 26;
}

char Rotor::translate(char c)
{
	c = cleanChar(c);
	if (c == '-') return '-';
	return transitionTable[(c-'A'+m_pos) % 26];
}

//TODO: write a test-case with m_pos != 0
char Rotor::inv_translate(char c)
{
	c = cleanChar(c);
	if (c == 1) return '-';
	// the inverse eqn for the ring position looks messier than it is. huh
	return (((inv_transitionTable[c-'A']-'A')-m_pos+26) % 26) + 'A';
}


bool RotorI::nextCanAdvance()
{
	return m_pos == ('Q'-'A');
}

bool RotorII::nextCanAdvance()
{
	return m_pos == ('E'-'A');
}

bool RotorIII::nextCanAdvance()
{
	return m_pos == ('V'-'A');
}

bool RotorIV::nextCanAdvance()
{
	return m_pos == ('J'-'A');
}

bool RotorV::nextCanAdvance()
{
	return m_pos == ('Z'-'A');
}

bool RotorVI::nextCanAdvance()
{
	return m_pos == ('Z'-'A') || m_pos == ('M'-'A');
}

bool RotorVII::nextCanAdvance()
{
	return m_pos == ('Z'-'A') || m_pos == ('M'-'A');
}

bool RotorVIII::nextCanAdvance()
{
	return m_pos == ('Z'-'A') || m_pos == ('M'-'A');
}





void rotorFactory(char rotorNum, int pos, Rotor* dst)
{
	switch (rotorNum) {
		case 1:
		*dst = (Rotor) RotorI(pos);
	break;
	case 2:
		*dst = (Rotor) RotorII(pos);
		break;
	case 3:
		*dst = (Rotor) RotorIII(pos);
		break;
	case 4:
		*dst = (Rotor) RotorIV(pos);
		break;
	case 5:
		*dst = (Rotor) RotorV(pos);
		break;
	case 6:
		*dst = (Rotor) RotorVI(pos);
		break;
	case 7:
		*dst = (Rotor) RotorVII(pos);
		break;
	case 8:
		*dst = (Rotor) RotorVIII(pos);
		break;
	case 'B':
		*dst = (Rotor) RotorBeta(pos);
		break;
	case 'G':
		*dst = (Rotor) RotorGamma(pos);
		break;
	default:
		*dst = (Rotor) RotorI(pos);
	}
}
