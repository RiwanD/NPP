//#include "stdafx.h"
#include <cv>
#include <highgui>

using namespace std;

int main() {
	lplImage* img = cvLoadImage("/home/Documents/test.jpg");

	/*Show the original image*/
	cvNamedWindow("Original");
	cvShowImage("Original", img);

	/*Show the original image using Gaussian kernel to remove noise*/
	cvSmooth(img, imgg, CV_GAUSSIAN, 3, 3);

	/*Converting the original image into grayscale*/
	lplImage *imgGrayScale = cvCreateImage(cvGetSize(img), 8, 1);
	cvCvtColor(img, imgGrayScale, CV_BGR2GRAY);

	cvNamedWindow("GrayScale Image");
	
	cvShowImage("GrayScale Image", imgGrayScale);

	/*Thresholding the grayscale image to get better results*/
	cvThreshold(imgGrayScale, imgGrayScale, 100, 255, CV_THRESH_BINARY_INV);

	cvNamedWindow("Thresholded Image");
	cvShowImage("Thresholded Image", imgGrayScale);

	CvSeq *contour;		//Hold pointer to a contour
	CvSeq *result;		//Hold sequence of points of a contour
	CvMemStorage *storage = cvCreateMemStorage(0);		//Storage area for all contours

	/*Finding all contours in the image*/
	cvFindContours(imgGrayScale, storage, &contour, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));
	
	/*Iterating through each contour*/
	while(contour) {
		/*Obtain a sequence of points of the contour, pointed by the variable 'contour'*/
		result = cvApproxPoly(contour, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(contour)*0.02, 0);

		/*If there are 3 vertices in the contour and the area of the triangle is more than 100 pixels*/
		if(result->total==3 && fabs(cvContourArea(result, CV_WHOLE_SEQ)) > 100) {
			/*Iterating through each point*/
			CvPoint *pt[3];
			for(int i=0 , i<3 ; i++) {
				pt[i] = (CvPoint *) cvGetSeqElem(result, i);
			}

			/*Drawing lines around the triangle*/
			cvLine(img, *pt[0], *pt[1], cvScalar(255, 0, 0), 4);
			cvLine(img, *pt[1], *pt[2], cvScalar(255, 0, 0), 4);
			cvLine(img, *pt[2], *pt[3], cvScalar(255, 0, 0), 4);
		}

		/*Obtain the next contour*/
		contour = contour->h_next;
	}

	/*Show the image in which identified shapes are marked*/
	cvNamedWindow("Tracked");
	cvShowImage("Tracked", img);

	cvWaitKey(0);		//Wait for a key press

	/*Cleaning up*/
	cvDestroyAllWindow();
	cvReleaseMemStorage(&storage);
	cvReleaseImage(&image);
	cvReleaseImage(&imgGrayScale);

	return 0;
}
