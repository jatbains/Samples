// FileCopy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{
	FILE *fd1;
	FILE *fd2;
	fstream file1;
	char val = ' ';
	char input[] = "This is an input string for this silly test";
	int size = sizeof(input) / sizeof(input[0]);
	// Open the source file
	char *messg = (char *)malloc(sizeof(char)*size);
	memset(messg, 0, size);

	fopen_s(&fd1, "Source", "w+");
	fwrite(input, sizeof(char), size, fd1);
	fclose(fd1);

	// Open the destination file
	memset(input, 0, size);
	// Read one byte at a time

	fopen_s(&fd1, "Source", "r+");
	fopen_s(&fd2, "Destination", "w+");
	while (val != '\0')
	{
		fread(&val, sizeof(char), 1, fd1);
		cout << val;
		// write this to new file 
		fwrite(&val, sizeof(char), 1, fd2);
	}

	fclose(fd1);
	fclose(fd2);

	//fread(input, sizeof(char), size, fd1);
	//fwrite(input, sizeof(char), size, fd2);


	cout << endl;
	system("pause");
    return 0;
}

