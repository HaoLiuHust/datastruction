#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

template<class T>
class LinkedStack
{
	LinkedStack():top(0){}
	~LinkedStack();

	bool IsEmpty()const{ return top == 0; }
	T Top()const;
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
#endif