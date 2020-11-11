//
// Created by shubh on 2020-11-09.
//

#include "FaceRecognizer.h"
#include <opencv2/core.hpp>
#include <opencv2/face.hpp>
#include <vector>
using namespace std;

FaceRecognizer::FaceRecognizer(vector<KnownPerson> known) {
	// initialize database
	for (const KnownPerson &person: known) {
		peopleDatabase.addKnownPerson(person);
	}

	model = cv::face::LBPHFaceRecognizer::create();
	vector<cv::Mat> imgs;
	vector<int> labels;
	for (int i = 0; i < peopleDatabase.knownSize(); ++i) {
		// add to images
		auto personImg = peopleDatabase[i].getImage();
		imgs.reserve(imgs.size() + personImg.size());
		imgs.insert(imgs.end(), personImg.begin(), personImg.end());

//		labels.insert(labels.end(), );
	}

//	model->train(, labels);
}
void FaceRecognizer::addPerson(KnownPerson known) {

}
