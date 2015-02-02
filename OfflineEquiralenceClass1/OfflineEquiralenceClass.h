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
	Chain<int>* C;//�洢�ȼ۹�ϵ������
	int num;//Ԫ�ظ���
	void findEquiralence();//���ҵȼ���
};


void offlineEC::findEquiralence()
{
	bool *outflag = new bool[num + 1];//��ʶ��ǰԪ���Ƿ��Ѿ������һ���ȼ�����
	LinkedStack<int> S;
	ChainIterator<int> CI;//�����������������е�Ԫ��

	for (int i = 1; i < num + 1; ++i)
	{
		outflag[i] = false;
	}

	for (int i = 1; i < num + 1; ++i)
	{
		if (!outflag[i])//��û�������������һ���µĵȼ���Ŀ�ʼ
		{
			cout << "�µĵȼ��ࣺ" << i;
			outflag[i] = true;
			S.Add(i);
			while (!S.IsEmpty())//����ջ��Ϊ�գ�˵��������������ȼ����Ԫ��
			{
				int j;
				S.Delete(j);
				int* q = CI.Initialize(C[j]);
				while (q)//������Ӧ��������Ϊһ�������ڵ�Ԫ������ͬһ���ȼ���
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
	cout << "����Ԫ�صĸ�����" << endl;
	cin >> n;
	if (n<2)
	{
		std::cerr << "error:Ԫ�ظ���̫��" << endl;
		exit(1);
	}

	cout << "�����ϵ�Եĸ�����" << endl;
	cin >> r;
	if (r<1)
	{
		std::cerr << "error:��ϵ������Ӧ��1��" << endl;
		exit(1);
	}

	offlineEC EC(n);
	cout << "�����ϵ�ԣ�" << endl;
	int a, b;
	for (int i = 0; i < r;++i)
	{
		cout << "����һ�Թ�ϵ�ԣ�";
		cin >> a;
		cin >> b;
		while (a>n||b>n||a<=0||b<=0)
		{
			std::cerr << "error:Ԫ��ֵ��������,��������" << endl;
			cout << "����һ�Թ�ϵ�ԣ�";
			cin >> a;
			cin >> b;
		}

		EC.C[a].Insert(0, b);
		EC.C[b].Insert(0, a);
	}

	EC.findEquiralence();
}
#endif