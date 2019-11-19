#include "colorPoint.h"

int main()
{
	ColorPoint *pDer;
	Point *pBase, po;

	pBase = &po;
	pDer = (ColorPoint*)pBase;

	pDer->set(3, 3);
	pDer->showPoint();

	//pDer->showColorPoint();
	//pDer->showPoint();

	getchar();
	return 0;
}