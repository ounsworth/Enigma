
#include <string.h>

#include "enigmaMachine.h"


/** COnstructor **/
WehrmachtMachine::WehrmachtMachine() 
{
	// instead, create a "neutral rotor" which maps evrey letter to itself by overriding translate() and inv_translate() to { return c; }
	// and make that the default.
	WehrmachtMachine("NNNN", "AAA", ALPHABET);
}


WehrmachtMachine::~WehrmachtMachine() {
	delete[] m_plugboard;
}

WehrmachtMachine::WehrmachtMachine(const char* rotorConfig, const char* initVector)
{
	WehrmachtMachine(rotorConfig, initVector, ALPHABET);
}

/** Constructor **/
WehrmachtMachine::WehrmachtMachine(const char* rotorConfig, const char* initVector, const char* plugboard)
{
	init(rotorConfig, initVector, plugboard);
}

void WehrmachtMachine::init(const char* rotorConfig, const char* initVector)
{
	init(rotorConfig, initVector, ALPHABET);
}

void WehrmachtMachine::init(const char* rotorConfig, const char* initVector, const char* plugboard)
{	
	m_plugboard = new char[27];
	strcpy(m_plugboard, plugboard);
	// parse both user input strings, and create the Rotor and Reflector objects	
	char pos;
	int i;
	for(i=0; i<3; i++) {
	
		// validate the initVector string
		pos = toupper(initVector[i]);
		if (pos < 'A' || pos > 'Z')
			throw ENIGMA_INVALID_INIT_VECTOR_ERROR;
	
	
		// parse the rotorConfig string and construct the Rotor objects
		switch(rotorConfig[i]) {
		case '1':
			m_rotors[i] = RotorI(pos);
			break;
		case '2':
			m_rotors[i] = RotorII(pos);
			break;
		case '3':
			m_rotors[i] = RotorIII(pos);
			break;
		case '4':
			m_rotors[i] = RotorIV(pos);
			break;
		case '5':
			m_rotors[i] = RotorV(pos);
			break;
		case '6':
			m_rotors[i] = RotorVI(pos);
			break;
		case '7':
			m_rotors[i] = RotorVII(pos);
			break;
		case '8':
			m_rotors[i] = RotorVIII(pos);
			break;
		case 'N':
			m_rotors[i] = NullRotor(0);
			break;
		case '\0': 	// premature end-of-string (ie string too short)
		default:
			throw ENIGMA_INVALID_ROTOR_CONFIG_ERROR;
		}
	}
	
	bool fourRotors = strlen(initVector) >= 4;
	if ( fourRotors ) {
		// validate the initVector string
		pos = toupper(initVector[3]);
		if (pos < 'A' || pos > 'Z')
			throw ENIGMA_INVALID_INIT_VECTOR_ERROR;
	
	
		// parse the rotorConfig string and construct the Rotor objects
	
		switch( rotorConfig[3] ) {
		case 'B':
			m_rotors[3] = RotorBeta(pos);
			break;
		case 'G':
			m_rotors[3] = RotorGamma(pos);
			break;	
		case 'N':
			m_rotors[3] = NullRotor(0);
			break;
		case '\0': 	// premature end-of-string (ie string too short)
		default:
			throw ENIGMA_INVALID_ROTOR_CONFIG_ERROR;
		}
	} else {
		// In the 3-rotor configuration, we add a null rotor to fill out the array
		// The is preferable to only having 3 in the array to prevent timing attacks
		m_rotors[3] = NullRotor(0);
	}
	
	switch( rotorConfig[3] ) {
	case 'B':
		m_reflector = fourRotors ? (Reflector) ReflectorBThin() : (Reflector) ReflectorB();
		break;
	case 'C':
		m_reflector = fourRotors ? (Reflector) ReflectorCThin() : (Reflector) ReflectorC();
		break;
	case 'N':
		m_reflector = NullReflector();
		break;
	case '\0': 	// premature end-of-string (ie string too short)
	default:
		throw ENIGMA_INVALID_ROTOR_CONFIG_ERROR;		
	}
	#ifdef DEBUG
	printPlugboard();
	#endif
}


void WehrmachtMachine::advance()
{	
	// the 1st rotor always advances
	m_rotors[0].advance();
		
	if( m_rotors[0].nextCanAdvance() )
		m_rotors[1].advance();
		
	if( m_rotors[1].nextCanAdvance() ) {
		m_rotors[2].advance();
		
		// the pawl of the 3rd rotor will catch on the notch of the 2nd rotor
		// leading to the so-called "double-step" behaviour
		m_rotors[1].advance();
	}
	
	// even if there are 4 rotors, only the first 3 rotate because there are only ever 3 pawls
	// They never made a proper 4-rotor model of the Wehrmacht machine, it was just a field-rigged 3-rotor model.
}

char WehrmachtMachine::translate(char c)
{
	int rot;
	for(rot=0; rot<4; rot++) {
			c = m_rotors[rot].translate(c);
	}	
	// reflect and go back
	c = m_reflector.translate(c);
	
	for(rot=4; rot>=0; rot--) {
			c = m_rotors[rot].inv_translate(c);
	}
	
	return c;
}

void WehrmachtMachine::resetPlugboard()
{
	printf("resetPlugboard() 1\n");
	strcpy(m_plugboard, ALPHABET);
	printf("resetPlugboard() 2\n");
}

//TODO: write some test cases for this!
void WehrmachtMachine::setPlugboardPair(char p1, char p2)
{
	p1 = toupper(p1);
	p2 = toupper(p2);
	if (p1 < 'A' || p1 > 'Z' || p2 < 'A' || p2 > 'Z')
		return;

	// reset any previous plugs
	char c;
	c = m_plugboard[p1-'A'];
	m_plugboard[c-'A'] = c;
	c = m_plugboard[p2-'A'];
	m_plugboard[c-'A'] = c;
	
	m_plugboard[p1-'A'] = p2;
	m_plugboard[p2-'A'] = p1;
}


