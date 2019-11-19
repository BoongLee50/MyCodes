#ifndef MYSTACK_H
#define MYSTACK_H

#include"BaseArray.h"

class MyStack : public BaseArray {
	int s, in, out;
public:
	MyStack(int s);
	void push(int s);
	int capacity();
	int length();
	int pop();
};

#endif