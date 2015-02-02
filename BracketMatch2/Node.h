#ifndef NODE_H
#define NODE_H
template<class T>
class LinkedStack;//����ģ����

template<class T>
class Node
{
public:
	friend class LinkedStack<T>;//����Ϊ��Ԫ����Ϊ��Ҫ����Node��˽�г�Ա
	friend std::ostream& operator<<(std::ostream& output, const LinkedStack<T>& s);
private:
	Node<T> *next;
	T data;
};
#endif