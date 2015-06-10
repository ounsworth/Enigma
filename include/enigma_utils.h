#ifndef ENIGMA_UTILS_H
#define ENIGMA_UTILS_H

#ifndef ALPHABET
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#endif

char cleanChar(char c);
void cleanText(char* msg, int len);

#endif
