#ifndef LIST
#define LIST
template<typename E> 
class List {        // List ADT �����������Ͷ���

private:

  void operator =(const List&) {}           // Protect assignment

  List(const List&) {}            // Protect copy constructor

public:

  List() {}                // Default constructor ���캯��

  virtual ~List() {}   // Basedestructor ��������

  // Clear contents from thelist, to make it empty. ����б��е�����

  virtual void clear() = 0;

 // Insert an element at the current location.

 // item: The element to be inserted �ڵ�ǰλ�ò���Ԫ��item

  virtual void insert(const E& item) = 0;

 // Append an element at the end of the list.

 // item: The element to be appended �ڱ�β���Ԫ��item

  virtual void append(const E& item) = 0;

 // Remove and return the current element.

 // Return: the element that was removed. ɾ����ǰԪ�أ���������Ϊ����ֵ

  virtual E remove() = 0;

 // Set the current position to the start of the list. ����ǰλ������Ϊ˳�����ʼ��

  virtual void moveToStart() = 0;

// Set the current position to the end of the list. ����ǰλ������Ϊ˳���ĩβ

  virtual void moveToEnd() = 0;

// Move the current position one step left. No change

 // if already at beginning. ����ǰλ������һ���������ǰλ������λ�Ͳ���

  virtual void prev() = 0;

 // Move the current position one step right. No change

 // if already at end. ����ǰλ������һ���������ǰλ����ĩβ�Ͳ���

  virtual void next() = 0;

 // Return: The number of elements in the list. �����б�ǰ��Ԫ�ظ���

  virtual int length() const = 0;

 // Return: The position of the current element. ���ص�ǰԪ�ص�λ��

  virtual int currPos() const = 0;

 // Set current position.

 // pos: The position to make current. ����ǰλ������Ϊpos

  virtual void moveToPos(int pos) = 0;

 // Return: The current element. ���ص�ǰԪ��

  virtual const E& getValue()  = 0;
};
#endif
