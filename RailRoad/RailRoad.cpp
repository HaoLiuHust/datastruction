#include "RailRoad.h"
using std::cout;
using std::cin;

bool RailRoad(int r[], int n, int k)
{
	LinkedStack<int> *H;
	H = new LinkedStack<int>[k + 1];
	int NowOut = 1;//����ֱ���������ĳ����
	int MinH = n+2;//����춥����С�ĳ����
	int MinS;//��С����ŵĻ�����
	for (int i = 0; i < n;++i)
	{
		if (r[i]==NowOut)
		{
			cout << "������" << NowOut << "�����ֱ���ƶ�������" << std::endl;
			++NowOut;
			while (MinH == NowOut)//��黺�����С����ţ���������
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
	cout << "������" << MinH << "�ӻ����" << MinS << "�ƶ���������" << std::endl;
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
			cout << "������" << num << "�ƶ��������" << i << std::endl;
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
	cout << "������" << num << "�ƶ��������" << besttrack << std::endl;
	if (num < MinH)
	{
		MinH = num;
		MinS = besttrack;
	}

	return true;
}