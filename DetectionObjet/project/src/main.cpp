/*Libraries*/
#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include "../include/shapeDetect.h"


/*Namespaces*/
using namespace std;
using namespace cv;


/*Main function*/
int main(int argc, char *argv[]) {
	/*Variables declaration*/
	int cameraID	= 0;		//Default device
	int apiID		= CAP_ANY;	//Auto detect default API
	string shape	= NULL;

	/*Intanciate Mat object*/
	Mat frame;

	/*Initialize video capture*/
	VideoCapture video;

	/*Open selected camera with selected API*/
	video.open(cameraID, apiID);
	if(!video.isOpened()) {
		cout << "ERROR - Unable to open camera -> Exit program." << endl;
	}

	/*Get video stream continuously*/
	while(true) {
		/*Wait a new frame and stored it*/
		video.read(frame);
		if(frame.empty()) {
			cout << "ERROR - No frame captured -> Exit program" << endl;
			break;
		}

		/*Detect object shape*/
		shape = shapeDetect(frame);
		cout << "INFO - The object is a " << shape << "." << endl;
	}
	
	return EXIT_SUCCESS;
}
