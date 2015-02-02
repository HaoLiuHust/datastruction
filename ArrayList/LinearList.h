#ifndef LINEARLIST_H
#define LINEARLIST_H
#include<iostream>
#include<cstdlib>
#include<new>
using std::cout;
using std::endl;
template<class T>
class LinearList
{
    public:
        LinearList(int MaxListSize=10);//构造函数
        virtual ~LinearList();
        bool IsEmpty()const
        {
            return length==0;
        }
        int Length()const {return length;}
        bool Find(int k,T& x)const;//返回第K个元素到中
        int Search(T& x)const;//返回x的位置
        LinearList<T>& Delete(int k,T& x);
        LinearList<T>& Insert(int k,const T& x);
        void Output(std::ostream& out)const;

    protected:
    private:
        int length;
        int MaxSize;
        T *element;
};

class NoMem
{
    public :
    NoMem(){
        cout<<"No Memory"<<endl;
    //std::exit(1);
    }

};

class OutofBounds
{
public :
    OutofBounds()
    {
        cout<<"Out of Bounds"<<endl;
    //std::exit(1);
    }
};


void my_new_handler()
{
    throw NoMem();
}

template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
    std::new_handler old_Handler=std::set_new_handler(my_new_handler);
    MaxSize=MaxListSize;
    element=new T[MaxSize];
    length=0;

}

template<class T>
LinearList<T>::~LinearList()
{
    delete[]element;
    MaxSize=0;
    length=0;
}

template<class T>
bool LinearList<T>::Find(int k,T&x)const
{
    if(k<0||k>length)
        return false;
     x=element[k-1];
     return true;
}

template<class T>
int LinearList<T>::Search(T &x)const
{
    int i=0;
    while(i<length&&element[i]!=x)
    {
        i++;
    }
    if(i==length) return 0;
    else return i+1;
}

template<class T>
LinearList<T>& LinearList<T>::Delete(int k,T &x)
{
    if(Find(k,x))
    {
        for(int i=k;i<length;++i)
        {
            element[i-1]=element[i];
        }
        length--;
        return *this;
    }
    else
    {
       throw OutofBounds();
    }
}

template<class T>
LinearList<T>& LinearList<T>::Insert(int k,const T &x)
{
    if(k<0||k>length)
    {
       throw OutofBounds();
    }
    else if(length==MaxSize)
    {
        throw NoMem();
    }
    else
        {
            for(int i=length;i>k;--i)
            {
                element[i]=element[i-1];
            }
            element[k]=x;
            length++;
            return *this;
        }
}

template<class T>
void LinearList<T>::Output(std::ostream& out)const
{
    for(int i=0;i<length;i++)
    {

        out<<element[i]<<" ";
    }
}

template<class T>
std::ostream& operator<<(std::ostream &out,const LinearList<T>& x)
{
    x.Output(out);
    return out;
}

#endif // LINEARLIST_H
