// RecursiveExponentiation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int RecurseExp(int n, int ex);

int main()
{
	int num = 0;
	int ex = 0;
	cout << "Enter a number " << endl;
	cin >> num;
	cout << "Enter the exponentiation " << endl;
	cin >> ex;

	cout << "The recursive exponentiation is " << RecurseExp(num, ex) << endl;


	system("pause");
    return 0;
}

int RecurseExp(int n,int ex)
{
	if (ex == 1)
		return n;

	return (n*RecurseExp(n,ex-1));
}
