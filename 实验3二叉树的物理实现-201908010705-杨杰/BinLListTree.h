#include "BinNode.h"
#include "BinTree.h"
#include <iostream>
#include <queue>
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
};
