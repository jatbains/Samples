// ModularExponentiation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(int x, unsigned int y, int p)
{
	int res = 1;      // Initialize result

	x = x % p;  // Update x if it is more than or 
				// equal to p

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res*x) % p;

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x*x) % p;
	}
	return res;
}

int main()
{
	int base = 2;
	int exp = 5;
	int mod = 5;
	int ans = 1;
	cout << "Enter the numbers" << endl;
	// First calculate the exponentiation 
	// Then do modulation
	for (int i = 1; i <= exp; i++)
	{
		ans *= base;
	}
	// Do mpdulation
	ans = ans%mod;

	cout << "Answer is " << ans << endl;

	cout << "Using method " << power(2, 5, 5) << endl;

	system("pause");
    return 0;
}

