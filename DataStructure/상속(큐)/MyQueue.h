#ifndef MYQUEUE_H
#define MYQUEUE_H
#include"BaseArray.h"

class MyQueue :public BaseArray
{
	int q, in, out;
public:
	MyQueue(int q);
	void enqueue(int q);
	int capacity();
	int length();
	int dequeue();
};

#endif