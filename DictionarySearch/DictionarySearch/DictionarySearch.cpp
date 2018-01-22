// DictionarySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>	
#include <iostream>
#include <set>
#include <hash_set>
#include <cmath>
#include <algorithm>
#include <math.h>
#include <unordered_set>

using namespace std;

static int wordBreak(string s, unordered_set<string> dict, int l, int h);

int main()
{
	string c = "CatMat";
	
	unordered_set<string> dict;
	dict.insert("Cat");
	dict.insert("Mat");
	dict.insert("Ca");
	dict.insert("tM");
	dict.insert("t");
	dict.insert("a");
	dict.insert("C");
	dict.insert("Dog");
	dict.insert("og");
	dict.insert("Do");
	

    return 0;
}
 static int wordBreak(string s, unordered_set<string> dict, int l, int h)
 {

	if (l > h)
		return s.length();
	
	string temp = s.substr(l, h);
	if (dict.find(temp) != dict.end())
		return 0;

	string str = "";
	int min = s.length();
	for (int i = l; i < h; i++) {
		str += s[i];
		if (dict.find(str) != dict.end()) {
			min = std::min(min, wordBreak(s, dict, i + 1, h) + 1);
		}
	}
	return min;
}
