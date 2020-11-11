#include <opencv2/core.hpp>
#include "KnownPerson.h"
#include <vector>
#include <string>
using namespace std;

// Constructor that creates a database object


// Destructor
KnownPerson::~KnownPerson() {
}

// Set first name
void KnownPerson::setFirstName(string fName) {
	firstName = fName;
}

// Set last name
void KnownPerson::setLastName(string lName) {
	lastName = lName;
}

// Set phone number
void KnownPerson::setPhoneNumber(string pNum) {
	phoneNumber = pNum;
}

// Set images
void KnownPerson::setImage(vector<cv::Mat> imgs) {
	images = imgs;
}

// Get first name
string KnownPerson::getFirstName() {
	return firstName;
}

// Get last name
string KnownPerson::getLastName() {
	return lastName;
}

// Get phone number
string KnownPerson::getPhoneNumber() {
	return phoneNumber;
}

// Get image
vector<cv::Mat> KnownPerson::getImage() {
	return images;
}
KnownPerson::KnownPerson(int id,
                         const string &first_name,
                         const string &last_name,
                         const string &phone_number,
                         const vector<cv::Mat> &images)
	: id(id), firstName(first_name), lastName(last_name), phoneNumber(phone_number), images(images) {}


