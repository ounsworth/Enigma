#include <stdio.h>
#include <string.h>

#include "enigma_utils.h"
#include "rotors.h"
#include "reflectors.h"

#ifndef ALPHABET
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#endif


void testOneChar(char c) {
	printf("Translating \'%c\' :\n",c);
	
	printf("\nRotor I:\n");
	RotorI rotor(0);
	
	c = rotor.translate(c);
	printf("rotor.translate(c) = %c\n",c);
	
	
	c = rotor.inv_translate(c);
	printf("rotor.inv_translate(c) = %c\n",c);
}

int main(int argc, char *argv[]) {
	
	if (argc >= 2) {
		testOneChar(argv[1][0]);
		return 0;
	}
		
	printf("Testing the translation functions for typos, \"ABC..Z\"-> rotorX -> inv_rotorX =? \"ABC..Z\"\n");

	Rotor rotors[10];

	// Rotor I
	printf("\nRotor I:\n");
	rotorFactory(1, 0, &rotors[0]);
	char alpha[27] = ALPHABET;
	
	int i;
	for(i=0; i<26; i++) {
		alpha[i] = rotors[0].translate(alpha[i]);
		alpha[i] = rotors[0].inv_translate(alpha[i]);
	}
	if( strcmp(alpha, ALPHABET) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHABET);
		printf("Output: %s\n", alpha);
	}
	
	
	// Rotor II
	printf("\nRotor II:\n");
	rotorFactory(2, 0, &rotors[1]);
	strcpy(alpha, ALPHABET);
	
	for(i=0; i<26; i++) {
		alpha[i] = rotors[1].translate(alpha[i]);
		alpha[i] = rotors[1].inv_translate(alpha[i]);
	}
	if( strcmp(alpha, ALPHABET) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHABET);
		printf("Output: %s\n", alpha);
	}
	
	
	// Rotor III
	printf("\nRotor III:\n");
	rotorFactory(3, 0, &rotors[2]);
	strcpy(alpha, ALPHABET);
	
	for(i=0; i<26; i++) {
		alpha[i] = rotors[2].translate(alpha[i]);
		alpha[i] = rotors[2].inv_translate(alpha[i]);
	}
	if( strcmp(alpha, ALPHABET) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHABET);
		printf("Output: %s\n", alpha);
	}
	
	
	// Rotor IV
	printf("\nRotor IV:\n");
	rotorFactory(4, 0, &rotors[3]);
	strcpy(alpha, ALPHABET);
	
	for(i=0; i<26; i++) {
		alpha[i] = rotors[3].translate(alpha[i]);
		alpha[i] = rotors[3].inv_translate(alpha[i]);
	}
	if( strcmp(alpha, ALPHABET) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHABET);
		printf("Output: %s\n", alpha);
	}
	
	
	// Rotor V
	printf("\nRotor V:\n");
	rotorFactory(5, 0, &rotors[4]);
	strcpy(alpha, ALPHABET);
	
	for(i=0; i<26; i++) {
		alpha[i] = rotors[4].translate(alpha[i]);
		alpha[i] = rotors[4].inv_translate(alpha[i]);
	}
	if( strcmp(alpha, ALPHABET) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHABET);
		printf("Output: %s\n", alpha);
	}
	
	
	// Rotor VI
	printf("\nRotor VI:\n");
	rotorFactory(6, 0, &rotors[5]);
	strcpy(alpha, ALPHABET);
	
	for(i=0; i<26; i++) {
		alpha[i] = rotors[5].translate(alpha[i]);
		alpha[i] = rotors[5].inv_translate(alpha[i]);
	}
	if( strcmp(alpha, ALPHABET) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHABET);
		printf("Output: %s\n", alpha);
	}
	
	
	// Rotor VII
	printf("\nRotor VII:\n");
	rotorFactory(7, 0, &rotors[6]);
	strcpy(alpha, ALPHABET);
	
	for(i=0; i<26; i++) {
		alpha[i] = rotors[6].translate(alpha[i]);
		alpha[i] = rotors[6].inv_translate(alpha[i]);
	}
	if( strcmp(alpha, ALPHABET) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHABET);
		printf("Output: %s\n", alpha);
	}
	
	
	// Rotor VIII
	printf("\nRotor VIII:\n");
	rotorFactory(8, 0, &rotors[7]);
	strcpy(alpha, ALPHABET);
	
	for(i=0; i<26; i++) {
		alpha[i] = rotors[7].translate(alpha[i]);
		alpha[i] = rotors[7].inv_translate(alpha[i]);
	}
	if( strcmp(alpha, ALPHABET) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHABET);
		printf("Output: %s\n", alpha);
	}
	
	
	// Rotor Beta
	printf("\nRotor Beta:\n");
	rotorFactory('B', 0, &rotors[8]);
	strcpy(alpha, ALPHABET);
	
	for(i=0; i<26; i++) {
		alpha[i] = rotors[8].translate(alpha[i]);
		alpha[i] = rotors[8].inv_translate(alpha[i]);
	}
	if( strcmp(alpha, ALPHABET) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHABET);
		printf("Output: %s\n", alpha);
	}
	
	
	// Rotor Gamma
	printf("\nRotor Gamma:\n");
	rotorFactory('G', 0, &rotors[9]);
	strcpy(alpha, ALPHABET);
	
	for(i=0; i<26; i++) {
		alpha[i] = rotors[9].translate(alpha[i]);
		alpha[i] = rotors[9].inv_translate(alpha[i]);
	}
	if( strcmp(alpha, ALPHABET) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHABET);
		printf("Output: %s\n", alpha);
	}
	
	
	
	
	// Test the full rotor sequence 12345B
	printf("\nThe full rotor sequence 1234B\n");
	Reflector reflector = ReflectorB();
	strcpy(alpha, ALPHABET);
	
	int rot;
	for(i=0; i<26; i++) {
		// intentionally without rotor rotation, testing functionality incrementally
		for(rot=0; rot<5; rot++) {
				alpha[i] = rotors[rot].translate(alpha[i]);
		}	
		// reflect and go back
		alpha[i] = reflector.translate(alpha[i]);
		
		for(rot=4; rot>=0; rot--) {
				alpha[i] = rotors[rot].inv_translate(alpha[i]);
		}
	}
	
	// at this point it's enrypted. Now let's decrypt it!
	//printf("Intermediate: %s\n",alpha);
	
	for(i=0; i<26; i++) {
		for(rot=0; rot<5; rot++) {
			// intentionally without rotor rotation, testing functionality incrementally
				alpha[i] = rotors[rot].translate(alpha[i]);
		}	
		// reflect and go back
		alpha[i] = reflector.translate(alpha[i]);
		
		for(rot=4; rot>=0; rot--) {
			// intentionally without rotor rotation, testing functionality incrementally
				alpha[i] = rotors[rot].inv_translate(alpha[i]);
		}
	}
	
	if( strcmp(alpha, ALPHABET) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHABET);
		printf("Output: %s\n", alpha);
	}
	
	
}
