//
// Created by shubh on 2020-11-09.
//

#include "FaceRecognizer.h"
#include <opencv2/core.hpp>
#include <opencv2/face.hpp>
#include <vector>
using namespace std;

FaceRecognizer::FaceRecognizer(const vector<KnownPerson> &known) {
	// initialize database
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
	model = cv::face::LBPHFaceRecognizer::create();
	model->train(imgs, labels);
}
void FaceRecognizer::addPerson(KnownPerson person) {
	int i = peopleDatabase.addKnownPerson(person);
	auto personImg = person.getImage();

	vector<int> labels(personImg.size(), i);

	model->update(personImg, labels);
}
KnownPerson FaceRecognizer::predict(const cv::Mat &image) {
	int index = model->predict(image);

	return peopleDatabase[index];
}
FaceRecognizer::~FaceRecognizer() = default;
