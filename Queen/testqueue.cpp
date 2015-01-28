#include "ArrayQueue.h"

int main()
{
	ArrayQueue<int> Q(11);
	Q.Add(1);
	Q.Add(2);
	Q.Add(1);
	Q.Add(2);
	Q.Add(1);
	Q.Add(2);
	Q.Add(1);
	Q.Add(2);
	std::cout << Q;
	std::cout << Q.Quantity() << std::endl;
	int x;
	Q.Delete(x);
	std::cout << Q;
	std::cout << Q.Quantity() << std::endl;
	system("pause");
	return 0;
}