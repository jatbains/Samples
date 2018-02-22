#pragma once

typedef struct KNode
{
	short index;
	long value;
	struct KNode *left;
	struct KNode *right;
};

class KDTree
{
private:
	KNode *root;
	KNode *InsertTree(KNode *node, int ind, long val, int depth);
	bool CompareVals(KNode *node, int ind, long val);
	bool SearchTree(KNode *node, int ind, long val, int depth);
	KNode *AllocNode(int ind, long val);
public:
	KDTree();
	void BuildTree(int ind, long val);
	KNode *Insert(KNode *node, int ind, long val);
	bool Search(int ind, long val);
};
