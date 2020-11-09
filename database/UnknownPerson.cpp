#include "UnknownPerson.h"
#include <opencv2/core.hpp>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

// Constructor that creates a database object
UnknownPerson::UnknownPerson(vector<cv::Mat> imgs) {
	images = imgs;
}

// Destructor
UnknownPerson::~UnknownPerson() {
}

// Set images
void UnknownPerson::setImage(vector<cv::Mat> imgs) {
	images = imgs;
}

// Getter Methods
// Get image
vector<cv::Mat> UnknownPerson::getImage() {
	return images;
}


