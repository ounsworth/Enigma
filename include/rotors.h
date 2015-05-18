#ifndef ENIGMA_ROTOR_H
#define ENIGMA_ROTOR_H

#include <string.h>

#include "enigma_utils.h"


/**
 * Abstract class for an Enigma Rotor
 */
class Rotor
{
public:
	/** Construcors **/
	Rotor(char pos);
	Rotor() { Rotor(0); }
	
 	bool advance();
 	
 	char translate(char c);	 	
 	char inv_translate(char c);
 	
 	// should I also have translate(char* str) ?
 	
protected:
	int m_pos;
	char transitionTable[27];
	char inv_transitionTable[27];

};


/* The raw transition table for the five standard rotors for a Wehrmacht Enigma Machine:

Entry = ABCDEFGHIJKLMNOPQRSTUVWXYZ (rotor right side)   
        ||||||||||||||||||||||||||
I     = EKMFLGDQVZNTOWYHXUSPAIBRCJ
II    = AJDKSIRUXBLHWTMCQGZNPYFVOE
III   = BDFHJLCPRTXVZNYEIWGAKMUSQO
IV    = ESOVPZJAYQUIRHXLNFTGKDCMWB
V     = VZBRGITYUPSDNHLXAWMJQOFECK
*/ 


/**
 * Rotor 1 of the Wehrmacht Enigma machine
 */
class Rotor1 : public Rotor
{
	public:
		bool advance();
		
		/** Constructor */
		Rotor1(char pos) : Rotor(pos) {
			strcpy(transitionTable,    "EKMFLGDQVZNTOWYHXUSPAIBRCJ");
			strcpy(inv_transitionTable,"UWYGADFPVZBECKMTHXSLRINQOJ");
		}
};


/**
 * Rotor II of the Wehrmacht Enigma machine
 */
class Rotor2 : public Rotor
{
	public:
		bool advance();
		
		/** Constructor */
		Rotor2(char pos) : Rotor(pos) {
			strcpy(transitionTable, 		"AJDKSIRUXBLHWTMCQGZNPYFVOE");
			strcpy(inv_transitionTable, "AJPCZWRLFBDKOTYUQGENHXMIVS");
		}

};


/**
 * Rotor III of the Wehrmacht Enigma machine
 */
class Rotor3 : public Rotor
{
	public:
		bool advance();

		/** Constructor */
		Rotor3(char pos) : Rotor(pos) {
			strcpy(transitionTable, 		"BDFHJLCPRTXVZNYEIWGAKMUSQO");	
			strcpy(inv_transitionTable, "TAGBPCSDQEUFVNZHYIXJWLRKOM");
		}

};


/**
 * Rotor IV of the Wehrmacht Enigma machine
 */
class Rotor4 : public Rotor
{
	public:
		bool advance();

	/** Constructor */
	Rotor4(char pos) : Rotor(pos) {
		strcpy(transitionTable, 		"ESOVPZJAYQUIRHXLNFTGKDCMWB");
		strcpy(inv_transitionTable, "HZWVARTNLGUPXQCEJMBSKDYOIF");
	}

};


/**
 * Rotor V of the Wehrmacht Enigma machine
 */
class Rotor5 : public Rotor
{
	public:
		bool advance();

	/** Constructor */
	Rotor5(char pos) : Rotor(pos) {
		strcpy(transitionTable, 		"VZBRGITYUPSDNHLXAWMJQOFECK");
		strcpy(inv_transitionTable, "QCYLXWENFTZOSMVJUDKGIARPHB");
	}
};

void rotorFactory(int rotorNum, int pos, Rotor* dst);

#endif
