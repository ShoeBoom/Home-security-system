#ifndef KNOWNPERSON_CLASS_H
#define KNOWNPERSON_CLASS_H
#include <string>
#include <vector>
#include <opencv2/core.hpp>

class KnownPerson {
 public:
  int id;
  std::string firstName;
  std::string lastName;
  std::string phoneNumber;
  std::vector<cv::Mat> images;

  // Constructor
  KnownPerson(int id,
              const std::string &first_name,
              const std::string &last_name,
              const std::string &phone_number,
              const std::vector<cv::Mat> &images);
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