
#include <stdio.h>

#include "enigmaMachine.h"

#define DEBUG 1

#define helpStr "Enigma takes its configuration via command-line parameters, and then encrypts/decrypts an input message on stdin, outputting the retult to stdout.\n\n"\
"Command-line Arguments (except where specified, there can be zero or more of each argument in any order):\n\n"\
"-h -- print this help message.\n"\
"-p AB -- connects A and B on the plugboard. Note that A and B can be any upper or lower case letter.\n"\
"\n"

/**
 *	Process command-line arguments, and perform the appropriate operation on the given WehrmachtMachine
 */
void procArgs(WehrmachtMachine* machine, const char* arg1, const char* arg2)
{
	if (strncmp(arg1, "-p", 2) == 0) {
		if (strnlen(arg2, 2) != 2) {
			#if DEBUG
				printf("DEBUG: strlen(arg2) != 2");
			#endif
			return;
		}
		
		machine->setPlugboardPair(arg2[0], arg2[1]);
	}
	
	#if DEBUG
	machine->printPlugboard();
	#endif
}


int main( int argc, const char* argv[] )
{
	if (argc == 1 || strncmp(argv[1],"-h",2) == 0) {
		printf(helpStr);
		exit(0);
	}
	
	WehrmachtMachine machine;
	machine.resetPlugboard();	// this _should_ be done in the contructor, but for some reason it seems neccessary to have here :S

	// process command-line params
	int i;
	for(i=1; i<=argc-2; i+=2) {
		#if DEBUG
		printf("arg1: %s, arg2: %s\n", argv[i], argv[i+1]);
		#endif
		procArgs(&machine, argv[i], argv[i+1]);
	}
	

	#if DEBUG
	printf("Listening for stdin\n");
	#endif
	
	// stdin loop -- encrypt this and put it out to stdout
	char c;
	c = getchar();
  while (c != EOF) {
  	c = cleanChar(c);
  	if (c != 1) {
  		putchar(c);
		}
		c = getchar();
  }


	return 0;
}
