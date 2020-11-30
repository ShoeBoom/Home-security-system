#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>

#include <opencv2/imgproc/imgproc.hpp>

#include "facial_rec/FaceRecognizer.h"
#include "facial_rec/camera/Camera.h"

using namespace cv;
using namespace std;
int main(int argc, const char *argv[]) {
	// still inaccurate due to sample size
	Camera camera = *Camera::getInstance();

	vector<KnownPerson> known;

	char input = 'Y';
	int i = 0;
	while (input != 'Q') {
		cout << "adding images for person" << i << endl;
		vector<cv::Mat> images;
		char input2;
		cin.get(input2);
		while (input2 != 'S') {
			Mat frame = camera.captureGrayscale();
			images.push_back(frame);
			cout << "added image for person" << i << ". enter 'S' to Stop" << endl;
			cin.get(input2);
		}

		KnownPerson person = KnownPerson("person" + to_string(i), "lastname", "1234", images);
		known.push_back(person);
		cout << "added person" << i << " to database. enter 'Q' to Stop" << endl;
		cin.ignore();
		cin.get(input);
		i++;
	}

	FaceRecognizer recognizer = FaceRecognizer(known);

	//--- GRAB AND WRITE LOOP
	cout << "Start grabbing" << endl
	     << "Press any key to terminate" << endl;
	for (;;) {

		Mat frame = camera.captureGrayscale();

		Result result = recognizer.predict(frame);
		cout << result.person.firstName << " " << result.confidence << endl;

		// show live and wait for a key with timeout long enough to show images
		imshow("Live", frame);

		if (waitKey(5) >= 0)
			break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}