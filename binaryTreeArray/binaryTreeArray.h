#ifndef BINARYTREEARRAY_H
#define BINARYTREEARRAY_H
#include <iostream>

template<class T>
class arrayTree
{
public:
	arrayTree(T *t, int end) :data(t), Last(end){ }
	void preOrder(int i);//前序
	void inOrder(int i);//中序
	void postOrder(int i);//后序
	void levelOrder();//层级
	int getLeftChildPos(int i){ return (2 * i) > Last ? -1 : 2 * i; }
	int getRightChildPos(int i){ return (2 * i + 1) > Last ? -1 : 2 * i + 1; }
private:
	T* data;
	int Last;
};

template<class T>
void arrayTree<T>::preOrder(int i)
{
	if(Last==0)
	{
		std::cout << "empty tree" << std::endl;
		return;
	}
	if(i<=Last)
	{
		if (data[i-1] != 0)
		{
			std::cout << data[i-1] << " ";
		}
		if (getLeftChildPos(i) != -1)
			preOrder(getLeftChildPos(i));
		if (getRightChildPos(i) != -1)
			preOrder(getRightChildPos(i));
	}
}

template<class T>
void arrayTree<T>::inOrder(int i)
{
	if(Last==0)
	{
		std::cout << "empty tree" << std::endl;
		return;
	}
	if(i<=Last)
	{
		if(data[i-1]!=0)
		{
			if (getLeftChildPos(i) != -1)
				inOrder(getLeftChildPos(i));

			std::cout << data[i - 1] << " ";

			if (getRightChildPos(i) != -1)
				inOrder(getRightChildPos(i));
		}
	}
}

template<class T>
void arrayTree<T>::postOrder(int i)
{
	if(Last==0)
	{
		std::cout << "empty tree" << std::endl;
	}
	if(i<=Last)
	{
		if(data[i-1]!=0)
		{
			if (getLeftChildPos(i) != -1)
				postOrder(getLeftChildPos(i));
			if (getRightChildPos(i) != -1)
				postOrder(getRightChildPos(i));

			std::cout << data[i - 1] << " ";
		}
	}
}

template<class T>
void arrayTree<T>::levelOrder()
{
	int level = 1;
	int i = 1;
	while (i<=Last)
	{
		for (int j = 0; j < (1 << (level-1))&&i<=Last;++j,++i)
		{
			if (data[i-1]!=0)
			{
				std::cout << data[i - 1] << " ";
			}
		}
		std::cout<<std::endl;
		level++;
	}
}
#endif // !BINARYTREEARRAY_H



