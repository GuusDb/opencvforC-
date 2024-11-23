#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace std;
using namespace cv;


int main()
{
	// Blank image
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	// Create circle
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);
	// rectangle
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
	// Line
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);
	// Put text
	putText(img, "Love Buky", Point(137, 267), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);

	imshow("Image", img);

	waitKey(0);
	return 0;
}

