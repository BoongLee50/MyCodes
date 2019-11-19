#ifndef COLORPOINT_H
#define COLORPOINT_H

#include "Point.h"
#include<string>
class ColorPoint : public Point
{
	string color;
public:
	ColorPoint();
	void setColor(string c="Black");
	void showColorPoint();
};

#endif
