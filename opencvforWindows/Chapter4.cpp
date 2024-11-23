#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace std;
using namespace cv;


// resize and crop

int main()
{
	string imagePath = "Resources/test.png";
	Mat img = imread(imagePath);
	Mat imgResize, imgCrop;

	// Resize image
	resize(img, imgResize, Size(), 0.5, 0.5);

	// Cropping - roi = region of intrest
	Rect roi(200, 100, 300, 300);
	imgCrop = img(roi);


	imshow("Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);

	waitKey(0);
	return 0;
}

