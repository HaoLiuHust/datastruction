#include "maze.h"
maze::maze(int m) :n(m)
{
	mazem = new int*[n + 2];
	for (int i = 0; i < n + 2; ++i)
	{
		mazem[i] = new int[n + 2];
	}
	for (int i = 0; i < n + 2;++i)
	{
		mazem[0][i] = 1;
		mazem[i][0] = 1;
		mazem[n + 1][i] = 1;
		mazem[i][n + 1] = 1;
	}
	
}

maze::maze(int* matrix, int m):n(m)
{
	mazem = new int*[n + 2];
	for (int i = 0; i < n + 2; ++i)
	{
		mazem[i] = new int[n + 2];
	}
	for (int i = 0; i < n + 2; ++i)
	{
		mazem[0][i] = 1;
		mazem[i][0] = 1;
		mazem[n + 1][i] = 1;
		mazem[i][n + 1] = 1;
	}

	for (int rows = 1; rows < n + 1;++rows)
	{
		for (int cols = 1; cols < n + 1;++cols)
		{
			mazem[rows][cols] = *(matrix+(rows - 1)*m+cols-1);
		}
	}
}

maze::~maze()
{
	if (mazem != NULL)
	{
		for (int i = 0; i < n + 2; ++i)
		{
			if (mazem[i] != NULL)
			{
				delete[] mazem[i];
			}
		}

		delete[] mazem;
	}
}

bool maze::FindPath()
{
	cout << "开始查找路径..." << endl;
	position current = { 1, 1 };//当前位置
	mazem[1][1] = 1;//阻止返回入口

	path = new LinkedStack<position>;
	position offset[4];
	offset[0].row = 0; offset[0].col = 1;//右
	offset[1].row = 1; offset[1].col = 0;//下
	offset[2].row = 0; offset[2].col = -1;//左
	offset[3].row = -1; offset[3].col = 0;//上

	int option = 0;
	int LastOption = 3;
	while (current.row != n || current.col != n)
	{
		int r, c;
		while (option <= LastOption)
		{
			r = current.row + offset[option].row;
			c = current.col + offset[option].col;
			if (mazem[r][c] == 0) break;

			option++;
		}

		if (option <= LastOption)
		{
			path->Add(current);
			current.row = r;
			current.col = c;
			mazem[r][c] = 1;
			option = 0;
		}
		else
		{
			if (path->IsEmpty())
			{
				return false;
			}
			position next;
			path->Delete(next);
			if (next.row == current.row)
			{
				option = 2 + next.col - current.col;
			}
			else
			{
				option = 3 + next.row - current.row;
			}

			current = next;
		}

	}
	
	cout << "查找完毕,如下图." << endl;
	ShowPath();
	return true;
}

void maze::InputMaze()
{
	
	for (int rows = 1; rows < n + 1; ++rows)
	{
		int flag = 1;
		cout << "请输入第" << rows << "行：" << endl;
		while (flag)
		{
			for (int cols = 1; cols < n + 1; ++cols)
			{
				cin >> mazem[rows][cols];
			}
			cout << "输入的第" << rows << "行为：";
			for (int cols = 1; cols < n + 1; ++cols)
			{
				cout << mazem[rows][cols] << " ";
			}

			if (mazem[1][1] == 1)
			{
				cout << "入口应没有障碍物，请重新输入。" << endl;
			}

			if (mazem[n][n] == 1)
			{
				cout << "出口应没有障碍物，请重新输入。" << endl;
			}
			cout << endl;
			cout << "重新输入请输入1，继续请输入其他数字:" << endl;
			cin.sync();
			int temp;
			cin >> temp;
			if (temp == 1)
			{
				flag = 1;
			}
			else
			{
				flag = 0;
			}
		}


	}

	cout << "输入完毕,输入的迷宫为：" << endl;
	OutputMaze();
}

void maze::OutputMaze()
{
	cout << "输入的迷宫为：" << endl;
	for (int rows = 1; rows < n + 1;++rows)
	{
		for (int cols = 1; cols < n + 1;++cols)
		{
			if (mazem[rows][cols] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_GREEN );
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_RED);

			}
			cout << mazem[rows][cols]<<" ";
		}
		cout << endl;
	}

	cout << endl;
}

void maze::ShowPath()
{
	while (!path->IsEmpty())
	{
		position temp;
		path->Delete(temp);
		mazem[temp.row][temp.col] = 2;
		//cout << temp.row << " " << temp.col << endl;
	}
	for (int rows = 1; rows < n + 1;++rows)
	{
		for (int cols = 1; cols < n + 1;++cols)
		{
			if (mazem[rows][cols]==2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
				cout << mazem[rows][cols] << " ";
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_INTENSITY | BACKGROUND_RED );

				cout << mazem[rows][cols] << " ";
			}
		}

		cout << endl;
	}
}