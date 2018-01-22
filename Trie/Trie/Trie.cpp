// Trie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Trie {
	const static int MAX_CHAR = 256;

public:
	class TNode
	{
	public:
		TNode * child[MAX_CHAR] = { NULL };
		int size = 0;    // Characters total
		bool isWordEnd;

		// Add The methods  Traverse down to a word
		// Add a word and allocate nodes recursively
		// count number of children  
		
		void AddWord(string s1);
		void AddWordRec(string s1, int l);
		int FindCount(string s1);
		int FindCountRec(string s1, int l);
		TNode *GetNode(char c)
		{
			TNode *p = child[c];
			if (p->child[c] != NULL)
			{
				// Traverse liked list
				return (child[c]);
			};
		};
		void SetNode(char c, TNode node)
		{
			child[c] = &node;
		}


	}tNode;
};

int Trie::TNode::FindCount(string s1)
{
	// Go through string to last node
	// Starting pointer
	char c = s1.at(0);

	TNode *p = child[c];  

	return FindCountRec(s1, 0);
	
}

int Trie::TNode::FindCountRec(string s1, int l)
{
	if (l == s1.length())
		return size;
	char c = s1.at(l);
	// Check to see if it is in the trie
	
	if (GetNode(c) == NULL)
	{
		return 0;
	}
	// Recurse
	FindCountRec(s1, l + 1);
}
void Trie::TNode::AddWordRec(string s1, int l)
{
	size++;
	if (l == s1.length())
		return;
	// Recur by getting characters and adding to the Trie
	char c = s1.at(l);
	// Check if it is Trie
	TNode *p = GetNode(c);
	if (p == NULL)
	{
		// Need to add it to the trie
		TNode child;
		if (c == '\0')
			child.isWordEnd = true;
		SetNode(c, child);
	}
	AddWordRec(s1, l + 1);
}

void Trie::TNode::AddWord(string s1)
{
	AddWordRec(s1, 0);
	
}


int main()
{
	// Create the Trie

	Trie myTrie;

	string s1 = "Christmas";
	
	myTrie.tNode.AddWord(s1);


	system("pause");
    return 0;
}

