#ifndef NODE_H
#define NODE_H
template<class T>
class LinkedQueue;//����ģ����

template<class T>
class Node
{
public:
	friend class LinkedQueue<T>;//����Ϊ��Ԫ����Ϊ��Ҫ����Node��˽�г�Ա
	friend std::ostream& operator<<(std::ostream& output, const LinkedQueue<T>& q);
private:
	Node<T> *next;
	T data;
};
#endif