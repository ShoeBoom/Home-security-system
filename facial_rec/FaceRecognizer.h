#ifndef CS3307_FACIAL_REC_FACERECOGNIZER_H_
#define CS3307_FACIAL_REC_FACERECOGNIZER_H_

#include "database/Database.h"
#include "database/KnownPerson.h"
#include <opencv2/core.hpp>
#include <opencv2/face.hpp>
#include <vector>

class FaceRecognizer {
 private:
  Database peopleDatabase;
  cv::Ptr<cv::face::LBPHFaceRecognizer> model;

 public:
  FaceRecognizer(const std::vector<KnownPerson> &known);
  ~FaceRecognizer();
  void addPerson(KnownPerson person);
  KnownPerson predict(const cv::Mat &image);
};

#endif //CS3307_FACIAL_REC_FACERECOGNIZER_H_
