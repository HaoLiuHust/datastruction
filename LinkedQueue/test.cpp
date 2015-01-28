#include "LinkedQueue.h"

int main()
{
	LinkedQueue<int> Q;
	std::cout << "Q is Empty? "<<Q.IsEmpty() << std::endl;
	Q.Add(1);
	Q.Add(2);
	Q.Add(3);
	Q.Add(4);
	Q.Add(5);
	Q.Add(6);
	Q.Add(7);
	Q.Add(8);
	std::cout << "Quantity of Q is " << Q.Quantity() << std::endl;
	std::cout << "Q is:" << std::endl;
	std::cout << Q << std::endl;
	int x;
	Q.Delete(x);
	std::cout << "The num deleted is " << x << std::endl;
	std::cout << "Quantity of Q is " << Q.Quantity() << std::endl;
	std::cout << "Q is:" << std::endl;
	std::cout << Q << std::endl;
	system("pause");
	return 0;
}