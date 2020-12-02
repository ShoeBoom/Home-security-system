#define THRESHOLD 20.0

#include "FaceRecognizer.h"
#include <opencv2/core.hpp>
#include <opencv2/face.hpp>
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

	this->callAll({.personID = index, .confidence = confidence});
	return {.personID = index, .confidence = confidence};
}
bool FaceRecognizer::isEmpty() {
	return Database::getInstance().knownSize() == 0;
}
/**
 * Add a callback to be called everytime a prediction is made
 * @param function the callback. The result.personID = -1 when a known person is not found, -2 when a face is found but is unknown
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
