#include "Checkbox.h"
#include <istream>

int main()
{
	int net[] = { 1, 2, 3, 2, 1, 3, 4, 4 };	

	if (CheckBox(net, 8))
	{
		std::cout << "�ɲ��߿��غ�" << std::endl;
	}
	else
	{
		std::cout << "���ɲ��߿��غ�" << std::endl;
	}

	system("pause");

	return 0;
}