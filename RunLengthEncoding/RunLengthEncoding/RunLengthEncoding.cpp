// RunLengthEncoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;
char* RLE(const char* input);

int main()
{
	const char *string = "AAAaaaBBBcccMMMnnnPPoGGGgggwwwWWW";
	char *runLE = nullptr;

	runLE = RLE(string);


	cout << runLE << endl;

	system("pause");
    return 0;
}

char* RLE(const char* input)
{
	const char * p = input;
	char sChar;
	char *s = &sChar;
	char frq = 0;        // No more than 9 of each character
	int len = strlen(input);
	char *oStr = (char *)malloc(2 * len + 1);  // Output string
	char *rLen = oStr;
											   // Got through the input string
											   // Start the encoding and count number of unique char and when it changes
											   // output the frequency to an output string
	while (*p != '\0')
	{
		*s = *p;   // set *s to first in a sequence
		frq = 0;   // set frequency to 0 for this sequence
		while (*p == *s)
		{

			frq++;
			p++;

		}
		// Output 
		*rLen = frq + '0';   // Count
		rLen++;
		*rLen = *s;    // Character
		rLen++;        // Move forward 
		p++;           // Move forward
	}

	*rLen = '\0';   // Terminate string

	return oStr;  // Pointer to string output

}