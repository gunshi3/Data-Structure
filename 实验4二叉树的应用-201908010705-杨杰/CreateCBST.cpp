#include <iostream>
#include <algorithm>
#include <vector>
#include "BinNode.h"
#include "BinTree.h"
#include "BinLListTree.h"
using namespace std;
int main()
{
	int N;
	cin>>N;
	vector<int> v;
	int value;
	for(int i=0;i<N;i++)
	{
		cin>>value;
		v.push_back(value);
	}
	sort(v.begin(),v.end());
	BinNode<int>* root=new BinNode<int>;
	BinLListTree<int>* bT=new BinLListTree<int>;
	root=bT->CreateCBST(v);
	bT->LevelOrderTraverse(root);
	return 0;
}
