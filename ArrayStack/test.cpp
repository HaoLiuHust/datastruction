#include "ArrayStack.h"

int main()
{
	ArrayStack<int> S;
	std::cout << "S is empty? " << S.IsEmpty() << std::endl;
	S.Add(1);
	S.Add(2);
	S.Add(3);
	S.Add(4);
	S.Add(5);
	S.Add(6);
	std::cout << "S is :" << std::endl;
	std::cout << S;
	std::cout << std::endl;
	std::cout << "Quantity of S is " << S.Quantity() << std::endl;
	int x;
	S.Delete(x);
	std::cout << "Num Deleted is " << x << std::endl;
	std::cout << "S is :" << std::endl;
	std::cout << S;
	std::cout << std::endl;
	std::cout << "Quantity of S is " << S.Quantity() << std::endl;

	int a[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	ArrayStack<int> S2(a, 8);
	std::cout << "S2 is :" << std::endl;
	std::cout << S2;
	std::cout << std::endl;
	std::cout << "Quantity of S2 is " << S2.Quantity() << std::endl;
	system("pause");
	return 0;

}