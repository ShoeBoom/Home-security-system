#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>

#include <opencv2/imgproc/imgproc.hpp>

#include "facial_rec/FaceRecognizer.h"

using namespace cv;
using namespace std;
int main(int argc, const char *argv[]) {
	vector<KnownPerson> known;
	vector<cv::Mat> images;
	string file = string(argv[1]);
	Mat image = imread(file, 0);

	images.push_back(image);
	KnownPerson owner = KnownPerson("firstname", "lastname", "1234", images);
	known.push_back(owner);

	string file2 = string(argv[2]);
	Mat image2 = imread(file2, 0);
	vector<cv::Mat> images2;
	images2.push_back(image2);
	KnownPerson owner2 = KnownPerson("person2", "lastname", "1234", images2);
	known.push_back(owner2);

	FaceRecognizer recognizer = FaceRecognizer(known);

	Mat frame;
	//--- INITIALIZE VIDEOCAPTURE
	VideoCapture cap;
	// open the default camera using default API
	// cap.open(0);
	// OR advance usage: select any API backend
	int deviceID = 0;             // 0 = open default camera
	int apiID = cv::CAP_ANY;      // 0 = autodetect default API
	// open selected camera using selected API
	cap.open(deviceID, apiID);
	// check if we succeeded
	if (!cap.isOpened()) {
		cerr << "ERROR! Unable to open camera\n";
		return -1;
	}
	//--- GRAB AND WRITE LOOP
	cout << "Start grabbing" << endl
	     << "Press any key to terminate" << endl;
	for (;;) {
		// wait for a new frame from camera and store it into 'frame'
		cap.read(frame);
		// check if we succeeded
		if (frame.empty()) {
			cerr << "ERROR! blank frame grabbed\n";
			break;
		}

		Mat greyMat2;
		cv::cvtColor(frame, greyMat2, cv::COLOR_BGR2GRAY);
		Result result = recognizer.predict(greyMat2);
		cout << result.person.firstName << " " << result.confidence << endl;

		// show live and wait for a key with timeout long enough to show images
		imshow("Live", greyMat2);
		if (waitKey(5) >= 0)
			break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}