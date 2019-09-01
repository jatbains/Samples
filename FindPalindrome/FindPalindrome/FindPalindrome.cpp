// FindPalindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
bool isPalindrome(char *s, char *t);
char * findPalinDrome(string str);

int main()
{
    
	std::string  myString;
	char *palin = NULL;

	std::cout << "Enter a string\n";

	std::cin >> myString;
	int len = myString.length();

	if (isPalindrome(&myString[0],&myString[len-1]))
	{
		cout << "This is a Palindrome\n";
	}
	else
	{
		cout << "Not a Palindrome\n";
	}

	// Check to see if a palindrome is in string
	palin = findPalinDrome(myString);
	if (palin)
	{
		cout << "Palindrome is ", palin;
	}

	getchar();
	return 0;
}

char * findPalinDrome(string str)
{
	char *p1 = NULL;
	char *p2 = NULL;
	char *t1 = NULL, *t2 = NULL;
	p1 = p2 = &str[0];
	int len = str.length();
	bool foundPalindrome = false;

	for (int x = 0; x < len; x++)
	{
		p2++;
	}
	p2--;

	// Go through the string and find palindrom substrings
	// if p1 == p2 while p1++ and p2-- then we have a palindrome
	//

	//   cyaeayd
	// p1 = c , p2 = d
	// abcdyaay
	// p1 = a; p2 = y
	// p1 = b
	// p2 = a
	// p2 = a
	// p2 = y
	// p2 = p1 = b
	// O(n2)

	t1 = p1;
	t2 = p2;
	// while ((foundPalindrome = isPalindrome(p1, p2)) != true)
	while (p1 < p2)
	{
		// Increment to next char
		// Search within this string
		// p2-- in a second loop
		p2 = t2;
		// while ((foundPalindrome = isPalindrome(p1, p2)) != true)
		while (p1 < p2)
		{
			if (isPalindrome(p1, p2))
			{
				foundPalindrome = true;
				break;
			}
			else {
				p2--;
			}
			
		}
		p1++;
		if (foundPalindrome)
		{
			break;
		}
	}
	// if true then return p1 termine p2
	//  *p2++ = '\0'
	if (foundPalindrome)
	{
		*p2++ = '\0';
		return t1;
	}
	p1 = t1;
	p2 = t2;
	// Cheack from the end
	//while ((foundPalindrome = isPalindrome(p1, p1)) != true)
	while (p1 < p2)
	{
		
		// Search in a second loop while incrementing p1++
		p1 = t1;
		//while ((foundPalindrome = isPalindrome(p1, p2)) != true)
		while (p1 < p2)
		{
			if (isPalindrome(p1, p2))
			{
				foundPalindrome = true;
				break;
			}
			else {
				p1++;
			}
		
		}
		p2--;
		if (foundPalindrome)
		{
			break;
		}
	}
	if (foundPalindrome)
	{
		*p2++ = '\0';
		return t1;
	}
	return NULL;
}

bool isPalindrome(char *s, char *t)
{

	while (s < t)
	{
		if (*s != *t)
		{
			return false;
		}
		s++;
		t--;
	}
	return true;
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
