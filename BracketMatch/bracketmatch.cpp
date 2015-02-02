#include <iostream>
#include <string>
#include "ArrayStack.h"
using std::cout;
using std::cin;
using std::endl;

void outputMatchedPairs(const std::string& str);
int main()
{
	std::string str;
	cout << "输入一个字符串:" << endl;
	getline(cin,str);
	cout << "你输入的字符串是：" << str << endl;
	cout << "里面匹配的括号位置是" << endl;
	outputMatchedPairs(str);

	system("pause");
	return 0;
}

void outputMatchedPairs(const std::string& str)
{
	ArrayStack<char> S(str.length()+1);//实例化堆栈记录左括号
	ArrayStack<int> pos(str.length()+1);//记录左括号位置
	char temp;
	int j;
	for (int i = 1; i <=str.length();++i)
	{
		if (str[i-1]=='(')
		{
			S.Add(str[i-1]);
			pos.Add(i);
		}
		else if(str[i-1]==')')
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

	while (!pos.IsEmpty())//若堆栈中还有左括号，则未匹配
	{
		S.Delete(temp);
		pos.Delete(j);
		cout << "没有与" << j << "处左括号匹配的右括号" << endl;

	}
}