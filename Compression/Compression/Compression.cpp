// Compression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "stdio.h"

void CompressedString(char *sourceStr);
int CountCharFreq(char *str, char myChar);
void CompressString(char *str, int num);

// String Compression
int main(int argc, char *argv[])
{
	char myString[20] = { 0 };
	char *compStr = NULL;
	printf("Enter your string \n");
	scanf_s("%s", myString,20);

	CompressedString(&myString[0]);

	printf("String is %s\n", myString);

}

void CompressedString(char *sourceStr)
{
	char *curChar = NULL;
	char *prevChar = NULL;
	char *compChar = NULL;
	curChar = sourceStr;
	int freq = 0;
	// GO through the string and compress in place.
	while (*curChar != '\0')
	{
		if (prevChar != NULL) {
			if (*curChar == *prevChar)
			{
				// Count the instances
				compChar = prevChar;
				freq = CountCharFreq(compChar, *prevChar);

				if (freq > 1)
				{
					// Call the Compression routine
					CompressString(curChar, freq);
					freq = 0;
				}
				// Modify preChar

			}
		}
	

		prevChar = curChar;
		curChar++;
	}


}
int CountCharFreq(char *str, char myChar)
{
	int count = 0;
	while ((*str == myChar) && (*str != '\0'))
	{
		count++;
		str++;
	}

	return count;
}

void CompressString(char *str, int num)
{
	// Character 
	char *temp = str;
	char myChar = *temp;
	// Frequency
	*temp = num+'0';
	char *copy = NULL;
	// Need to compress for char

	// Skip first
	temp++;
	str++;
	num -= 2;
	while ((char)*str == myChar)
	{
		// Advance to last char
		str++;
	}
	copy = str;
	while (copy != '\0')
	{
		num += 1;
		copy++;
	}
	// Copy remaining chars
	while ((*str != '\0')&& (num>0))
	{
		*temp = *str;
		temp++;
		str++;
		num--;
	}
	*str = '\0';
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
