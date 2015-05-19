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


Contacts         = ABCDEFGHIJKLMNOPQRSTUVWXYZ           
                   ||||||||||||||||||||||||||
Reflector B Thin = ENKQAUYWJICOPBLMDXZVFTHRGS
Reflector C Thin = RDOBJNTKVEHMLFCWZAXGYIPSUQ
*/

/**
 * Reflector Alpha of the Wehrmacht Enigma machine
 */
class ReflectorB : public Reflector
{
	public:
		ReflectorB() {
			strcpy(transitionTable, "YRUHQSLDPXNGOKMIEBFZCWVJAT");
		}
};


/**
 * Reflector Beta of the Wehrmacht Enigma machine
 */
class ReflectorC : public Reflector
{
	public:
		ReflectorC() {
			strcpy(transitionTable, "FVPJIAOYEDRZXWGCTKUQSBNMHL");
		}
};


/**
 * Reflector Beta of the Thin reflectors, Kriegsmarine M4 only Enigma machine
 */
class ReflectorBThin : public Reflector
{
	public:
		ReflectorBThin() {
			strcpy(transitionTable, "ENKQAUYWJICOPBLMDXZVFTHRGS");
		}
};


/**
 * Reflector Beta of the Thin reflectors, Kriegsmarine M4 only Enigma machine
 */
class ReflectorCThin : public Reflector
{
	public:
		ReflectorCThin() {
			strcpy(transitionTable, "RDOBJNTKVEHMLFCWZAXGYIPSUQ");
		}
};


#endif
