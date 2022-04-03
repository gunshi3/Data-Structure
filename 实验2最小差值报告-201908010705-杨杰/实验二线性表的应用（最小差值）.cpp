#include "List.h"
#include "AList.h"
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n=0;
	cin>>n;
	AList<int> A(n);
	int m=0;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		A.append(m);
	}
	int min=9999,temp=0;
	for(int i=0;i<A.length();i++)
	{
		for(int j=i+1;j<A.length();j++)
		{
			A.moveToPos(i);
			int a=A.getValue();
			A.moveToPos(j);
			int b=A.getValue();
			temp=abs(a-b);
			if(temp<min) min=temp;
		}
	}
	cout<<min;
}
