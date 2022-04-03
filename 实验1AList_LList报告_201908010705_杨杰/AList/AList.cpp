#include "List.h"
#include "AList.h"
#include <iostream>
using namespace std;
void print(AList<char>& A,int n);
int main()
{
	AList<char> A(100);
	char c;
	while((c=getchar())!='\n')
	{
		A.append(c);
	}
	int l=0,n=0,o=0;
	char ch;
	for(int i=0;i<A.length();i++)
	{
		A.moveToPos(i);
		ch=A.getValue();
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
			l++;
		else if(ch>='0'&&ch<='9')
		{
			n++;
			A.remove();
			i--;
		}
		else
			o++;
	}
	cout<<l<<" "<<n<<" "<<o<<endl;
	int len=A.length();
	print(A,len);
	return 0;
}
/***********************

*function ofprint

*打印顺序表中元素

************************/

void print(AList<char>& A,int n){
    	int i;
        for(i=0;i<n;i++){
            A.moveToPos(i);
            cout<<A.getValue()<<""; //调用getValue操作得到当前元素
        }
        cout<<endl<<endl;
}
