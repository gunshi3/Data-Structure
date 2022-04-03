#ifndef BINTREE
#define BINTREE
#include "BinNode.h"
#include <vector>
using namespace std;
template <typename Elem> 
class BinTree
{
	public:
		BinTree() {} //构造函数 
		~BinTree() {} //析构函数 
		virtual void setRoot(BinNode<Elem>* rt) = 0; //设置根结点 
		virtual BinNode<Elem>* getRoot() = 0; //返回根结点 
		virtual void clear(BinNode<Elem>* rt) = 0; //清空二叉树 
		virtual bool BinTreeEmpty(BinNode<Elem>* rt) = 0; //判断二叉树是否为空树 
		virtual void preorder(BinNode<Elem>* rt) = 0; //前序遍历 
		virtual void Inorder(BinNode<Elem>* rt) = 0; //中序遍历 
		virtual void postorder(BinNode<Elem>* rt) = 0; //后序遍历 
		virtual void LevelOrderTraverse(BinNode<Elem>* rt) = 0; //层次遍历 
		virtual int BinTreeDepth(BinNode<Elem>* rt) = 0; //获得二叉树的深度
		virtual int count(BinNode<Elem>* rt) = 0; //获得二叉树的结点数 
		virtual bool find(BinNode<Elem>* rt,const Elem& e) = 0; //查找二叉树中是否含有元素e 
		virtual	int countLeft(vector<Elem>& v) = 0; //计算二叉树的左子树的结点数 
		virtual BinNode<Elem>* CreateCBST(vector<Elem>& v) = 0; //创建完全二叉搜索树 
};
#endif
