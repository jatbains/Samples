// EnglishInt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int x = 0;
	int thous = 0, hund = 0, ten = 0,sin=0;
	char *num[] = { "One","Two","Three","Four","Five","Six","Seven","Eight","Nine" };
	char *place[] = { "Thousand","Hundred","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
	cout << "Enter a number " << endl;

	cin >> x;
	thous = x / 1000;
	hund = x / 100;
	hund = hund % 10;
	ten = x / 10;
	ten = ten % 10;
	sin = x % 10;

	cout << "Number is : " << num[thous-1] << " " << place[0] << " " <<num[hund-1] << " " << place[1] << " " << place[ten ] << " " << num[sin-1] << endl;


	system("pause");
    return 0;
}

