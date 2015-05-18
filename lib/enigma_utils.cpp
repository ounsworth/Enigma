
#include <ctype.h>
#include <stdio.h>


char cleanChar(char c)
{

//printf("DEBUG:: cleanChar()\n");

	if (c == '\0') return c;
	
	c = toupper(c);
	
	// throw out non-alpha chars
	if (c >= 'A' && c <= 'Z') return c;
	else return '-';
}

void cleanText(char* msg, int len)
{
	char c;
	char newStr[len];
	int i, newI=0;
	for(i=0; i<len; i++) {
		c = msg[i];
		if(c == '\0') 
		{
		//	newStr[i] = '\0';
			break;
		}
		
		c = cleanChar(c);
		
		// throw out non-alpha chars
		if (c == 1) continue;
		
		newStr[newI++] = c;
	}
	
	// just to be safe
	newStr[newI] = '\0';
	for(i=0; i<len; i++)
	{
		msg[i] = newStr[i];
		if(msg[i] == '\0') break;
	}
}
