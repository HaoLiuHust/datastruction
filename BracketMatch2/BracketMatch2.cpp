// BracketMatch2.cpp : 定义控制台应用程序的入口点。
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
	cout << "输入一个字符串:" << endl;
	getline(cin, str);
	cout << "你输入的字符串是：" << str << endl;
	cout << "里面匹配的括号位置是" << endl;
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
				cout << "没有与" << i << "处右括号匹配的左括号" << endl;
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
		cout << "没有与" << j << "处左括号匹配的右括号" << endl;

	}
}