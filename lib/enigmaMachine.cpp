
#include <string.h>

#include "enigmaMachine.h"


WehrmachtMachine::WehrmachtMachine(const char* rotorConfig, const char* initVector)
{
	if ( ! WehrmachtMachine::validateRotorConfigStr(rotorConfig) )
		throw ENIGMA_INVALID_ROTOR_CONFIG_ERROR;
		
	if ( ! WehrmachtMachine::validateInitVector(initVector) )
		throw ENIGMA_INVALID_INIT_VECTOR_ERROR;
	
	resetPlugboard();
	
}

WehrmachtMachine::WehrmachtMachine() 
{ 
	WehrmachtMachine(ENIGMA_DEFAULT_ROTOR_CONFIG, ENIGMA_DEFAULT_INIT_VECTOR); 
}


bool WehrmachtMachine::validateRotorConfigStr(const char* rotorConfig)
{
	return true;
}


bool WehrmachtMachine::validateInitVector(const char* initVector)
{
	return true;
}

void WehrmachtMachine::resetPlugboard()
{
	strcpy(plugboard, ALPHABET);
}

//TODO: write some test cases for this!
void WehrmachtMachine::setPlugboardPair(char p1, char p2)
{
	if (p1 < 'A' || p1 > 'Z' || p2 < 'A' || p2 > 'Z')
		return;

	// reset any previous plugs
	char c;
	c = plugboard[p1-'A'];
	plugboard[c-'A'] = c;
	c = plugboard[p2-'A'];
	plugboard[c-'A'] = c;
	
	plugboard[p1-'A'] = p2;
	plugboard[p2-'A'] = p1;
}
