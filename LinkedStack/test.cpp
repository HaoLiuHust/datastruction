#include "LinkedStack.h"

int main()
{
	LinkedStack<int> S;
	std::cout << "S is Empty? " << S.IsEmpty() << std::endl;
	S.Add(1);
	S.Add(2);
	S.Add(3);
	S.Add(4);
	S.Add(5);
	S.Add(6);
	S.Add(7);
	S.Add(8);
	std::cout << "Suantity of S is " << S.Suantity() << std::endl;
	std::cout << "S is:" << std::endl;
	std::cout << S << std::endl;
	int x;
	S.Delete(x);
	std::cout << "The num deleted is " << x << std::endl;
	std::cout << "Suantity of S is " << S.Suantity() << std::endl;
	std::cout << "S is:" << std::endl;
	std::cout << S << std::endl;
	system("pause");
	return 0;
}