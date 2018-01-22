// MergeIntervals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


//*
//* Definition for an interval.
 typedef struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 }Interval;

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals);
};

vector<Interval> Solution::merge(vector<Interval> &intervals)
{
	// We get a vector of the intervals
	// Need to find overlapping intervals and return a 
	// vector of overlapping ones
	int list[21] = { 0 };   // has list of numbers
	int st = 0, en = 0;
	stack<Interval> iStack;
	vector<Interval>::iterator it;
	Interval temp;

	it = intervals.begin();

	iStack.push(*it);
	it++;

	for (; it != intervals.end(); it++)
	{
		temp = iStack.top();
		// Check with the top
		if (temp.end < it->start)
		{
			// No overlap
			iStack.push(*it);
		}
		// else overlap
		else if (temp.end > it->start)
		{
			temp.end = it->end;
			iStack.pop();
			iStack.push(temp);
		}

		//push onto stack and update if start is 
		// less than previous end

	}

	
	// Solve for overlap

	// Go through the intervals and check for overlap in the hash table
	// Processing a number line
	intervals.clear();
	while (!iStack.empty())
	{
		intervals.push_back(iStack.top());
		iStack.pop();
	}

	return intervals;
}



int main()
{
	Solution *mySol = new Solution();
	vector<Interval> vals = { {1,3},{2,6},{8,10},{15,18} };
	vector<Interval> merged;
	
	merged = mySol->merge(vals);

	vector<Interval>::iterator it;

	for (it = merged.begin(); it != merged.end(); it++)
	{
		cout << " Start " << it->start << " End " << it->end << endl;
	}


	system("pause");
    return 0;
}

