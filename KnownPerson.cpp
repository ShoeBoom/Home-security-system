#include "KnownPerson.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

// Constructor that creates a database object
KnownPerson::KnownPerson(string fName, string lName, string pNum, vector<Mat> imgs) { 
      firstName = fName;
      lastName = lName;
	  phoneNumber = pNum;
	  images = imgs;
}

// Destructor
KnownPerson::-KnownPerson(){
}

// Set first name
void KnownPerson::setFirstName(string fName){
	firstName = fName;
}

// Set last name
void KnownPerson::setLastName(string lName){
	lastName = lName;
}

// Set phone number
void KnownPerson::setPhoneNumber(string pNum){
	phoneNumber = pNum;
}

// Set images
void KnownPerson::setImage(vector<Mat> imgs){
	images = imgs;
}

// Get first name
string KnownPerson::getFirstName(){
	return firstName;
}

// Get last name
string KnownPerson::getLastName(){
		return lastName;
}

// Get phone number
string KnownPerson::getPhoneNumber(){
	return phoneNumber;
}

// Get image
vector<Mat> KnownPerson::getImage(){
	return images;
}


