#include "List.h"
#include "Link.h" 
#include<assert.h>

//This is the declaration for LList. It is split into two parts

//because it is too big to fit on one book page

//Linked list implementation

using namespace std;

template <typename E> class LList:public List<E> {

private:

 Link<E>* head;   // Pointer to list header ָ������ͷ���

 Link<E>* tail;    // Pointer to last element ָ���������һ�����

 Link<E>* curr;   // Access to current element ָ��ǰԪ��

  int cnt;              // Size of list ��ǰ�б��С

 

 void init() {      // Intialization helper method ��ʼ��

   curr = tail = head = new Link<E>();

   cnt = 0;

  }

 

 void removeall() {

   while(head != NULL) {

     curr = head;

     head = head->next;

     delete curr;

    }

  }

 

public:

 LList(int size=100) { init(); }         // Constructor ���캯��

 ~LList() { removeall(); }           // Destructor ��������

 void clear() { removeall(); init(); }   // Clear list����б�

  // Insert "it" atcurrent position �ڵ�ǰλ�ò��롰it��

 void insert(const E& it) {

   curr->next = new Link<E>(it, curr->next); 

   if (tail == curr) tail = curr->next; // New tail �µ�βָ��

   cnt++;

  }

 void append(const E& it) {       // Append "it" to list ���б��β��׷�ӡ�it��

   tail = tail->next = new Link<E>(it, NULL);

   cnt++;

  }

  // Remove and return current element ɾ�������ص�ǰԪ��

  E remove() {

   assert(curr->next != NULL);     //"Noelement" ����ǰû��Ԫ�����жϳ���

    E it = curr->next->element;      // Remember value ����Ԫ��ֵ

    Link<E>* ltemp = curr->next;    // Remember link node����ָ������Ϣ

   if (tail == curr->next) tail = curr;  // Reset tail ����βָ��

   curr->next = curr->next->next;  // Remove from list���б���ɾ��

    delete ltemp;                // Reclaim space ���տռ�

   cnt--;                         // Decrement the count ��ǰ�����ȼ�һ

   return it;

  }

 void moveToStart()            // Place curr at list start��curr����������ͷ��

    { curr = head; }

 void moveToEnd()   // Place curr at list end ��curr����������β��

    {curr = tail; }

// Move curr one step left; no change ifalready at front

// ��currָ����ǰ��һ��������Ѿ�ָ��ͷ���˾Ͳ���Ҫ�ı�

 void prev() {

   if (curr == head) return;  // No previous element ����ǰָ����ͷָ��ֱ�ӷ���

   Link<E>* temp = head;

    // March down list until we findthe previous element ѭ������ֱ���ҵ�ǰһ��Ԫ��

   while (temp->next!=curr) temp=temp->next;

   curr = temp;

  }

  // Move curr one step right; no changeif already at end 

  //��currָ��������һ��������Ѿ�ָ��β���˾Ͳ���Ҫ�ı�

 void next()

  {if (curr != tail) curr = curr->next; }

 

  int length() const  { return cnt; } // Return length ���ص�ǰ�б��С

 

  // Return the position of the current element ���ص�ǰԪ�ص�λ��

  int currPos() const {

   Link<E>* temp = head;

   int i;

   for (i=0; curr != temp; i++)

     temp = temp->next;

   return i;

  }

  // Move down list to "pos" position �����ƶ����б�pos��λ��

 void moveToPos(int pos) {

   assert ((pos>=0)&&(pos<=cnt));//"Position out of range" ���ڷ�Χ��

   curr = head;

   for(int i=0; i<pos; i++) curr = curr->next;

  }

 

 const E& getValue() const { // Return current element ���ص�ǰԪ��

   assert(curr->next != NULL);//"No value" ����Ϊ��

   return curr->next->element;

  }

};
