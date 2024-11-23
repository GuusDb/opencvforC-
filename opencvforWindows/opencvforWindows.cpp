// opencvforWindows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace std;
using namespace cv;

// Camera

int main()
{
	// id of the camera
	VideoCapture cap(0);
	Mat img;


	while (true) {
		cap.read(img);

		imshow("Image", img);
		waitKey(1);
	}
	return 0;

}


// video
//
//int main()
//{
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//
//	bool videoFinished = false;
//
//	while (!videoFinished) {
//		cap.read(img);
//		if (img.empty()) {
//			videoFinished = true;
//			continue;
//		}
//		imshow("Image", img);
//		waitKey(1);
//	}
//	return 0;
//
//}

// picture

//int main()
//{
//	string imagePath = "Resources/test.png";
//	Mat image = imread(imagePath);
//	imshow("Image", image);
//	waitKey(0);
//	return 0;
//}

