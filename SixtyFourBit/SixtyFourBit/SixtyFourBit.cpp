// SixtyFourBit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>



using namespace std;

class SixtyFour
{
public:
	SixtyFour(int32_t max, uint32_t min)
	{
		Major = max;
		Minor = min;
	}
	// Add two Numbers
	SixtyFour operator+(SixtyFour Number);
	uint32_t AddLowerNum(uint32_t low);
	int32_t AddHigherNum(int32_t high);

private:
	int32_t Major;
	uint32_t Minor;
};

uint32_t SixtyFour::AddLowerNum(uint32_t low)
{
	// Add Lower numbers check for overflow
	uint32_t overflow;

}

int32_t SixtyFour::AddHigherNum(int32_t high)
{


}

SixtyFour SixtyFour::operator+(SixtyFour Number)
{
	// Create a new class
	SixtyFour Result(0, 0);
	uint32_t overflow;
	uint32_t lowresult;
	// Add lower numbers check for overflow
	// lowresult = this->Minor + Number;


}

int main()
{
    return 0;
}

