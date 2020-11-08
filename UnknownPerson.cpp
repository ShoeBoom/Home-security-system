#include "UnknownPerson.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

// Constructor that creates a database object
UnknownPerson::UnknownPerson(vector<Mat> imgs) { 
	  images = imgs;
}

// Destructor
UnknownPerson::-UnknownPerson(){
}

// Set images
void UnknownPerson::setImage(vector<Mat> imgs){
	images = imgs;
}

// Getter Methods
// Get image
vector<Mat> UnknownPerson::getImage(){
	return images;
}


