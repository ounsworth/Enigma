#ifndef ENIGMA_REFLECTOR_H
#define ENIGMA_REFLECTOR_H

#include <string.h>

#include "enigma_utils.h"

class Reflector
{
public:
	/** Construcor **/
	Reflector() { }
 	
 	char translate(char c);
 	
protected:
	char transitionTable[27];

};

/* The raw transition table for the two standard reflectors for a Wehrmacht Enigma Machine:
Contacts    = ABCDEFGHIJKLMNOPQRSTUVWXYZ                
              ||||||||||||||||||||||||||
Reflector B = YRUHQSLDPXNGOKMIEBFZCWVJAT
Reflector C = FVPJIAOYEDRZXWGCTKUQSBNMHL
*/

/**
 * Reflector Alpha of the Wehrmacht Enigma machine
 */
class ReflectorAlpha : public Reflector
{
	public:
		ReflectorAlpha() {
			strcpy(transitionTable, "YRUHQSLDPXNGOKMIEBFZCWVJAT");
		}
};


/**
 * Reflector Beta of the Wehrmacht Enigma machine
 */
class ReflectorBeta : public Reflector
{
	public:
		ReflectorBeta() {
			strcpy(transitionTable, "FVPJIAOYEDRZXWGCTKUQSBNMHL");
		}
};



#endif
