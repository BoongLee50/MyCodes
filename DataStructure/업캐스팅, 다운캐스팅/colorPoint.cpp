#include "colorPoint.h"

ColorPoint::ColorPoint()
{
	this->setColor("black");
}

void ColorPoint::setColor(string c)
{
	color = c;
}

void ColorPoint::showColorPoint()
{
	cout << "Color :" << color << endl;
	cout << "(" << x << "," << y << ")" << endl;
}