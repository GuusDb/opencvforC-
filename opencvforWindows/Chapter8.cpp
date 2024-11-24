#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/videoio.hpp> // For VideoCapture

using namespace std;
using namespace cv;


// resize and use dnn for faster response s
int main()
{
	// Load the face detection cascade
	CascadeClassifier faceCascade;
	if (!faceCascade.load("Resources/haarcascade_frontalface_default.xml")) {
		cout << "Error: XML file not loaded" << endl;
		return -1;
	}

	// Open the default camera (camera ID 0)
	VideoCapture cap(0);
	if (!cap.isOpened()) {
		cout << "Error: Camera not accessible" << endl;
		return -1;
	}

	Mat frame;
	while (true) {
		// Capture a frame from the camera
		cap >> frame;
		if (frame.empty()) {
			cout << "Error: Empty frame" << endl;
			break;
		}

		// Convert the frame to grayscale for face detection
		Mat gray;
		cvtColor(frame, gray, COLOR_BGR2GRAY);

		// Detect faces in the frame
		vector<Rect> faces;
		faceCascade.detectMultiScale(gray, faces, 1.1, 10);

		// Draw rectangles around detected faces
		for (Rect face : faces) {
			rectangle(frame, face.tl(), face.br(), Scalar(255, 0, 255), 3);
		}

		// Display the frame
		imshow("Real-Time Face Detection", frame);

		// Break the loop if the user presses 'q' (waitKey returns the ASCII code)
		if (waitKey(30) == 'q') break;
	}

	// Release the camera and close all windows
	cap.release();
	destroyAllWindows();

	return 0;
}
