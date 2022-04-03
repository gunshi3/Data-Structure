#include <iostream>
#include "graphm.h"
#define INFINITY 9999
using namespace std;
int  minVertex(Graphm<int>* G,int* D)
{
	int i,v=-1;
	for(i=0;i<G->n();i++)
	{
		if(G->getMark(i)==0)
		{
			v=i;
			break;
		}
	}
	for(i++;i<G->n();i++)
	{
		if(G->getMark(i)==0&&D[i]<D[v])
		{
			v=i;
		}
	}
	return v;
}
void Dijkstra(Graphm<int>* G,int* D)
{
	int i,v,w;
	for(i=0;i<G->n();i++)
	{
		v=minVertex(G,D);
		if(D[v]==INFINITY) return;
		G->setMark(v,1);
		for(w=G->first(v);w<G->n();w=G->next(v,w))
		{
			if(D[w]>D[v]+G->weight(v,w))
			{
				D[w]=D[v]+G->weight(v,w);
			}
		}
	}
}
int main() 
{
	int n,m;
	cin>>n>>m;
	Graphm<int>* G=new Graphm<int>(n);
	int t,a,b,c;
	for(int i=0;i<m;i++)
	{
		cin>>t>>a>>b>>c;
		if(t) G->setEdge(a-1,b-1,c*c);
		else G->setEdge(a-1,b-1,c);
	}
	int D[n];
	D[0]=0;
	for(int i=1;i<n;i++)
	{
		D[i]=INFINITY;
	}
	Dijkstra(G,D);
	cout<<D[n-1];
	return 0;
}
