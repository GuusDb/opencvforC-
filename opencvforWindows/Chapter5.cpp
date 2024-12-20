#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace std;
using namespace cv;


// Warp perspective
float w = 250;
float h = 350;
Mat matrix, imgWarp;

int main()
{
	string imagePath = "Resources/cards.jpg";
	Mat img = imread(imagePath);

	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	// Check if you have selected the correct point in case of bug
	for (int i = 0; i < 4;i++) {
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("Image", img);
	imshow("Image Warp", imgWarp);


	waitKey(0);
	return 0;
}
