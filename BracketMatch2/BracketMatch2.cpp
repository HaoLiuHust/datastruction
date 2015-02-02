// BracketMatch2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "LinkedStack.h"

using std::cout;
using std::cin;
using std::endl;
void outputMatchedPairs(const std::string& str);

int _tmain(int argc, _TCHAR* argv[])
{
	std::string str;
	cout << "����һ���ַ���:" << endl;
	getline(cin, str);
	cout << "��������ַ����ǣ�" << str << endl;
	cout << "����ƥ�������λ����" << endl;
	outputMatchedPairs(str);

	system("pause");
	return 0;
}

void outputMatchedPairs(const std::string& str)
{
	LinkedStack<char> S;
	LinkedStack<int> pos;
	char temp;
	int j;
	for (int i = 1; i <= str.length(); ++i)
	{
		if (str[i - 1] == '(')
		{
			S.Add(str[i - 1]);
			pos.Add(i);
		}
		else if (str[i - 1] == ')')
		{
			if (S.IsEmpty())
			{
				cout << "û����" << i << "��������ƥ���������" << endl;
			}
			else
			{
				pos.Delete(j);
				S.Delete(temp);
				cout << "MatchedPairs: " << j << " " << i << endl;
			}
		}
	}

	while (!pos.IsEmpty())
	{
		S.Delete(temp);
		pos.Delete(j);
		cout << "û����" << j << "��������ƥ���������" << endl;

	}
}