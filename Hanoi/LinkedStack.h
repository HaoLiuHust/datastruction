#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include <iostream>
#include "Node.h"
#include "exceptionerror.h"

template<class T>
class LinkedStack
{
public:
	LinkedStack():top(0){}
	~LinkedStack();
	friend std::ostream& operator<<(std::ostream& output,const LinkedStack& s)
	{
		if (s.IsEmpty())
		{
			output << "empty stack" << std::endl;
		}
		else
		{
			Node<T>* p = s.top;
			while (p)
			{
				output << p->data << " ";
				p = p->next;
			}
		}

		return output;
	}
	bool IsEmpty()const{ return top == 0; }
	T Top()const;
	int Suantity()const;
	LinkedStack<T>& Add(const T& x);
	LinkedStack<T>& Delete(T& x);
private:
	Node<T>* top;
};

template<class T>
LinkedStack<T>::~LinkedStack()
{
	Node<T>* next;
	while (top)
	{
		next = top->next;
		delete top;
		top = next;
	}
}

template<class T>
T LinkedStack<T>::Top()const
{
	if (IsEmpty())
	{
		throw OutofBounds();
	}
	return top->data;
}

template<class T>
LinkedStack<T>& LinkedStack<T>::Add(const T& x)
{
	Node<T>* p = new Node<T>;
	p->data = x;
	p->next = top;
	top = p;

	return *this;
}

template<class T>
LinkedStack<T>& LinkedStack<T>::Delete(T& x)
{
	if (IsEmpty())
	{
		throw OutofBounds();
	}
	else
	{
		x = top->data;
		Node<T>* p = top;
		top = top->next;
		delete p;

		return *this;
		
	}
}

template<class T>
int LinkedStack<T>::Suantity()const
{
	Node<T>* p=top;
	int cnt = 0;
	while (p)
	{
		p = p->next;
		cnt++;
	}
	return cnt;
}
#endif