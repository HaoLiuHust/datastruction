#include "RailRoad.h"
#include <iostream>

int main()
{
	int n=0, k=0;
	
	while (n<1||k<1)
	{
		std::cout << "�������(>0)�� ";
		std::cin >> n;
		std::cout << "���������(>0)��";
		std::cin >> k;
	}
	

	int *p = new int[n];
	std::cout << "����" << n << "�ڳ������" << std::endl;
	int i = 0;
	while (i<n)
	{
		std::cin >> p[i++];
	}

	if (!RailRoad(p,n,k))
	{
		std::cout << "����ʧ��" << std::endl;
	}

	system("pause");
	return 0;
}