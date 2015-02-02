#include "RailRoad.h"
using std::cout;
using std::cin;

bool RailRoad(int r[], int n, int k)
{
	LinkedStack<int> *H;
	H = new LinkedStack<int>[k + 1];
	int NowOut = 1;//可以直接移入出轨的车厢号
	int MinH = n+2;//缓冲轨顶部最小的车厢号
	int MinS;//最小车厢号的缓冲轨号
	for (int i = 0; i < n;++i)
	{
		if (r[i]==NowOut)
		{
			cout << "将车厢" << NowOut << "从入轨直接移动到出轨" << std::endl;
			++NowOut;
			while (MinH == NowOut)//检查缓冲轨最小车厢号，相等则输出
			{
				output(MinH, MinS, H, k, n);
				++NowOut;
			}
		}
		else
		{
			if(!movetocache(MinH, MinS, H, k, n, r[i]))
			{
				return false;
			}
		}			
	}

	return true;
}

void output(int& MinH, int& MinS, LinkedStack<int> *H, int k, int n)
{
	cout << "将车厢" << MinH << "从缓冲轨" << MinS << "移动到出轨上" << std::endl;
	H[MinS].Delete(MinH);
	MinH = n + 2;
	for (int i = 1; i < k + 1;++i)
	{
		if (!H[i].IsEmpty() && H[i].Top()<MinH)
		{
			MinH = H[i].Top();
			MinS = i;
		}
	}
}

bool movetocache(int &MinH, int &MinS, LinkedStack<int>* H, int k, int n, int num)
{
	

	int besttrack = 0;
	int BestTop = n + 1;
	int x;
	for (int i = 1; i < k + 1;++i)
	{
		if (H[i].IsEmpty())
		{
			H[i].Add(num);
			cout << "将车厢" << num << "移动到缓冲轨" << i << std::endl;
			if (num < MinH)
			{
				MinH = num;
				MinS = i;
			}
			return true;
		}

		x = H[i].Top();
		if (num<x&&x<BestTop)
		{
			BestTop = x;
			besttrack = i;
		}
	}

	if (!besttrack)
	{
		return false;
	}

	H[besttrack].Add(num);
	cout << "将车厢" << num << "移动到缓冲轨" << besttrack << std::endl;
	if (num < MinH)
	{
		MinH = num;
		MinS = besttrack;
	}

	return true;
}