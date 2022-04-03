#include <iostream>
#include "graphm.h"
#include "graph.h"

using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	Graphm<char>* G=new Graphm<char>(n);
	G->setType(0);
	char val;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		G->putVex(i,val);
	}
	char v1,v2;
	int wt;
 	for(int i=0;i<m;i++)
 	{
 		cin>>v1>>v2>>wt;
 		G->setEdge(G->locateVex(v1),G->locateVex(v2),wt);
	}
	int maxv=n-1,count=0,maxnum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<G->weight(i,j)<<' ';
			if(G->isEdge(i,j))
			count++;
		}
		cout<<endl;
		if(count>=maxnum)
		{
			maxnum=count;
			maxv=i;
		}
		count=0;
	}
	cout<<G->getVex(maxv)<<' '<<maxnum;
	return 0;
} 
