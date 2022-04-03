#ifndef BINNODE
#define BINNODE 
#include <iostream> 
template <typename Elem> 
class BinNode
{
	private:
		Elem e;
		BinNode* lc;
		BinNode* rc;
	public:
		BinNode() //构造函数 
		{
			lc=NULL;
			rc=NULL;
		}
		BinNode(Elem tmp,BinNode* l=NULL,BinNode* r=NULL) //构造函数
		{
			e=tmp;
			lc=l;
			rc=r;
		}
		const Elem& getValue() const //返回结点值 
		{
			return e;
		}
		void setValue(const Elem& tmp) //设置结点值 
		{
			e=tmp;
		}
		BinNode* left() const //返回左孩子 
		{
			return lc;
		}
		void setLeft(BinNode* l) //设置左孩子 
		{
			lc=l;
		}
		BinNode* right() const //返回右孩子 
		{
			return rc;
		}
		void setRight(BinNode* r) //设置右孩子 
		{
			rc=r;
		}
		bool isLeaf() //判断是否是叶结点 
		{
			if(lc==NULL&&rc==NULL)
				return true;
			else 
				return false;
		}
};
#endif
