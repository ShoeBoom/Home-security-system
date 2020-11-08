#ifndef UNKNOWNPERSON_CLASS_H
#define UNKNOWNPERSON_CLASS_H
#include <string>
#include <vector>

class UnknownPerson {
    public:             
        vector<Mat> images;

    // Constructor
	UnknownPerson(vector<Mat> imgs)
    // Destructor
    ~UnknownPerson();

    // Setter Methods
	void setImage(vector<Mat> imgs);


    // Getter Methods
	vector<Mat> getImage();

};

#endif