#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
template<class T>
class BinaryTreeNode
{
	-
	friend void Visit(BinaryTreeNode<T> *);
	friend void InOrder(BinaryTreeNode<T> *);
	friend void PreOrder(BinaryTreeNode<T> *);
	friend void PostOrder(BinaryTreeNode<T> *);
	friend void LevelOrder(BinaryTreeNode<T> *);
public:
	//构造函数
	BinaryTreeNode(){ LeftChild = RightChild = 0; }
	BinaryTreeNode(const T& e){ data = e; LeftChild = RightChild = 0; }
	BinaryTreeNode(const T& e, BinaryTreeNode *l, BinaryTreeNode *r)
	{
		data = e;
		LeftChild = l;
		RightChild = r;
	}
private:
	T data;
	BinaryTreeNode<T> *LeftChild;//左子树
	BinaryTreeNode<T> *RightChild;//右子树
};

template<class T>
void Visit(BinaryTreeNode<T> *t)
{
	std::cout << t->data << " ";
}

template<class T>
void PreOrder(BinaryTreeNode<T> *t)
{
	if(t)
	{
		Visit(t);
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
}

template<class T>
void InOrder(BinaryTreeNode<T> *t)
{
	if(t)
	{
		InOrder(t->LeftChild);
		Visit(t);
		InOrder(t->RightChild);
	}
}

template<class T>
void PostOrder(BinaryTreeNode<T> *t)
{
	if (t)
	{
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		Visit(t);
	}
}


#endif
