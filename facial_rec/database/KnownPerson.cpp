/** 
 * Known person
 * Stores information about the known person (name, phone number, images).
 * @author group53
 */
#include <opencv2/core.hpp>
#include "KnownPerson.h"
#include <vector>
#include <string>
using namespace std;

/** 
 * Constructor that creates a known person object
 * @param first_name first name
 * @param last_name last name
 * @param phone_number phone number
 * @param images images of known person
 */
KnownPerson::KnownPerson(const string &first_name,
                         const string &last_name,
                         const string &phone_number,
                         const vector<cv::Mat> &images)
	: firstName(first_name), lastName(last_name), phoneNumber(phone_number), images(images) {}

/** 
 * Destructor
 */
KnownPerson::~KnownPerson() {
}

/** 
 * Set person's first name
 * @param fName
 */
void KnownPerson::setFirstName(string fName) {
	firstName = fName;
}

/** 
 * Set person's last name
 * @param lName
 */
void KnownPerson::setLastName(string lName) {
	lastName = lName;
}

/** 
 * Set person's phone number
 * @param pNum
 */
void KnownPerson::setPhoneNumber(string pNum) {
	phoneNumber = pNum;
}

/** 
 * Set person's images
 * @param imgs
 */
void KnownPerson::setImage(vector<cv::Mat> imgs) {
	images = imgs;
}

/** 
 * Get person's first name
 * @return first name
 */
string KnownPerson::getFirstName() {
	return firstName;
}

/** 
 * Get person's last name
 * @return last name
 */
string KnownPerson::getLastName() {
	return lastName;
}

/** 
 * Get person's phone number
 * @return phone number
 */
string KnownPerson::getPhoneNumber() {
	return phoneNumber;
}

/** 
 * Get person's images
 * @return images
 */
vector<cv::Mat> KnownPerson::getImage() {
	return images;
}




