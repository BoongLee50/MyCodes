#ifndef BASEARRAY_H
#define BASEARRAY_H

#include<iostream>
using namespace std;

class BaseArray
{
	int array;
	int *arr;
protected:
	BaseArray(int array = 100);
	~BaseArray();
	void put(int numa, int numb);
	int get(int numa);
	int getArray();
};

#endif
