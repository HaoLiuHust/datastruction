#ifndef CHAIN_H
#define CHAIN_H

#include<iostream>
#include "exceptionerror.h"
using std::cout;
using std::endl;

template<class T>
class Chain;

template <class T>
class ChainIterator;

template<class T>
class ChainNode
{
    friend Chain<T>;
	friend ChainIterator<T>;
    private:
        T data;
        ChainNode<T> *link;
};

template<class T>
class ChainIterator
{
public:
    T* Initialize(const Chain<T>& c)
    {
        location=c.first;
        if(location)
            return &location->data;
        return 0;
    }
    T* Next()
    {
        if(!location) return 0;
        location=location->link;
        if(location) return &location->data;
        return 0;
    }
private:
    ChainNode<T> *location;
};


template<class T>
class Chain
{
    friend ChainIterator<T>;
    public:
        Chain(){first=0;};
        virtual ~Chain();
        bool IsEmpty()const {return first==0;}
        int Length()const;
        bool Find(int k,T& x)const;
        int Search(const T& x)const;
        Chain<T>& Delete(int k,T& x);
        Chain<T>& Insert(int k,const T& x);
        void Erase();
        Chain<T>& Append(const T& x);
        void Output(std::ostream& out)const;
        void Binsort(int range,int(*value)(T& x));
    protected:
    private:
        ChainNode<T> *first;//Point to first node
        ChainNode<T> *last;
};

template<class T>
void Chain<T>::Binsort(int range,int(*value)(T& x))
{
    int b;//箱子索引号
    ChainNode<T> **bottom,**top;
    //箱子初始化
    bottom=new ChainNode<T>*[range+1];
    top=new ChainNode<T>*[range+1];
    for(b=0;b<=range;b++)
    {
        bottom[b]=0;
    }

    for(;first;first=first->link)
    {
        b=value(first->data);
        if(bottom[b])
        {
            top[b]->link=first;
            top[b]=first;
        }
        else
        {
            bottom[b]=top[b]=first;
        }
    }

    ChainNode<T> *y=0;
    for(b=0;b<=range;b++)
    {
        if(bottom[b])
        {
            if(y)
                y->link=bottom[b];
            else
                first=bottom[b];

            y=top[b];
        }
    }
        if(y) y->link=0;
        delete[] bottom;
        delete[] top;

}

template<class T>
Chain<T>& Chain<T>::Append(const T& x)
{
    ChainNode<T> *y=new Chain<T>();
    y->data=x;
    y->link=0;
    if(first)
    {
        last->link=y;
        last=y;
    }
    else
    {
        first=last=y;
    }

    return *this;
}



template<class T>
void Chain<T>::Erase()
{
    ChainNode<T> *next;
    while(first)
    {
        next=first->link;
        delete first;
        first=next;
    }
}

template<class T>
Chain<T>::~Chain()
{
    ChainNode<T> *next;
    while(first)
    {
        next=first->link;
        delete first;
        first=next;
    }
}

template<class T>
int Chain<T>::Length()const
{
    ChainNode<T> *current=first;
    int len=0;
    while(current)
    {
        len++;
        current=current->link;
    }
    return len;
}

template<class T>
bool Chain<T>::Find(int k,T& x)const
{
    if(k<1) return false;
    ChainNode<T> *current=first;
    int index=1;
    while(index<k&&current)
    {
        current=current->link;
        index++;

    }
    if(current)
    {
        x=current->data;
        return true;
    }
    return false;
}

template<class T>
int Chain<T>::Search(const T &x)const
{
    ChainNode<T> *current=first;
    int index=1;
    while(current&&current->data!=x)
    {
        current=current->link;
        index++;
    }
    if(current) return index;
    return false;
}

template<class T>
void Chain<T>::Output(std::ostream& out)const
{
    ChainNode<T> *current=first;
    for(current=first;current;current=current->link)
    {
        out<<current->data<<" ";
    }

}

template<class T>
std::ostream& operator<<(std::ostream& output,const Chain<T> &x)
{
    x.Output(output);
    return output;
}

template<class T>
Chain<T>& Chain<T>::Delete(int k,T& x)
{
    if(k<1||!first)
        throw OutofBounds();
    ChainNode<T> *p=first;
    if(k==1)
        first=first->link;
    else
    {
        ChainNode<T> *q=first;
        for(int index=1;index<k-1&&q;index++)
        {
            q=q->link;
        }
        if(!q||q->link)
            throw OutofBounds();
        p=q->link;
        if(p==last){last=q;}
        q->link=p->link;
    }
    x=p->data;
    delete p;
    return *this;
}

template<class T>
Chain<T>& Chain<T>::Insert(int k,const T &x)
{
    if(k<0)
        throw OutofBounds();
    ChainNode<T> *p=first;
    for(int index=1;index<k&&!p;++index)
    {
        p=p->link;
    }
    if(k>0&&!p) throw OutofBounds();
    ChainNode<T> *y=new ChainNode<T>;
    y->data=x;
    if(k)
    {
        y->link=p->link;
        p->link=y;
    }
    else
    {
        y->link=first;
        first=y;
    }
    if(!y->link)
        last=y;
    return *this;
}
#endif // CHAIN_H
