#ifndef ENIGMA_ENIGMA_MACHINE_H
#define ENIGMA_ENIGMA_MACHINE_H

#include <stdexcept>
#include <stdio.h>

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

	private:
		char* m_plugboard;
		Rotor m_rotors[4];
		Reflector m_reflector;
		

	public:
		/** Constructors */
		WehrmachtMachine();
		~WehrmachtMachine();
		
		/**
		 * @param rototConfig - a string from the user indicating the types and order of rotors to install
		 * @param initVector - the string from the user indicating the starting positions of the rotors to be parsed
		 * @throws ENIGMA_INVALID_ROTOR_CONFIG_ERROR if the rotorConfig string is invalid
		 * @throws ENIGMA_INVALID_INIT_VECTOR_ERROR if the initVector is invalid
		 */
		WehrmachtMachine(const char* rotorConfig, const char* initVector, const char* plugboard);
		
		WehrmachtMachine(const char* rotorConfig, const char* initVector);
		
		void init(const char* rotorConfig, const char* initVector, const char* plugboard);
		void init(const char* rotorConfig, const char* initVector);

		void advance();
		char translate(char c);

		void resetPlugboard();
		void setPlugboardPair(char p1, char p2);
		void printPlugboard() { printf("Plugboard: %s\n", m_plugboard); }
		void setRotors(const char* rotorConfig);
		void setInitVector(const char* initVector);
};

 
 #endif
