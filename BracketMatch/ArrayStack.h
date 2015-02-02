#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include "exceptionerror.h"

template<class T>
class ArrayStack
{
public:
	ArrayStack(const int& MaxStackSize = 10);
	ArrayStack(T* s, const int& n,const int& MaxStackSize=10);
	~ArrayStack()
	{
		if (stack!=NULL)
		{
			delete[] stack;
		}
	}
	friend std::ostream& operator<<(std::ostream& output,const ArrayStack<T>& s)
	{
		if (s.IsEmpty())
		{
			output << "Stack is empty" << std::endl;
		}
		else
		{
			for (int i = 0; i <= s.top;++i)
			{
				output << s.stack[i] << " ";
			}
		}

		return output;
	}
	bool IsEmpty()const{ return top == -1; }
	bool IsFull()const{ return top == MaxTop; }
	T Top()const;
	ArrayStack<T>& Add(const T& x);
	ArrayStack<T>& Delete(T& x);
	int Quantity()const
	{
		return top + 1;
	}
private:
	int top;
	int MaxTop;
	T* stack;
};

template<class T>
ArrayStack<T>::ArrayStack(const int& MaxStackSize=10):MaxTop(MaxStackSize-1),top(-1)
{
	stack = new T[MaxStackSize];
}

template<class T>
ArrayStack<T>::ArrayStack(T* s, const int& n,const int& MaxStackSize):MaxTop(MaxStackSize-1),top(n-1)
{
	if (top>MaxTop)
	{
		throw OutofBounds();
	}
	else
	{
		stack = new T[MaxStackSize];
		memcpy(stack, s, n*sizeof(T));
	}
}

template<class T>
T ArrayStack<T>::Top()const
{
	if (IsEmpty())
	{
		throw OutofBounds();
	}
	else
		return stack[top];
	
}

template<class T>
ArrayStack<T>& ArrayStack<T>::Add(const T& x)
{
	if (IsFull())
	{
		throw NoMem();
	}
	else
	{
		stack[++top] = x;
		return *this;
	}
}

template<class T>
ArrayStack<T>& ArrayStack<T>::Delete(T& x)
{
	if (IsEmpty())
	{
		throw OutofBounds();
	}
	else
	{
		x=stack[top--];
		return *this;
	}
}
#endif