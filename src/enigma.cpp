
#include <stdio.h>

#include "enigmaMachine.h"

#define DEBUG

#define helpStr "Usage:\n\n"\
"enigma -r ###[A]B -iv AAA[A] [-p AB]*"\
"\n\nEnigma takes its configuration via command-line parameters, and then encrypts/decrypts an input message on stdin, outputting the retult to stdout.\n\n"\
"Command-line Arguments:\n\n"\
"Usage:\n"\
"enigma -r ###[A]B [-p AB] -iv AAA[A] [-p CD]...\n\n"\
"-h -- print this help message.\n\n"\
"-r ###[A]B -- the rotor configuration, where # represents a number in {1-8,N} indicating which of the standard rotors to use, or the null rotor which returns the input letter, A is in {B,G,N} indicating special fourth rotor Beta, Gamma, or null for no 4rth rotor, and B is in {B,C,N} indicating reflector B, C, or null. Note that the 4th rotor [A] can be omitted from this string. Valid rotor configurations strings include \"123B\", \"456BB\", \"876GN\", etc. This argument must be present.\n\n"\
"-iv AAA[A] -- the initialization vector, where A is any letter in [A-Z]. The fourth letter is only used if a fourth rotor was specified.\n"\
"-p AB -- connects A and B on the plugboard. Note that A and B can be any upper or lower case letter. There may be zero or more \"-p AB\" arguments.\n\n"\
"\n"

/**
 *	Process command-line argument for plugboard plugs, and perform the appropriate operation on the given WehrmachtMachine
 */
void procPlugs(WehrmachtMachine* machine, const char* arg1, const char* arg2)
{
	if (strncmp(arg1, "-p", 2) == 0) {
		if (strnlen(arg2, 2) != 2) {
			#ifdef DEBUG
				printf("DEBUG: strlen(arg2) != 2");
			#endif
			return;
		}		
		machine->setPlugboardPair(arg2[0], arg2[1]);
		#ifdef DEBUG
		machine->printPlugboard();
		#endif
	}
}


int main( int argc, const char* argv[] )
{
	if (argc == 1 || strncmp(argv[1],"-h",2) == 0) {
		printf(helpStr);
		exit(0);
	}
	
	if(argc >= 2 && strncmp(argv[1], "-h", 2) == 0) {
		printf( helpStr );
	}
	
	// get the rotor config
	char rotorConfig[6];
	if(argc >= 3 && strncmp(argv[1], "-r", 2) == 0 && strnlen(argv[2], 4) >= 3) {
		strncpy(rotorConfig, argv[2], 5);
		rotorConfig[5] = '\0';
	} else {
		printf("Error: the first command-line argument must be \"-r ###[A]\" where \"###\" or \"###A\" represents the rotor configuration, as per the explanation in -h.");
		exit(0);
	}
	
	
	// get the initialization vector
	char initVector[5];
	if(argc >= 5 && strncmp(argv[3], "-iv", 3) == 0 && strnlen(argv[4], 4) >= 3) {
		strncpy(initVector, argv[4], 4);
		initVector[4] = '\0';
	} else {
		printf("Error: the second command-line argument must be \"-riv ###[#]\" where \"###\" or \"####\" represents the starting positions of the rotors, as per the explanation in -h.");
		exit(0);
	}
	
	#ifdef DEBUG
	printf("rotorConfig: \"%s\"\n", rotorConfig);
	printf("initVector: \"%s\"\n", initVector);
	#endif
	
	WehrmachtMachine machine;
	try {
		machine.init(rotorConfig, initVector);
		printf("Done Constructor\n");
	} catch (int e) {
		if ( e == ENIGMA_INVALID_ROTOR_CONFIG_ERROR )
			printf("ENIGMA_INVALID_ROTOR_CONFIG_ERROR: \"%s\"\n\n", rotorConfig);
		else if ( e == ENIGMA_INVALID_INIT_VECTOR_ERROR )
			printf("ENIGMA_INVALID_INIT_VECTOR_ERROR: \"%s\"\n\n", initVector);
		
		return 0;
	}
	printf("1\n");
	machine.resetPlugboard();	// this _should_ be done in the contructor, but for some reason it seems neccessary to have here :S
	printf("2\n");

	// process command-line params
	int i;
	for(i=5; i<=argc-2; i+=2) {
		#ifdef DEBUG
		printf("arg1: %s, arg2: %s\n", argv[i], argv[i+1]);
		#endif
		procPlugs(&machine, argv[i], argv[i+1]);
	}
	

	#ifdef DEBUG
	printf("Listening for stdin\n");
	#endif
	
	// stdin loop -- encrypt this and put it out to stdout
	char c;
	c = getchar();
  while (c != EOF) {
  	c = cleanChar(c);
  	if (c != 1) {
		// TODO!!
		c = machine.translate(c);
  		putchar(c);
  		machine.advance();
	}
	c = getchar();
  }

	return 0;
}
