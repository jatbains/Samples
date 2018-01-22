// ReverseStringWord.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void ReverseWordsSentence(char *st);
void ReverseWords(char *beg, char *end);

int main()
{
	string sentence;
	cout << "Enter a sentence" << endl;
	
	getline(cin, sentence);


	ReverseWordsSentence((char *)sentence.c_str());



	system("pause");
    return 0;
}

void ReverseWordsSentence(char *st)
{
	char *s = st;
	char *p = st;
	char *q = NULL;
	char t;
	while (*p != '\0')
		p++;
	p--;
	ReverseWords(s, p);

	// String is reversed now
	// Reverse individual words
	cout << st << endl;
	s = st;
	q = st;
	p = st;
	while (*p != '\0')
	{
		p++;
		if (*p == '\0')
		{
			ReverseWords(s, p - 1);
		}
		else if (*p == ' ')
		{
			ReverseWords(s, p-1);
			s = p + 1;
		}

	}
	
	cout << st << endl;
}
void ReverseWords(char *beg, char *end)
{
	char t;
	while (beg < end)
	{
		t = *beg;
		*beg++ = *end;
		*end-- = t;
	}
}