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
	
 	void advance();
 	
 	char translate(char c);	 	
 	char inv_translate(char c);
 	
 	bool nextCanAdvance();
 	
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

Additional rotors used by Kriegsmarine M3 and M4 only:
Entry = ABCDEFGHIJKLMNOPQRSTUVWXYZ (rotor right side)   
        ||||||||||||||||||||||||||
VI    = JPGVOUMFYQBENHZRDKASXLICTW
VII   = NZJHGRCXMYSWBOUFAIVLPEKQDT
VIII  = FKQHTLXOCBJSPDZRAMEWNIUYGV

The special fourth rotors, also called Zusatzwalzen or Greek rotors. Used on the Kriegsmarine M4 with thin reflectors only:
Entry = ABCDEFGHIJKLMNOPQRSTUVWXYZ (rotor right side)   
        ||||||||||||||||||||||||||
Beta  = LEYJVCNIXWPBQMDRTAKZGFUHOS
Gamma = FSOKANUERHMBTIYCWLQPZXVGJD


Rotor					Next left rotor steps when rotor steps from->to
I							Q -> R
II						E -> F
III						V -> W
IV						J -> K
V							Z -> A
VI VII VIII 	Z -> A and M -> N
*/ 


/**
 * Rotor I of the Wehrmacht Enigma machine
 */
class RotorI : public Rotor
{
	public:		
		/** Constructor */
		RotorI(char pos) : Rotor(pos) {
			strcpy(transitionTable,    "EKMFLGDQVZNTOWYHXUSPAIBRCJ");
			strcpy(inv_transitionTable,"UWYGADFPVZBECKMTHXSLRINQOJ");
		}
		
	 	bool nextCanAdvance();
};


/**
 * Rotor II of the Wehrmacht Enigma machine
 */
class RotorII : public Rotor
{
	public:
		/** Constructor */
		RotorII(char pos) : Rotor(pos) {
			strcpy(transitionTable, 		"AJDKSIRUXBLHWTMCQGZNPYFVOE");
			strcpy(inv_transitionTable, "AJPCZWRLFBDKOTYUQGENHXMIVS");
		}
		
	 	bool nextCanAdvance();

};


/**
 * Rotor III of the Wehrmacht Enigma machine
 */
class RotorIII : public Rotor
{
	public:
		/** Constructor */
		RotorIII(char pos) : Rotor(pos) {
			strcpy(transitionTable, 		"BDFHJLCPRTXVZNYEIWGAKMUSQO");	
			strcpy(inv_transitionTable, "TAGBPCSDQEUFVNZHYIXJWLRKOM");
		}
		
	 	bool nextCanAdvance();

};


/**
 * Rotor IV of the Wehrmacht Enigma machine
 */
class RotorIV : public Rotor
{
	public:
		/** Constructor */
		RotorIV(char pos) : Rotor(pos) {
			strcpy(transitionTable, 		"ESOVPZJAYQUIRHXLNFTGKDCMWB");
			strcpy(inv_transitionTable, "HZWVARTNLGUPXQCEJMBSKDYOIF");
		}
		
	 	bool nextCanAdvance();

};


/**
 * Rotor V of the Wehrmacht Enigma machine
 */
class RotorV : public Rotor
{
	public:
		/** Constructor */
		RotorV(char pos) : Rotor(pos) {
			strcpy(transitionTable, 		"VZBRGITYUPSDNHLXAWMJQOFECK");
			strcpy(inv_transitionTable, "QCYLXWENFTZOSMVJUDKGIARPHB");
		}
		
	 	bool nextCanAdvance();
};


/**
 * Rotor VI used by Kriegsmarine M3 and M4 Enigma machines only
 */
class RotorVI : public Rotor
{
	public:
		/** Constructor */
		RotorVI(char pos) : Rotor(pos) {
			strcpy(transitionTable, 		"JPGVOUMFYQBENHZRDKASXLICTW");
			strcpy(inv_transitionTable, "SKXQLHCNWARVGMEBJPTYFDZUIO");
		}
		
	 	bool nextCanAdvance();
};


/**
 * Rotor VII used by Kriegsmarine M3 and M4 Enigma machines only
 */
class RotorVII : public Rotor
{
	public:
		/** Constructor */
		RotorVII(char pos) : Rotor(pos) {
			strcpy(transitionTable, 		"NZJHGRCXMYSWBOUFAIVLPEKQDT");
			strcpy(inv_transitionTable, "QMGYVPEDRCWTIANUXFKZOSLHJB");
		}
		
	 	bool nextCanAdvance();
};


/**
 * Rotor VIII used by Kriegsmarine M3 and M4 Enigma machines only
 */
class RotorVIII : public Rotor
{
	public:
		/** Constructor */
		RotorVIII(char pos) : Rotor(pos) {
			strcpy(transitionTable, 		"FKQHTLXOCBJSPDZRAMEWNIUYGV");
			strcpy(inv_transitionTable, "QJINSAYDVKBFRUHMCPLEWZTGXO");
		}
		
	 	bool nextCanAdvance();
};


/**
 * Rotor Beta used by Kriegsmarine M4 machine with thin reflectors only
 */
class RotorBeta : public Rotor
{
	public:
		/** Constructor */
		RotorBeta(char pos) : Rotor(pos) {
			strcpy(transitionTable, 		"LEYJVCNIXWPBQMDRTAKZGFUHOS");
			strcpy(inv_transitionTable, "RLFOBVUXHDSANGYKMPZQWEJICT");
		}
		
	 	bool nextCanAdvance();
};


/**
 * Rotor Gamma used by Kriegsmarine M4 machine with thin reflectors only
 */
class RotorGamma : public Rotor
{
	public:
		/** Constructor */
		RotorGamma(char pos) : Rotor(pos) {
			strcpy(transitionTable, 		"FSOKANUERHMBTIYCWLQPZXVGJD");
			strcpy(inv_transitionTable, "ELPZHAXJNYDRKFCTSIBMGWQVOU");
		}
		
	 	bool nextCanAdvance();
};


void rotorFactory(char rotorNum, int pos, Rotor* dst);

#endif
