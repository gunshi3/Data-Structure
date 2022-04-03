#include<iostream>
#include<list>
using namespace std;
class Node
{
	private:
		int id;
	public:
		Node(int n);
		int getId();
};
Node::Node(int n)
{
	id=n;
}
int Node::getId()
{
	return id;
}
int main()
{
	list<Node> l;
	list<Node>::iterator it;
	int n=0,k=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		Node* t=new Node(i);
		l.push_back(*t);
	}
	it=l.begin();
	for(int i=1;l.size()>1;i++)
	{
		if(i%k==0||i%10==k) it=l.erase(it);
		else it++;
		if(it==l.end()) it=l.begin();
	}
	cout<<(*it).getId();
	return 0;
}
