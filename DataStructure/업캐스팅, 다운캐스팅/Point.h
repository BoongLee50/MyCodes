#ifndef POINT_H
#define POINT_H

#include<iostream>
using namespace std;

class Point
{
protected:
	int x, y;
public:
	Point(int xx=0, int yy=0);
	void set(int x=0, int y=0);
	void showPoint();
};

#endif
