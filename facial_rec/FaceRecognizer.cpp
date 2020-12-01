#include "FaceRecognizer.h"
#include <opencv2/core.hpp>
#include <opencv2/face.hpp>
#include "./camera/Camera.h"
#include <vector>
using namespace std;

FaceRecognizer::FaceRecognizer(const vector<KnownPerson> &known) {
	// initialize database
	Database peopleDatabase = Database::getInstance();
	for (const KnownPerson &person: known) {
		peopleDatabase.addKnownPerson(person);
	}
	// format imgs and labels
	vector<cv::Mat> imgs;
	vector<int> labels;
	for (int i = 0; i < peopleDatabase.knownSize(); ++i) {
		// add to images
		auto personImg = peopleDatabase[i].getImage();
		imgs.reserve(imgs.size() + personImg.size());
		imgs.insert(imgs.end(), personImg.begin(), personImg.end());

		labels.insert(labels.end(), personImg.size(), i);
	}
	getModel()->train(imgs, labels);
}
FaceRecognizer::FaceRecognizer() = default;
void FaceRecognizer::addPerson(KnownPerson person) {
	Database peopleDatabase = Database::getInstance();
	int i = peopleDatabase.addKnownPerson(person);
	auto personImg = person.getImage();

	vector<int> labels(personImg.size(), i);

	getModel()->update(personImg, labels);
}

Result FaceRecognizer::predictCamera() {
	Camera cam = Camera::getInstance();
	return this->predict(cam.captureGrayscale());
}

Result FaceRecognizer::predict(const cv::Mat &image) {
	Database peopleDatabase = Database::getInstance();
	int index = 0;
	double confidence = 0.0;
	getModel()->predict(image, index, confidence);

	return {.person = peopleDatabase[index], .confidence = confidence};
}
bool FaceRecognizer::isEmpty() {
	return getModel().empty();
}
FaceRecognizer::~FaceRecognizer() = default;
