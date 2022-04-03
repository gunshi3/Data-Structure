#ifndef BINTREE
#define BINTREE
#include "BinNode.h"
#include <vector>
using namespace std;
template <typename Elem> 
class BinTree
{
	public:
		BinTree() {} //���캯�� 
		~BinTree() {} //�������� 
		virtual void setRoot(BinNode<Elem>* rt) = 0; //���ø���� 
		virtual BinNode<Elem>* getRoot() = 0; //���ظ���� 
		virtual void clear(BinNode<Elem>* rt) = 0; //��ն����� 
		virtual bool BinTreeEmpty(BinNode<Elem>* rt) = 0; //�ж϶������Ƿ�Ϊ���� 
		virtual void preorder(BinNode<Elem>* rt) = 0; //ǰ����� 
		virtual void Inorder(BinNode<Elem>* rt) = 0; //������� 
		virtual void postorder(BinNode<Elem>* rt) = 0; //������� 
		virtual void LevelOrderTraverse(BinNode<Elem>* rt) = 0; //��α��� 
		virtual int BinTreeDepth(BinNode<Elem>* rt) = 0; //��ö����������
		virtual int count(BinNode<Elem>* rt) = 0; //��ö������Ľ���� 
		virtual bool find(BinNode<Elem>* rt,const Elem& e) = 0; //���Ҷ��������Ƿ���Ԫ��e 
		virtual	int countLeft(vector<Elem>& v) = 0; //������������������Ľ���� 
		virtual BinNode<Elem>* CreateCBST(vector<Elem>& v) = 0; //������ȫ���������� 
};
#endif
