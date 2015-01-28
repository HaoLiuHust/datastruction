#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include <iostream>
#include <new>
#include "Node.h"
#include "exceptionerror.h"

template<class T>
class LinkedQueue
{
public:
	LinkedQueue():front(0),rear(0){}
	~LinkedQueue();
	friend std::ostream& operator<<(std::ostream& output,const LinkedQueue<T>& q)
	{
		if (q.IsEmpty())
		{
			output << "empty queue" << std::endl;
		}
		else
		{
			Node<T>* p = q.front;
			while (p)
			{
				output << p->data << " ";
				p = p->next;
			}			
		}

		return output;
	}
	bool IsEmpty()const{ return front == 0; }
	bool IsFull()const;
	T First()const;//返回第一个元素
	T Last()const;//返回最后一个元素
	LinkedQueue<T>& Add(const T& x);//添加元素
	LinkedQueue<T>& Delete(T& x);//删除元素
	int Quantity()const;//返回元素个数
private:
	Node<T> *front;
	Node<T> *rear;
};

template<class T>
LinkedQueue<T>::~LinkedQueue()
{
	Node<T>* next;
	while (front)
	{
		next = front->next;
		delete front;
		front = next;
	}
}

template<class T>
bool LinkedQueue<T>::IsFull()const
{
	Node<T>* p;
	try
	{
		p = new Node<T>;
		delete p;
		return false;
	}
	catch (CMemoryException* e)
	{
		return true;
	}
}

template<class T>
T LinkedQueue<T>::First()const
{
	if (IsEmpty())
	{
		throw OutofBounds();
	}

	return front->data;
}

template<class T>
T LinkedQueue<T>::Last()const
{
	if (IsEmpty())
	{
		throw OutofBounds();
	}

	return rear->data;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Add(const T& x)
{
	Node<T> *p = new Node<T>;
	p->data = x;
	p->next = 0;
	if (front)
	{
		rear->next = p;
	}
	else front = p;

	rear = p;
	return *this;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Delete(T& x)
{
	if (IsEmpty())
	{
		throw OutofBounds();
	}
	x = front->data;
	Node<T>* p = front;//为了释放front空间
	front = front->next;
	delete p;

	return *this;
}

template<class T>
int LinkedQueue<T>::Quantity()const
{
	if (IsEmpty())
	{
		return 0;
	}
	int count = 0;
	Node<T>* p = front;
	while (p)
	{
		p=p->next;
		count++;
	}

	return count;
}
#endif