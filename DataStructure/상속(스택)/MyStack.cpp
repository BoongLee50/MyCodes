#include"MyStack.h"

MyStack::MyStack(int s)
{
	in = out = 0;
	BaseArray Base();
}

void MyStack::push(int s)
{
	put(in++, s);
	out = in;
}

int MyStack::capacity()
{
	return getArray();
}

int MyStack::length()
{
	return out;
}

int MyStack::pop()
{
	return get(--out);
}