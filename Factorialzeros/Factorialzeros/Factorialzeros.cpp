// Factorialzeros.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
int Factorial(int n,int a[]);
int factorsoffive(int i);
int coutnFactZeros(int num);


int main()
{
	int num = 0;
	cout << "Enter a number " << endl;
	cin >> num;
	int numz = 0;
	int zero[2] = { 0 }; // first is instance of g and second is for 2
	// Get Factorial
	cout << "Factorial is " << Factorial(num,zero) << endl;


	// Find the trailing zeros
	// In bits a zero is 
	// Count both

	if (zero[0] > zero[1])
		numz = zero[1];
	else
		numz = zero[0];


	cout << "Number of zeros is " << coutnFactZeros(num) << endl;

	cout << "Memoized Values is " << numz << endl;

	system("pause");
    return 0;
}
int factorsoffive(int i)
{
	int count = 0;
	while (i % 5 == 0) {
		count++;
		i /= 5;
	}
	return count;
}
int coutnFactZeros(int num)
{
	int count = 0;
	for (int i = 2; i <= num; i++)
	{
		count += factorsoffive(i);
	}
	return count;
}

int Factorial(int n, int zero[])
{
	if (n == 0)
	{		
		return 1;
	}
	if ((n % 5) == 0)
		zero[0]++;
	if ((n % 2) == 0) {
		zero[1]++;
	}
	return (n*Factorial((n - 1),zero));
}