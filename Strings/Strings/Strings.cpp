// Strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <iostream>
#include <ostream>

int main()
{
	int i = 0;
	 std::string platform;

	 for (i = 0; i <= 12; i++)
	 {
		 platform = "The number is " + std::to_string(i);
		 std::cout << platform << std::endl;
	 }

	 getchar();
    return 0;
}

