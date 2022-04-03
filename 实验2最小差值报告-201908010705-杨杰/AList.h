#include"List.h"

#include<assert.h>

 

template<typename E>         // Array-based list implementation 基于数组的线性表实现

class AList : public List<E> {

private:

  int maxSize;         // Maximum size of list 顺序表的容量

  int listSize;                      // Number of list items now 目前的大小

  int curr;            // Position of current element 当前元素的位置

  E* listArray;                       // Array holding list elements 列表元素将存放到该数组中

public:

  AList(int size=100) {             // Constructor 构造函数

    maxSize = size;

    listSize = curr = 0;

    listArray = new E[maxSize];

  }

  ~AList() { delete [] listArray; }     // Destructor 析构函数

  void clear() {                    // Reinitialize the list 初始化顺序表

   delete [] listArray;             // Remove the array 删除原有数组

   listSize = curr = 0;               // Reset the size 重新设置列表参数

    listArray = new E[maxSize];     // Recreate array 新建空数组

  }

  // Insert "it" atcurrent position 在当前位置插入it

  void insert(const E& it) {

    assert(listSize < maxSize); //"List capacity exceeded"超出顺序表范围会断言终止程序

for(int i=listSize; i>curr; i--)  // Shift elements up 右移元素

      listArray[i] = listArray[i-1];         // to make room

    listArray[curr] = it;

    listSize++;                         //Increment list size 列表长度加一

  }

  void append(const E& it) {       // Append "it" 在顺序表的末尾追加it

    assert(listSize < maxSize);                 // 断言判断

    listArray[listSize++] = it;

  }

  // Remove and return thecurrent element. 删除并返回当前元素

  E remove() {

    assert((curr>=0) && (curr <listSize));     // No element 没有元素会断言终止程序

    E it = listArray[curr];             // Copy the element 拷贝当前元素

for(int i=curr; i<listSize-1; i++)                // Shift them down 左移元素

//listArray[curr]将被覆盖掉

      listArray[i] = listArray[i+1];

    listSize--;                            // Decrementsize 列表长度减一

    return it;

  }

  void moveToStart() { curr = 0; }        // Reset position. 将curr当前位置设置为开头

  void moveToEnd() { curr = listSize; }    // Set at end . 将curr设置为末尾

  void prev() { if (curr != 0) curr--; }             // Back up. 将curr前移一位

  void next() { if (curr < listSize) curr++;}       // Next. 将curr后移一位

 // Return list size 返回顺序表长度

  int length() const  { return listSize; }

 // Return current position 返回当前位置

  int currPos() const { return curr; }

  // Set current list position to "pos" 将当前位置curr设置为pos

  void moveToPos(int pos) {

assert ((pos>=0)&&(pos<=listSize));       // Pos out of range

//pos超出顺序表范围会断言终止程序

    curr = pos;

  }

  const E& getValue()  {                           // Returncurrent element 返回值是当前元素

assert((curr>=0)&&(curr<listSize));         //No current element

//当前位置超出范围时断言终止程序

    return listArray[curr];

  }

};
