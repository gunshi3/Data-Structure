#include "BinNode.h"
#include "BinTree.h"
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
template <typename Elem> 
class BinLListTree:public BinTree<Elem>
{
	private:
		BinNode<Elem>* root;
	public:
		void clear(BinNode<Elem>* rt) //��ն����� 
		{
			if(rt==NULL) return;
			if(rt->left()!=NULL)
				clear(rt->left());
			if(rt->right()!=NULL)
				clear(rt->right());
			delete rt;
			rt=NULL;
		}
		BinLListTree() //���캯�� 
		{
			root=new BinNode<Elem>;
		}
		~BinLListTree() //�������� 
		{
			clear(root);
			root=NULL;
		}
		void setRoot(BinNode<Elem>* rt) //���ø���� 
		{
			root=rt;
		}
		BinNode<Elem>* getRoot() //���ظ���� 
		{
			return root;
		}
		bool BinTreeEmpty(BinNode<Elem>* rt) //�ж϶������Ƿ�Ϊ���� 
		{
			if(rt==NULL) return true;
			else return false;
		}
		void preorder(BinNode<Elem>* rt) //ǰ����� 
		{
			if(rt==NULL) return;
			printf("%d ",rt->getValue());
			preorder(rt->left());
			preorder(rt->right()); 
		}
		void Inorder(BinNode<Elem>* rt) //������� 
		{
			if(rt==NULL) return;
			Inorder(rt->left());
			printf("%d ",rt->getValue());
			Inorder(rt->right());
		}
		void postorder(BinNode<Elem>* rt) //������� 
		{
			if(rt==NULL) return;
			postorder(rt->left());
			postorder(rt->right());
			printf("%d ",rt->getValue());
		}
		void LevelOrderTraverse(BinNode<Elem>* rt) //��α���
		{
			if(rt==NULL) return;
			queue<BinNode<Elem>*> q;
			q.push(rt);
			BinNode<Elem>* curr;
			while(!q.empty())
			{
				curr=q.front();
				if(curr->left()!=NULL)
					q.push(curr->left());
				if(curr->right()!=NULL)
					q.push(curr->right());
				printf("%d ",curr->getValue());
				q.pop();
			}
		}
		int BinTreeDepth(BinNode<Elem>* rt) //��ö����������
		{
			if(rt==NULL) return 0;
			int ld=0,rd=0;
			if(rt->left()!=NULL)
				ld=BinTreeDepth(rt->left());
			if(rt->right()!=NULL)
				rd=BinTreeDepth(rt->right());
			return (ld>rd ? ld:rd)+1;
		}
		int count(BinNode<Elem>* rt) //��ö������Ľ���� 
		{
			if(rt==NULL) return 0;
			return count(rt->left())+count(rt->right())+1;
		}
		bool find(BinNode<Elem>* rt,const Elem& e) //���Ҷ��������Ƿ���Ԫ��e
		{
			if(rt==NULL) return false;
			queue<BinNode<Elem>*> q;
			q.push(rt);
			BinNode<Elem>* curr;
			while(!q.empty())
			{
				curr=q.front();
				if(curr->left()!=NULL)
					q.push(curr->left());
				if(curr->right()!=NULL)
					q.push(curr->right());
				if(curr->getValue()==e) return true;
				q.pop();
			}
			return false;
		}
		int countLeft(vector<Elem>& v) //������������������Ľ���� 
		{
			int N=v.size();
			int n=0,x=0;
			n=log(N+1)/log(2); //��Ҷ��������������Ĳ��� 
			x=N-(pow(2,n)-1); //Ҷ����� 
 			x=min(x,int(pow(2,n-1))); //��������Ҷ����� 
 			x=x+pow(2,n-1)-1; //�������Ľ���� 
 			return x;
		}
		BinNode<Elem>* CreateCBST(vector<Elem>& v) //������ȫ���������� 
		{
			BinNode<Elem>* rt=new BinNode<Elem>;
			if(v.size()==1) //�����Ҷ��� 
			{
				rt->setValue(v[0]);
				return rt;
			}
			int x=countLeft(v); //������������������Ľ����
 			rt->setValue(v[x]); //����� 
 			vector<int> vl,vr;
 			vl.assign(v.begin(),v.begin()+x); //������ 
 			if(x+1<=v.size()-1) //�����������Ϊ�� 
				vr.assign(v.begin()+x+1,v.end()); //������ 
			rt->setLeft(CreateCBST(vl)); //��������������ȫ���������� 
			if(vr.size()) //�����������Ϊ��
				rt->setRight(CreateCBST(vr)); //��������������ȫ���������� 
 			return rt;
		}
};
