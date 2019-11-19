#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
using namespace std;

class Shape
{
	Shape *next;
protected:
	virtual void draw() { cout << " Shape" << endl; }
public:
	Shape() { next = NULL; }
	void paint() { draw(); }
	Shape* add(Shape* p){ this->next = p; return p; }
	Shape* getNext() { return next; }
	void setNext(Shape* p) { this->next = p->next; }
};

class Line : public Shape
{
public:
	virtual void draw() { cout << " Line" << endl; }
};

class Circle : public Shape
{
public:
	virtual void draw() { cout << " Circle" << endl; }
};

class Rect : public Shape
{
public:
	virtual void draw() { cout << " Rect" << endl; }
};

#endif