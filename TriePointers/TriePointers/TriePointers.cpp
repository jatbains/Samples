// TriePointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const int MAX_CHAR = 256;

typedef struct TrieNode
{
	struct TrieNode *children[MAX_CHAR];

	// isEndOfWord is true if the node represents
	// end of a word
	bool isEndOfWord;
}TrieNode;

// Create and add elements to a trinode
TrieNode *AllocTNode(void);
void InsertString(string s1, int l, TrieNode *t);

bool FindKey(TrieNode *t, string s1, int l);

int main()
{ 
	TrieNode *root = NULL;
	string s = "Christmas";
	string p = "Hello";
	// Populate root
	root = AllocTNode();
	InsertString(s,0,root);

	cout << endl;

	cout << (FindKey(root, s, 0) ? "Key Found" : "Key Not Found") << endl;

	cout << endl;

	system("pause");
    return 0;
}
// Find char in string
TrieNode *AllocTNode(void)
{
	TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < MAX_CHAR; i++)
		pNode->children[i] = NULL;

	return pNode;
}

void InsertString(string s1,int l,TrieNode *t)
{
	if (l == s1.length())
	{
		t->isEndOfWord = true;
		return;
	}

	// Insert into trie
	char c = s1.at(l);
	if (t->children[c] == NULL)
	{
		t->children[c] = AllocTNode();
		// 
	}
	// Recur
	InsertString(s1, l + 1, t->children[c]);

}

bool FindKey(TrieNode *t, string s1,int l)
{
	// Quit when end of string and reach the EndofWord
	if (l == s1.length())
	{
		return t->isEndOfWord;   // True if key found
	}
	// go to next char and move down trie
	char c = s1.at(l);
	if (t->children[c] == NULL)
		return false;            // Not found

	return FindKey(t->children[c], s1, l + 1);

}
