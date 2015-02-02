#include "RailRoad.h"
#include <iostream>

int main()
{
	int n=0, k=0;
	
	while (n<1||k<1)
	{
		std::cout << "车厢节数(>0)： ";
		std::cin >> n;
		std::cout << "缓冲轨条数(>0)：";
		std::cin >> k;
	}
	

	int *p = new int[n];
	std::cout << "输入" << n << "节车厢次序：" << std::endl;
	int i = 0;
	while (i<n)
	{
		std::cin >> p[i++];
	}

	if (!RailRoad(p,n,k))
	{
		std::cout << "排序失败" << std::endl;
	}

	system("pause");
	return 0;
}