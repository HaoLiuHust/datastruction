#ifndef NODE_H
#define NODE_H
template<class T>
class LinkedQueue;//声明模板类

template<class T>
class Node
{
public:
	friend class LinkedQueue<T>;//声明为友元，因为需要访问Node的私有成员
	friend std::ostream& operator<<(std::ostream& output, const LinkedQueue<T>& q);
private:
	Node<T> *next;
	T data;
};
#endif