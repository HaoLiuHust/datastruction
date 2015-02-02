#ifndef OFFLINEEQUIRALENCECLASS_H
#define OFFLINEEQUIRALENCECLASS_H

#include <iostream>
#include "Chain.h"
#include "LinkedStack.h"
using std::cout;
using std::cin;
using std::endl;

class offlineEC
{
public:
	offlineEC(int n):num(n)
	{
		C = new Chain<int>[n + 1];
	}

	~offlineEC(){
		if (C!=NULL)
		{
			delete[] C;
		}
	}

	friend void Offline_Equiralence();
	
private:
	Chain<int>* C;//存储等价关系的链表
	int num;//元素个数
	void findEquiralence();//查找等价类
};


void offlineEC::findEquiralence()
{
	bool *outflag = new bool[num + 1];//标识当前元素是否已经输出到一个等价类了
	LinkedStack<int> S;
	ChainIterator<int> CI;//迭代器，遍历链表中的元素

	for (int i = 1; i < num + 1; ++i)
	{
		outflag[i] = false;
	}

	for (int i = 1; i < num + 1; ++i)
	{
		if (!outflag[i])//若没有输出过，则是一个新的等价类的开始
		{
			cout << "新的等价类：" << i;
			outflag[i] = true;
			S.Add(i);
			while (!S.IsEmpty())//若堆栈不为空，说明还有属于这个等价类的元素
			{
				int j;
				S.Delete(j);
				int* q = CI.Initialize(C[j]);
				while (q)//遍历对应的链表，因为一个链表内的元素属于同一个等价类
				{
					if (!outflag[*q])
					{
						cout << " " << *q;
						outflag[*q] = true;
						S.Add(*q);
					}
					q = CI.Next();
				}
			}
			cout << endl;
		}
	}
}

void Offline_Equiralence()
{
	int n, r;
	cout << "输入元素的个数：" << endl;
	cin >> n;
	if (n<2)
	{
		std::cerr << "error:元素个数太少" << endl;
		exit(1);
	}

	cout << "输入关系对的个数：" << endl;
	cin >> r;
	if (r<1)
	{
		std::cerr << "error:关系对至少应有1个" << endl;
		exit(1);
	}

	offlineEC EC(n);
	cout << "输入关系对：" << endl;
	int a, b;
	for (int i = 0; i < r;++i)
	{
		cout << "输入一对关系对：";
		cin >> a;
		cin >> b;
		while (a>n||b>n||a<=0||b<=0)
		{
			std::cerr << "error:元素值输入有误,重新输入" << endl;
			cout << "输入一对关系对：";
			cin >> a;
			cin >> b;
		}

		EC.C[a].Insert(0, b);
		EC.C[b].Insert(0, a);
	}

	EC.findEquiralence();
}
#endif