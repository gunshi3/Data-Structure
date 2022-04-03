#include <iostream>
#include "graphl.h"

using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	Graphl<char>* G=new Graphl<char>(n);
	G->setType(0);
	char vex;
	for(int i=0;i<n;i++)
	{
		cin>>vex;
		G->setVex(i,vex);
	}
	char v1,v2;
	int weight;
	for(int i=0;i<m;i++)
	{
		cin>>v1>>v2>>weight;
		G->setEdge(G->locateVex(v1),G->locateVex(v2),weight);
	}
	int count=0,numVex=0,maxVex=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(G->isEdge(i,j)) 
			{
				cout<<'1'<<' ';
				count++;
			}
			else cout<<'0'<<' ';
		}
		cout<<endl;
		if(count>=numVex)
		{
			numVex=count;
			maxVex=i;
		}
		count=0;
	}
	cout<<G->getVex(maxVex)<<' '<<numVex;
	return 0;
}
