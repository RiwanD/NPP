/*Library*/
#include "../include/shapeDetect.h"


/*Namespaces*/
using namespace std;
using namespace cv;


/*Shape detection of objects fnuction*/
string shapeDetect(Mat src) {
	/*Variable*/
	char *ret;

	/*Find contours*/
	vector<vector<Point>> contours;
	findContours(src.clone(), contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	vector<Point> approx;
	Mat dst = src.clone();

	for(int i=0 ; i<contours.size() ; i++) {
		/*Approximate contours wth accuracy proprtional to the contours perimeter*/
		approxPolyDP(Mat(contours[i]), approx, arcLength(Mat(contours[i]), true)*0.02, true);

		/*Skip small and non-convex objects*/
		if(fabs(contourArea(contours[i])) < 100 || !isContourConvex(approx)) {
			continue;
		}

		if(approx.size() == 3) {
			return "TRIANGLE";
		} else if(approx.size() >= 4 && approx.size() <= 6) {
			/*Number of vertices of polygonal curve*/
			int nbrVertPolCurve = approx.size();

			/*Get cosines of corners*/
			vector<double> cos;
			for(int j=2 ; j<nbrVertPolCurve+1 ; j++) {
				cos.push_back(angle(approx[j%nbrVertPolCurve], approx[j-2], approx[j-1]));
			}

			/*Sort ascending the cosines values*/
			sort(cos.begin(), cos.end());

			/*Get the lowest/highest angles*/
			double minCos = cos.front();
			double maxCos = cos.back();

			/*Determine shape by the number of vertices curves and degrees obtained*/
			if(nbrVertPolCurve == 4 && minCos >= -0.1 && maxCos <= 0.3) {
				return "RECTANGLE";
			} else if(nbrVertPolCurve == 5 && minCos >= -0.34 && maxCos <= -0.27) {
				return "PENTAGONE";
			} else if(nbrVertPolCurve == 6 && minCos >= -0.55 && maxCos <= -0.45) {
				return "HEXAGONE";
			}	
		} else {
			/*Detect circles*/
			double area	= contourArea(contours[i]);
			Rect r		= boundingRect(contours[i]);
			int radius	= r.width/2;

			if(abs(1-((double) r.width/r.height)) <= 0.2 && abs(1-(area/(CV_PI*pow(radius, 2))))) {
				return "CIRCLE";
			}
		}
	}

	return "src";
}
