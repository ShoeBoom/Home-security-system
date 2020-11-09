#ifndef KNOWNPERSON_CLASS_H
#define KNOWNPERSON_CLASS_H
#include <string>
#include <vector>
#include <opencv2/core.hpp>

class KnownPerson {
 public:
  std::string firstName;
  std::string lastName;
  std::string phoneNumber;
  std::vector<cv::Mat> images;

  // Constructor
  KnownPerson(std::string fName, std::string lName, std::string pNum, std::vector<cv::Mat> imgs);
  // Destructor
  ~KnownPerson();

  // Setter Methods
  void setFirstName(std::string fName);
  void setLastName(std::string lName);
  void setPhoneNumber(std::string pNum);
  void setImage(std::vector<cv::Mat> imgs);

  // Getter Methods
  std::string getFirstName();
  std::string getLastName();
  std::string getPhoneNumber();
  std::vector<cv::Mat> getImage();
};

#endif