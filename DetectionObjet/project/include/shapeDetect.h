/**
 * File:        shapeDetect.h
 * Description: Contain the declarations of functions used
 */

/*Libraries*/
#include <iostream>
#include <string>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


/*Determine the shape of detected object*/
std::string shapeDetect(cv::Mat src);


/*Find the cosine of angle between vectors*/
static double angle(cv::Point pt1, cv::Point pt2, cv::Point pt3);
