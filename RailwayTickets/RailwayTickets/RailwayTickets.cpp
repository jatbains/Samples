// RailwayTickets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;


// This function calculates how railway sation can maximize profits
int maximizeProfits(int *val, int n, int m);


int main()
{
	int n = 3;                   // Total number of ticket windows
	int stall[3] = { 3,3,4 };    // Distribution of tickets among 3 windows with 3,3 ,4 tickets
	int m = 5;                   // Number to sell

	int *ticketDist;

	//cout << "Enter the number of ticket windows " << endl;
	//cin >> n;
	//cout << "Enter the number of tickets to sell " << endl;
	//cin >> m;

	ticketDist = new int[n];
	ticketDist = stall;

	//cout << "Enter the distribution of tickets " << endl;
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> ticketDist[i];
	//}

	cout << "The maximum profits are " << maximizeProfits(ticketDist, n, m) << endl;
	

	system("pause");
    return 0;
}

int maximizeProfits(int *val, int n, int m)
{
	vector<int> dist(val,val+n);      // Create a vector from the ticket distribution
	int sum = 0;
	
	// make a  max heap 
	make_heap(dist.begin(), dist.end());      

	for (int j = m; j != 0; j--)
	{
		// Pull off values from the heap  and add to the sum
		//  decrement value pulled off and push back onto the heap
		int max = dist.front();  //largest value

		// Move max value to end and heapify

		pop_heap(dist.begin(), dist.end());   
		dist.pop_back();                     // pop it out
		
		sum += max;
		// Decrement the max value and push vack onto the heap
		 
		if (max - 1) 
		{
			// insert m-1 into vector
			dist.push_back(max - 1);
			// heapify the vector

			push_heap(dist.begin(), dist.end());

		}
	}
	return sum;
}

