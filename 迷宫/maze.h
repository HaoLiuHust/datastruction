#ifndef MAZE_H
#define MAZE_H
#include "LinkedStack.h"
#include <cstdio>
#include<windows.h>

using std::cout;
using std::cin;
using std::endl;

struct position 
{
	int row;
	int col;
};


class maze
{
public:
	maze(int m);
	maze(int* matrix, int m);
	~maze();
	bool FindPath();
	void InputMaze();
	void OutputMaze();
	void ShowPath();
private:
	LinkedStack<position> *path;
	int **mazem;
	int n;
};


#endif