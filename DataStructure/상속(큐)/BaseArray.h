#ifndef BASEARRAY_H
#define BASEARRAY_H
#include<iostream>
using namespace std;

class BaseArray
{
	int capacity;
	int *mem;
protected:
	BaseArray(int capacity = 100);
	~BaseArray();
	void put(int index, int val);
	int get(int index);
	int getCapacity();
};

#endif
