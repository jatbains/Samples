// TrickyQuestions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

const static int N = 10;

int main()
{
	int x = 1;
	char *c = (char *)&x;
	int y = 5;
	unsigned int j = 0;
	void *p = NULL;
	cout << "\" Geeks Suck!! \"" << endl;

	if (!x^y)
		cout << "Equal" << endl;
	else
		cout << "Not equal" << endl;

	
	/*for (; cout << ++x << " " && x < N;)
	{ }*/

	while (cout << ++x << " " && x < N) {}
	cout << endl;

	cout << "Max is " << ~j << endl;

	x = x + y;
	y = x - y;
	x = x - y;

	cout << x << " " << y << endl;

	if (*c)
		cout << "Little Endian" << endl;
	else
		cout << "Big Endian" << endl;

	char *s = "Hello";

	printf("%s", s);
	cout << endl;
	printf(s);
	cout << endl;

	int num = 1024;
	int count = 0;
	while (num) 
	{
		num = num&(num - 1);
		count++;
	}
	cout << count << endl;

	cout << p << endl;

	system("pause");
    return 0;
}

