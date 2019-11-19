#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H

#include<iostream>
using namespace std;
#include<string>
#include"Shape.h"

class GraphicEditor : public Shape
{
	Shape *pStart;
	Shape *pEnd;
	Shape *p;
public:
	GraphicEditor();
	void run();
	void input();
	void remove();
	void list();
	void exit();
};

#endif