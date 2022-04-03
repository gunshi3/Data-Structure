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
		int countLeft(vector<Elem>& v) //计算二叉树的左子树的结点数 
		{
			int N=v.size();
			int n=0,x=0;
			n=log(N+1)/log(2); //除叶结点外满二叉树的层数 
			x=N-(pow(2,n)-1); //叶结点数 
 			x=min(x,int(pow(2,n-1))); //左子树的叶结点数 
 			x=x+pow(2,n-1)-1; //左子树的结点数 
 			return x;
		}
		BinNode<Elem>* CreateCBST(vector<Elem>& v) //创建完全二叉搜索树 
		{
			BinNode<Elem>* rt=new BinNode<Elem>;
			if(v.size()==1) //如果是叶结点 
			{
				rt->setValue(v[0]);
				return rt;
			}
			int x=countLeft(v); //计算二叉树的左子树的结点数
 			rt->setValue(v[x]); //根结点 
 			vector<int> vl,vr;
 			vl.assign(v.begin(),v.begin()+x); //左子树 
 			if(x+1<=v.size()-1) //如果右子树不为空 
				vr.assign(v.begin()+x+1,v.end()); //右子树 
			rt->setLeft(CreateCBST(vl)); //创建左子树的完全二叉搜索树 
			if(vr.size()) //如果右子树不为空
				rt->setRight(CreateCBST(vr)); //创建右子树的完全二叉搜索树 
 			return rt;
		}
};
