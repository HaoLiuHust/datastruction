#include "welcome.h"
#include "maze.h"

int main()
{
	//
	int n;
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 255|0);
	//cout << "hello world";
	//Welcome(n);

	int matrix[8][8] =
	{
		0, 0, 0, 0, 1, 0, 0, 0,
		0, 1, 0, 0, 1, 0, 0, 0,
		0, 1, 0, 0, 1, 0, 0, 0,
		0, 1, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 1, 0, 0, 1, 0,
		0, 0, 0, 1, 1, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0,

	};


	maze m((int*)matrix,8);
	m.OutputMaze();
	if (!m.FindPath())
	{
		cout << "û�д���ڵ����ڵ�·����" << endl;

	}
	
	
	
	system("pause");

	return 0;
}