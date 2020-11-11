#ifndef UNKNOWNPERSON_CLASS_H
#define UNKNOWNPERSON_CLASS_H
#include <string>
#include <vector>
#include <opencv2/core.hpp>

class UnknownPerson {
    public:
  std::vector<cv::Mat> images;

  // Constructor
  UnknownPerson(std::vector<cv::Mat> imgs);
  // Destructor
  ~UnknownPerson();

  // Setter Methods
  void setImage(std::vector<cv::Mat> imgs);

  // Getter Methods
  std::vector<cv::Mat> getImage();

};

#endif