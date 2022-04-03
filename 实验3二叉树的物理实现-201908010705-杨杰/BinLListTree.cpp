#include "BinLListTree.h"
#include <iostream>
#include <vector>
using namespace std;
BinNode<int>* createTree(vector<int>& vpost,vector<int>& vin) //重构二叉树 
{
	if(vpost.empty()&&vin.empty()) return NULL;
	int rtVal=vpost.back();
	BinNode<int>* rt=new BinNode<int>;
	rt->setValue(rtVal);
	unsigned int j=0;
	for(unsigned int i=0;i<vin.size();i++)
	{
		if(vin[i]==rtVal)
		{
			j=i;
			break;
		}		
	}
	vector<int> vinl;
	vector<int> vinr;
	vector<int> vpostl;
	vector<int> vpostr;
	if(j) vinl.assign(vin.begin(),vin.begin()+j);
	if(j+1<=vin.size()-1) vinr.assign(vin.begin()+j+1,vin.end());
	if(j) vpostl.assign(vpost.begin(),vpost.begin()+j);
	if(j<=vpost.size()-2) vpostr.assign(vpost.begin()+j,vpost.end()-1);
	rt->setLeft(createTree(vpostl,vinl));
	rt->setRight(createTree(vpostr,vinr));
	return rt;
}
int main()
{
	vector<int> vpost;
	vector<int> vin;
	int n=0;
	cin>>n;
	int value=0;
	for(int i=0;i<n;i++)
	{ 	
		cin>>value;
		vpost.push_back(value);
	}
	for(int i=0;i<n;i++)
	{
		cin>>value;
		vin.push_back(value);
	}
	BinNode<int>* root=new BinNode<int>;
	root=createTree(vpost,vin);
	BinLListTree<int>* bT=new BinLListTree<int>;
	bT->setRoot(root);
	bT->LevelOrderTraverse(root); //层次遍历二叉树 
	return 0;
}
