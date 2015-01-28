#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include <iostream>
#include <new>

#include "exceptionerror.h"
template<class T>
class ArrayQueue
{
	
public:
	ArrayQueue(const int &MaxQueueSize = 10);
	~ArrayQueue()
	{ 
		if (queue!=NULL)
		{
			delete[] queue;
		}
	 }	
	bool IsEmpty()const{ return front == rear; }
	bool IsFull()const{ return (((rear + 1) % MaxSize == front) ? true : false); }
	T First()const;
	T Last()const;
	ArrayQueue<T>& Add(const T& x);
	ArrayQueue<T>& Delete(T& x);
	int Quantity()const;//返回队列中的元素个数
	friend std::ostream& operator<<(std::ostream & output, const ArrayQueue<T>& q)
	{
		if (q.IsEmpty())
		{
			output << "queue is empty" << std::endl;
			return output;
		}
		
		for (int i = (q.front + 1) % q.MaxSize; i <= q.rear; (++i) %= q.MaxSize)
		{
		output << q.queue[i] << " ";
		}
		
		output << std::endl;
		return output;
	}
private:
	int front;
	int rear;
	int MaxSize;
	T *queue;
};

template<class T>
ArrayQueue<T>::ArrayQueue(const int &MaxQueueSize=10):MaxSize(MaxQueueSize+1),front(0),rear(0)
{
	if (MaxSize>1)
	{
		try
		{
			queue = new T[MaxSize];
		}
		catch (const std::bad_alloc& e)
		{
			std::cerr << "memory error" << std::endl;
		}		
		
	}
}

template<class T>
T ArrayQueue<T>::First()const
{
	if (IsEmpty())
		throw OutofBounds();

	return queue[(front + 1) % MaxSize];
}

template<class T>
T ArrayQueue<T>::Last()const
{
	if (IsEmpty())
		throw OutofBounds();

	return queue[rear%MaxSize];
}

template<class T>
ArrayQueue<T>& ArrayQueue<T>::Add(const T& x)
{
	if (IsFull())
		throw NoMem();
	rear = (rear + 1) % MaxSize;
	queue[rear] = x;
	return *this;
}

template<class T>
ArrayQueue<T>& ArrayQueue<T>::Delete(T& x)
{
	if (IsEmpty())
	{
		throw OutofBounds();
	}

	front = (front + 1) % MaxSize;
	x = queue[front];
	return *this;
}

template<class T>
int ArrayQueue<T>::Quantity()const
{
	if (IsEmpty())
	{
		return 0;
	}
	else if (IsFull())
	{
		return MaxSize-1;
	}
	
	if ((front+1)%MaxSize<rear)
	{
		return rear - (front+1)%MaxSize+1;
	}
	else
	{
		return MaxSize-(front - rear);
	}
	 
}

#endif