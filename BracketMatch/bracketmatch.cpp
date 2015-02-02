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
	cout << "����һ���ַ���:" << endl;
	getline(cin,str);
	cout << "��������ַ����ǣ�" << str << endl;
	cout << "����ƥ�������λ����" << endl;
	outputMatchedPairs(str);

	system("pause");
	return 0;
}

void outputMatchedPairs(const std::string& str)
{
	ArrayStack<char> S(str.length()+1);//ʵ������ջ��¼������
	ArrayStack<int> pos(str.length()+1);//��¼������λ��
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

	while (!pos.IsEmpty())//����ջ�л��������ţ���δƥ��
	{
		S.Delete(temp);
		pos.Delete(j);
		cout << "û����" << j << "��������ƥ���������" << endl;

	}
}