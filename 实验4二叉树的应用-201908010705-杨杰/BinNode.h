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
		BinNode() //���캯�� 
		{
			lc=NULL;
			rc=NULL;
		}
		BinNode(Elem tmp,BinNode* l=NULL,BinNode* r=NULL) //���캯��
		{
			e=tmp;
			lc=l;
			rc=r;
		}
		const Elem& getValue() const //���ؽ��ֵ 
		{
			return e;
		}
		void setValue(const Elem& tmp) //���ý��ֵ 
		{
			e=tmp;
		}
		BinNode* left() const //�������� 
		{
			return lc;
		}
		void setLeft(BinNode* l) //�������� 
		{
			lc=l;
		}
		BinNode* right() const //�����Һ��� 
		{
			return rc;
		}
		void setRight(BinNode* r) //�����Һ��� 
		{
			rc=r;
		}
		bool isLeaf() //�ж��Ƿ���Ҷ��� 
		{
			if(lc==NULL&&rc==NULL)
				return true;
			else 
				return false;
		}
};
#endif
