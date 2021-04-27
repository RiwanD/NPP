/**
 * File:	angle.cpp
 * Description:	Find a cosine of angle between vectors
 */


/*Library*/
#include "../include/shapeDetect.h"


/*Namespace*/
using namespace cv;


/*Function angle*/
static double angle(Point pt1, Point pt2, Point pt3) {
	/*Variables*/
	double deltaX1, deltaX2;
	double deltaY1, deltaY2;
	double result;

	/*Calcul cosine*/
	deltaX1 = pt1.x - pt3.x;
	deltaX2 = pt2.x - pt3.x;

	deltaY1 = pt1.y - pt3.y;
	deltaY2 = pt2.y - pt3.y;

	result = ((deltaX1*deltaX2) + (deltaY1*deltaY2)) / sqrt(((deltaX1*deltaX1)+(deltaY1*deltaY1)) * ((deltaX2*deltaX2)+(deltaY2*deltaY2)) + 1e-10);

	/*Return the result*/
	return result;
}
