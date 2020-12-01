#ifndef CS3307_FACIAL_REC_FACERECOGNIZER_H_
#define CS3307_FACIAL_REC_FACERECOGNIZER_H_

#include "database/Database.h"
#include "database/KnownPerson.h"
#include <opencv2/core.hpp>
#include <opencv2/face.hpp>
#include <vector>

struct Result {
  KnownPerson person;
  double confidence;
};

class FaceRecognizer {
 private:
  cv::Ptr<cv::face::LBPHFaceRecognizer> &getModel() {
	  static cv::Ptr<cv::face::LBPHFaceRecognizer> model = cv::face::LBPHFaceRecognizer::create();
	  return model;
  }

 public:
  FaceRecognizer(const std::vector<KnownPerson> &known);
  FaceRecognizer();
  ~FaceRecognizer();
  void addPerson(KnownPerson person);
  Result predict(const cv::Mat &image);
  Result predictCamera();
  bool isEmpty();
};

#endif //CS3307_FACIAL_REC_FACERECOGNIZER_H_
