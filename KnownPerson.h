#ifndef KNOWNPERSON_CLASS_H
#define KNOWNPERSON_CLASS_H
#include <string>
#include <vector>

class KnownPerson {
    public:             
		std::string firstName;    
		std::string lastName;
		std::string phoneNumber;
		vector<Mat> images;

    // Constructor
	KnownPerson(std::string fName, std::string lName, std::string pNum, vector<Mat> imgs)
    // Destructor
    ~KnownPerson();

    // Setter Methods
    void setFirstName(std::string fName);
    void setLastName(std::string lName);
	void setPhoneNumber(std::string pNum);
	void setImage(vector<Mat> imgs);

    // Getter Methods
    std::string getFirstName();
    std::string getLastName();
	std::string getPhoneNumber();
	vector<Mat> getImage();
};

#endif