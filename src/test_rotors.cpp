#include <stdio.h>
#include <string.h>

#include "enigma_utils.h"
//#include "../include/rotor.h"
#include "rotors.h"


#define ALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"


void testOneChar(char c) {
	printf("Translating \'%c\' :\n",c);
	
	printf("\nRotor I:\n");
	Rotor3 rotor(0);
	
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
	
	char alpha[27] = ALPHA;
	
	printf("Testing the translation functions for typos, \"ABC..Z\"-> rotorX -> inv_rotorX =? \"ABC..Z\"\n");

	// Rotor I
	Rotor rotor = Rotor1(0);
	printf("\nRotor I:\n");
	
	int i;
	for(i=0; i<26; i++) {
		alpha[i] = rotor.translate(alpha[i]);
		alpha[i] = rotor.inv_translate(alpha[i]);
	}
	if( strcmp(alpha, ALPHA) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHA);
		printf("Output: %s\n", alpha);
	}
	
	
	// Rotor II
	rotor = Rotor2(0);
	printf("\nRotor II:\n");
	
	for(i=0; i<26; i++) {
		alpha[i] = rotor.translate(alpha[i]);
		alpha[i] = rotor.inv_translate(alpha[i]);
	}
	if( strcmp(alpha, ALPHA) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHA);
		printf("Output: %s\n", alpha);
	}
	
	
	// Rotor III
	rotor = Rotor3(0);
	printf("\nRotor III:\n");
	
	for(i=0; i<26; i++) {
		alpha[i] = rotor.translate(alpha[i]);
		alpha[i] = rotor.inv_translate(alpha[i]);
	}
	if( strcmp(alpha, ALPHA) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHA);
		printf("Output: %s\n", alpha);
	}
	
	
	// Rotor IV
	rotor = Rotor4(0);
	printf("\nRotor IV:\n");
	
	for(i=0; i<26; i++) {
		alpha[i] = rotor.translate(alpha[i]);
		alpha[i] = rotor.inv_translate(alpha[i]);
	}
	if( strcmp(alpha, ALPHA) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHA);
		printf("Output: %s\n", alpha);
	}
	
	
	// Rotor V
	rotor = Rotor5(0);
	printf("\nRotor IV:\n");
	
	for(i=0; i<26; i++) {
		alpha[i] = rotor.translate(alpha[i]);
		alpha[i] = rotor.inv_translate(alpha[i]);
	}
	if( strcmp(alpha, ALPHA) == 0 )
		printf("No Errors!\n");
	else {
		printf("There's a mistake somewhere.\n");
		printf("Input:  %s\n", ALPHA);
		printf("Output: %s\n", alpha);
	}
}
