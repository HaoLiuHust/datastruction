#include "binaryTreeArray.h"

int main()
{
	int a[] = { 1, 2, 3, 2, 5, 0, 0, 0, 0, 0,2, 0, 0, 0 };

	arrayTree<int> tree(a, 11);
	tree.preOrder(1);
	std::cout << std::endl;
	tree.inOrder(1);
	std::cout << std::endl;
	tree.postOrder(1);

	std::cout << std::endl;
	tree.levelOrder();
	system("pause");

	return 0;
}