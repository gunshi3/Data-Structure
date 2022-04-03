#include <iostream>
#include "graphm.h"

using namespace std;
int main()
{
	int N,M;
	cin>>N>>M;
	Graphm<int>* G=new Graphm<int>(N);
	G->setType(0);
	for(int i=0;i<N;i++)
	{
		G->setVex(i,i+1);
		G->setEdge(i,i,1);
	}
	int a,b;
	for(int i=0;i<M;i++)
	{
		cin>>a>>b;
		G->setEdge(a-1,b-1,1);
	}
	for(int j=0;j<N;j++)
	{
		for(int i=0;i<N;i++)
		{
			if(i!=j&&G->isEdge(i,j))
			{
				for(int k=0;k<N;k++)
				{
					int temp=G->weight(i,k)+G->weight(j,k);
					G->setEdge(i,k,temp);
					temp=0;
				}
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(G->isEdge(i,j)) G->setEdge(j,i,1);
		} 
	}
	int flag=1,count=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(!G->isEdge(i,j))
			{
				flag=0;
				break;
			}
		}
		if(flag) count++;
		else flag=1;
	}
	cout<<count<<endl;
	return 0;
}
