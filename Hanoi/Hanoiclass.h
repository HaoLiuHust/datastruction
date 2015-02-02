#ifndef HANOICLASS_H
#define HANOICLASS_H
#include <iostream>
#include "LinkedStack.h"

using std::cout;
using std::endl;

class Hanoiclass
{
	friend void TowersOfHanoi(int);
public:
	void TowersOfHanoi(int n, int x, int y, int z);//µÝ¹é½â¾öººÅµËþ
private:
	LinkedStack<int> *S[4];
	void ShowState();//Êä³ö3¸öËþµÄ×´Ì¬
};

void Hanoiclass::TowersOfHanoi(int n, int x, int y, int z)
{
	if (n > 0)
	{
		TowersOfHanoi(n - 1, x, z, y);
		cout << "Move top disk from tower " << x << "to top of tower " << y << std::endl;
		int temp;
		S[x]->Delete(temp);//´ÓxËþ¶¥ÒÆ³öÅÌ×Ó
		S[y]->Add(temp);//ÅÌ×ÓÒÆÈëyËþ¶¥
		ShowState();
		TowersOfHanoi(n - 1, z, y, x);
	}
}

void TowersOfHanoi(int n)
{
	Hanoiclass X;
	for (int i = 1; i < 4;++i)
	{
		X.S[i] = new LinkedStack<int>;
	}

	for (int d = n; d>0;--d)
	{
		X.S[1]->Add(d);
	}
	X.ShowState();
	X.TowersOfHanoi(n, 1, 2, 3);
	
	delete X.S[2];
}

void Hanoiclass::ShowState()
{
	for (int i = 1; i < 4;++i)
	{
		cout << "Ëþ"<<i<<": ";
		if (!S[i]->IsEmpty())
		{
			cout << *S[i];
		}
		cout << endl;
	}
	
}
#endif