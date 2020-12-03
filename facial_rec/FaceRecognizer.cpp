#define THRESHOLD 15.0

#include "FaceRecognizer.h"
#include "./camera/Camera.h"
#include <vector>
using namespace std;

void FaceRecognizer::retrain() {
	// format imgs and labels
	vector<cv::Mat> imgs;
	vector<int> labels;
	for (int i = 0; i < Database::getInstance().knownSize(); ++i) {
		// add to images
		auto personImg = Database::getInstance()[i].getImage();
		imgs.reserve(imgs.size() + personImg.size());
		imgs.insert(imgs.end(), personImg.begin(), personImg.end());

		labels.insert(labels.end(), personImg.size(), i);
	}
	model->train(imgs, labels);
}

FaceRecognizer::FaceRecognizer() {
	model->setThreshold(THRESHOLD);
	if (Database::getInstance().knownSize() > 0) {
		retrain();
	}
};

void FaceRecognizer::addPerson(KnownPerson person) {
	Database::getInstance().addKnownPerson(person);
	retrain();
}

Result FaceRecognizer::predictCamera() {
	Camera cam = Camera::getInstance();
	return this->predict(cam.captureGrayscale());
}

Result FaceRecognizer::predict(const cv::Mat &image) {
	int index = 0;
	double confidence = 0.0;
	model->predict(image, index, confidence);
	double distance = -1;
	auto dect = FaceDetection::getDetector();
	auto data = dect.detectWithEyeDistance(image);
	if (index != -1) {
		distance = data.first_person_distance;
	} else {
		if (data.number_of_faces > 0 && data.first_person_distance < 2 && data.first_person_distance != -1) {
			index = -2;
		}
	}
	this->callAll({.personID = index, .confidence = confidence, .distance=distance, .image=image});

	return {.personID = index, .confidence = confidence, .distance=distance, .image=image};
}
bool FaceRecognizer::isEmpty() {
	return Database::getInstance().knownSize() == 0;
}
/**
 * Add a subscription to be called everytime a prediction is made
 * @param function: the subscribed function. The result.personID = -1 when a known person is not found,
 * 										-2 when a face is found but is unknown.
 * 										if result.distance > 2 the person is too far
 */
void FaceRecognizer::onPrediction(const std::function<void(Result)> &function) {
	callbacks.push_back(function);
}
void FaceRecognizer::callAll(Result result) {
	for (const auto &func : callbacks) {
		func(result);
	}
}
KnownPerson FaceRecognizer::getPersonByID(int i) {
	return Database::getInstance()[i];
}

FaceRecognizer::~FaceRecognizer() = default;
