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
		void clear(BinNode<Elem>* rt) //清空二叉树 
		{
			if(rt==NULL) return;
			if(rt->left()!=NULL)
				clear(rt->left());
			if(rt->right()!=NULL)
				clear(rt->right());
			delete rt;
			rt=NULL;
		}
		BinLListTree() //构造函数 
		{
			root=new BinNode<Elem>;
		}
		~BinLListTree() //析构函数 
		{
			clear(root);
			root=NULL;
		}
		void setRoot(BinNode<Elem>* rt) //设置根结点 
		{
			root=rt;
		}
		BinNode<Elem>* getRoot() //返回根结点 
		{
			return root;
		}
		bool BinTreeEmpty(BinNode<Elem>* rt) //判断二叉树是否为空树 
		{
			if(rt==NULL) return true;
			else return false;
		}
		void preorder(BinNode<Elem>* rt) //前序遍历 
		{
			if(rt==NULL) return;
			printf("%d ",rt->getValue());
			preorder(rt->left());
			preorder(rt->right()); 
		}
		void Inorder(BinNode<Elem>* rt) //中序遍历 
		{
			if(rt==NULL) return;
			Inorder(rt->left());
			printf("%d ",rt->getValue());
			Inorder(rt->right());
		}
		void postorder(BinNode<Elem>* rt) //后序遍历 
		{
			if(rt==NULL) return;
			postorder(rt->left());
			postorder(rt->right());
			printf("%d ",rt->getValue());
		}
		void LevelOrderTraverse(BinNode<Elem>* rt) //层次遍历
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
		int BinTreeDepth(BinNode<Elem>* rt) //获得二叉树的深度
		{
			if(rt==NULL) return 0;
			int ld=0,rd=0;
			if(rt->left()!=NULL)
				ld=BinTreeDepth(rt->left());
			if(rt->right()!=NULL)
				rd=BinTreeDepth(rt->right());
			return (ld>rd ? ld:rd)+1;
		}
		int count(BinNode<Elem>* rt) //获得二叉树的结点数 
		{
			if(rt==NULL) return 0;
			return count(rt->left())+count(rt->right())+1;
		}
		bool find(BinNode<Elem>* rt,const Elem& e) //查找二叉树中是否含有元素e
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
