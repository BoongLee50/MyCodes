#include "BaseArray.h"

BaseArray::BaseArray(int array)
{
	this->array = array;
	arr = new int[array];
}

BaseArray::~BaseArray()
{
	delete[]arr;
}

void BaseArray::put(int numa, int numb)
{
	arr[numa]=numb;
}

int BaseArray::get(int numa)
{
	return arr[numa];
}

int BaseArray::getArray()
{
	return array;
}