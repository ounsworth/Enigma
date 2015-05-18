#include "../include/utils.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	//char str[] = "This is a test string!";
	char c;
	
	c = getchar();
  while (c != EOF) {
  	c = cleanChar(c);
  	if (c != 1) {
  		putchar(c);
		}
		c = getchar();
  }
}
