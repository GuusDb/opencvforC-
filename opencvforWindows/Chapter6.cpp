// opencvforWindows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace std;
using namespace cv;

// COLOR DETECTION

Mat imgHSV, mask;
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

// If you do'n't know what colour you are looking for and still configuring use these settings
//int hmin = 0, smin = 0, vmin = 0;
//int hmax = 179, smax = 255, vmax = 255;

int main()
{
	string imagePath = "Resources/lambo.png";
	Mat img = imread(imagePath);

	// read more about color space
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	// trackbar
	namedWindow("Trackbars", (642, 200));
	createTrackbar("hue min", "Trackbars", &hmin, 179);
	createTrackbar("hue max", "Trackbars", &hmax, 179);
	createTrackbar("sat min", "Trackbars", &smin, 255);
	createTrackbar("sat max", "Trackbars", &smax, 255);
	createTrackbar("val min", "Trackbars", &vmin, 255);
	createTrackbar("val max", "Trackbars", &vmax, 255);


	while (true) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		// color is always a range of values due to light differences
		inRange(imgHSV, lower, upper, mask);
		imshow("Image mask", mask);

		waitKey(1);
	}


	return 0;
}

