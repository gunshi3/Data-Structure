#include "Link.h"
#include "List.h"
#include "LList.h"
#include<iostream>
using namespace std;
void print(LList<char> &L,int n);
int main()
{
    LList<char> L1(100);
    char c;
	while((c=getchar())!='\n')
		L1.append(c);		//调用链表中的append操作
	int l=0,n=0,o=0;
	char ch;
	for(int i=0;i<L1.length();i++)
	{
		L1.moveToPos(i);
		ch=L1.getValue();
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
			l++;
		else if(ch>='0'&&ch<='9')
		{
			n++;
			L1.remove();
			i--;
		}
		else
			o++;
	}
	int len=L1.length();
	cout<<l<<' '<<n<<' '<<o<<endl;
	print(L1,len);
	return 0;
}

/***********************

*function ofprint

*打印单链表中元素

************************/

void print(LList<char>& L,int n){
    	int i;
        for(i=0;i<n;i++){
            L.moveToPos(i);
            cout<<L.getValue()<<""; //调用getValue操作得到当前元素
        }
        cout<<endl<<endl;
}
