#ifndef RAILROAD_H
#define RAILROAD_H
#include <iostream>
#include "LinkedStack.h"

bool RailRoad(int r[], int n, int k);
void output(int &MinH, int &MinS, LinkedStack<int> *H, int k, int n);
bool movetocache(int &MinH, int &MinS, LinkedStack<int>* H, int k, int n, int num);
#endif