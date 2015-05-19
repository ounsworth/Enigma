#ifndef ENIGMA_ENIGMA_MACHINE_H
#define ENIGMA_ENIGMA_MACHINE_H

#include <stdexcept>

#include "rotors.h"


#define ENIGMA_DEFAULT_ROTOR_CONFIG "123B"
#define ENIGMA_DEFAULT_INIT_VECTOR "AAA"

// error codes for the WehrmachtMachine constructor to throw
#define ENIGMA_INVALID_ROTOR_CONFIG_ERROR -1
#define ENIGMA_INVALID_INIT_VECTOR_ERROR	-2

#ifndef ALPHABET
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#endif

/**
 * 
 *
 */
class WehrmachtMachine
{

	public:
		/** Constructors */
		WehrmachtMachine();
		WehrmachtMachine(const char* rotorConfig, const char* initVector);

		static bool validateRotorConfigStr(const char* rotorConfig);
		static bool validateInitVector(const char* initVector);

		void setRotorConfig(const char* rotorConfig);
		void setInitVector(const char* initVector);

		void resetPlugboard();
		void setPlugboardPair(char p1, char p2);

	private:
		Rotor rotors[4];
		char plugboard[27];
};

 
 #endif
