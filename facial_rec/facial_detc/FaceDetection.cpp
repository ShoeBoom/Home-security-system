//
// Created by shubh on 2020-12-02.
//

#include "FaceDetection.h"
#include <math.h>
using namespace std;
using namespace cv;

FaceDetection::~FaceDetection() {

}
FaceDetection::FaceDetection() {
	face_cascade.load("classifiers/haarcascade_frontalface_alt.xml");
	eyes_cascade.load("classifiers/haarcascade_eye.xml");
}
Data FaceDetection::detectWithEyeDistance(cv::Mat image) {
	std::vector<Rect> faces;
	face_cascade.detectMultiScale(image, faces);
	double diff = -1;
	if (!faces.empty()) {
		auto firstface = faces[0];
		Mat faceROI = image(faces[0]);

		std::vector<Rect> eyes;
		eyes_cascade.detectMultiScale(faceROI, eyes);
		if (eyes.size() >= 2) {
			diff = 100 / sqrt(pow(eyes[0].x - eyes[1].x, 2) + pow(eyes[0].y - eyes[1].y, 2));
		}
	}

	return {.number_of_faces = static_cast<int>(faces.size()), .faces = faces, .first_person_distance =  diff};
}
Data FaceDetection::detectWithoutEyeDistance(cv::Mat image) {
	std::vector<Rect> faces;
	face_cascade.detectMultiScale(image, faces);
	return {.number_of_faces = static_cast<int>(faces.size()), .faces = faces, .first_person_distance = -1};
}
