// RepeatedDNASequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

void MaximumSeq(char dna[], int i, int r);
void MaxSeqDriver(char dna[]);

int main()
{
	char DNA[] = { 'A','C','G','T' };

	// We wish to find all comninations with 10 letters
	// The total number will be 10 Choose 4.  
	MaxSeqDriver(DNA);

	system("pause");
	return 0;


}

void MaxSeqDriver(char dna[])
{
	for (int j = 0; j < 4; j++)
	{
		MaximumSeq(dna, 0, 3);
		cout << dna[j] << endl;
	}
}

void MaximumSeq(char dna[], int i,int r)
{
	if (i == r)
	{
		return;
	}



	MaximumSeq(dna, i+1, r);
		

// Maximum sequence
	
}
