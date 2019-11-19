#include "Point.h"

Point::Point(int xx,int yy)
{
	x = xx;
	y = yy;
}
void Point::set(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Point::showPoint()
{
	cout << "(" << x << "," << y << ")" << endl;
}