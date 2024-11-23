#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace std;
using namespace cv;


// basic functions

int main()
{
	string imagePath = "Resources/test.png";
	Mat img = imread(imagePath);
	Mat imgGray, imgBlur, imgCanny, imgDilation, imgErode;

	// To gray
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	// Blurring
	GaussianBlur(img, imgBlur, Size(3, 3), 3, 0);
	// Edge detection
	Canny(imgBlur, imgCanny, 25, 75);
	// dilate and erode it
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDilation, kernel);
	// erosion
	erode(imgDilation, imgErode, kernel);

	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDilation);
	imshow("Image Rrode", imgErode);


	waitKey(0);
	return 0;
}

