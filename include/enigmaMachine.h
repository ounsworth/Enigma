#ifndef ENIGMA_ENIGMA_MACHINE_H
#define ENIGMA_ENIGMA_MACHINE_H

#include <stdexcept>

#include "rotors.h"
#include "reflectors.h"


#define ENIGMA_DEFAULT_ROTOR_CONFIG "123B"
#define ENIGMA_DEFAULT_INIT_VECTOR "AAA"

// error codes for the WehrmachtMachine constructor to throw
#define ENIGMA_INVALID_ROTOR_CONFIG_ERROR -1
#define ENIGMA_INVALID_INIT_VECTOR_ERROR	-2


/**
 * 
 *
 */
class WehrmachtMachine
{

	public:
		/** Constructors */
		WehrmachtMachine();
		
		/**
		 * @param rototConfig - a string from the user indicating the types and order of rotors to install
		 * @param initVector - the string from the user indicating the starting positions of the rotors to be parsed
		 * @throws ENIGMA_INVALID_ROTOR_CONFIG_ERROR if the rotorConfig string is invalid
		 * @throws ENIGMA_INVALID_INIT_VECTOR_ERROR if the initVector is invalid
		 */
		WehrmachtMachine(const char* rotorConfig, const char* initVector);

		//static bool validateRotorConfigStr(const char* rotorConfig);
		//static bool validateInitVector(const char* initVector);

		void advance();

		void resetPlugboard();
		void setPlugboardPair(char p1, char p2);

	private:
		Rotor m_rotors[4];
		Reflector m_reflector;
		char m_plugboard[27];
};

 
 #endif
