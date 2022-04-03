#include"List.h"

#include<assert.h>

 

template<typename E>         // Array-based list implementation ������������Ա�ʵ��

class AList : public List<E> {

private:

  int maxSize;         // Maximum size of list ˳��������

  int listSize;                      // Number of list items now Ŀǰ�Ĵ�С

  int curr;            // Position of current element ��ǰԪ�ص�λ��

  E* listArray;                       // Array holding list elements �б�Ԫ�ؽ���ŵ���������

public:

  AList(int size=100) {             // Constructor ���캯��

    maxSize = size;

    listSize = curr = 0;

    listArray = new E[maxSize];

  }

  ~AList() { delete [] listArray; }     // Destructor ��������

  void clear() {                    // Reinitialize the list ��ʼ��˳���

   delete [] listArray;             // Remove the array ɾ��ԭ������

   listSize = curr = 0;               // Reset the size ���������б����

    listArray = new E[maxSize];     // Recreate array �½�������

  }

  // Insert "it" atcurrent position �ڵ�ǰλ�ò���it

  void insert(const E& it) {

    assert(listSize < maxSize); //"List capacity exceeded"����˳���Χ�������ֹ����

for(int i=listSize; i>curr; i--)  // Shift elements up ����Ԫ��

      listArray[i] = listArray[i-1];         // to make room

    listArray[curr] = it;

    listSize++;                         //Increment list size �б��ȼ�һ

  }

  void append(const E& it) {       // Append "it" ��˳����ĩβ׷��it

    assert(listSize < maxSize);                 // �����ж�

    listArray[listSize++] = it;

  }

  // Remove and return thecurrent element. ɾ�������ص�ǰԪ��

  E remove() {

    assert((curr>=0) && (curr <listSize));     // No element û��Ԫ�ػ������ֹ����

    E it = listArray[curr];             // Copy the element ������ǰԪ��

for(int i=curr; i<listSize-1; i++)                // Shift them down ����Ԫ��

//listArray[curr]�������ǵ�

      listArray[i] = listArray[i+1];

    listSize--;                            // Decrementsize �б��ȼ�һ

    return it;

  }

  void moveToStart() { curr = 0; }        // Reset position. ��curr��ǰλ������Ϊ��ͷ

  void moveToEnd() { curr = listSize; }    // Set at end . ��curr����Ϊĩβ

  void prev() { if (curr != 0) curr--; }             // Back up. ��currǰ��һλ

  void next() { if (curr < listSize) curr++;}       // Next. ��curr����һλ

 // Return list size ����˳�����

  int length() const  { return listSize; }

 // Return current position ���ص�ǰλ��

  int currPos() const { return curr; }

  // Set current list position to "pos" ����ǰλ��curr����Ϊpos

  void moveToPos(int pos) {

assert ((pos>=0)&&(pos<=listSize));       // Pos out of range

//pos����˳���Χ�������ֹ����

    curr = pos;

  }

  const E& getValue()  {                           // Returncurrent element ����ֵ�ǵ�ǰԪ��

assert((curr>=0)&&(curr<listSize));         //No current element

//��ǰλ�ó�����Χʱ������ֹ����

    return listArray[curr];

  }

};
