#include "MyQueue.h"

MyQueue::MyQueue(int q)
{
	in = out = 0;
	BaseArray Base();
}

void MyQueue::enqueue(int q)
{
	put(in++, q);
}

int MyQueue::capacity()
{
	return getCapacity();
}

int MyQueue::length()
{
	return in - out;
}

int MyQueue::dequeue()
{
	return get(out++);
}